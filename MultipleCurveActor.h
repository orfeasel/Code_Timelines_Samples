// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TimelineHandleComponent.h"
#include "MultipleCurveActor.generated.h"

UCLASS()
class TIMELINEPLUGINDEMO_API AMultipleCurveActor : public AActor
{
	GENERATED_BODY()

private:

	/** Rotates the actor - must me marked as UFUNCTION otherwise it won't fire */
	UFUNCTION()
	void RotateActor(FRotator NewRotator);

	/** Changes the color of the SM - must me marked as UFUNCTION otherwise it won't fire */
	UFUNCTION()
	void ChangeColor(FLinearColor NewColor);

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SM;

	UPROPERTY(VisibleAnywhere)
	UTimelineHandleComponent* TimelineHandleComp;

	UPROPERTY(EditAnywhere)
	UCurveLinearColor* LinearColorCurve;

	UPROPERTY(EditAnywhere)
	UCurveFloat* FloatCurve;
	
public:	
	// Sets default values for this actor's properties
	AMultipleCurveActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
