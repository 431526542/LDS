#pragma once
#include<assert.h>

template<typename T>

class ClassTemplateArr
{

private:
	// �����������Ҷ� ���ø��� ������ �޾� T*�� �Ѵ�.
	T* m_pData; //ctrl + R + R������ �����ߴ� �������� �ٲܼ� �ִ�.
	int m_iCount;
	int m_iMaxCount;

public:
	void push_back(const T& _iData); //const T& -> ������ �������� �ʵ� ������ �޾ƿ��� ���
	void resize(int _iResizeCount); 

	T& operator[] (int index); //�����ϴ� ����� TŸ�Ե��� ����ǰ� �װ��� ������ �����

public:
	ClassTemplateArr();
	~ClassTemplateArr();

};

//cpp������ �ƴ� ����� �־�� �ϴ� ����
//���ø��� Int�� float�� ���� ���� �ǰ� �������� ���Ѵ�.
//���ø��� ���ʿ� �ش��ȿ� ������ �Ǿ� �־�� �� �ش��� ����ϴ� ����� ���忡�� ������
//��û������ ���õ� �͵��� �� �ѹ��� ����� ���� �� �ֱ� ����

template<typename T>//cpp���ִ��� ����� �ű�� �����ϰ������ 1���� ���� �ؾ��Ѵ�.
//1��.ClassTemplateArr�� T���� �ȿ� �����Ǿ��ִ� �����ڸ� ��Ī�Ѵ�. ->T������ ����������Ѵ�.
ClassTemplateArr<T>::ClassTemplateArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2]; //����Ÿ����T�����Ѵ�.

}

template<typename T>
ClassTemplateArr<T>::~ClassTemplateArr()
{
	delete[] m_pData;
}

template<typename T>
void ClassTemplateArr<T>::push_back(const T& _iData) //���� �ٲ����
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

	T* pNew = new T[_iResizeCount]; //T������, T�� �ٲٰ�
	
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
