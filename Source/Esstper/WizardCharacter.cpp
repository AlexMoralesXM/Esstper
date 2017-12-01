// E

#include "WizardCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"





void AWizardCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Cast", IE_Pressed, this, &AWizardCharacter::Cast);
}

void AWizardCharacter::Cast()
{
	GetCharacterMovement()->DisableMovement();
	isCasting = true;
}



