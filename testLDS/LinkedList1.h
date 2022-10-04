#pragma once

struct Node
{
	int Data;
	Node* NextNode;
};

struct LinekedList
{
	int Count;
	Node* HeadNode;
};

void AddList(LinekedList* list);
void DeletList(LinekedList* list);
void PushBack(LinekedList* list, int pData);

