// E

#pragma once

#include "CoreMinimal.h"
#include "EsstperCharacter.h"
#include "WizardCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ESSTPER_API AWizardCharacter : public AEsstperCharacter
{
	GENERATED_BODY()
	
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Cast();

public:
	UPROPERTY(BlueprintReadOnly, Category = "Pawn|Character")
	bool isCasting;
	
	
};
