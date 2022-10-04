#pragma once

class ClassArr
{

private:
	int* m_pInt;
	int m_iCount;
	int m_iMaxCount;

public:
	void push_back(int _iData); //들어올 데이터만 적어주면된다, 호출한 가변배열은 this로 생략
	void resize(int _iResizeCount); //데이터가 다차면 함수활용과 동시에 요청시 함수 활용

	int& operator[] (int index); //해당타입을 반환해야하니 int로 선언

public:
	ClassArr();
	~ClassArr();
	
};

