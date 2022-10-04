#pragma once

struct Arr
{
	int* pArr;
	int Count;
	int MaxCount;
};

void AddAdress(Arr* iData);

void DelAdress(Arr* iData);

void Pushback(Arr* iData, int aData);

void Re_AddAdress(Arr* iData);