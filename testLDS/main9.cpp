#include <iostream>

class CParent
{
protected: //상속시 상속받은 자식 객체에서는 사용하고 싶지만 main에서는 감추고 싶을 때
	int m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

	virtual void Output()
	{
		std::cout << "부모" << std::endl;
	}

	void NewFunc()
	{

	}

public:
	CParent()
		:m_i(0)
	{
		std::cout << "부모생성자" << std::endl;
	}

	CParent(int _a)
		:m_i(_a)
	{
		std::cout << "부모 오버라이딩 생성자" << std::endl;
	}

	~CParent()
	{
		std::cout << "부모소멸자" << std::endl;
	}
};

class CChild : public CParent
{
private:
	float m_f;

public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 100;
	}

	void Output()
	{
		std::cout << "자식" << std::endl;
	}

	void NewFunc()
	{

	}

public:
	CChild()
		:CParent() //이것이 빠져있는것, CParent(1000)이렇게 선언해줘야 부모클래스에서 부모 오버라이딩 생성자를 호출해준다. 아니면 기본 생성자 호출함
		,m_f(0.f)
	{
		std::cout << "자식생성자" << std::endl;
	}

	~CChild()
	{
		std::cout << "자식소멸자" << std::endl;
	}
};

class CChildChild : public CChild
{
private:
	long long m_ll;

public:
	CChildChild()
		: CChild()
		, m_ll(0)
	{

	}

	~CChildChild()
	{

	}
};

int main()
{
	//객체지향 언어 특징
	/*
	1. 캡슐화(은닉성)
	2. 상속
	3. 다형성
	4. 추상화
	*/
	
	CParent parent;
	CChild child;
	//CChildChild childchild;
	//parent.SetInt(10);
	//child.SetInt(10);//CParent클레스 객체 안 m_i변수에 값을 넣어 주겠다.

	//상속
	/*
	1. 자식 또는 부모 클래스는 상속관계에서 다른 클래스의 맵머를 초기화 할 수 없다.
	2. 생성자 호출 순서 자식 ->부모
	3. 생성자 실행 순서, 초기화 순서 부모->자식
	4. 소멸자 실행 및 호출 순서, 자식 -> 부모
	*/

	//오버라이딩
	/*
	(오버로딩 : 함수명이 똑같은데 인자타입, 갯수가 달라 컴파일러가 구별 가능한 것들을 말함)
	1. 상속관련해서 발생하는 개념
	2. 같은 함수가 존재하고 자식에서 함수를 구현하면 자식쪽 함수를 우선적으로 호출함
	3. child.CParent::Output(); 이렇게 해서 부모쪽 함수를 호출할 수 있다.
	*/

	//다형성
	/*
	1.부모포인터 타입으로, 부모 클래스로부터 파생되는 자식 클래스 객체들의 주소를 가리킬 수 있다.
	2.모든 객체를 부모 클래스 타입으로 인식하게 되기 때문에, 실제 객체가 무엇인지 알 수 없다.
	3.virtual키워드 통해서, 각 클래스는 자신만의 고유한 가상함수 테이블을 가지게 된다.
	4. 각 클래스의 객체들은 가상함수 테이블 포인터에서 해당 클래스에 맞는 테이블을 가리키게 된다.
	5. 그 테이블에는 해당 클래스의 가상함수들이 등록
	*/
	//CParent* pParent = &child; // 부모클래스 포인터로 자식주소를 받는건 가능하다.
							   // 이것이 가능하면 부모로부터 파생되는 모든 자식들의 주소를 가르킬 수 있다.
	//CChild* pchild = &parent; //자식클래스 포인터로 부모주소를 받는 건 불가능하다.
	CParent* pParent = nullptr;

	parent.Output();
	pParent = &parent;
	pParent->Output();
	child.Output();
	pParent = &child;
	pParent->Output();

	//다운캐스팅
	/*
	1. 부모 클래스엣 선언되지 않은, 오직 자식쪽에서만 추가된 함수를 호출하고 싶을 때
	2. 자식 포인터 타입으로 일시적으로 캐스팅 해서 호출한다.
	3. 문제가 발생 할 수 있기 때문에 dynamic_cast 로 안전하게 확인해 볼 수 있다.
	4. RTTI(Run Time Type Identification or Information)
	*/
	//위험
	//(CChild*)pParent->NewFunc();
	//안전
	CChild* pChild = dynamic_cast<CChild*>(pParent);
	if (nullptr == pChild)
	{
		pChild->NewFunc();
	}

	//추상화
	/*
	1. 실제 객체를 생성할 목적의 클래스가 아닌, 상속을 통해서 구현해야할 내용을 전달하는 상속 목적으로 만들어진 클래스
	2. virtual, =0 (1개 이상의 순수가상함수를 포함하면 추상클래스가 된다)
	*/
	return 0;
}