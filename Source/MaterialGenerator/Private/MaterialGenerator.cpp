// Copyright (C) Shatrujit Aditya Kumar 2024. All Rights Reserved.

#include "MaterialGenerator.h"
#include "Editor.h"
#include "EditorUtilitySubsystem.h"
#include "EditorUtilityWidgetBlueprint.h"
#include "ToolMenus.h"
#include "ToolMenuSection.h"

#define LOCTEXT_NAMESPACE "FMaterialGeneratorModule"

namespace MaterialGeneratorModule
{
    static const FName GeneratorTabName = "Material Generator";
}

void FMaterialGeneratorModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    if (GIsEditor && !IsRunningCommandlet())
    {
        UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMaterialGeneratorModule::ExtendToolsMenu));
    }
   
}

void FMaterialGeneratorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FMaterialGeneratorModule::ExtendToolsMenu()
{
    UToolMenu* ToolMenu = UToolMenus::Get()->ExtendMenu("MainFrame.MainMenu.Tools");
    FToolMenuSection& ToolsSection = ToolMenu->FindOrAddSection("Tools");
    ToolsSection.AddMenuEntry("OpenMatGenWidget",
        LOCTEXT("OpenMatGen_Label", "Material Generator"),
        LOCTEXT("OpenMatGen_Desc", "Opens the Material Generator widget"),
        FSlateIcon(),
        FUIAction(FExecuteAction::CreateRaw(this, &FMaterialGeneratorModule::CreateWidget), FCanExecuteAction()));
}

void FMaterialGeneratorModule::CreateWidget()
{
    UObject* WidgetObj = LoadObject<UObject>(nullptr, TEXT("/MaterialGenerator/WU_MaterialGenerator.WU_MaterialGenerator"));
    UEditorUtilityWidgetBlueprint* WidgetBP = static_cast<UEditorUtilityWidgetBlueprint*>(WidgetObj);
    UEditorUtilitySubsystem* EditorUtilitySubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
    EditorUtilitySubsystem->SpawnAndRegisterTab(WidgetBP);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMaterialGeneratorModule, MaterialGenerator)