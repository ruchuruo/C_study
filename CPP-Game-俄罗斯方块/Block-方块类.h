#pragma once

struct Point
{
	int row;// 行
	int col;// 列
};

// 方块类
class Block
{
public:
	Block();
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

private:
	int m_blockType;              // 方块类型
	struct Point m_smallBlocks[4];// 小方块具体位置
};