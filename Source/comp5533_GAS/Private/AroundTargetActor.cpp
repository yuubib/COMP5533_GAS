// Fill out your copyright notice in the Description page of Project Settings.

#include "AroundTargetActor.h"
#include "Abilities/GameplayAbility.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Engine/OverlapResult.h"

void AAroundTargetActor::StartTargeting(UGameplayAbility* Ability)
{
	Super::StartTargeting(Ability);
	PrimaryPC = Cast<APlayerController>(Ability->GetOwningActorFromActorInfo()->GetInstigatorController());
}

void AAroundTargetActor::ConfirmTargetingAndContinue()
{
	APawn* SelfPawn = PrimaryPC->GetPawn();
	if (!SelfPawn)
	{
		return;
	}

	FVector PawnPoint = SelfPawn->GetActorLocation();

	TArray<FOverlapResult> OverlapResults;
	TArray<TWeakObjectPtr<AActor>> OverlapActors;

	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;
	QueryParams.bReturnPhysicalMaterial = false;


	if (SelfPawn)
	{
		QueryParams.AddIgnoredActor(SelfPawn);
	}
	bool QueryResult = GetWorld()->OverlapMultiByObjectType(
		OverlapResults,
		PawnPoint,
		FQuat::Identity,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn),
		FCollisionShape::MakeSphere(AroundRadius),
		QueryParams);
	if (QueryResult)
	{
		for (int i = 0; i < OverlapResults.Num(); i++)
		{
			APawn* Enemy = Cast<APawn>(OverlapResults[i].GetActor());
			if (Enemy && !OverlapActors.Contains(Enemy))
			{
				OverlapActors.Add(Enemy);
			}
		}
	}
	FGameplayAbilityTargetDataHandle TargetDataHandle;
	//FGameplayAbilityTargetData_LocationInfo* CenterLoc = new FGameplayAbilityTargetData_LocationInfo();
	//CenterLoc->TargetLocation.LiteralTransform = FTransform(LookPoint);
	//CenterLoc->TargetLocation.LocationType = EGameplayAbilityTargetingLocationType::LiteralTransform;
	////0号负载
	//TargetDataHandle.Add(CenterLoc);

	if (OverlapActors.Num() > 0)
	{
		FGameplayAbilityTargetData_ActorArray* ActorArray = new FGameplayAbilityTargetData_ActorArray();
		ActorArray->SetActors(OverlapActors);
		//1号负载
		TargetDataHandle.Add(ActorArray);
	}



	check(ShouldProduceTargetData());
	if (IsConfirmTargetingAllowed())
	{
		TargetDataReadyDelegate.Broadcast(TargetDataHandle);
	}

}
