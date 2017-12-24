// pasotee 2017

#include "LightningBolt.h"  
#include "Particles/ParticleSystemComponent.h"


ALightningBolt::ALightningBolt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Ads the particle system component.
	BoltParticle = CreateAbstractDefaultSubobject<UParticleSystemComponent>(TEXT("Bolt Particle"));
	SetRootComponent(BoltParticle);
}

void ALightningBolt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentTarget == nullptr)
	{
		
	}
	else
	{
		
	}

	FVector CurrentLocation = GetActorLocation();
	FVector TargetLocation = CurrentLocation + GetActorForwardVector() * ProjectileSpeed * DeltaTime;

	SetActorLocation(TargetLocation);

}

void ALightningBolt::SetBoltTarget(AActor* NewTarget)
{
	// Sets the current target to the new one.
	CurrentTarget = NewTarget;
}
