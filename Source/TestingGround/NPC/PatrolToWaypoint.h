// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "PatrolToWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class UPatrolToWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory) override;
	
protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector IndexKey;
	
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector WayPointKey;
};
