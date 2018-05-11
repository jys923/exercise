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
void printList(ListNode* ppHead);
void deleteNode(ListNode **ppHead, int data);
void insertNode(ListNode **ppHead, ListNode* newNode, int data);

int main() {
	ListNode* head = NULL;
	ListNode* newNode = NULL;

	newNode = add(0);
	appendNode(&head,newNode);
	newNode = add(4);
	appendNode(&head, newNode);
	newNode = add(2);
	appendNode(&head, newNode);
	newNode = add(1);
	appendNode(&head, newNode);
	printList(head);
	printf("=====================\n");
	deleteNode(&head, 4);
	printList(head);
	return 0;
}

void deleteNode(ListNode **ppHead, int data) {
	if (ppHead == NULL) {
		printf("empty\n");
		return;
	}
	else
	{
		ListNode* head = *ppHead;
		//head = head->next;
		ListNode* deleteNode = *ppHead;
		deleteNode = deleteNode->next;
		while (deleteNode !=NULL)
		{
			if (deleteNode->data == data)
			{
				head->next = deleteNode->next;
				free(deleteNode);
				break;
			}
			head = deleteNode;
			deleteNode = deleteNode->next;
		}
	}
}

void printList(ListNode* ppHead) {

	if (ppHead == NULL) {
		printf("empty\n");
	}
	else
	{
		//ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		ListNode* node = ppHead;
		while (node != NULL)
		{
			printf("node.data : %d\n", node->data);
			node = node->next;
		}
	}
}

void printList(ListNode** ppHead) {

	if (*ppHead == NULL) {
		printf("empty\n");
	}
	else
	{
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node = *ppHead;
		while (node != NULL)
		{
			printf("node.data : %d\n", node->data);
			node = node->next;
		}
	}
}

ListNode* add(int data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
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
