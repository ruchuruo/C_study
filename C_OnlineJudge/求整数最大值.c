/*
	求10个整数中最大值

	让所有数和max比较，如果比max大，那max就更新

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[10] = { -1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };
	int i = 0;
	int max = arr[0];

	for (i = 1; i < 10; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("%d\n", max);


	return 0;
}