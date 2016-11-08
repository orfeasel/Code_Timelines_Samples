// Fill out your copyright notice in the Description page of Project Settings.

#include "TimelinePluginDemo.h"
#include "MultipleCurveActor.h"

void AMultipleCurveActor::RotateActor(FRotator NewRotator)
{
	SetActorRotation(NewRotator);
}

void AMultipleCurveActor::ChangeColor(FLinearColor NewColor)
{
	//Dummy code
	UMaterialInstanceDynamic* Material = SM->CreateAndSetMaterialInstanceDynamic(0);

	Material->SetVectorParameterValue(FName("BaseColor"), NewColor);
}

// Sets default values
AMultipleCurveActor::AMultipleCurveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM = CreateDefaultSubobject<UStaticMeshComponent>(FName("SM"));

	TimelineHandleComp = CreateDefaultSubobject<UTimelineHandleComponent>(FName("TimelineHandleComp"));
}

// Called when the game starts or when spawned
void AMultipleCurveActor::BeginPlay()
{
	Super::BeginPlay();

	//Adding a float curve
	TimelineHandleComp->AddCurve(FloatCurve);

	//Adding a linear color curve
	TimelineHandleComp->AddCurve(LinearColorCurve);

	//Set interpolation values for the float curve
	TimelineHandleComp->SetInitialAndTargetValues(GetActorRotation(), GetActorRotation() + FRotator(180, 0, 180));

	//Binding the function that will fire in each tick of the float curve
	TimelineHandleComp->OnFloatCurveRotatorTickFunction.AddDynamic(this, &AMultipleCurveActor::RotateActor);

	//Binding the function that will fire in each tick of the linearcolor curve
	TimelineHandleComp->OnLinearColorCurveTickFunction.AddDynamic(this, &AMultipleCurveActor::ChangeColor);

	//Play from start and loop
	TimelineHandleComp->PlayTimelineFromStart(true);
}

