// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolToWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UPatrolToWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory) {

	APawn* ControlledPawn = OwnerComponent.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) {return EBTNodeResult::Failed;}

	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("Warning: Empty Patrol Route"))
			return EBTNodeResult::Failed;
	}

	auto BlackboardComp = OwnerComponent.GetBlackboardComponent();
	int Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolPoints[Index]);

	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	
	return EBTNodeResult::Succeeded;
	
}

