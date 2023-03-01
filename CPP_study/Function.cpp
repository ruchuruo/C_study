
#include "Function.h"

void n2(int 换行次数, char* 换行符号, int 符号个数)
{
	int i = 0;

	if (换行符号 != NULL && 符号个数 > 0)
	{
		printf("\n");
		for (i = 0; i < 符号个数; i++)
		{
			printf("%s", 换行符号);
		}
	}

	for (i = 0; i < 换行次数; i++)
	{
		printf("\n");
	}
}

// 计算整数位数
int digit(int num)
{
	int counter = 1;

	while (num >= 10)
	{
		num = num / 10;
		counter++;
	}

	return counter;
}