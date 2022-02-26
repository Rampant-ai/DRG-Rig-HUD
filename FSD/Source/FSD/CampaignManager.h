// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GeneratedMission.h"
#include "CampaignManager.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSD_API UCampaignManager : public UObject
{
	GENERATED_BODY()

public:
	//FMulticastInlineDelegate OnCampaignChanged;

	UFUNCTION(BlueprintCallable) bool IsCampaignMission(UObject* WorldContextObject, UGeneratedMission* mission) { return true; };
};
