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
private:
	TArray<FString> Dialogues;
};
