// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameFramework/PlayerController.h"
#include "SMainMenuWidget.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE5_DIALOGUESYSTEM_API AMenuHUD : public AHUD
{
	GENERATED_BODY()
public:
	void ShowMenu();
	void RemoveMenu();
protected:
	TSharedPtr<class SMainMenuWidget> MenuWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;

protected:
	virtual void BeginPlay() override;
};
