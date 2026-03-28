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
		MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetMPAttribute()).AddUObject(this, &ABaseCharacter::OnMPAttributeChanged);
		MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetStrengthAttribute()).AddUObject(this, &ABaseCharacter::OnStrengthAttributeChanged);
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

void ABaseCharacter::OnMPAttributeChanged(const FOnAttributeChangeData& Data)
{
	MPChangeEvent.Broadcast(Data.NewValue);
}

void ABaseCharacter::OnStrengthAttributeChanged(const FOnAttributeChangeData& Data)
{
	StrengthChangeEvent.Broadcast(Data.NewValue);
}

FMyGameplayAbilityInfo ABaseCharacter::GameplayAbilityInfo(TSubclassOf<UBaseMyGameplayAbility> AbilityClass, int level)
{
	UAbilitySystemComponent* MyAbilitySystemComponent = this->FindComponentByClass<UAbilitySystemComponent>();

	UBaseMyGameplayAbility* AbilityIncetance = AbilityClass->GetDefaultObject<UBaseMyGameplayAbility>();
	
	if (MyAbilitySystemComponent && AbilityIncetance)
	{
		return AbilityIncetance->GetAbilityInfo(level);
	}
	return FMyGameplayAbilityInfo();
}