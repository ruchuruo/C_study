
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

IMAGE* Block::m_Imgs[7] = { NULL, };// 小方块数组初始化
//int Block::m_Size = 100;            // 方块大小初始化
//int Block::m_SourceBlockSize = 100; // 方块大小初始化

Block::Block(int sourceBlockSize):
	m_SourceBlockSize(sourceBlockSize)// 素材方块大小
{
	// 只需要初始化一次小方块数组
	if (this->m_Imgs[0] == NULL)
	{
		// 加载图片
		IMAGE imgTmp;
		/*
			使用EasyX库函数中的loadimage函数时而会有该报错。
			Visual Studio顶栏【调试】→【调试属性】→【配置属性】→【高级】→【高级属性】右【字符集】设置成【使用多字节字符集】即可解决。

			或

			在图片名称前加个字母“L”或“_T（）”即可，示例如下：
				loadimage(0,L"2.jpg");
				loadimage(0,_T("2.jpg"));
		*/
		//       加载到,     图片地址
		loadimage(&imgTmp, L"res/tiles.png");
		
		// 如果有很多小图片会占用很多存储空间
		// 图片切割

		// 设置切割对象
		SetWorkingImage(&imgTmp);

		// 切7刀
		for (int i = 0; i < 7; i++)
		{
			// 给 m_Imgs 数组分配内存
			m_Imgs[i] = new IMAGE;

			// 切割
			//       放到,      从X,             到Y, 切割宽,        切割高
			getimage(m_Imgs[i], i * this->m_SourceBlockSize, 0, this->m_SourceBlockSize, this->m_SourceBlockSize);
		}

		// 恢复工作图像
		SetWorkingImage();
	}

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
	this->m_BlockType =
		1 + rand() % 7;// 1 - 7

	// 初始化 m_SmallBlocks
	for (int i = 0; i < 4; i++)
	{
		int val = blocks[m_BlockType - 1][i];

		// 这里是计算小方块的坐标
		this->m_SmallBlocks[i].row = val / 2;
		this->m_SmallBlocks[i].col = val % 2;
	}

	// 指向图片
	this->m_Img = this->m_Imgs[this->m_BlockType - 1];
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
	// 4个小方块
	for (int i = 0; i < 4; i++)
	{
		// 计算小方块的位置
		//int x = leftMargin + this->m_SmallBlocks[i].col * this->m_Size;
		//int y = topMargin + this->m_SmallBlocks[i].row * this->m_Size;
		int x = leftMargin + this->m_SmallBlocks[i].col * blockSize;
		int y = topMargin + this->m_SmallBlocks[i].row * blockSize;

		// 调整图像大小
		Resize(this->m_Img, blockSize, blockSize);

		// 放置图像
		putimage(x, y, this->m_Img);
	}
}
