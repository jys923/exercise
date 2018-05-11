#include "stdafx.h"

void recursiveCnt(int nCnt);
double power(double a, int num);

void main() {
	//recursiveCnt(5);
	printf("power:%.10lf\n", power(3.0, 5));
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