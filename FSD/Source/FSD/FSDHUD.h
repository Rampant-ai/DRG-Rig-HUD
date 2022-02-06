// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FSDHUD.generated.h"


UENUM()
enum class EHUDVisibilityReason : uint8
{
	Invalid = 0,
	UserChoice = 1,
	StandDown = 2,
	MenuActive = 4,
	Photography = 8,
	EHUDVisibilityReason_MAX = 9
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSD_API AFSDHUD : public AHUD
{
	GENERATED_BODY()

public:
	//UPROPERTY(BlueprintReadOnly) FMulticastInlineDelegate SetObjectivesVisible;
	//UPROPERTY(BlueprintReadOnly) FMulticastInlineDelegate OnHUDVisibilityChanged;
	//UPROPERTY(BlueprintReadOnly) char IsVisibleFlags;

	UFUNCTION(BlueprintCallable) bool ToggleHUDVisibility(EHUDVisibilityReason reason) { return false; };
	UFUNCTION(BlueprintCallable) void ShowObjectives(bool InVisibility) {};
	UFUNCTION(BlueprintCallable) void SetObjectivesVisible__DelegateSignature(bool InVisible, bool animate) {};
	UFUNCTION(BlueprintCallable) void SetHUDVisible(bool IsVisible, EHUDVisibilityReason reason) {};
	//UFUNCTION(BlueprintCallable) void PlayerSpawned(APlayerCharacter* Player) {};
	UFUNCTION(BlueprintCallable) void OnVisibilityChanged() {};
	UFUNCTION(BlueprintCallable) bool IsHUDVisibleFlagSet(EHUDVisibilityReason reason) { return false; };
	UFUNCTION(BlueprintCallable) void HudVisibilityChanged__DelegateSignature(bool InHudVisible) {};
	UFUNCTION(BlueprintCallable) bool GetHUDVisible() { return false; };
	UFUNCTION(BlueprintCallable) AFSDHUD* GetFSDHUD(APlayerController* InPlayerController) { return NULL; };
	//UFUNCTION(BlueprintCallable) void CameraDroneSpawned(APlayerCameraDrone* Drone) {};
};
