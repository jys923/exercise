#include "stdafx.h"

#define stackSize 100

typedef struct stack {
	int size;
	int items[stackSize];
}stack;

void pop(stack *pStack);
void push(stack *pStack, int data);

int main() {

	stack * pStack;
	pStack = (stack*)malloc(sizeof(stack));
	pStack->size = 0;
	printf("size of stack = %d\n", sizeof(stackSize));

	push(pStack, 10);
	push(pStack, 20);
	push(pStack, 30);
	push(pStack, 40);

	printf("%d\nn", pStack->items[pStack->size]);
	pop(pStack);
	pop(pStack);
	pop(pStack);
	pop(pStack);
	/*printf("%dn", pop(pStack));
	printf("%dn", pop(pStack));
	printf("%dn", pop(pStack));
	printf("%dn", pop(pStack));*/

	free(pStack);


	return 0;
}

void push(stack *pStack, int data) {
	if (pStack->size == stackSize)
	{
		printf("Error:Stack Over Flown\n");
		return;
	}
	else
	{
		pStack->items[pStack->size] = data;
		pStack->size++;
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
		printf("Pop:%d\n", pStack->items[pStack->size]);
		pStack->size--;
	}
}