// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolToWazpoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UPatrolToWazpoint::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory) {

	AAIController* AIController = OwnerComponent.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	APatrollingGuard* PatrollingGuard = Cast <APatrollingGuard > (ControlledPawn);
	TArray<AActor*> PatrolPoints = PatrollingGuard->WayPoints;


	auto BlackboardComp = OwnerComponent.GetBlackboardComponent();
	int Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolPoints[Index]);

	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	UE_LOG(LogTemp, Warning, TEXT("Next Index: %i"), NextIndex)
	return EBTNodeResult::Succeeded;
	
}

