




#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//									  行		   列
void 初始化棋盘(char 棋盘[行][列], int row, int col)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			棋盘[x][y] = ' ';
		}
	}
}




// 以下代码不够通用 如果改成10×10 还是只能打印3列
//void 打印棋盘(char 棋盘[行][列], int row, int col)
//{
//	int x = 0;
//	for (x = 0; x < row; x++)
//	{
//		printf(" %c | %c | %c \n", 棋盘[x][0], 棋盘[x][1], 棋盘[x][2]);
//
//		if (x < row-1)
//		{
//			printf("---|---|---\n");
//		}
//	}
//}


// 改造
void 打印棋盘(char 棋盘[行][列], int row, int col)
{
	int x = 0;
	for (x = 0; x < row; x++)
	{
		//printf(" %c | %c | %c \n", 棋盘[x][0], 棋盘[x][1], 棋盘[x][2]);
		int y = 0;
		for (y = 0; y < col; y++)
		{
			printf(" %c ", 棋盘[x][y]);
			if (y < col-1)
			{
				printf("|");
			}
		}
		printf("\n");

		if (x < row - 1)
		{
			//printf("---|---|---\n");
			int y = 0;
			for (y < 0; y < col; y++)
			{
				printf("---");
				if (y < col-1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}







void 玩家移动(char 棋盘[行][列], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家走*\n");
	
	while (1)
	{
		printf("请输入坐标下棋:横 竖>");

		scanf("%d %d", &x, &y);

		// 判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			// (下棋)，(判断坐标是否被占用 等于空格就是没占用)，(x和y减一是为了输入1 1对应数组的0 0)
			if (棋盘[x - 1][y - 1] == ' ')
			{
				棋盘[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}





void 电脑移动(char 棋盘[行][列], int row, int col)
{
	printf("电脑走>\n");

	while (1)
	{
		//电脑要下在0-2内 row和col是3 所以%3的余数就是2
		int x = rand() % row;
		int y = rand() % col;

		// 判断占用
		if (棋盘[x][y] == ' ')
		{
			棋盘[x][y] = '#';
			break;
		}
	}
}





int 棋盘满(char 棋盘[行][列], int row, int col)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			return 0;// 棋盘没满
		}
	}

	return 1;
}
// 
char isWin(char 棋盘[行][列], int row, int col)
{
	int i = 0;

	// 判断三行
	for (i = 0; i < row; i++)
	{
		if (棋盘[i][0] == 棋盘[i][1] && 棋盘[i][1] == 棋盘[i][2] && 棋盘[i][1] != ' ')
		{
			return 棋盘[i][1];// 所在位置是什么符号就返回什么符号 省去了判断符号
		}
	}

	// 判断三列
	for (i = 0; i < col; i++)
	{
		if (棋盘[0][i] == 棋盘[1][i] && 棋盘[1][i] == 棋盘[2][i] && 棋盘[1][i] != ' ')
		{
			return 棋盘[1][i];
		}
	}

	// 判断对角线
	if (棋盘[0][0] == 棋盘[1][1] && 棋盘[1][1] == 棋盘[2][2] && 棋盘[1][1] != ' ')
	{
		return 棋盘[1][1];
	}

	if (棋盘[0][2] == 棋盘[1][1] && 棋盘[1][1] == 棋盘[2][0] && 棋盘[1][1] != ' ')
	{
		return 棋盘[1][1];
	}

	// 函数 判断平局 这里参数用小写是以为外面的函数接收的形参是row和col
	// 如果棋盘满了返回1，不满返回0
	int ret = 棋盘满(棋盘, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//继续
	return 'C';
}