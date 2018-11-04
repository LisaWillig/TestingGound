// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrolToWazpoint.h"


EBTNodeResult::Type UPatrolToWazpoint::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory) {

	UE_LOG(LogTemp, Warning, TEXT("TEST"))
	return EBTNodeResult::Succeeded;
	
}

