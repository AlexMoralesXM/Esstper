// pasotee 2017

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "IntroHUD.generated.h"

/**
 * Updates and changes the Intro HUD
 */

class UUserWidget;

UCLASS()
class ESSTPER_API AIntroHUD : public AHUD
{
	GENERATED_BODY()

protected:
	// Widget used to story telling.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Story")
	TSubclassOf<UUserWidget> StoryWidgetTemplate;

private:
	// Widget Instance for the story widget template.
	UUserWidget* StoryWidget;

protected:
	void BeginPlay() override;
};
