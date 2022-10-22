#include <iostream>
#include <map> //���������Ž��Ʈ�� �ڷᱸ��
#include <set>

#include <string>

using std::map;
using std::make_pair;
using std::wcout;
using std::endl;

using std::set;

using std::wstring;

#define MAN		1
#define WOMAN   2
struct tStdInfo
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo()
		:szName{}, age(0), gender(0)
	{
	}

	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender)
		:szName{}, age(_age), gender(_gender)
	{
		wcscpy_s(szName, _pName);
	}
};

struct pair
{
	const wchar_t* first;
	tStdInfo second;
};

class MyClass
{
private:
	int a;
public:
	bool operator < (const MyClass& _other) const
	{
		if (a < _other.a)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	set<int> setInt; //int�� ������ �� �ִ� ����Ž����ݿ� Ž���� ������ �ڷᱸ�� �˰����� ����� �����̳�

	setInt.insert(100); //������ �ֱ�
	setInt.insert(50);
	setInt.insert(150);

	//1��
	map<const wchar_t*, tStdInfo> mapData; //ù��° Ÿ���� Ű�� ��. ����Ž��Ʈ���� �����ϴ� ���� �����ͷ� ���/ �ι�° Ÿ���� �� �����Ϳ� �����ִ� �߰����� ������ Ÿ���� ���Ѵ�.

	tStdInfo info(L"ȫ�浿",18,MAN);
	tStdInfo info2(L"������", 25, WOMAN);

	mapData.insert(make_pair(L"ȫ�浿", info)); //make_pair�� �ΰ��� �������� ����� �Լ� �̴�.
	mapData.insert(make_pair(L"������", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(L"������"); // map�� ù��° Ÿ���� const wchar_t*�̹Ƿ� L"ȫ�浿"�� �־��ش�. 
									   // �׷��� ����� ���� ����� L"ȫ�浿"�� �̸����� �����  make_pair�� ���´�
	
	_wsetlocale(LC_ALL, L"korean");

	//ã�� ���ߴ�.
	if (mapiter == mapData.end())
	{
		wcout << L"end" << endl;
	}
	else
	{
		wcout << L"�̸� : " << mapiter->second.szName << endl;
		wcout << L"���� : " << mapiter->second.age << endl;
		wcout << L"���� : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else
		{
			wcout << L"�� �� ����" << endl;
		}
	}

	/*
	mapiter->first; //ȫ�浿�� ���ڿ��� �ּ�
	mapiter->second; //info�� ���� ����ü*/

	//2��
	map<MyClass, tStdInfo> mapStdInfo;
	MyClass a;
	mapStdInfo.insert(make_pair(a, info));

	wstring str;
	str = L"asdfgh";
	str += L"asdasd";
	str[1] = L'c';

	wstring str2;
	if (str < str2)
	{

	}


	return 0;
}