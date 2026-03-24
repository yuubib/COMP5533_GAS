// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BaseMyGameplayAbility.generated.h"

// 前置宣告（避免循環依賴）
class UBaseMyGameplayAbility;

UENUM(BlueprintType)
enum class ECostType : uint8
{
	HP,
	MP,
	Strength
};

USTRUCT(BlueprintType)
struct COMP5533_GAS_API FMyGameplayAbilityInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	float CD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	ECostType CostType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	float CostValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	UMaterialInstance* IconMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	TSubclassOf<class UBaseMyGameplayAbility> AbilityClass;

	FMyGameplayAbilityInfo();
	FMyGameplayAbilityInfo(float InCD, ECostType InCostType, float InCostValue, UMaterialInstance* InIconMaterial, TSubclassOf<class UBaseMyGameplayAbility> InAbilityClass);
};

UCLASS()
class COMP5533_GAS_API UBaseMyGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	UMaterialInstance* IconMaterial;

	UFUNCTION(BlueprintCallable, Category = "AbilityInfo")
	FMyGameplayAbilityInfo GetAbilityInfo(int level);
};