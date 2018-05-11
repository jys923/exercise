#include "stdafx.h"

void recursive(int nCnt);

void main() {
	recursive(5);
}

void recursive(int nCnt) {
	if (nCnt <= 0)
	{
		printf("발사\n");
		return;
	}
	else
	{
		printf("카운트 다운 : %d\n", nCnt);
		recursive(nCnt - 1);
	}
}