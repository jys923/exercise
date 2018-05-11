#include "stdafx.h"

void recursiveCnt(int nCnt);
double power(double a, int num);
int factorial(int num);
int fibonacci(int n);

void main() {
	//recursiveCnt(5);
	printf("power:%.10lf\n", power(3.0, 5));
	printf("factorial:%d\n", factorial(5));

	/*printf("fibonacci\n");
	int n = 10;
	for (int i = 0; i < n; i++) {
		printf("%d ", fibonacci(i));
	}
	printf("\n");*/

	fibonacci(10);
	
}

int fibonacci(int n) {
	printf("%d ", n);
	return (n==0||n==1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int factorial(int num) {
	if (num==1)
	{
		return 1;
	}
	else
	{
		return num * factorial(num - 1);
	}
}

double power(double a, int num) {
	if (num==0)
	{
		return 1;
	}
	else
	{
		return a * power(a, num - 1);
	}
	//return a * power(a, num - 1);
}

void recursiveCnt(int nCnt) {
	if (nCnt <= 0)
	{
		printf("발사\n");
		return;
	}
	else
	{
		printf("카운트 다운 : %d\n", nCnt);
		recursiveCnt(nCnt - 1);
	}
}