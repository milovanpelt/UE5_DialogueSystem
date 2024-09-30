// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/SQuickStartWindowMenu.h"
#include "SlateOptMacros.h"
#include <SlateQuickstartWindow/Public/Widgets/DialogueManager.h>

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SQuickStartWindowMenu::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SHorizontalBox)
		+SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(0, 20, 20, 0)
		[
			NewCharacterDialogueSection(TEXT("CharacterA"))
		]

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(0, 20, 20, 0)
		[
			NewCharacterDialogueSection(TEXT("CharacterB"))
		]
	]; // end of slots
}

void SQuickStartWindowMenu::OnTextChanged(const FText& NewText, ETextCommit::Type CommitType, int32 DialogueIndex)
{
	//DialogueManager::GetInstance().SetDialogue(DialogueIndex, NewText);

}

TSharedRef<SVerticalBox> SQuickStartWindowMenu::NewCharacterDialogueSection(const FString& CharacterName)
{
	// Dialogue Character Name
	return SNew(SVerticalBox)
	+ SVerticalBox::Slot()
	.AutoHeight()
	.VAlign(VAlign_Top)
	[
		SNew(STextBlock)
		.Text(FText::FromString("Character Name: " + CharacterName))
	]
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0, 0, 0, 0)
	.VAlign(VAlign_Top)
	[
		SNew(SEditableTextBox)
		.OnTextCommitted(this, &SQuickStartWindowMenu::OnTextChanged, 0)
		.Text(FText::FromString("Enter character name here"))
		.MinDesiredWidth(200)
	]

	// Dialogue box 1
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0, 10, 0, 0)
	.VAlign(VAlign_Top)
	[
		SNew(STextBlock)
		.Text(FText::FromString("Dialogue 1: "))
	]
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0, 0, 0, 0)
	.VAlign(VAlign_Top)
	[
		SNew(SEditableTextBox)
		.OnTextCommitted(this, &SQuickStartWindowMenu::OnTextChanged, 1)
		.Text(FText::FromString("Enter your dialogue here"))
		.MinDesiredWidth(200)
	]

	// Dialogue box 2
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0, 10, 0, 0)
	.VAlign(VAlign_Top)
	[
		SNew(STextBlock)
		.Text(FText::FromString("Dialogue 2: "))
	]
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0, 0, 0, 0)
	.VAlign(VAlign_Top)
	[
		SNew(SEditableTextBox)
		.OnTextCommitted(this, &SQuickStartWindowMenu::OnTextChanged, 2)
		.Text(FText::FromString("Enter your dialogue here"))
		.MinDesiredWidth(200)
	]

	// Dialogue box 3
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0, 10, 0, 0)
	.VAlign(VAlign_Top)
	[
		SNew(STextBlock)
		.Text(FText::FromString("Dialogue 3: "))
	]
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0, 0, 0, 0)
	.VAlign(VAlign_Top)
	[
		SNew(SEditableTextBox)
		.OnTextCommitted(this, &SQuickStartWindowMenu::OnTextChanged, 2)
		.Text(FText::FromString("Enter your dialogue here"))
		.MinDesiredWidth(200)
	];
}

void SQuickStartWindowMenu::OnCharacterDialogueChanged(const FString& CharacterName, const FText& NewText, ETextCommit::Type CommitType)
{
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION