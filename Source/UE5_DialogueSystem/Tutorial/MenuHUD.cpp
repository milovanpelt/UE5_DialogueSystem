// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"

#include "Engine/Engine.h"
#include "Widgets/SWeakWidget.h"

void AMenuHUD::ShowMenu()
{
	if (GEngine && GEngine->GameViewport) {
		MenuWidget = SNew(SMainMenuWidget);
		MenuWidget->OwningHUD = this;
		GEngine->GameViewport->AddViewportWidgetContent(MenuWidget.ToSharedRef());

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AMenuHUD::RemoveMenu()
{
	if (GEngine && GEngine->GameViewport && MenuWidget.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidget.ToSharedRef());

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	ShowMenu();
}