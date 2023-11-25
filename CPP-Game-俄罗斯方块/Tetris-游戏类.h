#pragma once

// 游戏类
class Tetris
{
public:
	// 行, 列, 上边界距离, 下边界距离, 左边界距离, 右边界距离, 方块大小, 渲染延时
	Tetris(int rows, int cols, int topMargin, int downMargin, int leftMargin, int rightMargin, int blockSize, int delay);
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
	int m_Timer;        // 每秒渲染定时器
	int m_Delay;        // 渲染延时
	bool m_upDateWindow;// 是否渲染
};