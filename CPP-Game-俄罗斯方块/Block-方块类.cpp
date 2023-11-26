
#include "Block-方块类.h"
#include <stdlib.h>

/*
	在调用 new Block 时，会自动调用Block的默认构造函数，所以我们需要在这个构造函数里面完成新方块的创建。
	俄罗斯方块的表示方法有很多，最常见的是使用一个二维数组，表示一种俄罗斯方块的某种形态，也就是说，
	一个俄罗斯方块，需要使用4个二维数组来表示各个形态（4个方向）。
	我们这里使用一个更灵巧的方式：

	|      0  1
	|   0 [0][1]   [ ][1]   [ ][ ]   [ ][ ]   [ ][ ]   [ ][ ]   [ ][ ]   [ ][ ]
	|   1 [2][3]   [ ][3]   [2][ ]   [ ][3]   [ ][3]   [2][3]   [ ][3]   [2][3]
	|   2 [4][5]   [ ][5]   [4][5]   [4][5]   [4][5]   [ ][5]   [ ][5]   [4][5]
	|   3 [6][7]   [ ][7]   [ ][7]   [6][ ]   [ ][7]   [ ][7]   [6][7]   [ ][ ]

	int blocks[7][4] = {
		1,3,5,7, // I
		2,4,5,7, // Z 1型
		3,5,4,6, // Z 2型
		3,5,4,7, // T
		2,3,5,7, // L
		3,5,7,6, // J
		2,3,4,5, // 田
	};
*/

Block::Block()
{
	int blocks[7][4] =
	{
		1,3,5,7, // I
		2,4,5,7, // Z 1型
		3,5,4,6, // Z 2型
		3,5,4,7, // T
		2,3,5,7, // L
		3,5,7,6, // J
		2,3,4,5, // 田
	};

	// 随机生存一种俄罗斯方块
	this->m_blockType =
		1 + rand() % 7;// 1 - 7

	// 初始化 m_smallBlocks
	for (int i = 0; i < 4; i++)
	{
		int val = blocks[m_blockType - 1][i];

		// 这里是计算小方块的坐标
		this->m_smallBlocks[i].row = val / 2;
		this->m_smallBlocks[i].col = val % 2;
	}
}

Block::~Block()
{
}

// 下降
void Block::drop()
{
}

// 左移
void Block::moveLeft()
{
}

// 右移
void Block::moveRight()
{
}

// 旋转
void Block::rotate()
{
}

// 绘制 上边界距离, 下边界距离, 左边界距离, 右边界距离, 方块大小
void Block::draw(int topMargin, int downMargin, int leftMargin, int rightMargin, int blockSize)
{
}
