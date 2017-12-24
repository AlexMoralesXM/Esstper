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

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
		float ProjectileSpeed;

	// Sets the target of the bolt projectile.
	void SetBoltTarget(AActor* NewTarget);

protected:
	// Target of the lightning bolt.
	AActor * CurrentTarget;

	UPROPERTY(EditAnywhere, Category = "Spell")
	UParticleSystemComponent* BoltParticle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
