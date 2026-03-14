// Fill out your copyright notice in the Description page of Project Settings.


#include "EngineProject/Public/TokyMGFTestComponent.h"

#include "Components/GameFrameworkComponentManager.h"


// Sets default values for this component's properties
UTokyMGFTestComponent::UTokyMGFTestComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTokyMGFTestComponent::BeginPlay()
{
	Super::BeginPlay();
	if (AActor* OwnerPawn = GetOwner())
	{
		FTimerHandle TimerHandle,TimerHandle2;
		FTimerManager& TimerManager = OwnerPawn->GetWorld()->GetTimerManager();
		TimerManager.SetTimer(TimerHandle,[=]()
		{
			if (OwnerPawn)
			{
				FVector Location = OwnerPawn->GetActorLocation();
				Location.X += 100;
				OwnerPawn->SetActorLocation(Location);
			}
		}, 0.1f ,true);

		TimerManager.SetTimer(TimerHandle2,[this, OwnerPawn, &TimerManager, TimerHandle]()
		{
			if (OwnerPawn)
				if (UGameFrameworkComponentManager* ComponentManager = GetWorld()->GetGameInstance()->GetSubsystem<UGameFrameworkComponentManager>())
				{
					ComponentManager->RemoveReceiver(OwnerPawn);
					TimerManager.ClearTimer(const_cast<FTimerHandle&>(TimerHandle));
				}
		},1.f,false);
	}
}


void UTokyMGFTestComponent::SendSimulateData_Implementation(AActor* TargetActor) const
{
	if (TargetActor&& TargetActor->HasAuthority())
	{	
		FTransform NewTransform{

		};
		TargetActor->SetActorTransform(NewTransform);
	}
}

// Called every frame
void UTokyMGFTestComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

