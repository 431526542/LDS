#include <iostream>
#include <map> //레드블랙이진탐색트리 자료구조
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
	set<int> setInt; //int를 저장할 수 있는 이진탐색기반에 탐색에 용이한 자료구조 알고리즘을 사용한 컨테이너

	setInt.insert(100); //데이터 넣기
	setInt.insert(50);
	setInt.insert(150);

	//1번
	map<const wchar_t*, tStdInfo> mapData; //첫번째 타입을 키값 즉. 이진탐색트리를 구성하는 비교의 데이터로 사용/ 두번째 타입은 그 데이터에 딸려있는 추가적인 데이터 타입을 말한다.

	tStdInfo info(L"홍길동",18,MAN);
	tStdInfo info2(L"이재혜", 25, WOMAN);

	mapData.insert(make_pair(L"홍길동", info)); //make_pair는 두개를 묶음으로 만드는 함수 이다.
	mapData.insert(make_pair(L"이재혜", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(L"이재혜"); // map의 첫번째 타입이 const wchar_t*이므로 L"홍길동"를 넣어준다. 
									   // 그러면 저장된 값의 출력은 L"홍길동"의 이름으로 저장된  make_pair가 나온다
	
	_wsetlocale(LC_ALL, L"korean");

	//찾지 못했다.
	if (mapiter == mapData.end())
	{
		wcout << L"end" << endl;
	}
	else
	{
		wcout << L"이름 : " << mapiter->second.szName << endl;
		wcout << L"나이 : " << mapiter->second.age << endl;
		wcout << L"성별 : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"남자" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"여자" << endl;
		}
		else
		{
			wcout << L"알 수 없음" << endl;
		}
	}

	/*
	mapiter->first; //홍길동의 문자열의 주소
	mapiter->second; //info의 정보 구조체*/

	//2번
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