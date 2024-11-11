#include "Serialization.h"

TMap<FName, FComponentSerializeFunc>& GetSerializeFuncRegistry() {
	static TMap<FName, FComponentSerializeFunc> TypeRegistryInstance;
	return TypeRegistryInstance;
}

void AddToSerializeRegistry(const FName& ComponentName, const FComponentSerializeFunc& SerializeFunc) {
	if (!GetSerializeFuncRegistry().Contains(ComponentName)) {
		GetSerializeFuncRegistry().Add(ComponentName, SerializeFunc);
	}
}
TMap<FName, FComponentDeserializeFunc>& GetDeserializeFuncRegistry() {
	static TMap<FName, FComponentDeserializeFunc> TypeRegistryInstance;
	return TypeRegistryInstance;
}

void AddToDeserializeRegistry(const FName& ComponentName, const FComponentDeserializeFunc& DeserializeFunc) {
	if (!GetDeserializeFuncRegistry().Contains(ComponentName)) {
		GetDeserializeFuncRegistry().Add(ComponentName, DeserializeFunc);
	}
}
