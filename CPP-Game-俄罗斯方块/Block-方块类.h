#pragma once

#include <vector>
//#include "EasyX_2023大暑版/include/easyx.h"
#include "EasyX_2023大暑版/include/graphics.h"

using namespace std;

struct Point
{
	int row;// 行
	int col;// 列
};

// 方块类
class Block
{
public:
	Block(int sourceBlockSize);
	~Block();

	// 下降
	void drop();

	// 左移
	void moveLeft();
	
	// 右移
	void moveRight();

	// 旋转
	void rotate();

	// 绘制 上边界距离, 下边界距离, 左边界距离, 右边界距离, 方块大小
	void draw(int topMargin, int downMargin, int leftMargin, int rightMargin, int blockSize);

	// 获取 小方块图像指针数组，用来 渲染固化的方块时 获取方块类型
	static IMAGE** getImgs();

	// 方块是否在地图里
	bool blockInMap(const vector<vector<int>>& vGameMap);

	// 固化方块
	void solidify(vector<vector<int>>& vGameMap);

	// 重载运算符，用来深拷贝，返回引用 可以连续赋值
	Block& operator=(const Block& otherBlock);

private:
	int m_BlockType;              // 方块类型
	struct Point m_SmallBlocks[4];// 小方块具体位置

	IMAGE *m_Img;                 // 图像指针，用来指向m_Imgs，因为图片一样，所以不需要很多份
	static IMAGE *m_Imgs[7];      // 小方块图像指针数组，静态，方块类共用
	//static int m_Size;            // 方块大小
	int m_SourceBlockSize;        // 素材方块大小，裁剪要用
};