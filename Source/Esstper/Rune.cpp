// pasotee 2017

#include "Rune.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ARune::ARune()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up the rune mesh.
	RuneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rune Mesh"));
	SetRootComponent(RuneMesh);
	//RuneMesh->SetupAttachment(RootComponent);

	// Set up the rune mesh.
	RuneText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Rune Name"));
	RuneText->SetupAttachment(RuneMesh);
	RuneText->SetRelativeLocation(FVector(0.f, 0.f, 100.f));
}

// Called when the game starts or when spawned
void ARune::BeginPlay()
{
	Super::BeginPlay();
	
	// Create the material for this instance.
	RuneMaterial = UMaterialInstanceDynamic::Create(RuneBaseMaterial, this);

	// Set the mesh's material to the created one.
	RuneMesh->SetMaterial(0, RuneMaterial);
}

// Called every frame
void ARune::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateTextRotation();
}

//Rotates the text mesh towards the player.
void ARune::UpdateTextRotation()
{
	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector RuneLocation = GetActorLocation();

	FVector Difference = PlayerLocation - RuneLocation;
	Difference = Difference * FVector(1.f, 1.f, 0.f);
	FVector NormalVector = Difference.GetSafeNormal();

	//NormalVector.ToOrientationRotator();
	FRotator TargetRotation = NormalVector.Rotation();
	RuneText->SetWorldRotation(TargetRotation);

}

// Sets the rune glow to the value.
void ARune::ChangeRuneGlow(float Value)
{
	RuneMaterial->SetScalarParameterValue(TEXT("Emission"), Value);
}

