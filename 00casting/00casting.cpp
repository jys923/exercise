// 00casting.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

class cData {
	public:int m_nType;
	public:char m_szMessage[8];
};

int main()
{
	char sz[] = { 0x61,0x62,0x63,0x00 };
	printf("sz[]:%s\n", sz);
	int a = *((int*)sz);
	printf("int a:%08X\n", a);
	int a1 = 0x00616263;
	printf("(char*)&a1:%s\n", (char*)&a1);

	char src[5] = { 'a','b','c','d',0x00 };
	char dest[5] = { 0, };
	memcpy(dest, src, 3);
	printf("dest[]:%s\n", dest);

	cData data;
	char szPacket[12];
	data.m_nType = 14;
	strcpy(data.m_szMessage, "test");
	memset(szPacket, 0x0, sizeof(szPacket));
	memcpy(szPacket, &data, sizeof(data));
	printf("szPacket[0]:%d\n", szPacket[0]);
	printf("szPacket[4]:%s\n", (char*)&szPacket[4]);
	printf("data.m_nType:%d\n", data.m_nType);
	printf("data.m_szMessage:%s\n", data.m_szMessage);

	char szPacket2[12];
	data.m_nType = 111;
	strcpy(data.m_szMessage, "test354");
	*((cData *)szPacket2) = data;
	printf("szPacket2[0]:%d\n", szPacket2[0]);
	printf("szPacket2[4]:%s\n", (char*)&szPacket2[4]);

	return 0;
}

