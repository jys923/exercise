#include "stdafx.h"

#define stackSize 100

typedef struct stack {
	int size;
	int items[stackSize];
}stack;

void pop(stack *pStack);
void push(stack *pStack, int data);

//int main() {
//
//	stack * pStack;
//	pStack = (stack*)malloc(sizeof(stack));
//	pStack->size = 0;
//	printf("size of stack = %d\n", sizeof(stackSize));
//
//	push(pStack, 10);
//	push(pStack, 20);
//	push(pStack, 30);
//	push(pStack, 40);
//
//	printf("%d\n", pStack->items[pStack->size]);
//	pop(pStack);
//	pop(pStack);
//	pop(pStack);
//	pop(pStack);
//	/*printf("%dn", pop(pStack));
//	printf("%dn", pop(pStack));
//	printf("%dn", pop(pStack));
//	printf("%dn", pop(pStack));*/
//
//	free(pStack);
//
//
//	return 0;
//}
//
//void push(stack *pStack, int data) {
//	if (pStack->size == stackSize)
//	{
//		printf("Error:Stack Over Flown\n");
//		return;
//	}
//	else
//	{	//pStack->size++;
//		pStack->items[pStack->size] = data;
//		pStack->size++;
//	}
//}
//void pop(stack *pStack) {
//	if (pStack->size == 0)
//	{
//		printf("Error:Stack Under Flown\n");
//		return;
//	}
//	else
//	{
//		printf("Pop:%d\n", pStack->items[pStack->size]);
//		pStack->size--;
//	}
//}

#define STACKSIZE 100

typedef struct {
	int size;
	int items[STACKSIZE];
} STACK;

void push(STACK *ps, int x)
{
	if (ps->size == STACKSIZE) {
		printf("Error: stack overflown");
		return;
	}
	else
		ps->items[ps->size++] = x;
}
int pop(STACK *ps)
{
	if (ps->size == 0) {
		printf("Error: stack underflown");
		return -1;
	}
	else
		return ps->items[ps->size];
}

int main()
{
	STACK *ps;
	ps = (STACK*)malloc(sizeof(STACK));
	ps->size = 0;

	printf("size of stack = %d\n", sizeof(STACK));
	printf("size of stack = %d\n", ps->size);

	push(ps, 10);

	push(ps, 20);
	push(ps, 30);
	push(ps, 40);

	printf("%d\n", pop(ps));
	printf("%d\n", pop(ps));
	printf("%d\n", pop(ps));
	printf("%d\n", pop(ps));

	free(ps);
}