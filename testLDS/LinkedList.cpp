#include "LinkedList.h"
#include<iostream>

void InitList(tLinkedList* _pList)
{
	//데이터가 들어어오면 그때그때 만듬 그래서 초기화 값에 노드 주소가 없음
	_pList->pHeadNode = nullptr;
	//초기화 상태 데이터가 한개도 없으니 카운트는 0개
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	//1.동적할당으로 노드생성
	//노스 사이즈 만큼 데이터를 할당한 만큼 노드 데이터만큼 사용하기 위함.
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	//2. 데이터 파트에 데이터를 집어 넣는다.
	pNode->iData = _iData;
	//3.푸쉬백이기때문에 다음데이터는 없다 그래서 주소도 없다.
	pNode->pNextNode = nullptr;
	//4. 추가된 데이터가 처음인지 아닌지
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// 현재 가장 마지막 노드를 찾아서
		//그 노드의 pNext를 생성시킨 노드의 주소로 채움
		tNode* pCurFinalNode = _pList->pHeadNode; // 헤드노드를 건드리지 않기 위해 지역변수 이용
		while (pCurFinalNode->pNextNode)
		{
			//헤드 노드가 널포인트 인지 아닌지 판별해 마지막 노드인지 판별
			/*if (pCurFinalNode->pNextNode == nullptr)
			{
				break;
			}*/

			pCurFinalNode = pCurFinalNode->pNextNode;
		}
		pCurFinalNode->pNextNode = pNode;
	}
	++_pList->iCount;
}

void ReleaseList(tLinkedList* _pList)
{
	tNode* pDeletNode = _pList->pHeadNode;

	while (pDeletNode)
	{
		tNode* pNext = pDeletNode->pNextNode;
		free(pDeletNode);
		pDeletNode = pNext;
	}
}

void PushFront(tLinkedList* _pList, int _iData)
{
	//1.노드생성
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));
	//2.데이터 넣기
	pNewNode->iData = _iData;
	//3.추가된 데이터에 주소값 을 기존 헤드로 지정
	pNewNode->pNextNode = _pList->pHeadNode;

	//리스트의 헤드노드 포인터를 갱신한다.
	_pList->pHeadNode = pNewNode;

	//데이터 카운트 증가
	++_pList->iCount;
}
