#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "data.h"


// 由于32位进程，最大只有2G
// 需要在64位下编译，

// 指定位置打印
void printChar(int posX, int posY, const char* pszChar, WORD wArr)
{
	// 1.设置光标属性
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	// 2.修改光标在控制台中的坐标位置
	COORD loc;
	loc.X = posX * 2;
	loc.Y = posY;
	// 设置颜色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	// 3.设置光标在控制台中的坐标位置
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	printf(pszChar);
}



void main()
{
	system("title 数据检索系统");
	clock_t start, finish;

	start = clock();
	init(); // 加载数据
	//sorttofile(); // 数据排序
	finish = clock();
	printf("\n数据加载完成，共用时：%f 秒\n", (double)(finish - start) / CLOCKS_PER_SEC);

	while (1)
	{
		printChar(24, 10, "(选择编号  回车确认)", rand() % 0xF + 0x0);
		printChar(27, 12, "① 查 询", rand() % 0xF + 0x0);
		printChar(27, 14, "② 增 加", rand() % 0xF + 0x0);
		printChar(27, 16, "③ 修 改", rand() % 0xF + 0x0);
		printChar(27, 18, "④ 删 除", rand() % 0xF + 0x0);
		printChar(25, 22, "请输入你的选择：[ ]\b\b", rand() % 0xF + 0x0);
		
		int num;
		scanf("%d", &num);
		switch (num)
		{
			case 1:
			{
				char str[100] = { 0 };
				printf("请输入要查找的QQ\n", str);
				scanf("%s", str);
				search(str);
				puts("搜索完成！！！\n");
				break;
			}
			case 2:
			{
				char str[100] = { 0 };
				printf("请输入要插入的QQ\n", str);
				scanf("%s", str);

				char str1[100] = { 0 };
				printf("请输入要插入的密码\n", str1);
				scanf("%s", str1);

				insert(str, str1);
				puts("插入成功！！！\n");

				break;
			}
			case 3:
			{
				char str[100] = { 0 };
				printf("请输入要修改的QQ\n", str);
				scanf("%s", str);

				char str1[100] = { 0 };
				printf("请输入要修改的密码\n", str1);
				scanf("%s", str1);

				changeit(str, str1);
				puts("修改完成！！！\n");
				break;
			}
			case 4:
			{
				char str[100] = { 0 };
				printf("请输入要删除的QQ", str);
				scanf("%s", str);
				deleteit(str);
				puts("删除成功！！！\n");
				break;
			}
			default:
				break;
		}
	}

	system("pause");
}