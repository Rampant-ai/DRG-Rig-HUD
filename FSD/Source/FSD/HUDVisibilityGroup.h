// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
//#include "Components/Widget.h"
//#include "Components/SlateWrapperTypes.h"
#include "HUDVisibilityGroup.generated.h"

UENUM(BlueprintType)
enum class EHUDVisibilityMode : uint8
{
	Visible = 0,
	Dynamic = 1,
	Hidden = 2,
	EHUDVisibilityMode_MAX = 3
};

UENUM(BlueprintType)
enum class EHUDVisibilityPresets : uint8
{
	AllVisible = 0,
	Recommended = 1,
	Minimal = 2,
	AllHidden = 3,
	EHUDVisibilityPresets_MAX = 4
};

UENUM(BlueprintType)
enum class EHUDVisibilityGroups : uint8
{
	OnScreenHelp = 0,
	EnemyHealth = 1,
	RadarAndDepth = 2,
	PlayerHealthShield = 3,
	PlayerNameClassIcon = 4,
	PlayerItems = 5,
	PlayerResources = 6,
	WeaponInfo = 7,
	Grenades = 8,
	FlashLight = 9,
	Flares = 10,
	Crosshair = 11,
	Objectives = 12,
	TeamDisplay = 13,
	SentryGunDisplay = 14,
	EHUDVisibilityGroups_MAX = 15
};

USTRUCT(BlueprintType)
struct FHUDVisibilityRegisteredWidget
{
	GENERATED_BODY()

	//TWeakObjectPtr<UWidget> Widget;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSD_API UHUDVisibilityGroup : public UDataAsset
{
	GENERATED_BODY()

public:
	//UPROPERTY(BlueprintReadOnly) FMulticastInlineDelegate OnModeChanged;
	//UPROPERTY(BlueprintReadOnly) FMulticastInlineDelegate OnVisibilityChanged;
	UPROPERTY(BlueprintReadOnly) EHUDVisibilityGroups GroupID;
	UPROPERTY(BlueprintReadOnly) FText Title;
	UPROPERTY(BlueprintReadOnly) bool AllowDynamicMode;
	UPROPERTY(BlueprintReadOnly) bool AllowHiddenMode;
	UPROPERTY(BlueprintReadOnly) bool bDynamicallyVisible;
	//UPROPERTY(BlueprintReadOnly) TArray<FHUDVisibilityRegisteredWidget> RegisteredWidgets;
	UPROPERTY(BlueprintReadOnly) EHUDVisibilityMode RecommendedMode;
	UPROPERTY(BlueprintReadOnly) EHUDVisibilityMode MinimalMode;

	UFUNCTION(BlueprintCallable) void VisibilityDelegate__DelegateSignature(UHUDVisibilityGroup* Group, bool IsVisible) {};
	UFUNCTION(BlueprintCallable) void SetModeFromPreset(EHUDVisibilityPresets Preset) {};
	UFUNCTION(BlueprintCallable) void SetMode(EHUDVisibilityMode InMode) {};
	UFUNCTION(BlueprintCallable) void SetHudGroupDynamicallyVisible(UHUDVisibilityGroup* Group, bool IsVisible) {};
	UFUNCTION(BlueprintCallable) void SetGroupDynamicallyVisible(bool IsVisible) {};

	// looks like UWidget and ESlateVisibility become unresolved external symbols if we tag these as UFUNCTIONs.
	//void RegisterWidgetWithVisibilityGroup(UWidget* Widget, UHUDVisibilityGroup* Group, ESlateVisibility VisibleMode, ESlateVisibility HiddenMode) {};
	//void RegisterMultipleWidgetsWithVisibilityGroup(TArray<UWidget*> Widgets, UHUDVisibilityGroup* Group, ESlateVisibility VisibleMode, ESlateVisibility HiddenMode) {};

	UFUNCTION(BlueprintCallable) void ModeDelegate__DelegateSignature(UHUDVisibilityGroup* Group, EHUDVisibilityMode Mode) {};
	UFUNCTION(BlueprintCallable) bool IsModeAllowed(EHUDVisibilityMode InMode) { return false; };
	UFUNCTION(BlueprintCallable) bool IsInDynamicMode() { return false; };
	UFUNCTION(BlueprintCallable) bool IsHudGroupVisible(UHUDVisibilityGroup* Group) { return false; };
	UFUNCTION(BlueprintCallable) bool IsGroupVisible() { return false; };
	UFUNCTION(BlueprintCallable) EHUDVisibilityMode GetMode() { return EHUDVisibilityMode::Visible; };
	//UFUNCTION(BlueprintCallable) TArray<EHUDVisibilityMode> GetAllowedModes();
};
