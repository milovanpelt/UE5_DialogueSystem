// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SLATEQUICKSTARTWINDOW_API SQuickStartWindowMenu : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SQuickStartWindowMenu)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply OnTestButtonClicked();
	void OnTextCheckBoxStateChanged(ECheckBoxState NewState);
	void OnTextChanged(const FText& NewText, ETextCommit::Type CommitType, int32 DialogueIndex);
	ECheckBoxState IsTestBoxChecked() const;

protected:
	bool bIsTextBoxChecked;
	TArray<FString> Dialogues;
};
