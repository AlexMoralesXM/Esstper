// pasotee 2017

#include "IntroHUD.h"
#include "Widgets/SUserWidget.h"
#include "Blueprint/UserWidget.h"

void AIntroHUD::BeginPlay()
{
	Super::BeginPlay();

	if (StoryWidgetTemplate == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing StoryWidgetTemplate on intro HUD."));
		return;
	}
	else
	{
		StoryWidget = CreateWidget<UUserWidget>(GetWorld(), StoryWidgetTemplate);
		StoryWidget->AddToViewport();
	}
}


