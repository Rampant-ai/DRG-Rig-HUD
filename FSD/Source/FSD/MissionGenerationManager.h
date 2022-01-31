// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneratedMission.h"
#include "MissionGenerationManager.generated.h"

UCLASS() //ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UMissionGenerationManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	//UPROPERTY(BlueprintReadOnly) TMap<int32_t, FGeneratedMissionGroup> AllMissionGroups;
	//UPROPERTY(BlueprintReadOnly) bool ResetSelectedMission;

	UFUNCTION(BlueprintCallable) TArray<UGeneratedMission*> GetMissions(int32 Seed) { return *new TArray<UGeneratedMission*>(); };
	UFUNCTION(BlueprintCallable) UGeneratedMission* GetMissionFromSeeds(int32 GlobalSeed, int32 MissionSeed) { return NULL; };
	UFUNCTION(BlueprintCallable) TArray<UGeneratedMission*> GetAvailableMissions() { return *new TArray<UGeneratedMission*>(); };
};
