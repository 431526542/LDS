#pragma once

template<typename T>
struct tListNode
{
public:
	T			data;
	tListNode* pPrev;
	tListNode* pNext;

	//�⺻������
	tListNode()
		:data(), pPrev(nullptr), pNext(nullptr)
	{

	}

	tListNode(const* T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		:data(_data),
		pPrev(_pPrev),
		pNext(_pNext)
	{

	}
};

template<typename T>
class CList
{
private:
	int m_iCount;
	tListNode<T>* m_pHead;
	tListNode<T>* m_pTail;
public:
	void push_back(const T& _data);
	void push_front(const T& _data);
public:
	CList();
	~CList();
};

template<typename T>
void CList<T>::push_back(const T& _data)
{
	//�Էµ� �����͸� ������ ��带 �����Ҵ�
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);
	//ó�� �Էµ� �����Ͷ��
	if (m_pHead == nullptr)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else //�����Ͱ� 1�� �̻󿡼� �Էµ� ���
	{
		//���� ���� ������ �����͸� �����ϰ� �ִ� ��尡 ���� ������ ��带 ����Ű�� �ȴ�.
		//���� ������ ��尡 ���� ����Ű�� �Ѵ�.
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;
		//list�� ������ ����� �ּҰ��� ���� �Էµ� ���� �����Ѵ�.
		m_pTail = pNewNode;
	}
	//ī��Ʈ �� ����
	++m_iCount;
}

template<typename T>
void CList<T>::push_front(const T& _data)
{
	//���λ����� ����� ������ ���� ������� �ּҰ����� ä��
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);
	//���� ������� ������, �ּҰ��� ���� ������ ����� �ּҷ� ä��
	m_pHead->pPrev = pNewNode;
	//����Ʈ�� ���� ������ ����� �ּҸ� ���ο� ����ּҷ� �����Ѵ�.
	m_pHead = pNewNode;
	//ī��Ʈ �� ����
	++m_iCount;
}

template<typename T>
CList<T>::CList()
	:m_pHead(nullptr), m_pTail(nullptr), m_iCount(0)
{

}

template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeletNode = m_pHead;

	while (pDeletNode)
	{
		tListNode<T>* pNext = pDeletNode->pNext;
		delete(pDeletNode);
		pDeletNode = pNext;
	}
}