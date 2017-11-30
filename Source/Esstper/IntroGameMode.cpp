// Fill out your copyright notice in the Description page of Project Settings.

#include "IntroGameMode.h"
#include "IntroGameState.h"

void AIntroGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Get the current Game state from this world.
	IntroGameState = Cast<AIntroGameState>(GetWorld()->GetGameState());

	// Ensures the game state was found.
	if (IntroGameState == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Intro Game Mode has wrong game state set."));
	}

}

void AIntroGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Updates the current line's time.
	CurrentTime += DeltaSeconds;

	// Demands a new line when this is finished.
	if (CurrentTime >= TotalTime)
	{
		UpdateStory();
	}
}

void AIntroGameMode::UpdateStory()
{
	// Checks for a game state.
	if (IntroGameState == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Intro Game state not found by game mode."));
	}

	FStory* CurrentStory = IntroGameState->GetCurrentStory();

	// Checks if there are still lines in the game state.
	if (CurrentStory == nullptr)
	{
		//TODO: Move to next scene.
		UE_LOG(LogTemp, Warning, TEXT("Ne-a ajuns."));
		return;
	}

	// Updates all the variables to match the current story line.
	CurrentTime = 0.f;
	CurrentLine = CurrentStory->LineToDisplay;
	TotalTime = CurrentStory->WaitTime;
}



