// Fill out your copyright notice in the Description page of Project Settings.


#include "TestManager.h"

void UTestManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TokyCollectionData.InitData();
}

void UTestManager::Deinitialize()
{
	Super::Deinitialize();
}

void UTestManager::TestFunction()
{
	TokyCollectionData = FTokyCollectionData();
}
