#include "stdafx.h"

typedef struct __node {
	int data;
	struct __node *next;
}node;

node * createNode(int data);
void delNode(node ** head , node* curNode);
void addNode(node ** head,node * newNode);
void printNode(node ** head);
void insertNode(node * beforeNode, node * newNode);

int main() {
	node * node1 = createNode(1);
	node * node2 = createNode(2);
	node * node3 = createNode(3);
	addNode(&node1, node2);
	addNode(&node1, node3);
	return 0;
}

void printNode(node ** head)
{
	if (*head == NULL) 
	{
		printf("empty\n");
	}
	else
	{
		node * cur = *head;

		while (cur->next != NULL) {
			printf("data:%d\n", cur->data);
			cur = cur->next;
		}		
	}
};


void delNode(node ** head, node* curNode) 
{
	node * cur;

	if (*head == curNode)
	{
		*head = curNode->next;
	}
	else
	{
		cur = *head;
		while (cur != NULL && cur->next != curNode)
		{
			cur = cur->next;
		}

		if (cur != NULL)
			cur->next = cur->next;
	}
};

void insertNode(node * beforeNode, node * newNode)
{
	newNode->next = beforeNode->next;
	beforeNode->next = newNode;
};

node * createNode(int data) {
	node * newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};

void addNode(node ** head, node * newNode) {
	if (*head == NULL) {
		*head = newNode;
	}
	else
	{
		node * cur = *head;

		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newNode;
	}
};