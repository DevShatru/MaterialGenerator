// Copyright Shatrujit Aditya Kumar, 2023. All Rights Reserved.

#pragma once

#include "EditorUtilityWidget.h"
#include "MaterialGeneratorWidget.generated.h"

class UEditorUtilityEditableTextBox;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, config=MaterialGenerator)
class MATERIALGENERATOR_API UMaterialGeneratorWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UEditorUtilityEditableTextBox* TexturesDirectoryBox;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UEditorUtilityEditableTextBox* MaterialsDirectoryBox;

protected:
	UPROPERTY(config, BlueprintReadOnly)
	FText TexturesLocation;

	UPROPERTY(config, BlueprintReadOnly)
	FText MaterialsLocation;

private:
	void PopulateDefaults();
};
