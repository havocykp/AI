#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// 1000��������
#define allN 10000000

// ��ʼ��,�����ڴ�
void init();
// ��ȡ
char *convertQQ(char *str);
// ��ѯ
void search(char *str);
// ɾ��
void deleteit(char *str);
// ����
void insert(char *str, char *pass);
// �޸�
void changeit(char *str, char *newpass);
// �����ڴ�
void assignmem(char **pp, int deep, char *str);
// �ַ�ת��Ϊ����
int getnum(char ch);
// ������д���ļ�
void memtofile(char **p, int deep, FILE *pf);
// �ļ���������
void sorttofile();

