// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"

#include "../Engine/Classes/Engine/Engine.h"
#include "../Slate/Public/Widgets/SWeakWidget.h"

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine && GEngine->GameViewport) {
		MenuWidget = SNew(SMainMenuWidget);
		MenuWidget->OwningHUD = this;
		GEngine->GameViewport->AddViewportWidgetContent(MenuWidget.ToSharedRef());
	}
}
