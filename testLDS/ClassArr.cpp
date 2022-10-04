#include "ClassArr.h"
#include<assert.h>

/*
* �����Ҵ� new, delete
*/


ClassArr::ClassArr() //ClassArrŬ���� �ȿ� ����Ǿ��ִ� ClassArr�����ڴ� ~�����Ѵ�.
	: m_pInt(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2) //�̷��� �ʱ�ȭ �����ش�.
{
	m_pInt = new int[2]; //�����Ҵ�, int�ڷ��� 2��ġ��ŭ

}

ClassArr::~ClassArr()
{
	delete[] m_pInt; //������ int�ڷ��� ũ�⸸ŭ �����.
}

void ClassArr::push_back(int _iData)
{
	if (m_iCount >= m_iMaxCount)
	{
		resize(m_iMaxCount * 2);//�����Ͱ� ������ �ƽ�ī��Ʈ���� ���� 2��
	}

	m_pInt[m_iCount++] = _iData;
}

void ClassArr::resize(int _iResizeCount) //����� ��û�� ��û�� ��ŭ �ø�
{
	//1.���� �ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iCount >= _iResizeCount)
	{
		assert(nullptr);
	}
	//2.�������� ��ų ������ŭ �����Ҵ�
	int* pNew = new int[_iResizeCount];
	//3.������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pInt[i];
	}
	//4.�������� �޸� ����
	delete[] m_pInt;
	//5.�迭�� ���ο� ������ ����Ű�� �Ѵ�.
	m_pInt = pNew;
	//6.m_iMaxCount ������ ����
	m_iMaxCount = _iResizeCount;
}

int& ClassArr::operator[](int index)
{
	return m_pInt[index]; //m_pInt�� ����Ű���ִ� index�� ��¡���ִ� ���� ��ȯ
}
