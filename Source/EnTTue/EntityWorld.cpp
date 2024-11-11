#include "EnTTue/EntityWorld.h"

#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "ToolContextInterfaces.h"

#include "EnTTue/Components/BaseComponents.h"
#include "EnTTue/Components/Tags.h"
#include "EnTTue/Components/TransformComponents.h"
#include "EnTTue/Utils/CommonUtil.h"

UDataTable* FEntityWorld::GetDataTable(const FString& Path)
{
	return LoadObject<UDataTable>(nullptr, *Path);
}

void FEntityWorld::Save() {
	TSharedPtr<FJsonObject> MasterJson = MakeShareable(new FJsonObject());

	for (auto&& [Entity] : ForEachEntity()) {
		TSharedPtr<FJsonObject> EntityJson = MakeShareable(new FJsonObject());

		// Make Json Array
		TArray<TSharedPtr<FJsonValue>> ComponentArray;
		VisitComponents(Entity, [&](const entt::type_info& Info) {
			const FName ComponentName = CommonUtil::ComponentTypeInfoToName(Info);
			
			UE_LOG(LogECS, Warning, TEXT("Component: %s"), *ComponentName.ToString());
			UE_LOG(LogECS, Warning, TEXT("Registered: %d"), GetSerializeFuncRegistry().Num());
			if (GetSerializeFuncRegistry().Contains(ComponentName)) {
				const TSharedPtr<FJsonObject> ComponentObject = GetSerializeFuncRegistry()[ComponentName](*this, Entity);
				if (ComponentObject) {
					ComponentArray.Add(MakeShareable(new FJsonValueObject(ComponentObject)));
				}
			}
			return false;  // Continue the loop
		});
		
		// Add Array to Entity
		EntityJson->SetArrayField("Components", ComponentArray);

		// Add Entity to Master
		MasterJson->SetObjectField(FString::FromInt(static_cast<int32>(Entity)), EntityJson);
	}

	FString Output;
	const TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Output);
	FJsonSerializer::Serialize(MasterJson.ToSharedRef(), Writer);

	FString SaveDir = *FPaths::ProjectSavedDir();
	FFileHelper::SaveStringToFile(Output, *SaveDir.Append(TEXT("world_save.json")));

	// Dump the Json data:
	UE_LOG(LogECS, Warning, TEXT("Json: %s"), *Output);
}

void FEntityWorld::Load() {
	for (auto&& [Entity] : ForEachEntity()) {
		EmplaceOrReplace<FDestroyAtEndOfTickTag>(Entity);
	}

	FString LoadDir = *FPaths::ProjectSavedDir();
	FString Input;
	FFileHelper::LoadFileToString(Input, *LoadDir.Append(TEXT("world_save.json")));

	TSharedPtr<FJsonObject> MasterJson;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Input);
	if (FJsonSerializer::Deserialize(Reader, MasterJson) && MasterJson.IsValid()) {
		for (const auto& Pair : MasterJson->Values) {
			EEntity Entity = Create();
			const TArray<TSharedPtr<FJsonValue>>& ComponentArray = Pair.Value->AsObject()->GetArrayField("Components");

			for (const auto& ComponentValue : ComponentArray) {
				TSharedPtr<FJsonObject> ComponentObject = ComponentValue->AsObject();
				const FName ComponentName = FName(*ComponentObject->GetStringField("Name"));
				const FString& JsonData = ComponentObject->GetStringField("Data");

				if (GetDeserializeFuncRegistry().Contains(ComponentName)) {
					GetDeserializeFuncRegistry()[ComponentName](*this, Entity, JsonData);
				} else {
					UE_LOG(LogECS, Warning, TEXT("No deserialization function registered for component: %s"), *ComponentName.ToString());
				}
			}
		}
	} else {
		UE_LOG(LogECS, Error, TEXT("Failed to parse world_save.json"));
	}
}

FVector FEntityWorld::GetWorldPosition(const EEntity Entity) {
	if (const FWorldPositionComponent* WorldPosition = TryGet<FWorldPositionComponent>(Entity)) {
		return WorldPosition->Position;
	}

	FVector WorldPosition; // Calculate WorldPosition
	if (const FParentComponent* Parent = TryGet<FParentComponent>(Entity)) {
		WorldPosition = GetWorldPosition(Parent->Parent) + Get<FPositionComponent>(Entity);
		return WorldPosition;
	}
		
	WorldPosition = Get<FPositionComponent>(Entity);
	return WorldPosition;
}

FRotator FEntityWorld::GetWorldRotation(const EEntity Entity) {
	if (const FWorldRotationComponent* WorldRotation = TryGet<FWorldRotationComponent>(Entity)) {
		return WorldRotation->Rotation;
	}

	FRotator WorldRotation; // Calculate WorldRotation
	if (const FParentComponent* Parent = TryGet<FParentComponent>(Entity)) {
		WorldRotation = GetWorldRotation(Parent->Parent) + Get<FRotationComponent>(Entity);
		return WorldRotation;
	}

	WorldRotation = Get<FRotationComponent>(Entity);
	return WorldRotation;
}

FVector FEntityWorld::GetWorldScale(const EEntity Entity) {

	if (const FWorldScaleComponent* WorldScale = TryGet<FWorldScaleComponent>(Entity)) {
		return WorldScale->Scale;
	}
		
	FVector WorldScale; // Calculate WorldScale
	if (const FParentComponent* Parent = TryGet<FParentComponent>(Entity)) {
		WorldScale = GetWorldScale(Parent->Parent) * Get<FScaleComponent>(Entity);
		return WorldScale;
	}

	WorldScale = Get<FScaleComponent>(Entity);
	return WorldScale;
}


