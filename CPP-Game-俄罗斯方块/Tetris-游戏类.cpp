
#include "Tetris-游戏类.h"

Tetris::Tetris
(
	int rows,       // 行
	int cols,       // 列
	int topMargin,  // 上边界距离
	int downMargin, // 下边界距离
	int leftMargin, // 左边界距离
	int rightMargin,// 右边界距离
	int blockSize,  // 方块大小
	int delay       // 渲染延时
):
	m_Rows(rows),
	m_Cols(cols),
	m_TopMargin(topMargin),
	m_LeftMargin(leftMargin),
	m_BlockSize(blockSize),
	m_Delay(delay)
{
	// 给 地图 初始化
	for (int i = 0; i < this->m_Rows; i++)
	{
		// 数组 行
		vector<int> mapRow;

		for (int j = 0; j < this->m_Cols; j++)
		{
			// 数组 行 初始化
			mapRow.push_back(0);
		}

		// 给 地图 插入数组 行
		this->m_VGameMap.push_back(mapRow);
	}
}

Tetris::~Tetris()
{
}

// 初始化
void Tetris::init()
{
}

// 开始游戏
void Tetris::play()
{
	// 初始化
	this->init();

	while (true)
	{
		// 接收用户输入
		this->keyEvent();

		this->m_Timer += this->getDrawDelay();

		if (this->m_Timer > this->m_Delay)
		{
			// 下降
			this->drop();

			// 时间到时确定渲染
			this->m_upDateWindow = true;

			// 清零渲染计时器
			this->m_Timer = 0;
		}

		// 确定渲染
		if (this->m_upDateWindow == true)
		{
			// 渲染游戏画面(更新游戏画面)
			this->upDateWindow();

			// 渲染后停止渲染
			this->m_upDateWindow = false;

			// 更新游戏相关数据(清行)
			this->clearLine();
		}
		
	}
}

// 接收用户输入
void Tetris::keyEvent()
{
	// 输入后立即渲染
	this->m_upDateWindow = true;

	// 清零渲染计时器
	this->m_Timer = 0;
}

// 渲染游戏画面
void Tetris::upDateWindow()
{
}

// 获取上一次调用该函数间隔了多少毫秒
int Tetris::getDrawDelay()
{
	// 第一次调用返回0

	return 0;
}

// 下降
void Tetris::drop()
{
}

// 清行
void Tetris::clearLine()
{
}
