#include "data.h"
#include <windows.h>

// 数据所在路径
char *path = "E:\\大数据相关数据\\data.txt";
char *sortpath = "E:\\大数据相关数据\\sort.txt";

// 十一级指针
char *********** allP = NULL;

void init()
{
	// 分配指针数组
	allP = malloc(sizeof(char*) * 10);
	// 清零
	memset(allP, '\0', sizeof(char*) * 10); 
	FILE *pf = fopen(path, "r");
	if (pf == NULL)
	{
		printf("文件打开失败！！！\n");
		return;
	}
	else
	{
		for (int i = 0; i < allN; ++i)
		{
			char str[50] = { 0 };
			fgets(str, 50, pf); // 读取
			char *tmpstr = convertQQ(str); // 获取QQ号
			if (isallnum(tmpstr))
			{
				assignmem(&allP, 11, tmpstr); // 分配内存
				// allP[1][2][3][4]...
				strcpy(allP[getnum(tmpstr[0])][getnum(tmpstr[1])][getnum(tmpstr[2])][getnum(tmpstr[3])][getnum(tmpstr[4])][getnum(tmpstr[5])][getnum(tmpstr[6])][getnum(tmpstr[7])][getnum(tmpstr[8])][getnum(tmpstr[9])], str);
			}
			// 改变输出颜色
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 0xF + 0x0);
			printf("%d : %s\n", i, str);
		}
	}

	fclose(pf);
}


char *convertQQ(char *str)
{
	int length = strlen(str); // 获取长度
	char *tmp = malloc(length + 1);
	strcpy(tmp, str); // 拷贝，避免数据自动回收
	char  *p = strchr(tmp, '-');
	if (p != NULL)
	{
		*p = '\0';
	}
	int count = strlen(tmp); // 获取QQ长度

	if (count < 10)
	{
		// '0' = 48
		for (int i = 10; i >= 0; i--, count--)
		{
			if (count >= 0) // 移动8个
			{
				tmp[i] = tmp[count];
			} 
			else
			{
				tmp[i] = '0'; // 填充0

			}
		}
	}

	return tmp;
}

// 判断字符串是否有非法字符
int isallnum(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return 0;
		}
		str++;
	}
	return 1;
}

int getnum(char ch)
{
	return ch - '0'; 
}


void assignmem(char **pp, int deep, char *str)
{
	if (deep == 1)
	{
		//int index = getnum(*(str + 10 - deep)); // index分配字符串
		pp[getnum(*(str + 10 - deep))] = malloc(sizeof(char) * 50);
		memset(pp[getnum(*(str + 10 - deep))], 0, sizeof(char) * 50);
		return;
	}
	if (deep == 11)
	{
		assignmem(*pp, deep - 1, str); // 递归调用 
		return;
	}
	// 代表每一位的数字
	//int index = getnum(*(str + 10 - deep));
	if (pp[getnum(*(str + 10 - deep))]) // != 0
	{
		assignmem(pp[getnum(*(str + 10 - deep))], deep - 1, str); // 递归调用
	}
	else
	{
		pp[getnum(*(str + 10 - deep))] = malloc(sizeof(char*) * 10);
		memset(pp[getnum(*(str + 10 - deep))], 0, sizeof(char*) * 10);
		assignmem(pp[getnum(*(str + 10 - deep))], deep - 1, str); // 递归调用
	}
}

void search(char *str)
{
	if (isallnum(str) == 0)
	{
		return;
	}
	if (strlen(str) > 10)
	{
		return;
	}
	char *tmp = malloc(11);
	int count = strlen(str);
	if (count <= 10) // 00770250
	{
		for (int i = 10; i >= 0; i--, count--)
		{
			if (count >= 0)
			{
				tmp[i] = str[count];
			}
			else
			{
				tmp[i] = '0';
			}
		}
	}
	else
	{
		printf("No No");
		return;
	}
	// 0
	if (allP[getnum(tmp[0])])
	{
		if (allP[getnum(tmp[0])][getnum(tmp[1])])
		{
			if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])])
			{
				if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])])
				{
					if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])])
					{
						if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])])
						{
							if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])])
							{
								if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])])
								{
									if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])])
									{
										if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])])
										{
											printf("%s\n", allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]);
											return;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("没有找到");
}

void deleteit(char *str)
{
	if (isallnum(str) == 0)
	{
		return;
	}
	if (strlen(str) > 10)
	{
		return;
	}
	char *tmp = malloc(11);
	int count = strlen(str);
	if (count <= 10)
	{
		for (int i = 10; i >= 0; i--, count--)
		{
			if (count >= 0)
			{
				tmp[i] = str[count];
			}
			else
			{
				tmp[i] = '0';
			}
		}
	}
	else
	{
		printf("No No");
		return;
	}
	if (allP[getnum(tmp[0])])
	{
		if (allP[getnum(tmp[0])][getnum(tmp[1])])
		{
			if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])])
			{
				if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])])
				{
					if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])])
					{
						if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])])
						{
							if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])])
							{
								if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])])
								{
									if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])])
									{
										if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])])
										{
											allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])] = NULL;
											return;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	printf("没有找到");
}

void insert(char *str, char *pass)
{
	if (isallnum(str) == 0)
	{
		return;
	}
	if (strlen(str) > 10)
	{
		return;
	}
	char *tmp = malloc(11);
	int count = strlen(str);
	if (count <= 10)
	{
		for (int i = 10; i >= 0; i--, count--)
		{
			if (count >= 0)
			{
				tmp[i] = str[count];
			}
			else
			{
				tmp[i] = '0';
			}
		}
	}
	else
	{
		printf("No No");
		return;
	}
	if (allP[getnum(tmp[0])])
	{
		if (allP[getnum(tmp[0])][getnum(tmp[1])])
		{
			if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])])
			{
				if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])])
				{
					if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])])
					{
						if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])])
						{
							if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])])
							{
								if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])])
								{
									if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])])
									{
										if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])])
										{
											printf("%s", allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]);
											printf("已经存在");
											return;
										}
										else
										{
											int length = strlen(pass);
											allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])] = calloc(length + 1, 1);
											strcpy(allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])], pass);

											return;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	printf("没有找到");
}

void changeit(char *str, char *newpass)
{
	if (isallnum(str) == 0)
	{
		return;
	}
	if (strlen(str) > 10)
	{
		return;
	}
	char *tmp = malloc(11);
	int count = strlen(str);
	if (count <= 10)
	{
		for (int i = 10; i >= 0; i--, count--)
		{
			if (count >= 0)
			{
				tmp[i] = str[count];
			}
			else
			{
				tmp[i] = '0';
			}
		}
	}
	else
	{
		printf("No No");
		return;
	}
	if (allP[getnum(tmp[0])])
	{
		if (allP[getnum(tmp[0])][getnum(tmp[1])])
		{
			if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])])
			{
				if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])])
				{
					if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])])
					{
						if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])])
						{
							if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])])
							{
								if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])])
								{
									if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])])
									{
										if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])])
										{
											printf("已经存在");
											free(allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]);
											int length = strlen(newpass);
											allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])] = calloc(length + 1, 1);
											strcpy(allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])], newpass);
											return;
										}
								
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("没有找到");
}

void memtofile(char **p, int deep, FILE *pf)
{
	if (p == NULL)
	{
		return;
	}
	if (deep == 1)
	{
		for (int i = 0; i < 10; ++i)
		{
			if (p[i] != NULL)
			{
				fputs(p[i], pf); // 写入
			}
		}
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		memtofile(p[i], deep - 1, pf); // 递归写入
	}
}

void sorttofile()
{
	FILE *pf = fopen(sortpath, "w");
	memtofile(allP, 10, pf); // 写入
	fclose(pf);
}


