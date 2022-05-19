// Fill out your copyright notice in the Description page of Project Settings.


#include "playerPawn.h"
#include "HeadMountedDisplayFunctionLibrary.h" 
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "vrMotionController.h"

// Sets default values
AplayerPawn::AplayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	VRCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCamera"));
	VRCamera->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AplayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Floor);

	FAttachmentTransformRules rules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, true);

	LController = GetWorld()->SpawnActor<AvrMotionController>();
	LController->SetOwner(this);
	LController->AttachToComponent(Root, rules);
	LController->hand = EControllerHand::Left;


	RController = GetWorld()->SpawnActor<AvrMotionController>();
	RController->SetOwner(this);
	RController->AttachToComponent(Root, rules);
	RController->hand = EControllerHand::Right;

}

// Called every frame
void AplayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AplayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("TeleportLeft", IE_Pressed, this, &AplayerPawn::TeleportLeft);
	PlayerInputComponent->BindAction("TeleportLeft", IE_Released, this, &AplayerPawn::TeleportLeftRelease);
	PlayerInputComponent->BindAction("TeleportRight", IE_Pressed, this, &AplayerPawn::TeleportRight);
	PlayerInputComponent->BindAction("TeleportRight", IE_Released, this, &AplayerPawn::TeleportRightRelease);
	PlayerInputComponent->BindAction("GrabLeft", IE_Pressed, this, &AplayerPawn::GrabLeft);
	PlayerInputComponent->BindAction("GrabLeft", IE_Released, this, &AplayerPawn::ReleaseLeft);
	PlayerInputComponent->BindAction("GrabRight", IE_Pressed, this, &AplayerPawn::GrabRight);
	PlayerInputComponent->BindAction("GrabRight", IE_Released, this, &AplayerPawn::ReleaseRight);
	 
}


void AplayerPawn::TeleportLeft() {
	LController->TeleportActive = true;

};

void AplayerPawn::TeleportLeftRelease() {
	LController->TeleportActive = false;

};;

void AplayerPawn::TeleportRight() {
	RController->TeleportActive = true;
};;

void AplayerPawn::TeleportRightRelease() {
	RController->TeleportActive = false;

};;

void AplayerPawn::GrabLeft() {
	UE_LOG(LogTemp, Warning, TEXT("Grab"));
	LController->Grab();
};;
void AplayerPawn::ReleaseLeft() {
	UE_LOG(LogTemp, Warning, TEXT("Release"));
	LController->Release();
};;
void AplayerPawn::GrabRight() {
	UE_LOG(LogTemp, Warning, TEXT("Grab"));
	RController->Grab();
};;
void AplayerPawn::ReleaseRight() {
	UE_LOG(LogTemp, Warning, TEXT("Release"));
	RController->Release();
};; 