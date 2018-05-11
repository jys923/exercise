#include "stdafx.h"

#define stackSize 100

typedef struct stack {
	int size;
	int items[stackSize];
}stack;

void pop(stack *pStack);
void push(stack *pStack, int data);
void print(stack *pStack);

typedef struct stackL {
	int data;
	struct stackL *next;
}stackL;

void popL(stackL **head);
void pushL(stackL **head, int data);
void printL(stackL *head);

int main() {

	stack * pStack;
	pStack = (stack*)malloc(sizeof(stack));
	pStack->size = 0;
	printf("size of stack = %d\n", sizeof(stackSize));

	push(pStack, 10);
	push(pStack, 20);
	push(pStack, 30);
	push(pStack, 40);
	print(pStack);
	printf("%d\n", pStack->items[pStack->size]);
	pop(pStack);
	pop(pStack);
	pop(pStack);
	print(pStack);
	printf("array stack\n");
	//pop(pStack);
	/*printf("%dn", pop(pStack));
	printf("%dn", pop(pStack));
	printf("%dn", pop(pStack));
	printf("%dn", pop(pStack));*/

	free(pStack);

	stackL* top = NULL;
	//top = (stackL *)malloc(sizeof(stackL));
	//top->data = NULL;
	//top->next = NULL;

	pushL(&top, 10);
	pushL(&top, 20);
	pushL(&top, 30);
	pushL(&top, 40);

	printf("ehklwl\n");
	printL(top);
	
	printf("ehklwl\n");
	popL(&top);
	popL(&top);
	popL(&top);
	popL(&top);
	popL(&top);
	printL(top);

	return 0;
}

void printL(stackL *head) {
	if (head == NULL) {
		printf("empty\n");
	}
	else
	{
		stackL * node = head;
		while (node!=NULL)
		{
			printf("node.data : %d\n", node->data);
			node = node->next;
		}
	}
}

void popL(stackL **head) {
	if (*head == NULL)
	{
		printf("empty\n");
		return;
	}
	stackL *top = *head;
	*head = (*head)->next;	
	free(top);
};
void pushL(stackL **head, int data) {
	stackL * node = (stackL *)malloc(sizeof(stackL));
	//stackL * top = *head;
	if (*head == NULL)
	{
		node->data = data;
		node->next = NULL;
		*head = node;
		return;
	}
	else
	{
		//stackL * top = *head;
		node->data = data;
		node->next = *head;
		*head = node;

	}
}

void print(stack *pStack) {
	for (size_t i = pStack->size ; i >= 0; i--)
	{
		printf("stack.data[%d]:%d\n", i, pStack->items[i]);
	}
}

void push(stack *pStack, int data) {
	if (pStack->size == stackSize)
	{
		printf("Error:Stack Over Flown\n");
		return;
	}
	else
	{	pStack->size++;
		pStack->items[pStack->size] = data;
		//pStack->size++;
	}
}
void pop(stack *pStack) {
	if (pStack->size == 0)
	{
		printf("Error:Stack Under Flown\n");
		return;
	}
	else
	{
		//printf("Pop:%d\n", pStack->items[pStack->size]);
		pStack->size--;
	}

}