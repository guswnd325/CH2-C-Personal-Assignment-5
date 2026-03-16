#include "CubeActor.h"

ACubeActor::ACubeActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACubeActor::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0, 50, 0)); 

	double totalDistance = 0;
	int eventCount = 0;

	for (int i = 1; i <= 10; i++)
	{
		FVector startVector;

		startVector = GetActorLocation();

		int key = 3 * i;

		FVector randVector = GetRandVector(moveRange);
		FRotator randRotator = GetRandRotator(rotationRange);

		Log(key,    FColor::Magenta, FString::Printf(TEXT("== Process %d =="), i));
		Log(key -1, FColor::Cyan,    randVector.ToString());
		Log(key -2, FColor::Green,   randRotator.ToString());

		Move(randVector);
		Turn(randRotator);

		totalDistance += FVector::Dist(startVector, GetActorLocation());

		if (FMath::RandBool())
		{
			TriggerEvent(eventCount);
		}
	}

	Log(-1, FColor::Cyan, FString::Printf(TEXT("Total Distance : %lf"), totalDistance));
	Log(-1, FColor::Cyan, FString::Printf(TEXT("Event Trigger Count : %d"), eventCount));
}

void ACubeActor::Log(int32 key, FColor color, FString msg) const
{
	GEngine->AddOnScreenDebugMessage(key, 5, color, msg);
}


FVector ACubeActor::GetRandVector(float range) const
{
	return FVector(
		FMath::RandRange(-range, range),
		FMath::RandRange(-range, range),
		FMath::RandRange(-range, range)
	);
}

FRotator ACubeActor::GetRandRotator(float range) const
{
	return FRotator(
		FMath::RandRange(-range, range),
		FMath::RandRange(-range, range),
		FMath::RandRange(-range, range)
	);
}

void ACubeActor::TriggerEvent(int &count) const
{
	count+=1;
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, TEXT("Event Trigger Call"));
}

void ACubeActor::Move(FVector dist)
{
	AddActorLocalOffset(dist);
}

void ACubeActor::Turn(FRotator rotator)
{
	AddActorLocalRotation(rotator);
}


void ACubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

