/*
	使用指针打印数组内容
		写一个函数打印arr数组的内容，不使用数组下标，使用指针。
		arr是一个整形一维数组
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void 打印数组1(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}

void 打印数组2(int* p, int* pend)
{
	while (p <= pend)
	{
		printf("%d ", *p);
		p++;
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	int* p = arr;
	int* pend = arr + sz - 1;

	打印数组1(p, sz);

	printf("\n");

	打印数组2(p, pend);


	return 0;
}