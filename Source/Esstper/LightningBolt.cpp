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

	FVector CurrentLocation = GetActorLocation();
	FVector ForwardDirection;

	if (CurrentTarget == nullptr)
	{
		ForwardDirection = GetActorForwardVector();
	}
	else
	{
		//TODO: Test if this is the actual forward direction.
		ForwardDirection = CurrentTarget->GetActorLocation() - CurrentLocation;
	}

	FVector TargetLocation = CurrentLocation + ForwardDirection * ProjectileSpeed * DeltaTime;

	SetActorLocation(TargetLocation);

}

void ALightningBolt::SetBoltTarget(AActor* NewTarget)
{
	// Sets the current target to the new one.
	CurrentTarget = NewTarget;
}
