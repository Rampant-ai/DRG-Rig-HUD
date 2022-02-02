// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameData.h"
#include "SpaceRigBar.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSD_API ASpaceRigBar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpaceRigBar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintReadOnly) UDrinkableDataAsset* DrinkableSpecial;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
