// pasotee 2017

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rune.generated.h"

//Forward declaration
class UStaticMeshComponent;
class UTextRenderComponent;

UCLASS()
class ESSTPER_API ARune : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARune();

protected:
	// Rune's Name
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Rune", meta = (AllowPrivateAccess = "true"))
	FString RuneName = "Rune Name";

	// Rune's Mesh
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rune", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* RuneMesh;

	// Rune's Text
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rune", meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* RuneText;

	// Rune's base Material
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune", meta = (AllowPrivateAccess = "true"))
	UMaterialInterface* RuneBaseMaterial;

private:
	// Material Instance used on Rune.
	UMaterialInstanceDynamic* RuneMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Rotates the text towards the player.
	void UpdateTextRotation();

	// Changes the glow of the rune
	void ChangeRuneGlow(float Value);
};
