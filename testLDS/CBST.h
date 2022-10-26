#pragma once

#include <assert.h>

enum class NODE_TYPE
{
	PARENT, //0	
	LCHILD, //1
	RCHILD, //2
	END     //3
};

template <typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};

template <typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{ _first, _second };
}

template <typename T1, typename T2>
struct tBSTNode
{
	//data
	tPair<T1, T2> Pair;
	//부모와 자식노드 사용
	tBSTNode* arrNode[(int)NODE_TYPE::END];
	/*
	//부모노드
	tBSTNode* pParent;
	//자식노드
	tBSTNode* pLeftChiled;
	tBSTNode* pRightChiled;*/
	bool IsRoot()
	{
		if (arrNode[(int)NODE_TYPE::PARENT] == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsLeftChild()
	{
		if(arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsRightChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsLeaf()
	{
		if (nullptr == arrNode[(int)NODE_TYPE::LCHILD] && nullptr == arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}

	bool IsFull()
	{
		if (arrNode[(int)NODE_TYPE::LCHILD] && arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}



	tBSTNode()
		:Pair()
		, arrNode{}
	{}

	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRChild)
		: Pair(_pair)
		, arrNode{ _pParent,_pLChild,_pRChild }
	{}
};

template <typename T1, typename T2>
class CBST
{
private:
	//루트주소
	tBSTNode<T1, T2>* m_pRoot;
	//데이터 갯수
	int	m_iCount;

public:
	bool insert(const tPair<T1, T2>& _pair);
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode);
	tBSTNode<T1, T2>* GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode);

	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);

private:
	tBSTNode<T1, T2>* DeleteNode(tBSTNode<T1, T2>* _pTargetNode);

public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{}

	//iterator
	class iterator
	{
	private:
		CBST<T1, T2>* m_pBST;
		tBSTNode<T1, T2>* m_pNode; //null인경우 end iterator

	public:
		// == 
		bool operator == (const iterator& _other)
		{
			if (m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		// !=
		bool operator != (const iterator& _other)
		{
			return !(*this == _other);
		}
		// *
		const tPair<T1, T2>& operator *()
		{
			//m_pNode nullper 체크 (end iterator인지 아닌지)
			assert(m_pNode);

			return m_pNode->Pair;
		}
		// ->
		const tPair<T1, T2>* operator ->()
		{
			//m_pNode nullper 체크 (end iterator인지 아닌지)
			assert(m_pNode);

			return &m_pNode->Pair;
		}
		// ++
		iterator& operator ++()
		{
			m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
			return *this;
		}

	public:
		iterator()
			: m_pBST(nullptr)
			, m_pNode(nullptr)
		{}

		iterator(CBST<T1, T2>* _pBST, tBSTNode<T1, T2>* _pNode)
			: m_pBST(_pBST)
			, m_pNode(_pNode)
		{}

		friend class CBST<T1, T2>;
	};
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);
	/*
	pNewNode->Pair = _pair;
	pNewNode->pParent = nullptr;
	pNewNode->pLeftChiled = nullptr;
	pNewNode->pRightChiled = nullptr;*/

	//첫번째 데이터 라면
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE node_type = NODE_TYPE::END;

		while (true)
		{
			if (pNode->Pair.first < pNewNode->Pair.first)
			{
				node_type = NODE_TYPE::RCHILD;
			}
			else if (pNode->Pair.first > pNewNode->Pair.first)
			{
				node_type = NODE_TYPE::LCHILD;
			}
			else
			{
				return false;
			}

			if (nullptr == pNode->arrNode[(int)node_type])
			{
				pNode->arrNode[(int)node_type] = pNewNode;
				pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;
			}
			else
			{
				pNode = pNode->arrNode[(int)node_type];
			}
		}
	}

	//데이터 개수 증가
	++m_iCount;

	return true;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode)
{
	tBSTNode<T1, T2>* pSuccessor = nullptr;
	//1. 오른쪽 자식이 있는 경우, 오른쪽 자식으로 가서, 왼쪽 자식이 없을때 까지 내려김
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD])
	{
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}
	//2. 부모로 부터 왼쪽자식일 때 까지 위로 올라감, 그때 부모가 후속자
	else
	{
		pSuccessor = _pNode;

		while (true)
		{
			//더이상 위쪽으로 올라갈 수 없다. -> 마지막 노드였다
			if (pSuccessor->IsRoot())
				return nullptr;
			//부모로부터 왼쪽 자식인지 체크
			if (pSuccessor->IsLeftChild())
			{
				//그때 부모가 후속자
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else
			{
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
			}
		}
	}

	return pSuccessor;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode)
{
	return nullptr;
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	tBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}

	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{
	tBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	while (true)
	{
		if (pNode->Pair.first < _find)
		{
			node_type = NODE_TYPE::RCHILD;
		}
		else if (pNode->Pair.first > _find)
		{
			node_type = NODE_TYPE::LCHILD;
		}
		else
		{
			//찾았다.
			break;
		}

		if (nullptr == pNode->arrNode[(int)node_type])
		{
			//못찾았다.
			pNode = nullptr;
			break;
		}
		else
		{
			pNode = pNode->arrNode[(int)node_type];
		}

		return iterator(this, pNode);
	}
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::erase(const iterator& _iter)
{
	assert(this == _iter.m_pBST);

	/*
	//1.자식이 하나도 없는 경우
	if (_iter.m_pNode->IsLeftChild())
	{
		//부모노드로 접근, 삭제될 노드인 자식을 가리키는 포인터를 nullptr로 만든다
		if (_iter.m_pNode->IsChild())
			_iter.m_pNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
		else
			_iter.m_pNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;

		delete _iter.m_pNode;
	}*/

	tBSTNode<T1,T2>* pSuccessor = DeleteNode(_iter.m_pNode);

	return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* _pTargetNode)
{
	//삭제시킬 노드의 후속자 노드를 찾아준다.
	tBSTNode<T1, T2>* pSuccessor = GetInOrderPredecessor(_pTargetNode);

	//1.자식이 하나도 없는 경우
	if (_pTargetNode->IsLeaf())
	{
		//삭제시킬 노드의 후속자 노드를 찾아준다.
		//pSuccessor = GetInOrderPredecessor(_pTargetNode);

		//삭제할 노드가 루트였다(자식이 없고 루트 => BST안에 데이터가 1개밖에 없었다)
		if (_pTargetNode == m_pRoot)
		{
			m_pRoot == nullptr;
		}
		else
		{
			//부모노드로 접근, 삭제될 노드인 자식을 가리키는 포인터를 nullptr로 만든다
			if (_pTargetNode->IsLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;
		}

		delete _pTargetNode;

		//데이터갯수 맞춰줌
		--m_iCount;
	}
	//2.자식이2개인경우
	else if (_pTargetNode->IsFull())
	{
		//삭제할 ㄴ드가 중위 후속자 노드가 됨
		//pSuccessor = GetInOrderPredecessor(_pTargetNode);
		
		// 삭제 될 자리에 중위 후속자의 값을 복사시킨다.
		_pTargetNode->Pair = pSuccessor->Pair;
		//중위 후속자 노드를 삭제한다.
		DeleteNode(pSuccessor);
		//삭제할 노드가 곧 중위 후속자가 되었다.
		pSuccessor = _pTargetNode;
	}
	//3.자식이 1개인 경우
	else
	{
		//삭제시킬 노드의 후속자 노드를 찾아준다.
		//pSuccessor = GetInOrderPredecessor(_pTargetNode);

		NODE_TYPE eChildType = NODE_TYPE::LCHILD;
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			eChildType = NODE_TYPE::RCHILD;

		//삭제할 노드가 루트였다
		if (_pTargetNode == m_pRoot)
		{
			m_pRoot == _pTargetNode->arrNode[(int)eChildType];
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
		}
		else
		{
			//삭제될 노드의 부모와 삭제될 노드의 자식을 연결해 준다.
			if (_pTargetNode->IsLeftChild())
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = _pTargetNode->arrNode[(int)eChildType];
			}
			else
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = _pTargetNode->arrNode[(int)eChildType];
			}

			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = _pTargetNode->arrNode[(int)NODE_TYPE::PARENT];
		}
		delete _pTargetNode;

		//데이터갯수 맞춰줌
		--m_iCount;
	}

	return pSuccessor;
}
