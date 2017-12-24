// pasotee 2017

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightningBolt.generated.h"

class UParticleSystemComponent;

UCLASS()
class ESSTPER_API ALightningBolt : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties.
	ALightningBolt();

	// Travel speed of the projectile.
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float ProjectileSpeed;

protected:
	// Target of the lightning bolt.
	AActor * CurrentTarget;

	// Particle System component for trails.
	UPROPERTY(EditAnywhere, Category = "Spell")
	UParticleSystemComponent* BoltParticle;

public:	
	// Updates the actor's location.
	virtual void Tick(float DeltaTime) override;

	// Sets the target of the bolt projectile.
	void SetBoltTarget(AActor* NewTarget);
	
};
