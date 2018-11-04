// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolToWazpoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UPatrolToWazpoint::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory) {

	auto BlackboardComp = OwnerComponent.GetBlackboardComponent();

	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("Waypoint Index: %i"), Index);
	return EBTNodeResult::Succeeded;
	
}

