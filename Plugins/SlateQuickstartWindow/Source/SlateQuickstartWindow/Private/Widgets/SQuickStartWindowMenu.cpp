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
			NewCharacterDialogueSection()
		]

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.Padding(0, 20, 20, 0)
		[
			NewCharacterDialogueSection()
		]
	];
}

void SQuickStartWindowMenu::OnTextChanged(const FText& NewText, ETextCommit::Type CommitType, int32 DialogueIndex)
{
	//DialogueManager::GetInstance().SetDialogue(DialogueIndex, NewText);

}

void SQuickStartWindowMenu::OnCharacterDialogueChanged(const FText& NewText, ETextCommit::Type CommitType, const TCHAR* CharacterName, int32 DialogueIndex)
{
	FString NameAsString = FString(CharacterName);
	DialogueManager::GetInstance().SetNamedDialogue(NameAsString, DialogueIndex, NewText);
}

TSharedRef<SVerticalBox> SQuickStartWindowMenu::NewCharacterDialogueSection()
{
	const FString& CharacterName = "";

	// Dialogue Character Name
	return SNew(SVerticalBox)
	+ SVerticalBox::Slot()
	.AutoHeight()
	.VAlign(VAlign_Top)
	[
		SNew(STextBlock)
		.Text(FText::FromString("Character Name: "))
	]
	+ SVerticalBox::Slot()
	.AutoHeight()
	.Padding(0, 0, 0, 0)
	.VAlign(VAlign_Top)
	[
		SNew(SEditableTextBox)
		.OnTextCommitted(this, &SQuickStartWindowMenu::OnCharacterDialogueChanged, *CharacterName, 0)
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
		.OnTextCommitted(this, &SQuickStartWindowMenu::OnCharacterDialogueChanged, *CharacterName, 0)
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
		.OnTextCommitted(this, &SQuickStartWindowMenu::OnCharacterDialogueChanged, *CharacterName, 1)
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
		.OnTextCommitted(this, &SQuickStartWindowMenu::OnCharacterDialogueChanged, *CharacterName, 2)
		.Text(FText::FromString("Enter your dialogue here"))
		.MinDesiredWidth(200)
	];
}



END_SLATE_FUNCTION_BUILD_OPTIMIZATION