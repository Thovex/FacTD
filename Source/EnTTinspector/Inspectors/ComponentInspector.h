#pragma once

#include "EnTTue/Include.h"

class IComponentInspector {
public:
	IComponentInspector() = default;
	IComponentInspector(FEntityWorld& World, const EEntity Entity) : World(&World), Entity(Entity) {}
	virtual ~IComponentInspector() = default;

	TSharedPtr<SBorder> RootWidget = nullptr;

	virtual TSharedPtr<SBorder> CreateWidget()
	{
		SAssignNew(RootWidget, SBorder)
			.BorderBackgroundColor(FLinearColor::Transparent)
			.Padding(2);

		return RootWidget;
	}
	virtual void Tick(UWorld* WorldRoot, FEntityWorld& EntityWorld, const float DeltaTime) {}

	FEntityWorld* World = nullptr;
	EEntity Entity = entt::null;
	FName FancyName = NAME_None;
};

