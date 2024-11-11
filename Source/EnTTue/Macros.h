#pragma once

#define DEFINE_COMPONENT(T) \
static TSharedPtr<FJsonObject> Serialize_##T##_ToJson(FEntityWorld& World, EEntity Entity) { \
if (T* Component = World.TryGet<T>(Entity)) { \
TSharedPtr<FJsonObject> Json = MakeShareable(new FJsonObject()); \
FString JsonData; \
FJsonObjectConverter::UStructToJsonObjectString<T>(*Component, JsonData, 0, 0); \
const FName FancyName = CommonUtil::ComponentTypeInfoToName(entt::resolve<T>().info()); \
Json->SetStringField("Name", FancyName.ToString()); \
Json->SetStringField("Data", JsonData); \
return Json; \
} \
return nullptr; \
} \
static void Register_##T##_Serialization() { \
FName ComponentName = CommonUtil::ComponentTypeInfoToName(entt::resolve<T>().info()); \
AddToSerializeRegistry(ComponentName, Serialize_##T##_ToJson); \
} \
static const bool bRegistered_##T = []() { Register_##T##_Serialization(); return true; }(); \
static bool Deserialize_##T##_FromJson(FEntityWorld& World, EEntity Entity, const FString& JsonData) { \
T Component; \
if (FJsonObjectConverter::JsonObjectStringToUStruct<T>(JsonData, &Component, 0, 0)) { \
World.EmplaceOrReplace<T>(Entity, Component); \
return true; \
} \
return false; \
} \
static void Register_##T##_Deserialization() { \
FName ComponentName = CommonUtil::ComponentTypeInfoToName(entt::resolve<T>().info()); \
AddToDeserializeRegistry(ComponentName, Deserialize_##T##_FromJson); \
} \
static const bool bDeserializationRegistered_##T = []() { Register_##T##_Deserialization(); return true; }();
