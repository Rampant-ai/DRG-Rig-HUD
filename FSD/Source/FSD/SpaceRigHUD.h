// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSDHUD.h"
#include "SpaceRigHUD.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FSD_API ASpaceRigHUD : public AFSDHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly) TArray<UObject*> NotificationQueue;
	UPROPERTY(BlueprintReadOnly) bool bNotificationQueueActive;

	UFUNCTION(BlueprintCallable) void SetNotificationQueueActive(bool Inactive) {};
	UFUNCTION(BlueprintCallable) void ReceiveNotificationQueueActivated() {};
	UFUNCTION(BlueprintCallable) void ReceiveNotificationAdded(UObject* InNotification) {};
	//UFUNCTION(BlueprintCallable) UWindowWidget* QueueWindowClass(TSoftClassPtr<UObject> InWindowType) { return NULL; };
	//UFUNCTION(BlueprintCallable) void QueueWindow(UWindowWidget* InWindow) {};
	UFUNCTION(BlueprintCallable) void QueueNotificationObject(UObject* InObject) {};
	//UFUNCTION(BlueprintCallable) void QueueMissionShout(TSoftObjectPtr<UDialogDataAsset> InShout) {};
	UFUNCTION(BlueprintCallable) bool IsNotificationQueueEmpty() { return false; };
	UFUNCTION(BlueprintCallable) UObject* DequeueNotificationObject() { return NULL; };
};
