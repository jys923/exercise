#include "stdafx.h"

void recursive(int nCnt);

void main() {
	recursive(5);
}

void recursive(int nCnt) {
	if (nCnt <= 0)
	{
		printf("�߻�\n");
		return;
	}
	else
	{
		printf("ī��Ʈ �ٿ� : %d\n", nCnt);
		recursive(nCnt - 1);
	}
}