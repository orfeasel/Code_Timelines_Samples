// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TimelineHandleComponent.h"
#include "VectorCurveActor.generated.h"

UCLASS()
class TIMELINEPLUGINDEMO_API AVectorCurveActor : public AActor
{
	GENERATED_BODY()

private:

	//We're going to move our actor starting from this point
	FVector PivotPoint;

	/** Moves the Actor - must be marked as UFUNCTION, otherwise it won't fire */
	UFUNCTION()
	void MoveActor(FVector NewLocation);

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SM;

	UPROPERTY(VisibleAnywhere)
	UTimelineHandleComponent* TimelineHandleComp;

	UPROPERTY(EditAnywhere)
	UCurveVector* VectorCurve;
	
public:	
	// Sets default values for this actor's properties
	AVectorCurveActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
