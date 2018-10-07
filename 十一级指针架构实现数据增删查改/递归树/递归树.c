#include <stdio.h>
#include <stdlib.h>

int nNum = 0;

void test1() // 11
{
	nNum++;
	for (int i = 0; i < 10; ++i) {
		nNum++;
	}
	printf("nNum = %d", nNum);
}

void test2()  // 111
{
	nNum++;
	for (int i = 0; i < 10; ++i) {
		nNum++;
		for (int j = 0; j < 10; ++j) {
			nNum++;
		}
	}
	printf("nNum = %d", nNum);
}

void test3()  // 1111
{
	nNum++;
	for (int i = 0; i < 10; ++i) {
		nNum++;
		for (int j = 0; j < 10; ++j) {
			nNum++;
			for (int k = 0; k < 10; ++k) {
				nNum++;
			}
		}
	}
	printf("nNum = %d", nNum);
}

// ตÝน้
void go(int data)
{	
	nNum++;
	if (data == 0) {
		return;
	}

	for (int i = 0; i < 10; ++i) {
		go(data - 1);
	}
}

void main()
{

	go(2);
	printf("%d", nNum);


	system("pause");
}
