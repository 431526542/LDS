#include<iostream>
//#include "CList.h"
#include "CList2.h"

//1번
class CTest
{
private:
	int m_i;
public:
	//객체 없이 호출 가능
	static void MemberFunc() //static->정적맴버함수로써 객체없이 호출 가능
	{

	}
};

//2번
namespace MySpace //이름 공간
{
	int g_int; //전역변수 함수x
}
namespace Other
{
	int g_int; //이름공간이 달라 문제가 되지 않는다.
}

//3번
using namespace std; //std라는 네임스페이스를 사용하겠다 선언->네임스페이스 없는 취급
using std::endl; //이런식으로 std전체가 아닌 따로 때서 사용가능 하다.

int main()
{
	/*
	CList2<int> iarr;
	for (int i = 0; i < 3; ++i)
	{
		iarr.push_back(i);
	}
	*/

	//1번 호출 방법
	CTest::MemberFunc(); //이런식으로 호출
	//2번 접근 방법
	MySpace::g_int = 0;
	Other::g_int = 0;
	//3번
	int i;
	cout<< i << endl;
	cin >> i;  //이런식으로std::없이 사용가능

	return 0;
}