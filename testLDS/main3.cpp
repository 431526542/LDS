#include<iostream>
#include"CArr.h"
#include"CArr1.h"

int main()
{
	
	CArr<int> carr;
	CArr<float> farr;
	for (int i = 0; i < 10; ++i)
	{
		carr.push_back(i);
	}
	farr.push_back(3.14f);
	farr.push_back(2.333f);
	farr.push_back(95.021);
	farr.push_back(4.5514f);
	carr[2] = 300;
	farr[0] = 3.141592f;
	for (int j = 0; j < 10; ++j)
	{
		std::cout << carr.m_pData[j] << std::endl;
	}
	for (int k = 0; k < 4; ++k)
	{
		std::cout << farr.m_pData[k] << std::endl;
	}
	/*
	CArr1 carr;
	for (int i = 0; i < 10; ++i)
	{
		carr.push_back(i);
	}
	carr[2] = 300;
	carr[8] = 900;
	for (int j = 0; j < 10; ++j)
	{
		std::cout << carr.m_pInt[j] << std::endl;
	}*/
	return 0;
}