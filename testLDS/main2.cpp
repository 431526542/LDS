#include<iostream>
#include"ClassTemplateArr.h"

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
	//�Լ� ���ø�
	//ȣ���
	int i = Add<int>(10, 20); //Add�ε� T�κп� int�� �� �Լ� ��û
							  //�Լ� Ʋ�� ����� ���� <int>��� �������� ������ �Լ� ������ �ȵȴ�.

	//���� ���� int�����迭�� ��û�ϰ�ʹ�
	ClassTemplateArr<int> ctai;
	ctai.push_back(10);
	ctai.push_back(20);
	ctai.push_back(30);
	int iData = ctai[1]; //�޾ƺ���
	ctai[1] = 100; //�����غ���

	//�׸��� float ���ĵ� �ٷ� ����� �� �� �ִ�.
	ClassTemplateArr<float> ctaf;
	ctaf.push_back(3.14f);
	ctaf.push_back(6.28f);
	ctaf.push_back(30.444f);
	float fData = ctaf[0];

	return 0;
}