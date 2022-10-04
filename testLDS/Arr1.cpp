#include "Arr1.h"
#include<iostream>

void addArr(Arr* iData)
{
	iData->pint = (int*)malloc(sizeof(int) * 2);
	iData->Count = 0;
	iData->MaxCount = 2;
}

void DelArr(Arr* iData)
{
	free(iData->pint);
	iData->Count = 0;
	iData->MaxCount = 0;
}

void InputData(Arr* iData, int aData)
{
	if (iData->Count >= iData->MaxCount)
	{
		Re_addArr(iData);
	}

	iData->pint[iData->Count++] = aData;
}

void Re_addArr(Arr* iData)
{
	int* newArr = (int*)malloc(iData->MaxCount * 2 * sizeof(int));

	for (int i = 0; i < iData->Count; ++i)
	{
		newArr[i] = iData->pint[i];
	}

	free(iData->pint);

	iData->pint = newArr;

	iData->MaxCount *= 2;
}
