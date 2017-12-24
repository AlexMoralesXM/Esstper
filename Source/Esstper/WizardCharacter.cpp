// pasotee 2017

#include "WizardCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void AWizardCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Sets the input for the base controller.
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Binds the cast function.
	PlayerInputComponent->BindAction("Cast", IE_Pressed, this, &AWizardCharacter::Cast);

	//Binds the sense function.
	PlayerInputComponent->BindAction("Sense", IE_Pressed, this, &AWizardCharacter::Sense);
}

void AWizardCharacter::Cast()
{
	// Stops the character movement.
	GetCharacterMovement()->StopActiveMovement();

	// Starts the casting animation.
	isCasting = true;
}

void AWizardCharacter::Sense()
{
	// Stops the character movement.
	GetCharacterMovement()->StopActiveMovement();

	// Starts the sensing animation.
	isSensing = true;
}

void AWizardCharacter::MoveForward(float Value)
{
	// Interrupts the spell cast on movement.
	Super::MoveForward(Value);
	
	if (Value != 0.f)
	{
		InterruptAnimations();
	}
}

void AWizardCharacter::MoveRight(float Value)
{
	// Interrupts the spell cast on movement.
	Super::MoveRight(Value);

	if (Value != 0.f)
	{
		InterruptAnimations();
	}
}

void AWizardCharacter::InterruptAnimations()
{
	isCasting = false;
	isSensing = false;
}

void AWizardCharacter::SpawnBolt()
{

}

