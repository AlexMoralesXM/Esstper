// pasotee 2017

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "IntroGameState.generated.h"

/**
 * Holds the current state of the game.
 */

USTRUCT(BlueprintType)
struct FStory
{
	GENERATED_USTRUCT_BODY()

	// Current line of the story.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Intro")
	FString LineToDisplay;

	// Display time of the current line.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Intro")
	float WaitTime;

	//TODO: Add sound.
};

UCLASS()
class ESSTPER_API AIntroGameState : public AGameState
{
	GENERATED_BODY()

protected:
	// Index of the current Story displayed.
	int32 CurrentIndex = 0;
	
	// Array of all stories.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story")
	TArray<FStory> Story;

public:
	// Returns the current story to the game mode.
	FStory* GetCurrentStory();

};
