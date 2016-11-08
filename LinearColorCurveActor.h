// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TimelineHandleComponent.h"
#include "LinearColorCurveActor.generated.h"

UCLASS()
class TIMELINEPLUGINDEMO_API ALinearColorCurveActor : public AActor
{
	GENERATED_BODY()

private:

	/** Changes the color of the SM - must be marked as UFUNCTION otherwise it won't fire */
	UFUNCTION()
	void ChangeColor(FLinearColor NewColor);

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SM;

	UPROPERTY(VisibleAnywhere)
	UTimelineHandleComponent* TimelineHandleComp;


	UPROPERTY(EditAnywhere)
	UCurveLinearColor* LinearColorCurve;
	
public:	
	// Sets default values for this actor's properties
	ALinearColorCurveActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
