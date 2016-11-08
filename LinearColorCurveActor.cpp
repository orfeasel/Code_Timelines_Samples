// Fill out your copyright notice in the Description page of Project Settings.

#include "TimelinePluginDemo.h"
#include "LinearColorCurveActor.h"



void ALinearColorCurveActor::ChangeColor(FLinearColor NewColor)
{
	//Dummy code
	UMaterialInstanceDynamic* Material = SM->CreateAndSetMaterialInstanceDynamic(0);

	Material->SetVectorParameterValue(FName("BaseColor"), NewColor);
}

// Sets default values
ALinearColorCurveActor::ALinearColorCurveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM = CreateDefaultSubobject<UStaticMeshComponent>(FName("SM"));

	TimelineHandleComp = CreateDefaultSubobject<UTimelineHandleComponent>(FName("TimelineHandleComp"));
}

// Called when the game starts or when spawned
void ALinearColorCurveActor::BeginPlay()
{
	Super::BeginPlay();

	//Add a curve to play
	TimelineHandleComp->AddCurve(LinearColorCurve);

	//Bind a function to call in each timeline tick
	TimelineHandleComp->OnLinearColorCurveTickFunction.AddDynamic(this, &ALinearColorCurveActor::ChangeColor);

	//Play from start and loop
	TimelineHandleComp->PlayTimelineFromStart(true);
}

