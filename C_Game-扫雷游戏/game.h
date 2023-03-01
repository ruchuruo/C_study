#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#define 行 9
#define 列 9
#define 行S 行+2
#define 列S 列+2
#define 非常简单 10


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void 初始化棋盘(char 棋盘[行S][列S], int rows, int cols);

// 因为数组传过来的是11*11的，所以这里还是要用[行S][列S]，只不过打印只打印中间9*9的
void 打印棋盘(char 棋盘[行S][列S], int row, int col);

// 因为数组传过来的是11*11的，所以这里还是要用[行S][列S]，只不过只用到中间9*9的
void 设置地雷(char 棋盘[行S][列S], int row, int col);

// 地雷数组中排查信息，最后放到显示数组
void 发现地雷(char 地雷[行S][列S], char 显示[行S][列S], int row, int col);



