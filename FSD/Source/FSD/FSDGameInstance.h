// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CampaignManager.h"
#include "FSDGameInstance.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UFSDGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadOnly) UCampaignManager* CampaignManager;

	UFUNCTION(BlueprintCallable) AFSDPlayerController* GetLocalFSDPlayerController() { return NULL; };
};
