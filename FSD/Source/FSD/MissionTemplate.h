// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MissionTemplate.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSD_API UMissionTemplate : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly) UTexture2D* MissionIcon;
	UPROPERTY(BlueprintReadOnly) UTexture2D* MissionIconSmall;
	UPROPERTY(BlueprintReadOnly) int32 MissionTypeIndex;
};
