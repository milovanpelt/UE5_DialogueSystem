// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueTriggerBox.h"


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
		UE_LOG(LogTemp, Warning, TEXT("Dialogue Box"));
	}
}