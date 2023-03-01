/*
	获得某年某月有多少天，输入年份和月份，计算这一年这个月有多少天

	多组输入，一行有两个整数，分别表示年份和月份，用空格分隔

	针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天

	输入：2008 2
	输出：29
*/
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int y = 0;
	int m = 0;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//				   一 二 三							十
	//				   月 月 月.....................		二
	//													月

	printf("开始输入ctrl+c停止>");

	while (scanf("%d %d", &y, &m) != EOF)
	{
		int day = days[m];
		if (m == 2)
		{
			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			{
				day += 1;
			}
		}

		printf("%d\n", day);
	}
}