// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/SQuickStartWindowMenu.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SQuickStartWindowMenu::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.Text(FText::FromString("Test Button"))
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Top)
			[
				SNew(SButton)
				.Text(FText::FromString("Press Me"))
				.OnClicked(FOnClicked::CreateSP(this, &SQuickStartWindowMenu::OnTestButtonClicked))
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.Text(FText::FromString("Test Checkbox"))
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Top)
			[
				SNew(SCheckBox)
				.OnCheckStateChanged(FOnCheckStateChanged::CreateSP(this, &SQuickStartWindowMenu::OnTestCheckBoxStateChanged))
				.IsChecked(bIsTestBoxChecked)
			]
		]
	];
}

FReply SQuickStartWindowMenu::OnTestButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello, world! The checkbox is %s."), (bIsTestBoxChecked ? TEXT("checked") : TEXT("unchecked")));
	return FReply::Handled();
}

void SQuickStartWindowMenu::OnTestCheckBoxStateChanged(ECheckBoxState NewState)
{
	bIsTestBoxChecked = NewState == ECheckBoxState::Checked ? true : false;
}

ECheckBoxState SQuickStartWindowMenu::IsTestBoxChecked() const
{
	return bIsTestBoxChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
