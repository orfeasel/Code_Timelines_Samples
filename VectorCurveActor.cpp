// Fill out your copyright notice in the Description page of Project Settings.

#include "TimelinePluginDemo.h"
#include "VectorCurveActor.h"


void AVectorCurveActor::MoveActor(FVector NewLocation)
{
	//Move relative to the initial location
	SetActorLocation(PivotPoint + NewLocation);
}

// Sets default values
AVectorCurveActor::AVectorCurveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM = CreateDefaultSubobject<UStaticMeshComponent>(FName("SM"));


	TimelineHandleComp = CreateDefaultSubobject<UTimelineHandleComponent>(FName("TimelineHandleComp"));
}

// Called when the game starts or when spawned
void AVectorCurveActor::BeginPlay()
{
	Super::BeginPlay();

	PivotPoint = GetActorLocation();

	//Add a vector curve
	TimelineHandleComp->AddCurve(VectorCurve);

	//Bind the function that we're going to call in each tick
	TimelineHandleComp->OnVectorCurveTickFunction.AddDynamic(this, &AVectorCurveActor::MoveActor);

	//Play from start and loop.
	TimelineHandleComp->PlayTimelineFromStart(true);
}

