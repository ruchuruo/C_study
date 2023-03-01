/*
	打印闰年
		打印1000年到2000年之间的闰年

		判断闰年
			1.被4整除，不能被100整除
			1.能被400整除

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int y = 0;
	int 总数 = 0;

	for (y = 1000; y <= 2000; y++)
	{
		if ((y % 4 == 0)&&(y % 100 != 0) || (y % 400 == 0))
		{
			printf("%d ", y);
			总数++;
		}
	}
	printf("\n总数：%d", 总数);



	return 0;
}