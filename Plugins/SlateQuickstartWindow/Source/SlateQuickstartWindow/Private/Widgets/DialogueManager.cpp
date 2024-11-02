// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/DialogueManager.h"

void DialogueManager::SetDialogue(int32 DialogueIndex, const FText& NewText)
{
	bool DoesDialogueExist = Dialogues.IsValidIndex(DialogueIndex);
	const FString Dialogue = NewText.ToString();

	if (DoesDialogueExist)
	{
		Dialogues[DialogueIndex] = Dialogue;
	}
	else
	{
		Dialogues.Add(Dialogue);
	}

	UE_LOG(LogTemp, Warning, TEXT("Dialogue %d saved: %s"), DialogueIndex + 1, *Dialogues[DialogueIndex]);
}

void DialogueManager::SetNamedDialogue(const FString& CharacterName, const int DialogueIndex, const FText& NewText)
{
	bool DoesCharacterNameExist = NamedDialogues.Contains(CharacterName);
	const FString Dialogue = NewText.ToString();

	if (DoesCharacterNameExist)
	{
		TArray<FString>& DialogueArray = NamedDialogues[CharacterName];
		if (DialogueIndex < DialogueArray.Num())
		{
			DialogueArray[DialogueIndex] = Dialogue;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Dialogue Index is out of bounds: %s"), DialogueIndex);
		}
	}
	else
	{
		TArray<FString> NewDialogueArray;

		for (int32 i = 0; i < DialogueIndex; i++)
		{
			NewDialogueArray.Add(FString());
		}

		NewDialogueArray.Add(Dialogue);
		NamedDialogues.Add(CharacterName, NewDialogueArray);
	}

	UE_LOG(LogTemp, Warning, TEXT("Dialogue %d saved for %s: %s"), DialogueIndex + 1, *CharacterName, *Dialogue);
}

const TArray<FString>& DialogueManager::GetAllNamedDialogues(const FString& CharacterName) const
{
	bool IsValidCharacterName = NamedDialogues.Contains(CharacterName);
	if (IsValidCharacterName)
	{
		return NamedDialogues[CharacterName];
	}
	else
	{
		static const TArray<FString> EmptyArray;
		return EmptyArray;
	}
}

FString& DialogueManager::GetDialogue(int32 DialogueIndex)
{
	return Dialogues[DialogueIndex];
}

TArray<FString>& DialogueManager::GetAllDialogues()
{
	return Dialogues;
}