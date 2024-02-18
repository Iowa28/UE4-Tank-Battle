
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class UDEMYPROJECT2_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;
	
	virtual float TakeDamage(float Damage, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 MaxHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 CurrentHealth;
	
};
