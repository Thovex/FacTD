#include "EnTTue/EnTTue.h"

#include "Modules/ModuleManager.h"

void FEnTTue::StartupModule() {
	IModuleInterface::StartupModule();
}

void FEnTTue::ShutdownModule() {
	IModuleInterface::ShutdownModule();
}
IMPLEMENT_MODULE(FEnTTue, EnTTue)
