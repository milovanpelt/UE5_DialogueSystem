// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/SQuickStartWindowMenu.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SQuickStartWindowMenu::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		// Dialogue box 1
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.Text(FText::FromString("Dialogue 1: "))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(10, 0, 0, 0)
			.VAlign(VAlign_Top)
			[
				SNew(SEditableTextBox)
				.OnTextCommitted(this, &SQuickStartWindowMenu::OnTextChanged, 0)
				.Text(FText::FromString("Enter your text here"))
				.MinDesiredWidth(200)
			]

			// Dialogue box 2
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.Text(FText::FromString("Dialogue 2: "))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(10, 0, 0, 0)
			.VAlign(VAlign_Top)
			[
				SNew(SEditableTextBox)
				.OnTextCommitted(this, &SQuickStartWindowMenu::OnTextChanged, 1)
				.Text(FText::FromString("Enter your text here"))
				.MinDesiredWidth(200)
			]

			// Dialogue box 3
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.Text(FText::FromString("Dialogue 3: "))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(10, 0, 0, 0)
			.VAlign(VAlign_Top)
			[
				SNew(SEditableTextBox)
				.OnTextCommitted(this, &SQuickStartWindowMenu::OnTextChanged, 2)
				.Text(FText::FromString("Enter your text here"))
				.MinDesiredWidth(200)
			]
		]

		// Saving Dialogue Button
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.FillWidth(100)
			.Padding(0, 0, 0, 0)
			.VAlign(VAlign_Top)
			[
				SNew(SButton)
				.Text(FText::FromString("Save Dialogue(s)"))
				.OnClicked(FOnClicked::CreateSP(this, &SQuickStartWindowMenu::OnTestButtonClicked))
			]
		]
	]; // end of slots
}

FReply SQuickStartWindowMenu::OnTestButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello, world! The checkbox is %s."), (bIsTextBoxChecked ? TEXT("checked") : TEXT("unchecked")));
	return FReply::Handled();
}

void SQuickStartWindowMenu::OnTextCheckBoxStateChanged(ECheckBoxState NewState)
{
	bIsTextBoxChecked = NewState == ECheckBoxState::Checked ? true : false;
}

void SQuickStartWindowMenu::OnTextChanged(const FText& NewText, ETextCommit::Type CommitType, int32 DialogueIndex)
{
	if (Dialogues.IsValidIndex(DialogueIndex))
	{
		Dialogues[DialogueIndex] = NewText.ToString();
	}
	else
	{
		Dialogues.Add(NewText.ToString());
	}

	UE_LOG(LogTemp, Warning, TEXT("Dialogue %d saved: %s"), DialogueIndex + 1, *Dialogues[DialogueIndex]);
}

ECheckBoxState SQuickStartWindowMenu::IsTestBoxChecked() const
{
	return bIsTextBoxChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION