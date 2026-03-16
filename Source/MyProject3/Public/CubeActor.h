#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeActor.generated.h"



UCLASS()
class MYPROJECT3_API ACubeActor : public AActor
{

	UPROPERTY(EditAnywhere, Category = "Movement")
	float moveRange = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float rotationRange = 10.0f;

	GENERATED_BODY()
	
public:	
	ACubeActor();
	void Move(FVector dist);
	void Turn(FRotator rotator);
	void TriggerEvent(int &count) const;
	void Log(int32 key, FColor color, FString msg) const;
	FVector GetRandVector(float range) const;
	FRotator GetRandRotator(float range) const;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};


