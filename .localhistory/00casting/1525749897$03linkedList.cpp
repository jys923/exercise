#include "stdafx.h"

#pragma warning(disable : 4996)

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ListNode;

ListNode* add(int data);
void appendNode(ListNode** ppHead, ListNode* newNode);
void printList(ListNode** ppHead);
void deleteNode(ListNode **ppHead, int data);
void insertNode(ListNode **ppHead, ListNode* newNode, int data);

int main() {
	
	return 0;
}

ListNode* add(int data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = NULL;
	newNode->next = NULL;

	return newNode;
}

void appendNode(ListNode** ppHead, ListNode* newNode) {
	ListNode* tail = (ListNode*)malloc(sizeof(ListNode));
	if (*ppHead == NULL) {
		*ppHead = newNode;
	}
	else
	{
		tail = *ppHead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
