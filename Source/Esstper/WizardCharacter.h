// pasotee 2017

#pragma once

#include "CoreMinimal.h"
#include "EsstperCharacter.h"
#include "WizardCharacter.generated.h"

/**
 * Specific controller for the wizard.
 */

class ALightningBolt;

UCLASS()
class ESSTPER_API AWizardCharacter : public AEsstperCharacter
{
	GENERATED_BODY()

//////////////////// Movement Interrupts ////////////////////

protected:
	// Setting the input's for the player.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Forward movement for spell casting interruptions
	void MoveForward(float Value) override;

	// Lateral movement for spell casting interruptions
	void MoveRight(float Value) override;

	// TODO: Stop casting when jumping.

	// Interrupt all animations.
	UFUNCTION(BlueprintCallable, Category = "Casting")
		void InterruptCasts();

//////////////////// Lightning Bolt Casting ////////////////////

public:
	// Is the player now shooting?
	UPROPERTY(BlueprintReadOnly, Category = "ShootSpell")
	bool isShooting;

protected:
	// Starts the casting for the player.
	void StartShootBolt();

	// Casts the bolt.
	UFUNCTION(BlueprintCallable, Category = "AttackSpell")
	void CastBolt();

	// Spawns the lightning bolt.
	UFUNCTION(BlueprintImplementableEvent, Category = "AttackSpell")
	ALightningBolt* SpawnBolt();

//////////////////// Sensing Casting ////////////////////

public:
	// Is the player now sensing?
	UPROPERTY(BlueprintReadOnly, Category = "SenseSpell")
	bool isSensing;

protected:
	// Starts the sensing for the player.
	void StartCastSense();





};
