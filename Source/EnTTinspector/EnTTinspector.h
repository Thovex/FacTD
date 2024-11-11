#pragma once

#include "Modules/ModuleManager.h"

#include "EnTTinspector/Include.h"

class FEnTTinspector final : public IModuleInterface {
public:
	static TSharedPtr<SVerticalBox> Root;
	static TSharedPtr<SVerticalBox> DebugInfo;

	static TSet<FName> IgnoredInspectors;
	static TMap<FName, TFunction<TSharedRef<IComponentInspector>(FEntityWorld&, EEntity Entity)>> RegisteredInspectors;

	static bool bInitialized;

protected:
	FTSTicker::FDelegateHandle TickDelegateHandle;
	bool InspectorTick(float DeltaTime);

	void DestroyEntity(FRegistry& Registry, EEntity Entity);

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

