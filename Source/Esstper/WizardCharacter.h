// pasotee 2017

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
	// Setting the input's for the player.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Starts the casting for the player.
	void Cast();

	// Starts the sensing for the player.
	void Sense();

public:
	// Is the player now casting?
	UPROPERTY(BlueprintReadOnly, Category = "Casting")
	bool isCasting;

	// Is the player now sensing?
	UPROPERTY(BlueprintReadOnly, Category = "Casting")
	bool isSensing;

protected:
	// Forward movement for spell casting interruptions
	void MoveForward(float Value) override;

	// Lateral movement for spell casting interruptions
	void MoveRight(float Value) override;
	
	// TODO: Stop casting when jumping.

protected:
	// Interrupt all animations.
	UFUNCTION(BlueprintCallable, Category = "Casting")
	void InterruptAnimations();
};
