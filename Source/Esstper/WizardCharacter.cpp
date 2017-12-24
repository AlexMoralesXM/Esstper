// pasotee 2017

#include "WizardCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "LightningBolt.h"

//////////////////// Movement Interrupts ////////////////////

void AWizardCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Sets the input for the base controller.
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Binds the cast function.
	PlayerInputComponent->BindAction("Cast", IE_Pressed, this, &AWizardCharacter::StartShootBolt);

	//Binds the sense function.
	PlayerInputComponent->BindAction("Sense", IE_Pressed, this, &AWizardCharacter::StartCastSense);
}

void AWizardCharacter::MoveForward(float Value)
{
	// Interrupts the spell cast on movement.
	Super::MoveForward(Value);
	
	if (Value != 0.f)
	{
		InterruptCasts();
	}
}

void AWizardCharacter::MoveRight(float Value)
{
	// Interrupts the spell cast on movement.
	Super::MoveRight(Value);

	if (Value != 0.f)
	{
		InterruptCasts();
	}
}

void AWizardCharacter::InterruptCasts()
{
	isShooting = false;
	isSensing = false;
}

//////////////////// Lightning Bolt Casting ////////////////////

void AWizardCharacter::StartShootBolt()
{
	// Stops the character movement.
	GetCharacterMovement()->StopActiveMovement();

	// Starts the casting animation.
	isShooting = true;
}

void AWizardCharacter::CastBolt()
{
	ALightningBolt* boltSpawned = SpawnBolt();
	//TODO: Set the target if any.
	
}

//////////////////// Sensing Casting ////////////////////

void AWizardCharacter::StartCastSense()
{
	// Stops the character movement.
	GetCharacterMovement()->StopActiveMovement();

	// Starts the sensing animation.
	isSensing = true;
}

void AWizardCharacter::CastSenseSphere()
{
	ASenseSphere* sphereSpawned = SpawnSphere();

}
