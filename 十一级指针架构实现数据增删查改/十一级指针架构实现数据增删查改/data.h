#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// 1000万条数据
#define allN 10000000

// 初始化,载入内存
void init();
// 截取
char *convertQQ(char *str);
// 查询
void search(char *str);
// 删除
void deleteit(char *str);
// 插入
void insert(char *str, char *pass);
// 修改
void changeit(char *str, char *newpass);
// 分配内存
void assignmem(char **pp, int deep, char *str);
// 字符转换为数字
int getnum(char ch);
// 将数据写入文件
void memtofile(char **p, int deep, FILE *pf);
// 文件数据排序
void sorttofile();

