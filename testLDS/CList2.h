#pragma once

template<typename T>
struct tListNode
{
	T			data;
	tListNode<T>* pPrev;
	tListNode<T>* pNext;

	tListNode()
		: data(), pPrev(nullptr), pNext(nullptr)
	{
	}

	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		: data(_data), pPrev(_pPrev), pNext(_pNext)
	{

	}
};

template<typename T>
class CList2
{
private:
	tListNode<T>* m_pHead;
	tListNode<T>* m_pTail;
	int			  m_iCount;
public:
	void push_back(const T& _data);
	void push_front(const T& _data);
public:
	CList2();
	~CList2();
};

template<typename T>
void CList2<T>::push_back(const T& _data)
{
	tListNode<T>* pNextNode = new tListNode<T>(_data, nullptr, nullptr);

	if (m_pHead == nullptr)
	{
		m_pHead = pNextNode;
		m_pTail = pNextNode;
	}
	else
	{
		m_pTail->pNext = pNextNode;
		pNextNode->pPrev = m_pTail;
		m_pTail = pNextNode;
	}

	++m_iCount;
}

template<typename T>
void CList2<T>::push_front(const T& _data)
{
	tListNode<T>* pNextNode = new tListNode<T>(_data, nullptr, m_pHead);
	m_pHead->pPrev = pNextNode;
	m_pHead = pNextNode;
	++m_iCount;
}

template<typename T>
CList2<T>::CList2()
	: m_pHead(nullptr), m_pTail(nullptr), m_iCount(0)
{

}

template<typename T>
CList2<T>::~CList2()
{
	tListNode<T>* pDeletNode = m_pHead;

	while (pDeletNode)
	{
		tListNode<T>* pNext = pDeletNode->pNext;
		delete(pDeletNode);
		pDeletNode = pNext;
	}
}
