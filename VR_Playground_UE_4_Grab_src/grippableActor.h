// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "grippableActor.generated.h"

UCLASS()
class CPP_VR_API AgrippableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AgrippableActor();

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* StaticMesh;
	 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
