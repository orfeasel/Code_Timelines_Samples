// Fill out your copyright notice in the Description page of Project Settings.

#include "TimelinePluginDemo.h"
#include "FloatCurveActor.h"



void AFloatCurveActor::MoveActor(FVector NewLocation)
{
	//Move actor is going to be called with an interpolated value
	SetActorLocation(NewLocation);
}

void AFloatCurveActor::RotateActor(FRotator NewRotation)
{
	//Will rotate the actor with an interpolated rotation
	SetActorRotation(NewRotation);
}

// Sets default values
AFloatCurveActor::AFloatCurveActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM = CreateDefaultSubobject<UStaticMeshComponent>(FName("SM"));

	//Init Component
	TimelineHandleComp = CreateDefaultSubobject<UTimelineHandleComponent>(FName("TimelineHandleComp"));
}

// Called when the game starts or when spawned
void AFloatCurveActor::BeginPlay()
{
	Super::BeginPlay();

	//Add a curve to the component
	TimelineHandleComp->AddCurve(FloatCurve);

	//Since we're playing a float curve, we're going to interpolate between two values.
	//In this case we're going to move our actor forward by 150 units
	TimelineHandleComp->SetInitialAndTargetValues(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 150);

	//Moreover, we're going to rotate 180 degrees around Y and X axis
	TimelineHandleComp->SetInitialAndTargetValues(GetActorRotation(), GetActorRotation() + FRotator(180.f, 0, 180.f));

	//Function to call in each timeline tick
	TimelineHandleComp->OnFloatCurveVectorTickFunction.AddDynamic(this, &AFloatCurveActor::MoveActor);

	//Function to call for FRotator types
	TimelineHandleComp->OnFloatCurveRotatorTickFunction.AddDynamic(this, &AFloatCurveActor::RotateActor);

	//Play the timeline from start
	TimelineHandleComp->PlayTimelineFromStart();

}

