#pragma once
/*
	맨 앞쪽,중간에 데이터 추가시 관리에 용이하다. (리스드 장점)
	데이터 찿을시 한번에 주소 접근가능(리스트 단점)
*/
struct tNode
{
	//내가 저장하고자 하는데이터와 다음 노드의 주소도 들어간다.
	//1. 데이터를 알아야 한다.
	int iData;
	//2.다음노드의 주소를 알아야 하기때문에 본인 타입과 똑같은 다음노드 포인터를 알아야한다.
	tNode* pNextNode;
};

struct tLinkedList
{
	//데이터를 집어넣으면 뭘기억해야 할까?
	//1. 데이터를 몇게 넣었는지 알아야한다.
	int iCount;
	//2. 리스트 본인은 첫번째 노드의 주소값을 알아야 한다.
	tNode* pHeadNode;
};

//연결형 리스트 초기화
void InitList(tLinkedList* _pList);
//연결형 리스트 데이터 추가(뒤로)
void PushBack(tLinkedList* _pList, int _iData);
//연결형 리스트 해제
void ReleaseList(tLinkedList* _pList);
//연결형 리스트 데이터 추가(앞으로)
void PushFront(tLinkedList* _pList, int _iData);