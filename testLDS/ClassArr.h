#pragma once

class ClassArr
{

private:
	int* m_pInt;
	int m_iCount;
	int m_iMaxCount;

public:
	void push_back(int _iData); //���� �����͸� �����ָ�ȴ�, ȣ���� �����迭�� this�� ����
	void resize(int _iResizeCount); //�����Ͱ� ������ �Լ�Ȱ��� ���ÿ� ��û�� �Լ� Ȱ��

	int& operator[] (int index); //�ش�Ÿ���� ��ȯ�ؾ��ϴ� int�� ����

public:
	ClassArr();
	~ClassArr();
	
};

