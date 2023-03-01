/*
	Ñî»ÔÈý½Ç

			1
		   1 1
		  1 2 1
		 1 3 3 1
		1 4 6 4 1

		1
		1 1
		1 2 1
		1 3 3 1
		1 4 6 4 1
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}

			if (i == j)
			{
				arr[i][j] = 1;
			}

			if (i >= 2 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}