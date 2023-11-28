#pragma once

#include <vector>
#include "EasyX_2023大暑版/include/graphics.h"

using namespace std;

// 游戏类
class Tetris
{
public:

	Tetris
	(
		int rows,       // 行
		int cols,       // 列
		int topMargin,  // 上边界距离
		int downMargin, // 下边界距离
		int leftMargin, // 左边界距离
		int rightMargin,// 右边界距离
		int blockSize,  // 方块大小
		int delay       // 渲染延时
	);
	~Tetris();

	// 初始化
	void init();

	// 开始游戏
	void play();

private:
	// 接收用户输入
	void keyEvent();

	// 渲染游戏画面
	void upDateWindow();

	// 获取上一次调用该函数间隔了多少毫秒
	int getDrawDelay();

	// 下降
	void drop();

	// 清行
	void clearLine();

private:
	int m_Timer;                   // 每秒渲染定时器
	int m_Delay;                   // 渲染延时
	bool m_upDateWindow;           // 是否渲染

	vector<vector<int>> m_VGameMap;// 地图，二维数组，存放游戏数据(0表示没方块，其他数值表示方块种类，比如5表示第5种方块)
	int m_Rows;                    // 行
	int m_Cols;                    // 列
	int m_TopMargin;               // 上边界距离
	int m_LeftMargin;              // 左边界距离
	int m_BlockSize;               // 方块大小
	IMAGE m_Bgimg;                 // 背景图片
};