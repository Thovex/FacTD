#pragma once

#include "EnTTue/EntityWorld.h"

#include "Dom/JsonObject.h"

using FComponentSerializeFunc = TFunction<TSharedPtr<FJsonObject>(FEntityWorld&, EEntity)>;
ENTTUE_API TMap<FName, FComponentSerializeFunc>& GetSerializeFuncRegistry();
ENTTUE_API void AddToSerializeRegistry(const FName& ComponentName, const FComponentSerializeFunc& SerializeFunc);

using FComponentDeserializeFunc = TFunction<bool(FEntityWorld&, EEntity, const FString&)>;
ENTTUE_API TMap<FName, FComponentDeserializeFunc>& GetDeserializeFuncRegistry();
ENTTUE_API void AddToDeserializeRegistry(const FName& ComponentName, const FComponentDeserializeFunc& DeserializeFunc);