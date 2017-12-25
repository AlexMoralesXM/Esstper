// pasotee 2017

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SenseSphere.generated.h"

class UParticleSystemComponent;

UCLASS()
class ESSTPER_API ASenseSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASenseSphere();

protected:
	// Particle System component for trails.
	UPROPERTY(EditAnywhere, Category = "Spell")
	UParticleSystemComponent* SphereParticle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
