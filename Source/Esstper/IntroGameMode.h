// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "IntroGameMode.generated.h"

/**
 * Holds the game mode information for the intro.
 */

class AIntroGameState;

UCLASS()
class ESSTPER_API AIntroGameMode : public AGameMode
{
	GENERATED_BODY()
	

private: 
	// Reference to the current game state.
	AIntroGameState* IntroGameState;

	// Current time since the story line was changed.
	float CurrentTime = 0.f;

	// Total time for the current story line.
	float TotalTime = 0.f;

public:
	// Line displayed in the Story UI.
	UPROPERTY(BlueprintReadOnly, Category = "Intro")
	FString CurrentLine;

private:
	// Gets the next story from the Game state.
	void UpdateStory();

protected:
	// Sets references.
	void BeginPlay() override;

	// Tracks the time for the current line and requests new ones.
	void Tick(float DeltaSeconds) override;
};
