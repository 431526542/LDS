#include "ClassArr.h"
#include<assert.h>

/*
* 동적할당 new, delete
*/


ClassArr::ClassArr() //ClassArr클래스 안에 선언되어있는 ClassArr생성자는 ~정의한다.
	: m_pInt(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2) //이렇게 초기화 시켜준다.
{
	m_pInt = new int[2]; //동적할당, int자료형 2개치만큼

}

ClassArr::~ClassArr()
{
	delete[] m_pInt; //선언한 int자료형 크기만큼 지운다.
}

void ClassArr::push_back(int _iData)
{
	if (m_iCount >= m_iMaxCount)
	{
		resize(m_iMaxCount * 2);//데이터가 다차면 맥스카운트값에 대해 2배
	}

	m_pInt[m_iCount++] = _iData;
}

void ClassArr::resize(int _iResizeCount) //사용자 요청시 요청한 만큼 늘림
{
	//1.현재 최대 수용량 보다 더 적은 수치로 확장하려는 경우
	if (m_iCount >= _iResizeCount)
	{
		assert(nullptr);
	}
	//2.리사이즈 시킬 개수만큼 동적할당
	int* pNew = new int[_iResizeCount];
	//3.기존에 있는 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pInt[i];
	}
	//4.기존공간 메모리 해제
	delete[] m_pInt;
	//5.배열이 새로운 공간을 가리키게 한다.
	m_pInt = pNew;
	//6.m_iMaxCount 변경점 적용
	m_iMaxCount = _iResizeCount;
}

int& ClassArr::operator[](int index)
{
	return m_pInt[index]; //m_pInt가 가르키고있는 index가 지징해주는 값을 반환
}
