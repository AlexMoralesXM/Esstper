// pasotee 2017

#include "WizardCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void AWizardCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Sets the input for the base controller.
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Binds the cast function.
	PlayerInputComponent->BindAction("Cast", IE_Pressed, this, &AWizardCharacter::Cast);
}

void AWizardCharacter::Cast()
{
	// Stops the character movement.
	GetCharacterMovement()->StopActiveMovement();

	// Starts the casting animation.
	isCasting = true;
}

void AWizardCharacter::MoveForward(float Value)
{
	// Interrupts the spell cast on movement.
	Super::MoveForward(Value);
	
	if(Value != 0.f)
		isCasting = false;
}

void AWizardCharacter::MoveRight(float Value)
{
	// Interrupts the spell cast on movement.
	Super::MoveRight(Value);

	if (Value != 0.f)
		isCasting = false;
}


