#include<iostream>
#include"ClassArr.h"

//함수 템플릿
int Add(int a, int b)
{
	return a + b;
}
float add(int f, int f2)
{
	return f + f2;
}
/*
위와 같이 비슷한 함수인데 인자가 조금식 틀려 개발자가 또 만들어야하는 경우
->불필요한 노가다
그래서
*/
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	//ClassArr예시
	ClassArr carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	int& iData = carr[1]; //->int& operator[] (int index);를 호출 
	carr[1] = 200;
	
	//함수 템플릿
	//호출법
	int i = Add<int>(10, 20); //Add인데 T부분에 int가 들어간 함수 요청
							  //함수 틀을 만들어 놔서 <int>라고 선언하지 않으면 함수 생성이 안된다.


	return 0;
}