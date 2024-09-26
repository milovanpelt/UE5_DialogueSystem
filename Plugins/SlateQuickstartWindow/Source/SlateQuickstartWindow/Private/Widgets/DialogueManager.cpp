// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/DialogueManager.h"

void DialogueManager::SetDialogue(int32 DialogueIndex, const FText& NewText)
{
	if (Dialogues.IsValidIndex(DialogueIndex))
	{
		Dialogues[DialogueIndex] = NewText.ToString();
	}
	else
	{
		Dialogues.Add(NewText.ToString());
	}

	UE_LOG(LogTemp, Warning, TEXT("Dialogue %d saved: %s"), DialogueIndex, *Dialogues[DialogueIndex]);
}

FString& DialogueManager::GetDialogue(int32 DialogueIndex)
{
	return Dialogues[DialogueIndex];
}

TArray<FString>& DialogueManager::GetAllDialogues()
{
	return Dialogues;
}