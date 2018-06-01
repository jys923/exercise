#include "stdafx.h"

int add(int a, int b);

void main() {
	//char *str = "Test FuncPtr";
	int(*fPtr)(int,int) = add;
	int out = fPtr(1, 2);
	printf("fPtr test:%d\n", out);
}

int add(int a, int b) {
	return a + b;
}