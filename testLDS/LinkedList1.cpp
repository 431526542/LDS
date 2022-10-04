#include "LinkedList1.h"
#include <iostream>

void AddList(LinekedList* list)
{
	list->HeadNode = nullptr;
	list->Count = 0;
}

void DeletList(LinekedList* list)
{
	Node* DeletNode = list->HeadNode;
	while (DeletNode)
	{
		Node* Next = DeletNode->NextNode;
		free(DeletNode);
		DeletNode = Next;
	}
}

void PushBack(LinekedList* list, int pData)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->Data = pData;
	pNode->NextNode = nullptr;

	if (list->HeadNode == nullptr)
	{
		list->HeadNode = pNode;
	}
	else
	{
		Node* FianlNode = list->HeadNode;
		while (FianlNode->NextNode)
		{
			FianlNode = FianlNode->NextNode;
		}
		FianlNode->NextNode = pNode;
	}
	++list->Count;
}
