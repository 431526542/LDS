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
	//�߰��� ������ ���� ���� ������ �ڽ����� �۰ų� ������ ���ϰ�
	if (databoxrecount <= m_MaxCount)
	{
		assert(nullptr);
	}
	//�����Ҵ�
	int* pNew = new int[databoxrecount];
	//�����������ִ� ������ �Ҵ�� �������� �̵�
	for (int i = 0; i < m_Count; ++i)
	{
		pNew[i] = m_pInt[i];
	}
	//������������
	delete[] m_pInt;
	//���������� ���ο� ������ ����Ű����
	m_pInt = pNew;
	//MaxCount�� �÷��ֱ�
	m_MaxCount = databoxrecount;
}

int& CArr1::operator[](int idx)
{
	// TODO: ���⿡ return ���� �����մϴ�.
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
