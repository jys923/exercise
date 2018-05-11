#include "stdafx.h"

#pragma warning(disable : 4996)



typedef struct ListNode

{

	int data;

	struct ListNode* next;

}ListNode;



ListNode* Add(int data);

void AppendNode(ListNode** Head, ListNode* new_Node);

void Serach(ListNode** Head);

void Delete(ListNode **Head, int data);

void insertNode(ListNode **Head, int data);

void main() {

	ListNode* head = NULL;

	ListNode* new_Node = NULL;



	new_Node = Add(0);

	AppendNode(&head, new_Node);



	new_Node = Add(1);

	AppendNode(&head, new_Node);



	new_Node = Add(2);

	AppendNode(&head, new_Node);



	Serach(&head);

	new_Node = Add(3);

	insertNode(&head, new_Node, 1);

	Serach(&head);

}

ListNode* Add(int data) {

	ListNode* new_Node = (ListNode*)malloc(sizeof(ListNode));



	new_Node->data = data;

	new_Node->next = NULL;



	return new_Node;

}



void AppendNode(ListNode** Head, ListNode* new_Node) {

	ListNode* Tail;



	if ((*Head) == NULL) {

		*Head = new_Node;

	}

	else {

		Tail = (*Head);

		while (!(Tail->next == NULL)) {

			Tail = Tail->next;

		}

		Tail->next = new_Node;

	}

}



void Serach(ListNode** Head) {

	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));



	if ((*Head) == NULL) {

		printf("Not Data!\n");

		exit(1);

	}

	else {

		Node = (*Head);

		while (!(Node == NULL)) {

			printf("Node->data : %d\n", Node->data);

			Node = Node->next;

		}

	}



}



void Delete(ListNode **Head, int data) {

	ListNode* deleteNode = NULL;

	ListNode* Node = NULL;

	if (*Head == NULL) {

		printf("Not Data!\n");

		return ;

	}

	deleteNode = *Head;

	deleteNode = deleteNode->next;

	Node = *Head;

	while (!(deleteNode == NULL)) {

		if ((deleteNode->data) == data) {

			Node->next = deleteNode->next;

			free(deleteNode);

			break;

		}

		Node = deleteNode;

		deleteNode = deleteNode->next;

	}

}



void insertNode(ListNode** Head, ListNode *newNode, int search_data) {

	ListNode* insertNode = NULL;

	ListNode* Node = NULL;



	if (*Head == NULL) {

		printf("Not Data!\n");

		return ;

	}

	insertNode = *Head;

	insertNode = insertNode->next;

	Node = *Head;



	while (!(insertNode == NULL)) {

		if (insertNode->data == search_data) {

			newNode->next = Node->next;

			Node->next = newNode;

			break;

		}

	}

}

