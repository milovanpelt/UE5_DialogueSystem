// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerBox.h"
#include "DialogueTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class UE5_DIALOGUESYSTEM_API ADialogueTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay();
public:
	ADialogueTriggerBox();

	UFUNCTION()
		void Event(class AActor* overlappedActor, class AActor* otherActor);
};