// Copyright Shatrujit Aditya Kumar, 2023. All Rights Reserved.


#include "MaterialGeneratorWidget.h"

// Engine
#include "EditorUtilityWidgetComponents.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MaterialGeneratorWidget)

void UMaterialGeneratorWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PopulateDefaults();
}

void UMaterialGeneratorWidget::PopulateDefaults()
{
	if (!TexturesLocation.IsEmpty())
	{
		TexturesDirectoryBox->SetText(TexturesLocation);
	}

	if (!MaterialsLocation.IsEmpty())
	{
		MaterialsDirectoryBox->SetText(MaterialsLocation);
	}
}
