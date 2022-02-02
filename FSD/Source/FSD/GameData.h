// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GeneratedMission.h"
#include "GameData.generated.h"

// ------------------------------------------------------------------------------------------------

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UDrinkableDataAsset : public UObject //: public USavableDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly) FText DrinkableName;
	UPROPERTY(BlueprintReadOnly) FText DrinkableDescription;
	UPROPERTY(BlueprintReadOnly) int32 DrinkablePrice;
	UPROPERTY(BlueprintReadOnly) TSoftObjectPtr<UTexture2D> DrinkableIcon;

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

	bool IsDailyDealBought(UObject* WorldContextObject) { return true; };
	void GetDailyDeal(FDailyDeal outDeal) {};
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
};
