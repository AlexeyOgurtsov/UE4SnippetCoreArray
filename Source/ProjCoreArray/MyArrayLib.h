#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyArrayLib.generated.h"

UCLASS()
class UMyArrayLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Test)
	static void Cast_ToArray_OfConstPtr();

	UFUNCTION(BlueprintCallable, Category = Test)
	static void Array_Init();

	UFUNCTION(BlueprintCallable, Category = Test)
	static void Array_SerializeDeserialize();

	UFUNCTION(BlueprintCallable, Category = Test)
	static void ArrayObjects_SerializeDeserialize();

	UFUNCTION(BlueprintCallable, Category = Test)
	static void ArrayStructs_SerializeDeserialize();

	// ~String Array Begin
	UFUNCTION(BlueprintCallable, Category = Test)
	static void ArrayStr_Emplace();
	// ~String Array End
		
};