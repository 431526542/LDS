#pragma once
#include<assert.h>

template<typename T>

class ClassTemplateArr
{

private:
	// 데이터저장할때 템플릿에 영향을 받아 T*로 한다.
	T* m_pData; //ctrl + R + R누르면 선언했던 변수명을 바꿀수 있다.
	int m_iCount;
	int m_iMaxCount;

public:
	void push_back(const T& _iData); //const T& -> 원본을 수정하지 않되 참조만 받아오는 방식
	void resize(int _iResizeCount); 

	T& operator[] (int index); //참조하는 대상의 T타입들이 저장되고 그것을 참조를 줘야함

public:
	ClassTemplateArr();
	~ClassTemplateArr();

};

//cpp파일이 아닌 헤더에 있어야 하는 이유
//템플릿에 Int나 float이 들어가면 선언만 되고 구현되지 못한다.
//템플릿은 애초에 해더안에 구현이 되어 있어야 이 해더를 사용하는 사용자 입장에서 버전을
//요청했을때 관련된 것들을 다 한번에 만들어 놓을 수 있기 때문

template<typename T>//cpp에있던걸 헤더에 옮기고 구현하고싶으면 1번과 같이 해야한다.
//1번.ClassTemplateArr에 T버전 안에 구현되어있는 생성자를 지칭한다. ->T가뭔지 지정해줘야한다.
ClassTemplateArr<T>::ClassTemplateArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2]; //저장타입이T여야한다.

}

template<typename T>
ClassTemplateArr<T>::~ClassTemplateArr()
{
	delete[] m_pData;
}

template<typename T>
void ClassTemplateArr<T>::push_back(const T& _iData) //위에 바꿨던거
{
	if (m_iCount >= m_iMaxCount)
	{
		resize(m_iMaxCount * 2);
	}

	m_pData[m_iCount++] = _iData;
}

template<typename T>
void ClassTemplateArr<T>::resize(int _iResizeCount)
{
	if (m_iCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	T* pNew = new T[_iResizeCount]; //T포인터, T로 바꾸고
	
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}
	
	delete[] m_pData;
	
	m_pData = pNew;
	
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& ClassTemplateArr<T>::operator[](int index)
{
	return m_pData[index]; 
}
