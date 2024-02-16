
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	// LeftTrack->SetThrottle(Throw * 1.5);
	LeftTrack->SetThrottle(Throw);
	LeftTrack->DriveTrack();
	// LeftTrack->ApplySidewaysForce();
	// LeftTrack->CurrentThrottle = 0;
	// RightTrack->SetThrottle(-Throw * 1.5);
	RightTrack->SetThrottle(-Throw);
	RightTrack->DriveTrack();
	// RightTrack->ApplySidewaysForce();
	// RightTrack->CurrentThrottle = 0;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();

	float MoveThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(MoveThrow);

	float TurnThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(TurnThrow);
}
