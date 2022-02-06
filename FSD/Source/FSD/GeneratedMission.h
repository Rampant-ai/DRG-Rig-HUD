// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MissionTemplate.h"
#include "GeneratedMission.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSD_API UResourceData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly) FText Title;
	UPROPERTY(BlueprintReadOnly) FText TitlePlural;
	UPROPERTY(BlueprintReadOnly) FText Description;
	UPROPERTY(BlueprintReadOnly) FColor Color;
	UPROPERTY(BlueprintReadOnly) UTexture2D* Icon;

	UFUNCTION(BlueprintCallable) float GetOwnedAmount(UObject* WorldContextObject) { return 0; };
};


USTRUCT(BlueprintType)
struct FResourceSpawner
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadOnly) UResourceData* Resource;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSD_API UBiome : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly) FText BiomeName;
	UPROPERTY(BlueprintReadOnly) FText BiomeShortName;
	UPROPERTY(BlueprintReadOnly) FText BiomeDescription;
	UPROPERTY(BlueprintReadOnly) FColor BiomeColor;
	UPROPERTY(BlueprintReadOnly) TSoftObjectPtr<UTexture2D> BiomePicture;
	UPROPERTY(BlueprintReadOnly) TSoftObjectPtr<UTexture2D> BiomeIcon;
	UPROPERTY(BlueprintReadOnly) TSoftObjectPtr<UTexture2D> BiomeLargeImage;
	//UPROPERTY(BlueprintReadOnly) TSoftObjectPtr<UTexture2D> BiomeWorldMap;
	//UPROPERTY(BlueprintReadOnly) TSoftObjectPtr<UTexture2D> BiomeMissionBar;
	//UPROPERTY(BlueprintReadOnly) TSoftClassPtr<UObject> BiomeMapWidget;
	UPROPERTY(BlueprintReadOnly) TArray<FResourceSpawner> Resources;
	
	UFUNCTION(BlueprintCallable) UTexture2D* GetBiomeWorldMap() { return NULL; };
	UFUNCTION(BlueprintCallable) UTexture2D* GetBiomePicture() { return NULL; };
	//UFUNCTION(BlueprintCallable) UUserWidget* GetBiomeMapWidget();
	//UFUNCTION(BlueprintCallable) TArray<FSoftObjectPath> GetBiomeMapAssetList();
	UFUNCTION(BlueprintCallable) UTexture2D* GetBiomeLargeImage() { return NULL; };
	UFUNCTION(BlueprintCallable) UTexture2D* GetBiomeIcon() { return NULL; };
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UMissionComplexity : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly) FText Title;
	UPROPERTY(BlueprintReadOnly) int32 NumberOfDots;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UMissionDuration : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly) FText Title;
	UPROPERTY(BlueprintReadOnly) int32 NumberOfDots;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UMissionWarning : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly) TSoftClassPtr<UObject> MissionBP;
	UPROPERTY(BlueprintReadOnly) TArray<TSoftClassPtr<UObject>> BannedObjectives;
	UPROPERTY(BlueprintReadOnly) TArray<UMissionMutator*> BannedMutators;
	UPROPERTY(BlueprintReadOnly) TArray<UMutator*> Mutators;
	UPROPERTY(BlueprintReadOnly) FText Title;
	UPROPERTY(BlueprintReadOnly) FText RichDescription;
	UPROPERTY(BlueprintReadOnly) UTexture2D* Icon;
	UPROPERTY(BlueprintReadOnly) float HazardBonus;
	//UPROPERTY(BlueprintReadOnly) UMissionStat* MissionCompletedStat;
};



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UMissionMutator : public UDataAsset
{
	GENERATED_BODY()
public:
	//URunningMissionBP* MissionBP;
	//TArray<TSoftClassPtr<UObject>> BannedObjectives;
	UPROPERTY(BlueprintReadOnly) TArray<UMutator*> Mutators;
	UPROPERTY(BlueprintReadOnly) FText Title;
	UPROPERTY(BlueprintReadOnly) FText RichDescription;
	UPROPERTY(BlueprintReadOnly) UTexture2D* Icon;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UMutator : public UDataAsset
{
	GENERATED_BODY()
public:
};


USTRUCT(BlueprintType)
struct FGMMutatorItem
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadOnly) TArray<UMutator*> Mutators;
};


USTRUCT(BlueprintType)
struct FObjectiveMissionIcon
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadOnly) UTexture2D* Texture;
	UPROPERTY(BlueprintReadOnly) FLinearColor Tint;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSD_API UGeneratedMission : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly) UBiome* Biome;
	UPROPERTY(BlueprintReadOnly) int32 Seed;
	UPROPERTY(BlueprintReadOnly) int32 GlobalSeed;
	UPROPERTY(BlueprintReadOnly) UMissionTemplate* Template;
	UPROPERTY(BlueprintReadOnly) FText MissionName;
	
	//UPROPERTY(BlueprintReadOnly) UObjective* PrimaryObjective;	// has a few icon choices
	//UPROPERTY(BlueprintReadOnly) UObjective* SecondaryObjective;	// ditto
	
	UPROPERTY(BlueprintReadOnly) TMap<UMutator*, FGMMutatorItem> Mutators;
	UPROPERTY(BlueprintReadOnly) TArray<UMissionWarning*> MissionWarnings;
	UPROPERTY(BlueprintReadOnly) UMissionMutator* MissionMutator;

	UPROPERTY(BlueprintReadOnly) UMissionComplexity* ComplexityLimit;
	UPROPERTY(BlueprintReadOnly) UMissionDuration* DurationLimit;

	/*
	//UPROPERTY(BlueprintReadOnly) UMissionDNA* MissionDNA;
	//UPROPERTY(BlueprintReadOnly) enum class EMissionStructure MissionStructure;	// single, DD, EDD
	//UPROPERTY(BlueprintReadOnly) TSoftObjectPtr<ULevelSequence> LoaderLevelSequence;
	*/

	UFUNCTION(BlueprintCallable) FObjectiveMissionIcon GetSecondaryObjectiveIcon() { return FObjectiveMissionIcon(); };
	UFUNCTION(BlueprintCallable) TArray<UMutator*> GetMutators(UMutator* mutatorClass) { return TArray<UMutator*>(); };
	
	/*
	//UFUNCTION(BlueprintCallable) void Recieve_SetupPLS(AProceduralSetup* pls);
	//UFUNCTION(BlueprintCallable) bool IsSingleMission();
	//UFUNCTION(BlueprintCallable) bool IsLocked(AFSDPlayerController* Player);
	//UFUNCTION(BlueprintCallable) bool IsDeepDive();
	//UFUNCTION(BlueprintCallable) AProceduralSetup* GetPLS();
	//UFUNCTION(BlueprintCallable) float GetMissionScale();
	//UFUNCTION(BlueprintCallable) UMissionDNA* GetMissionDNA();
	//UFUNCTION(BlueprintCallable) AProceduralSetup* CreatePLS(int32_t Seed);
	//UFUNCTION(BlueprintCallable) bool AreMissionsEqual(UGeneratedMission* Other);
	*/
};
