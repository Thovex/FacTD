#pragma once

#include "EnTTinspector/Include.h"

namespace Inspectors::BaseComponents {
	class FNameComponentInspector : public IComponentInspector {
	public:
		FNameComponent* NameComponent = nullptr;

		FNameComponentInspector(FEntityWorld& World, const EEntity Entity) : IComponentInspector(World, Entity) {}
		virtual TSharedPtr<SBorder> CreateWidget() override;
	};
}
