// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TestManager.generated.h"

USTRUCT(BlueprintType)
struct FTokyCollectionData
{
	GENERATED_BODY()
	char flag:1;
	char initial:7;
	size_t FuncHandle;

	UPROPERTY(BlueprintReadWrite)
	int32 RefCount;

	FTokyCollectionData():flag(1),initial(1),FuncHandle(reinterpret_cast<size_t>(TestFunction))
	{
		
	}

	FTokyCollectionData& operator= (const FTokyCollectionData& other)
	{
		flag = other.flag;
		initial = other.initial;
		using FUNC = void(*)();
		FUNC func = FUNC(FuncHandle);
		func();
		return *this;
	}

	FTokyCollectionData& operator= (FTokyCollectionData&& other)
	{
		flag = other.flag;
		initial = other.initial;
		using FUNC = void(*)();
		FUNC func =FUNC(FuncHandle);
		func();
		other.~FTokyCollectionData();
		return *this;
	}

	virtual constexpr void InitData()
	{
		flag = 0b1;
		initial = 0b111;
	}

	static void TestFunction()
	{
		UE_LOG(LogTemp, Display, TEXT("TestFunction"));
	}
};
/**
 * 
 */
UCLASS()
class ENGINEPROJECT_API UTestManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable)
	void TestFunction();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	FTokyCollectionData TokyCollectionData;
};
