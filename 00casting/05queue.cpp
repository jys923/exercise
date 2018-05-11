#include "stdafx.h"

typedef struct node {
	int data;
	struct node* next;
}node;

void putQueue(node** head, int data);
int getQueue(node** head);
void printQueue(node* head);

int main() {
	node* queue = NULL;
	putQueue(&queue, 10);
	putQueue(&queue, 20);
	putQueue(&queue, 30);
	putQueue(&queue, 40);
	putQueue(&queue, 50);
	putQueue(&queue, 60);
	printQueue(queue);
	getQueue(&queue);
	getQueue(&queue);
	getQueue(&queue);
	printQueue(queue);
	return 0;
}

int getQueue(node** ppHead) {
	int result = NULL;
	if (ppHead == NULL) {
		printf("empty\n");
		
	}
	else
	{
		node* head = *ppHead;
		//node* deleteNode = *ppHead;
		node* deleteNode = head->next;
		while (deleteNode != NULL)
		{
			if (deleteNode->next == NULL)
			{
				result = deleteNode->data;
				head->next = deleteNode->next;
				free(deleteNode);
				break;
			}
			head = deleteNode;
			deleteNode = deleteNode->next;
		}
	}
	return result;
}

void printQueue(node* head) {
	node* top = head;
	while (top != NULL)
	{
		printf("Queue : %d \n", top->data);
		top = top->next;
	}

	/*while (head->next != NULL)
	{
		printf("Queue : %d \n", head->data);
		head = head->next;
	}*/
}

void putQueue(node** head, int data){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	if (*head == NULL) {		
		*head = newNode;
	}
	else
	{
		node* lastNode = *head;
		while (lastNode->next != NULL)
		{
			lastNode = lastNode->next;
		}
		//(*head)->next = newNode;
		lastNode->next = newNode;
	}
}