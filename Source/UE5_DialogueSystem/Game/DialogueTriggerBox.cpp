// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueTriggerBox.h"
#include "../../../Plugins/SlateQuickstartWindow/Source/SlateQuickstartWindow/Public/Widgets/DialogueManager.h"


ADialogueTriggerBox::ADialogueTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &ADialogueTriggerBox::Event);
}

void ADialogueTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}

void ADialogueTriggerBox::Event(AActor* overlappedActor, AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		/*for (int i = 0; i < DialogueManager::GetInstance().GetAllDialogues().Num(); i++)
		{
			FString Dialogue = DialogueManager::GetInstance().GetDialogue(i);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *Dialogue);
		}*/

		const TArray<FString>& Dialogues = DialogueManager::GetInstance().GetAllNamedDialogues("CharacterA");

		// Iterate over the array of dialogue strings and print each one
		for (const FString& Dialogue : Dialogues)
		{
			UE_LOG(LogTemp, Warning, TEXT("Dialogue: %s"), *Dialogue);
		}
	}
}