
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankTrack::SetThrottle(float Throttle)
{
	// CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
	CurrentThrottle = Throttle;

	// DriveTrack();
	// ApplySidewaysForce();
	// CurrentThrottle = 0;
}

void UTankTrack::OnHit(
	UPrimitiveComponent* HitComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse,
	const FHitResult& Hit
)
{
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0;
}

void UTankTrack::DriveTrack()
{
	UE_LOG(LogTemp, Warning, TEXT("%s %f"), *GetName(), CurrentThrottle);
	FVector ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTrack::ApplySidewaysForce()
{
	float SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());

	FVector CorrectionAcceleration = -SlippageSpeed / GetWorld()->GetDeltaSeconds() * GetRightVector();
	
	UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	FVector CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2;
	TankRoot->AddForce(CorrectionForce);
}
