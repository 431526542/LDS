#include <iostream>
#include <vector> //�����迭�� �ش��ϴ� ���� ���̺귯��
#include <list> //����������Ʈ�� �ش��ϴ� ���� ���̺귯��

using std::vector;
using std::list;


int main()
{
	//ǥ�ض��̺귯���� ���Ϳ� ����Ʈ ��.�����迭�� ����������Ʈ
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt[0] = 100;
	vecInt.at(1); //Ư�� �ε����� �����ؼ� �װ��� �����ڷ� ��ȯ���ִ°� vecInt[1]�� �Ȱ���.
	vecInt[1];
	vecInt.data(); //������ �����ּ� ��ȯ
	vecInt.size(); //�����͸� � ���� �־�����
	vecInt.capacity(); //���� �������� ��ĭ���� ����������

	//����Ʈ�ȿ� �������� ������ �ϴ� ��ȸ�ϰ�ʹ�(���ʹ� �̷������ε� �� �� �ִ�.)
	for (size_t i = 0; i < vecInt.size(); ++i)
	{
		std::cout << vecInt[i] << std::endl; // vecInt[i]�� �ƴϸ� vecInt.at(i)�̴�.
	}
	vector<int>::iterator viter = vecInt.begin();
	*viter = 100; //vecInt�� ó�������͸� 100���� �ִ´�.
	++viter; // vecInt�� ó�������� �ι�°������ ����Ŵ

	list<int> listInt;
	listInt.push_back(111);
	listInt.push_back(222);
	listInt.size();
	//�⺻������ ��ȸ�Ҽ� �ִ� �ݺ���iterator�� ����Ѵ�.
	//iterator�� Ŭ�����̴�. ����Ʈ ���ʿ� �ִ� Ŭ�����̴�. Ŭ�����ȿ� Ŭ������ �����Ǿ��ִ�(inner class)
	list<int>::iterator iter = listInt.begin(); //listInt�� ù��° ��带 ����Ų��
	int idata = *iter; //�̷����ϸ� listInt�� ù��° ������ 10�̶�� ���ڸ� ����Ų��.�����Ͱ� �ƴϴ�(�߿�).
					   //iteratorŬ���� ���ο� *���۷����Ͱ������Ǿ�����.*�Ǳ���� ��������Ʈ�� �������ڴ�.
	for (iter = listInt.begin(); iter != listInt.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}



	return 0;
}