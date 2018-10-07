#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "data.h"


// ����32λ���̣����ֻ��2G
// ��Ҫ��64λ�±��룬

// ָ��λ�ô�ӡ
void printChar(int posX, int posY, const char* pszChar, WORD wArr)
{
	// 1.���ù������
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	// 2.�޸Ĺ���ڿ���̨�е�����λ��
	COORD loc;
	loc.X = posX * 2;
	loc.Y = posY;
	// ������ɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	// 3.���ù���ڿ���̨�е�����λ��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	printf(pszChar);
}



void main()
{
	system("title ���ݼ���ϵͳ");
	clock_t start, finish;

	start = clock();
	init(); // ��������
	//sorttofile(); // ��������
	finish = clock();
	printf("\n���ݼ�����ɣ�����ʱ��%f ��\n", (double)(finish - start) / CLOCKS_PER_SEC);

	while (1)
	{
		printChar(24, 10, "(ѡ����  �س�ȷ��)", rand() % 0xF + 0x0);
		printChar(27, 12, "�� �� ѯ", rand() % 0xF + 0x0);
		printChar(27, 14, "�� �� ��", rand() % 0xF + 0x0);
		printChar(27, 16, "�� �� ��", rand() % 0xF + 0x0);
		printChar(27, 18, "�� ɾ ��", rand() % 0xF + 0x0);
		printChar(25, 22, "���������ѡ��[ ]\b\b", rand() % 0xF + 0x0);
		
		int num;
		scanf("%d", &num);
		switch (num)
		{
			case 1:
			{
				char str[100] = { 0 };
				printf("������Ҫ���ҵ�QQ\n", str);
				scanf("%s", str);
				search(str);
				puts("������ɣ�����\n");
				break;
			}
			case 2:
			{
				char str[100] = { 0 };
				printf("������Ҫ�����QQ\n", str);
				scanf("%s", str);

				char str1[100] = { 0 };
				printf("������Ҫ���������\n", str1);
				scanf("%s", str1);

				insert(str, str1);
				puts("����ɹ�������\n");

				break;
			}
			case 3:
			{
				char str[100] = { 0 };
				printf("������Ҫ�޸ĵ�QQ\n", str);
				scanf("%s", str);

				char str1[100] = { 0 };
				printf("������Ҫ�޸ĵ�����\n", str1);
				scanf("%s", str1);

				changeit(str, str1);
				puts("�޸���ɣ�����\n");
				break;
			}
			case 4:
			{
				char str[100] = { 0 };
				printf("������Ҫɾ����QQ", str);
				scanf("%s", str);
				deleteit(str);
				puts("ɾ���ɹ�������\n");
				break;
			}
			default:
				break;
		}
	}

	system("pause");
}