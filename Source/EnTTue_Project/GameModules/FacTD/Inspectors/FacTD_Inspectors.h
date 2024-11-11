#pragma once

#include <EnTTue_Project/GameModules/FacTD/Components/FacTD_GridComponents.h>

#include "EnTTinspector/Include.h"

namespace Inspectors::FacTD {
	class FFacTD_GridComponentInspector : public IComponentInspector {
	public:
		FFacTD_GridComponent* GridComponent = nullptr;

		FFacTD_GridComponentInspector(FEntityWorld& World, const EEntity Entity) : IComponentInspector(World, Entity) {}
		virtual TSharedPtr<SBorder> CreateWidget() override;
		virtual TSharedRef<SWidget> CreateGridEntitiesWidget();

	};
	
}
