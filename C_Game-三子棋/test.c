

/*
	三子棋
		test.c	测试游戏的逻辑

		game.h	关于游戏的函数声明，符号声明，头文件的包含

		game.c	游戏相关函数的实现


	游戏进行的过程
		1.玩家赢		- *
		2.电脑赢		- #
		3.平局		- Q
		4.游戏继续	- C

	char isWin 用来判断游戏的状态

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void 菜单()
{
	printf("******** ---三--- ---子--- ---棋--- ********\n");
	printf("******** ********  1.开始  ******** ********\n");
	printf("******** ********  0.退出  ******** ********\n");
	printf("******** ******** ******** ******** ********\n");
}

void 游戏()
{
	// 存储数据 - 二维数组
	char 棋盘[行][列];

	// 初始化棋盘 - 初始化空格
	初始化棋盘(棋盘, 行, 列);

	// 打印棋盘 - 本质是打印数组的内容
	打印棋盘(棋盘, 行, 列);

	// 接收游戏状态
	char ret = 0;

	while (1)
	{
		// 玩家下棋 - 是下在数组里 - 有限坐标里
		玩家移动(棋盘, 行, 列);
		打印棋盘(棋盘, 行, 列);
		// 判断玩家是否赢 - 传参然后遍历数组的 行 列 对角线
		ret = isWin(棋盘, 行, 列);
		if (ret != 'C')
		{
			break;
		}

		// 电脑下棋
		电脑移动(棋盘, 行, 列);
		打印棋盘(棋盘, 行, 列);
		// 判断电脑是否赢
		char ret = isWin(棋盘, 行, 列);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("***玩家胜利***\n");
	}
	else if(ret == '#')
	{
		printf("###电脑胜利###\n");
	}
	else
	{
		printf("---平局---\n");
	}
	// 判断结束 打印棋盘
	打印棋盘(棋盘, 行, 列);
}

int main()
{
	srand((unsigned)time(NULL));

	int 选择 = 0;
	do
	{
		菜单();
		printf("请输入 数字 选择>");
		scanf("%d", &选择);

		switch (选择)
		{
		case 1:
			printf("三子棋游戏\n");
			游戏();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (选择);






	return 0;
}