#pragma once

#define REGISTER_INSPECTOR(ComponentType, InspectorType) \
UE_LOG(LogTemp, Warning, TEXT("Registering inspector for %s"), *CommonUtil::ComponentTypeInfoToName(entt::resolve<ComponentType>().info()).ToString()); \
RegisteredInspectors.Add( \
CommonUtil::ComponentTypeInfoToName(entt::resolve<ComponentType>().info()), \
[] (FEntityWorld& RIWorld, EEntity Entity) { \
return MakeShared<InspectorType>(RIWorld, Entity); \
} \
)

#define IGNORE_COMPONENT(ComponentType) \
    IgnoredInspectors.Add(CommonUtil::ComponentTypeInfoToName(entt::resolve<ComponentType>().info()))

#define TERRAIN_TRACE_CHANNEL ECollisionChannel::ECC_GameTraceChannel1