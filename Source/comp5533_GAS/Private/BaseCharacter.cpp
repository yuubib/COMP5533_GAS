// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	UAbilitySystemComponent* MyAbilitySystemComponent = this->FindComponentByClass<UAbilitySystemComponent>();
	if (MyAbilitySystemComponent)
	{
		MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetHPAttribute()).AddUObject(this, &ABaseCharacter::OnHealthAttributeChanged);
	}
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseCharacter::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	HPChangeEvent.Broadcast(Data.NewValue);
}

FMyGameplayAbilityInfo ABaseCharacter::GetAbilityInfo(TSubclassOf<UBaseMyGameplayAbility> AbilityClass, int level)
{
	UAbilitySystemComponent* MyAbilitySystemComponent = this->FindComponentByClass<UAbilitySystemComponent>();

	if (MyAbilitySystemComponent && AbilityClass)
	{
		UBaseMyGameplayAbility* AbilityInstance = AbilityClass->GetDefaultObject<UBaseMyGameplayAbility>();
		if (AbilityInstance)
		{
			return AbilityInstance->GetAbilityInfo(level);
		}
	}
	return FMyGameplayAbilityInfo();
}