// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.h"
#include "BaseMyGameplayAbility.h"
// ==============================================
// !!! 修正：.generated.h 必須是所有 #include 的最後一個，且「必須」放在 UCLASS 宣告之前！
// ==============================================
#include "BaseCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangeEvent, float, NewValue);

UCLASS()
class COMP5533_GAS_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnHealthChangeEvent HPChangeEvent;

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnHealthChangeEvent MPChangeEvent;

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnHealthChangeEvent StrengthChangeEvent;

	void OnHealthAttributeChanged(const FOnAttributeChangeData& Data);

	void OnMPAttributeChanged(const FOnAttributeChangeData& Data);

	void OnStrengthAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	FMyGameplayAbilityInfo GameplayAbilityInfo(TSubclassOf<class UBaseMyGameplayAbility> AbilityClass, int level);
};