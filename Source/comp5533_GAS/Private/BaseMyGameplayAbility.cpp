// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseMyGameplayAbility.h"
#include "GameplayEffect.h" 

FMyGameplayAbilityInfo::FMyGameplayAbilityInfo()
	: CD(0.0f)
	, CostType(ECostType::HP)
	, CostValue(0.0f)
	, IconMaterial(nullptr)
	, AbilityClass(nullptr)
{
}

FMyGameplayAbilityInfo::FMyGameplayAbilityInfo(float InCD, ECostType InCostType, float InCostValue, UMaterialInstance* InIconMaterial, TSubclassOf<UBaseMyGameplayAbility> InAbilityClass)
	: CD(InCD)
	, CostType(InCostType)
	, CostValue(InCostValue)
	, IconMaterial(InIconMaterial)
	, AbilityClass(InAbilityClass)
{
}

FMyGameplayAbilityInfo UBaseMyGameplayAbility::GetAbilityInfo(int level)
{
	FMyGameplayAbilityInfo Info;

	// 取得冷卻時間
	if (UGameplayEffect* CDEffect = GetCooldownGameplayEffect())
	{
		CDEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(level, Info.CD);
	}

	// 取得消耗
	if (UGameplayEffect* CostEffect = GetCostGameplayEffect())
	{
		if (CostEffect->Modifiers.Num() > 0)
		{
			const FGameplayModifierInfo& ModInfo = CostEffect->Modifiers[0];
			ModInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(level, Info.CostValue);

			// 取得屬性名稱
			FString AttributeName = ModInfo.Attribute.AttributeName;
			
			if (AttributeName.Contains("Health") || AttributeName.Contains("HP"))
				Info.CostType = ECostType::HP;
			else if (AttributeName.Contains("Mana") || AttributeName.Contains("MP"))
				Info.CostType = ECostType::MP;
			else
				Info.CostType = ECostType::Strength;
		}
	}

	Info.IconMaterial = IconMaterial;
	Info.AbilityClass = GetClass();

	return Info;
}