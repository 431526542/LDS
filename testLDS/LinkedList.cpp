#include "LinkedList.h"
#include<iostream>

void InitList(tLinkedList* _pList)
{
	//�����Ͱ� ������� �׶��׶� ���� �׷��� �ʱ�ȭ ���� ��� �ּҰ� ����
	_pList->pHeadNode = nullptr;
	//�ʱ�ȭ ���� �����Ͱ� �Ѱ��� ������ ī��Ʈ�� 0��
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	//1.�����Ҵ����� ������
	//�뽺 ������ ��ŭ �����͸� �Ҵ��� ��ŭ ��� �����͸�ŭ ����ϱ� ����.
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	//2. ������ ��Ʈ�� �����͸� ���� �ִ´�.
	pNode->iData = _iData;
	//3.Ǫ�����̱⶧���� ���������ʹ� ���� �׷��� �ּҵ� ����.
	pNode->pNextNode = nullptr;
	//4. �߰��� �����Ͱ� ó������ �ƴ���
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// ���� ���� ������ ��带 ã�Ƽ�
		//�� ����� pNext�� ������Ų ����� �ּҷ� ä��
		tNode* pCurFinalNode = _pList->pHeadNode; // ����带 �ǵ帮�� �ʱ� ���� �������� �̿�
		while (pCurFinalNode->pNextNode)
		{
			//��� ��尡 ������Ʈ ���� �ƴ��� �Ǻ��� ������ ������� �Ǻ�
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
	//1.������
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));
	//2.������ �ֱ�
	pNewNode->iData = _iData;
	//3.�߰��� �����Ϳ� �ּҰ� �� ���� ���� ����
	pNewNode->pNextNode = _pList->pHeadNode;

	//����Ʈ�� ����� �����͸� �����Ѵ�.
	_pList->pHeadNode = pNewNode;

	//������ ī��Ʈ ����
	++_pList->iCount;
}
