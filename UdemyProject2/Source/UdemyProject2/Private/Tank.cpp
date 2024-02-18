
#include "Tank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;

	CurrentHealth = MaxHealth;
}

float ATank::TakeDamage(float Damage, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(Damage);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}

	return DamageToApply;
}

float ATank::GetHealthPercent() const
{
	return static_cast<float>(CurrentHealth) / static_cast<float>(MaxHealth);
}
