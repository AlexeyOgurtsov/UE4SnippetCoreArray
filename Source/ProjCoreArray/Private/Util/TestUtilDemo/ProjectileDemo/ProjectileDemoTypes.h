#pragma once

#include "Math/Vector.h"
//#include "Kismet/BlueprintFunctionLibrary.h"
//#include "ProjectileDemoTypes.generated.h"


//USTRUCT(BlueprintType, Category=Weapon)
struct FProjectileDemo_ProjectileSettings
{
	//GENERATED_BODY()
	
	FProjectileDemo_ProjectileSettings() {}

	/** LaunchShift*/
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(AllowPrivateAccess=true))
	float LaunchShift = 50.0F;
	
};

//UCLASS()
//class UProjectileDemoTypes : public UBlueprintFunctionLibrary
//{
//	GENERATED_BODY()
//
//public: 
//};