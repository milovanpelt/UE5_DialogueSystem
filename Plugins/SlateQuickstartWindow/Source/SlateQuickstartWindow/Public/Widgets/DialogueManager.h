// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SLATEQUICKSTARTWINDOW_API DialogueManager
{
public:
	static DialogueManager& GetInstance()
	{
		static DialogueManager Instance;
		return Instance;
	}

	void SetDialogue(int32 DialogueIndex, const FText& NewText);
	FString& GetDialogue(int32 DialogueIndex);
	TArray<FString>& GetAllDialogues();

	void SetNamedDialogue(const FString& CharacterName, const int DialogueIndex, const FText& NewText);
	const TArray<FString>& GetAllNamedDialogues(const FString& CharacterName) const;
private:
	TArray<FString> Dialogues;
	TMap<FString, TArray<FString>> NamedDialogues;
};
