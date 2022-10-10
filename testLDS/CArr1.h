#pragma once
class CArr1
{
private:
	int m_Count;
	int m_MaxCount;
public:
	int* m_pInt;
	void push_back(int data);
	void resize(int databoxrecount);
	int& operator[](int idx);
public:
	CArr1();
	~CArr1();
};

