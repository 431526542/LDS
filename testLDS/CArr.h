#pragma once
#include<assert.h>

template<typename T>
class CArr
{
private:
	//T* m_pData;
	int m_iCount;
	int m_iMaxCount;
public:
	T* m_pData;
	void push_back(const T& _Data); //원본은 수정x 참조는 받아온다.원형값 그대로 받아간다.
	void resize(int _iResizeCount); 
	T& operator[] (int idx);
public:
	CArr();
	~CArr();
};

template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr), m_iCount(0), m_iMaxCount(2) //초기값
{
	m_pData = new T[2]; // 동적할당하겠다 int자료형[2개만큼]
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData; //동적할당[배열] 해제한다.
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	if (m_iCount >= m_iMaxCount)
	{
		resize(m_iMaxCount * 2);
	}

	m_pData[m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	//데이터 확장 범위가 기존보다 같거나 작으면 문제
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	//1,리사이즈 시킬 개수만큼 동적할당 한다
	T* pNew = new T[_iResizeCount];
	//2.기존에 있던 데이터 새로운 공간으로 복사
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}
	//3.기존공간 해제
	delete[] m_pData;
	//4. 배열이 새로할당한 공간을 가르키게한다.
	m_pData = pNew;
	//5.iMaxCount값 증가
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx)
{

	return m_pData[idx];
}