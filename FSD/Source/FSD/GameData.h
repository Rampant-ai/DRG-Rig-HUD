// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GeneratedMission.h"
#include "HUDVisibilityGroup.h"
#include "GameData.generated.h"

// ------------------------------------------------------------------------------------------------

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UTemporaryBuff : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly) FText Description;
	UPROPERTY(BlueprintReadOnly) TSoftObjectPtr<UTexture2D> Icon;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UDrinkableDataAsset : public UObject //: public USavableDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly) FText DrinkableName;
	UPROPERTY(BlueprintReadOnly) FText DrinkableDescription;
	UPROPERTY(BlueprintReadOnly) int32 DrinkablePrice;
	UPROPERTY(BlueprintReadOnly) TSoftObjectPtr<UTexture2D> DrinkableIcon;
	UPROPERTY(BlueprintReadOnly) UTemporaryBuff* buff;

	UFUNCTION(BlueprintCallable) UTexture2D* GetDrinkableIcon() { return NULL; };
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UDrinkSettings : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly) TArray<UDrinkableDataAsset*> Drinkables;

	UFUNCTION(BlueprintCallable) UDrinkableDataAsset* GetBarDailySpecial(UObject* WorldContext) { return NULL; };
};

// ------------------------------------------------------------------------------------------------

UENUM()
enum class EDealType : uint8
{
	Buy = 0,
	Sell = 1,
};

USTRUCT(BlueprintType)
struct FDailyDeal
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadOnly) UResourceData* Resource;
	UPROPERTY(BlueprintReadOnly) EDealType DealType;
};


USTRUCT(BlueprintType)
struct FDailyDealSetup
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadOnly) UResourceData* Resource;
	UPROPERTY(BlueprintReadOnly) EDealType DealType;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UDailyDealSettings : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly) TArray<FDailyDealSetup> DailyDeals;

	UFUNCTION(BlueprintCallable) bool IsDailyDealBought(UObject* WorldContextObject) { return true; };
	UFUNCTION(BlueprintCallable) void GetDailyDeal(FDailyDeal outDeal) {};
};

// ------------------------------------------------------------------------------------------------

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSD_API UGameData : public UObject
{
	GENERATED_BODY()
public:
	// Abyss Bar Settings - Beer List
	UPROPERTY(BlueprintReadOnly) UDrinkSettings* DrinkSettings;

	// Mineral Trade Terminal's "Daily Deal"
	UPROPERTY(BlueprintReadOnly) UDailyDealSettings* DailyDealSettings;

	// Visibility groups are groups of widgets for display in the HUD
	UFUNCTION(BlueprintCallable) TArray<UHUDVisibilityGroup*> GetAllVisibilityGroups() { return *new TArray<UHUDVisibilityGroup*>(); };
};
