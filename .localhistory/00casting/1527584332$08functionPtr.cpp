#include "stdafx.h"

int add(int a, int b);

int bigger(int a, int b,int (*cmp)(int,int));
int big(int a, int b);
int small(int a, int b);

void main() {
	//char *str = "Test FuncPtr";
	int(*fPtr)(int,int) = add;
	int out = fPtr(1, 2);
	printf("fPtr test:%d\n", out);

	printf("Test Big\n");
	out = bigger(10, 20, big);
	printf("Test Big:%d\n", out);
	printf("Test Small\n");
	out = bigger(10, 20, small);
	printf("Test Small:%d\n", out);

}

int bigger(int a, int b, int(*cmp)(int, int)) {
	return cmp(a, b);
}

int big(int a, int b) {
	int tmp = NULL;
	if (a > b)
	{
		tmp = a;
	}
	else
	{
		tmp = b;
	}
	return tmp;
}
int small(int a, int b) {
	int tmp = NULL;
	if (a > b)
	{
		tmp = b;
	}
	else
	{
		tmp = a;
	}
	return tmp;
}

int add(int a, int b) {
	return a + b;
}