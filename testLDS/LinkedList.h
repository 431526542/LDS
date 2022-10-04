#pragma once
/*
	�� ����,�߰��� ������ �߰��� ������ �����ϴ�. (������ ����)
	������ �O���� �ѹ��� �ּ� ���ٰ���(����Ʈ ����)
*/
struct tNode
{
	//���� �����ϰ��� �ϴµ����Ϳ� ���� ����� �ּҵ� ����.
	//1. �����͸� �˾ƾ� �Ѵ�.
	int iData;
	//2.��������� �ּҸ� �˾ƾ� �ϱ⶧���� ���� Ÿ�԰� �Ȱ��� ������� �����͸� �˾ƾ��Ѵ�.
	tNode* pNextNode;
};

struct tLinkedList
{
	//�����͸� ��������� ������ؾ� �ұ�?
	//1. �����͸� ��� �־����� �˾ƾ��Ѵ�.
	int iCount;
	//2. ����Ʈ ������ ù��° ����� �ּҰ��� �˾ƾ� �Ѵ�.
	tNode* pHeadNode;
};

//������ ����Ʈ �ʱ�ȭ
void InitList(tLinkedList* _pList);
//������ ����Ʈ ������ �߰�(�ڷ�)
void PushBack(tLinkedList* _pList, int _iData);
//������ ����Ʈ ����
void ReleaseList(tLinkedList* _pList);
//������ ����Ʈ ������ �߰�(������)
void PushFront(tLinkedList* _pList, int _iData);