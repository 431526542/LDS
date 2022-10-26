#include <iostream>

class CParent
{
protected: //��ӽ� ��ӹ��� �ڽ� ��ü������ ����ϰ� ������ main������ ���߰� ���� ��
	int m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

	virtual void Output()
	{
		std::cout << "�θ�" << std::endl;
	}

	void NewFunc()
	{

	}

public:
	CParent()
		:m_i(0)
	{
		std::cout << "�θ������" << std::endl;
	}

	CParent(int _a)
		:m_i(_a)
	{
		std::cout << "�θ� �������̵� ������" << std::endl;
	}

	~CParent()
	{
		std::cout << "�θ�Ҹ���" << std::endl;
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
		std::cout << "�ڽ�" << std::endl;
	}

	void NewFunc()
	{

	}

public:
	CChild()
		:CParent() //�̰��� �����ִ°�, CParent(1000)�̷��� ��������� �θ�Ŭ�������� �θ� �������̵� �����ڸ� ȣ�����ش�. �ƴϸ� �⺻ ������ ȣ����
		,m_f(0.f)
	{
		std::cout << "�ڽĻ�����" << std::endl;
	}

	~CChild()
	{
		std::cout << "�ڽļҸ���" << std::endl;
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
	//��ü���� ��� Ư¡
	/*
	1. ĸ��ȭ(���м�)
	2. ���
	3. ������
	4. �߻�ȭ
	*/
	
	CParent parent;
	CChild child;
	//CChildChild childchild;
	//parent.SetInt(10);
	//child.SetInt(10);//CParentŬ���� ��ü �� m_i������ ���� �־� �ְڴ�.

	//���
	/*
	1. �ڽ� �Ǵ� �θ� Ŭ������ ��Ӱ��迡�� �ٸ� Ŭ������ �ʸӸ� �ʱ�ȭ �� �� ����.
	2. ������ ȣ�� ���� �ڽ� ->�θ�
	3. ������ ���� ����, �ʱ�ȭ ���� �θ�->�ڽ�
	4. �Ҹ��� ���� �� ȣ�� ����, �ڽ� -> �θ�
	*/

	//�������̵�
	/*
	(�����ε� : �Լ����� �Ȱ����� ����Ÿ��, ������ �޶� �����Ϸ��� ���� ������ �͵��� ����)
	1. ��Ӱ����ؼ� �߻��ϴ� ����
	2. ���� �Լ��� �����ϰ� �ڽĿ��� �Լ��� �����ϸ� �ڽ��� �Լ��� �켱������ ȣ����
	3. child.CParent::Output(); �̷��� �ؼ� �θ��� �Լ��� ȣ���� �� �ִ�.
	*/

	//������
	/*
	1.�θ������� Ÿ������, �θ� Ŭ�����κ��� �Ļ��Ǵ� �ڽ� Ŭ���� ��ü���� �ּҸ� ����ų �� �ִ�.
	2.��� ��ü�� �θ� Ŭ���� Ÿ������ �ν��ϰ� �Ǳ� ������, ���� ��ü�� �������� �� �� ����.
	3.virtualŰ���� ���ؼ�, �� Ŭ������ �ڽŸ��� ������ �����Լ� ���̺��� ������ �ȴ�.
	4. �� Ŭ������ ��ü���� �����Լ� ���̺� �����Ϳ��� �ش� Ŭ������ �´� ���̺��� ����Ű�� �ȴ�.
	5. �� ���̺��� �ش� Ŭ������ �����Լ����� ���
	*/
	//CParent* pParent = &child; // �θ�Ŭ���� �����ͷ� �ڽ��ּҸ� �޴°� �����ϴ�.
							   // �̰��� �����ϸ� �θ�κ��� �Ļ��Ǵ� ��� �ڽĵ��� �ּҸ� ����ų �� �ִ�.
	//CChild* pchild = &parent; //�ڽ�Ŭ���� �����ͷ� �θ��ּҸ� �޴� �� �Ұ����ϴ�.
	CParent* pParent = nullptr;

	parent.Output();
	pParent = &parent;
	pParent->Output();
	child.Output();
	pParent = &child;
	pParent->Output();

	//�ٿ�ĳ����
	/*
	1. �θ� Ŭ������ ������� ����, ���� �ڽ��ʿ����� �߰��� �Լ��� ȣ���ϰ� ���� ��
	2. �ڽ� ������ Ÿ������ �Ͻ������� ĳ���� �ؼ� ȣ���Ѵ�.
	3. ������ �߻� �� �� �ֱ� ������ dynamic_cast �� �����ϰ� Ȯ���� �� �� �ִ�.
	4. RTTI(Run Time Type Identification or Information)
	*/
	//����
	//(CChild*)pParent->NewFunc();
	//����
	CChild* pChild = dynamic_cast<CChild*>(pParent);
	if (nullptr == pChild)
	{
		pChild->NewFunc();
	}

	//�߻�ȭ
	/*
	1. ���� ��ü�� ������ ������ Ŭ������ �ƴ�, ����� ���ؼ� �����ؾ��� ������ �����ϴ� ��� �������� ������� Ŭ����
	2. virtual, =0 (1�� �̻��� ���������Լ��� �����ϸ� �߻�Ŭ������ �ȴ�)
	*/
	return 0;
}