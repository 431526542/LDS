#include<iostream>
//#include "CList.h"
#include "CList2.h"

//1��
class CTest
{
private:
	int m_i;
public:
	//��ü ���� ȣ�� ����
	static void MemberFunc() //static->�����ɹ��Լ��ν� ��ü���� ȣ�� ����
	{

	}
};

//2��
namespace MySpace //�̸� ����
{
	int g_int; //�������� �Լ�x
}
namespace Other
{
	int g_int; //�̸������� �޶� ������ ���� �ʴ´�.
}

//3��
using namespace std; //std��� ���ӽ����̽��� ����ϰڴ� ����->���ӽ����̽� ���� ���
using std::endl; //�̷������� std��ü�� �ƴ� ���� ���� ��밡�� �ϴ�.

int main()
{
	/*
	CList2<int> iarr;
	for (int i = 0; i < 3; ++i)
	{
		iarr.push_back(i);
	}
	*/

	//1�� ȣ�� ���
	CTest::MemberFunc(); //�̷������� ȣ��
	//2�� ���� ���
	MySpace::g_int = 0;
	Other::g_int = 0;
	//3��
	int i;
	cout<< i << endl;
	cin >> i;  //�̷�������std::���� ��밡��

	return 0;
}