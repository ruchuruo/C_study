#pragma once

// 头文件的包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 符号的定义
#define 行 3
#define 列 3





// 函数的声明

//初始化棋盘
void 初始化棋盘(char 棋盘[行][列], int row, int col);

// 打印棋盘
void 打印棋盘(char 棋盘[行][列], int row, int col);

// 玩家下棋							用形参row和col来接收实参
void 玩家移动(char 棋盘[行][列], int row, int col);

// 电脑下棋
void 电脑移动(char 棋盘[行][列], int row, int col);


//游戏进行的过程
//	1.玩家赢 - *
//	2.电脑赢 - #
//	3.平局 - Q
//	4.游戏继续 - C
//判断游戏输赢
char isWin(char 棋盘[行][列], int row, int col);
