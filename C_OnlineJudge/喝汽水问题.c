/*
	喝汽水，1瓶汽水1元，2个空瓶可以换1瓶汽水，给20元，可以喝多少汽水

		钱		喝了的		空瓶
		20		20			20
				10			10
				5			5
				2			3
				1			2
				1			1
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void 喝汽水1(int 钱)
{
	int 总计 = 钱;
	int 空瓶 = 钱;

	// 开始置换
	while (空瓶 >= 2)
	{
		总计 += 空瓶 / 2;
		空瓶 = 空瓶 / 2 + 空瓶 % 2;
	}

	printf("%d\n", 总计);
}

void 喝汽水2(int 钱)
{
	int 总计 = 0;
	if (钱 > 0)
	{
		总计 = 2 * 钱 - 1;
	}

	printf("%d\n", 总计);
}

int main()
{
	int 钱 = 0;
	printf("请输入钱数\n");
	scanf("%d", &钱);

	喝汽水1(钱);

	printf("\n");

	喝汽水2(钱);

	

	return 0;
}