#pragma once

#include "EnTTinspector/Include.h"

#include "EnTTue/Components/TransformComponents.h"

namespace Inspectors::TransformComponents {
	class FVelocityComponentInspector : public IComponentInspector {
	public:
		FVelocityComponent* VelocityComponent = nullptr;

		FVelocityComponentInspector(FEntityWorld& World, const EEntity Entity) : IComponentInspector(World, Entity) {}
		virtual TSharedPtr<SBorder> CreateWidget() override;
	};
}
