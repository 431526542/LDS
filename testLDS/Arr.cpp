#include "Arr.h"
#include<iostream>

void AddAdress(Arr* iData)
{
	iData->pArr = (int*)malloc(sizeof(int) * 2);
	iData->Count = 0;
	iData->MaxCount = 2;
}

void DelAdress(Arr* iData)
{
	free(iData->pArr);
	iData->Count = 0;
	iData->MaxCount = 0;
}

void Pushback(Arr* iData, int aData)
{
	if (iData->Count >= iData->MaxCount)
	{
		Re_AddAdress(iData);
	}

	iData->pArr[iData->Count++] = aData;
}

void Re_AddAdress(Arr* iData)
{
	int* New = (int*)malloc(iData->MaxCount * 2 * sizeof(int));

	for (int i = 0; i < iData->Count; ++i)
	{
		New[i] = iData->pArr[i];
	}
	
	free(iData->pArr);

	iData->pArr = New;

	iData->MaxCount *= 2;
}
