// pasotee 2017

#include "SenseSphere.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
ASenseSphere::ASenseSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereParticle = CreateAbstractDefaultSubobject<UParticleSystemComponent>(TEXT("Sphere Particle"));
	SetRootComponent(SphereParticle);

}

// Called every frame
void ASenseSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

