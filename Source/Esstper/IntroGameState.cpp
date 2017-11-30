// pasotee 2017

#include "IntroGameState.h"

// Returns the current story to the game mode.
FStory* AIntroGameState::GetCurrentStory()
{
	if (CurrentIndex < Story.Num())
	{
		// Get the current story from the array.
		FStory* StoryToReturn = &Story[CurrentIndex];

		// Increment the current Index.
		CurrentIndex++;

		return StoryToReturn;
	}

	else
	{
		// Array is finished so we return null.
		return nullptr;
	}
}


