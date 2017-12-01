// E

#include "WizardCharacter.h"




void AWizardCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Cast", IE_Pressed, this, &AWizardCharacter::Cast);
}

void AWizardCharacter::Cast()
{
	isCasting = true;
}



