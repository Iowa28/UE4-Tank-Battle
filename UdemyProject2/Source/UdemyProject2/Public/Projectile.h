
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

UCLASS()
class UDEMYPROJECT2_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();

	void LaunchProjectile(float Speed);

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* LaunchBlast = nullptr;
	
	UProjectileMovementComponent* ProjectileMovement = nullptr;
};
