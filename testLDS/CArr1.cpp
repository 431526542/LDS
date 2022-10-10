#include "CArr1.h"
#include <assert.h>

void CArr1::push_back(int data)
{
	if (m_Count >= m_MaxCount)
	{
		resize(m_MaxCount * 2);
	}

	m_pInt[m_Count++] = data;
}

void CArr1::resize(int databoxrecount)
{
	//추가할 데이터 값이 기존 데이터 박스보다 작거나 같을시 못하게
	if (databoxrecount <= m_MaxCount)
	{
		assert(nullptr);
	}
	//동적할당
	int* pNew = new int[databoxrecount];
	//기존공간에있는 데이터 할당된 공간으로 이동
	for (int i = 0; i < m_Count; ++i)
	{
		pNew[i] = m_pInt[i];
	}
	//기존공간해제
	delete[] m_pInt;
	//기존공간을 새로운 공간을 가르키게함
	m_pInt = pNew;
	//MaxCount값 올려주기
	m_MaxCount = databoxrecount;
}

int& CArr1::operator[](int idx)
{
	// TODO: 여기에 return 문을 삽입합니다.
	return m_pInt[idx];
}

CArr1::CArr1()
	:m_pInt(nullptr), m_Count(0), m_MaxCount(2)
{
	m_pInt = new int[2];
}

CArr1::~CArr1()
{
	delete[] m_pInt;
}
