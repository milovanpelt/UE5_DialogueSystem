// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class UE5_DIALOGUESYSTEM_API SMainMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuWidget){}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual bool SupportsKeyboardFocus() const override;

	FReply OnPlayClicked() const;
public:
	TWeakObjectPtr<class AMenuHUD> OwningHUD;
};
