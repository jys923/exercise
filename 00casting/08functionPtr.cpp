#include "stdafx.h"
#include "08functionPtrCallback.h"

int add(int a, int b);

// 전달되는 인자에 따라서 달리 동작하는 함수
int bigger(int a, int b,int (*cmp)(int,int));
int big(int a, int b);
int small(int a, int b);

typedef void(*callback)(void);
//void setCallback(callback back);
void exeCallback(callback back);
void tstCallback(void);

void result(void);

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

	printf("Test Callback\n");
	callback back = tstCallback;
	exeCallback(back);

	printf("Test Callback out\n");
	SetCallBackFuntion(&result);

	ExecutionCallBack();
	
}

void result(void) {
	printf("Result 08functionPtrCallback.h\n");
}

void exeCallback(callback back) {
	back();
}
void tstCallback(void) {
	printf("tstCallback\n");
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