#include<iostream>
#include"ClassArr.h"

//�Լ� ���ø�
int Add(int a, int b)
{
	return a + b;
}
float add(int f, int f2)
{
	return f + f2;
}
/*
���� ���� ����� �Լ��ε� ���ڰ� ���ݽ� Ʋ�� �����ڰ� �� �������ϴ� ���
->���ʿ��� �밡��
�׷���
*/
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	//ClassArr����
	ClassArr carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	int& iData = carr[1]; //->int& operator[] (int index);�� ȣ�� 
	carr[1] = 200;
	
	//�Լ� ���ø�
	//ȣ���
	int i = Add<int>(10, 20); //Add�ε� T�κп� int�� �� �Լ� ��û
							  //�Լ� Ʋ�� ����� ���� <int>��� �������� ������ �Լ� ������ �ȵȴ�.


	return 0;
}