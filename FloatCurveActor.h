// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TimelineHandleComponent.h"
#include "FloatCurveActor.generated.h"

UCLASS()
class TIMELINEPLUGINDEMO_API AFloatCurveActor : public AActor
{
	GENERATED_BODY()

private:

	/** Moves the Actor - must be marked as UFUNCTION, otherwise it won't fire */
	UFUNCTION()
	void MoveActor(FVector NewLocation);

	/** Rotates the Actor - must be marked as UFUNCTION, otherwise it won't fire */
	UFUNCTION()
	void RotateActor(FRotator NewRotation);


protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SM;

	/** The component that comes with the plugin */
	UPROPERTY(VisibleAnywhere)
	UTimelineHandleComponent* TimelineHandleComp;

	/** The curve that we're going to play*/
	UPROPERTY(EditAnywhere)
	UCurveFloat* FloatCurve;
	
public:	
	// Sets default values for this actor's properties
	AFloatCurveActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
};
