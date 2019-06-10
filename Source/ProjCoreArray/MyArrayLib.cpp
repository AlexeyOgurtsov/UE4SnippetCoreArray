#include "MyArrayLib.h"
#include "Util/LogUtilLib.h"

#include "Serialization/BufferArchive.h"
#include "Serialization/MemoryReader.h"

namespace
{
	class FImpl
	{
	public:
		static void LogObject(const UObject* Obj)
		{
			if(Obj)
			{
				UE_LOG(MyLog, Log, TEXT("Class=\"%s\""), *Obj->GetClass()->GetName());
				UE_LOG(MyLog, Log, TEXT("Name=\"%s\""), *Obj->GetName());

				//UE_LOG(MyLog, Log, TEXT("%s"), *Obj->ToString());
			}	
			else
			{
				UE_LOG(MyLog, Log, TEXT("nullptr"));
			}
		}

		template<class T>
		static void LogArray(const TArray<T*>& InArray)
		{
			UE_LOG(MyLog, Log, TEXT("Logging array..."));
			UE_LOG(MyLog, Log, TEXT("Num()=%d"), InArray.Num());
			for(int32 i = 0; i < InArray.Num(); i++)
			{
				const T* Elem = InArray[i];

				UE_LOG(MyLog, Log, TEXT("%d:"), i);
	
				LogObject(Elem);
			}
			UE_LOG(MyLog, Log, TEXT("Logging array DONE"));
		}

		static void LogArray(const TArray<int32>& InArray)
		{
			UE_LOG(MyLog, Log, TEXT("Logging array..."));
			UE_LOG(MyLog, Log, TEXT("Num()=%d"), InArray.Num());
			for(int32 i = 0; i < InArray.Num(); i++)
			{
				UE_LOG(MyLog, Log, TEXT("%d: %d"), i, InArray[i]);
			}
			UE_LOG(MyLog, Log, TEXT("Logging array DONE"));	
		}
	};

	class FImplTests
	{
	public:
		static void AccessArrayToConst(const TArray<const UObject*>& InObjs)	
		{
			// Nothing is to do here;
		};
	};
} // anonymous

void UMyArrayLib::ArrayStr_Emplace()
{
	UE_LOG(MyLog, Log, TEXT("ArrayStr_Emplace..."));
	TArray<FString> Lines;
	Lines.Emplace("One");
	UE_LOG(MyLog, Log, TEXT("ArrayStr_Emplace DONE"));
}

void UMyArrayLib::Cast_ToArray_OfConstPtr()
{
	UE_LOG(MyLog, Log, TEXT("Cast_ToArray_OfConstPtr..."));
	
	TArray<const UObject*> ConstObjs;
	TArray<UObject*> Objs;
	TArray<UObject*> ObjsTwo;

	// Does not compile!
	// {
	//FImplTests::AccessArrayToConst(Objs);
	// }

	// Does NOT compile!	
	// {
	// ConstObjs = Objs;
	// }

	ObjsTwo = Objs;

	UE_LOG(MyLog, Log, TEXT("Cast_ToArray_OfConstPtr DONE"));
}

void UMyArrayLib::Array_Init()
{
	UE_LOG(MyLog, Log, TEXT("Array_Init..."));
	
	TArray<UObject*> Objs;
	Objs.Init(nullptr, 3);
	
	FImpl::LogArray(Objs);

	UE_LOG(MyLog, Log, TEXT("Array_Init DONE"));
}

void UMyArrayLib::Array_SerializeDeserialize()
{
	UE_LOG(MyLog, Log, TEXT("Array_SerializeDeserialize..."));

	// WARNING!!! Of course NON-const must be EVER when SERIALIZING;
	TArray<int> REF_ARRAY = { 1, 2, 3 };
	UE_LOG(MyLog, Log, TEXT("REF_ARRAY:"));
	FImpl::LogArray(REF_ARRAY);

	FBufferArchive Buffer;
	{
		Buffer << REF_ARRAY;
	}

	{
		FMemoryReader Ar { Buffer, /*bPersistent*/true };
		TArray<int> LoadedArray;
		Ar << LoadedArray; // Deserializing with "<<"

		UE_LOG(MyLog, Log, TEXT("LoadedArray:"));
		FImpl::LogArray(LoadedArray);

		// Comparison
		bool const bEqual = (LoadedArray == REF_ARRAY);
		if(bEqual)
		{
			UE_LOG(MyLog, Log, TEXT("Arrays EQUAL"));
		}
		else
		{
			UE_LOG(MyLog, Warning, TEXT("Arrays *NOT* equal"));
		}
	}

	UE_LOG(MyLog, Log, TEXT("Array_SerializeDeserialize DONE"));
}

void UMyArrayLib::ArrayObjects_SerializeDeserialize()
{
	UE_LOG(MyLog, Log, TEXT("ArrayObjects_SerializeDeserialize..."));
	UE_LOG(MyLog, Warning, TEXT("Not yet impl"));
	UE_LOG(MyLog, Log, TEXT("ArrayObjects_SerializeDeserialize DONE"));
}

void UMyArrayLib::ArrayStructs_SerializeDeserialize()
{
	UE_LOG(MyLog, Log, TEXT("ArrayStructs_SerializeDeserialize..."));
	UE_LOG(MyLog, Warning, TEXT("Not yet impl"));
	UE_LOG(MyLog, Log, TEXT("ArrayStructs_SerializeDeserialize DONE"));
}