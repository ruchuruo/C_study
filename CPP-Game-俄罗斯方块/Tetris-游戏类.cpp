
#include "Tetris-游戏类.h"

const int SPEED_NORMAL = 500;// 速度正常 毫秒
const int SPEED_QUICK = 50;  // 速度快速 毫秒

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
	m_Delay(delay),
	m_BakBlock(this->m_BlockSize)// 备用方块，方块类创建需要传参
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
	// 创建游戏窗口
	initgraph(800, 600);

	// 加载背景图片
	loadimage(&this->m_Bgimg, L"res/bg1.png");

	// 初始化游戏数据

	// 给 地图 初始化
	for (int i = 0; i < this->m_Rows; i++)
	{
		for (int j = 0; j < this->m_Cols; j++)
		{
			this->m_VGameMap[i][j] = 0;
		}
	}
}

// 开始游戏
void Tetris::play()
{
	// 初始化
	this->init();

	// 开始游戏前需要先创建方块
	// 先有预告方块
	this->m_NextBlock = new Block(100);

	// 当前方块 等于 预告方块
	this->m_CurBlock = this->m_NextBlock;

	// 之后继续预告方块
	this->m_NextBlock = new Block(100);


	while (true)
	{
		// 接收用户输入
		this->keyEvent();

		// 获取上一次调用该函数间隔了多少毫秒
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
	//// 输入后立即渲染
	//this->m_upDateWindow = true;

	//// 清零渲染计时器
	//this->m_Timer = 0;
}

// 渲染游戏画面
void Tetris::upDateWindow()
{
	// 如果图像闪烁可以统一渲染
	// 开始批量绘制
	BeginBatchDraw();


	// 调用背景图片
	putimage(0, 0, &this->m_Bgimg);

	// 测试方块显示
	//Block b(100);
	//b.draw(10, 10, 10, 10, 30);

	// 获取 小方块图像指针数组
	IMAGE** retImgs = Block::getImgs();

	// 已经降落到底部的方块
	for (int i = 0; i < this->m_Rows; i++)
	{
		for (int j = 0; j < this->m_Cols; j++)
		{
			// 有方块
			if (this->m_VGameMap[i][j] != 0)
			{
				// 计算固化的方块坐标
				int x = j * this->m_BlockSize + this->m_LeftMargin;
				int y = i * this->m_BlockSize + this->m_TopMargin;

				// 渲染固化的方块
				// 数组中的元素是多少就渲染什么类型的方块
				putimage(x, y, retImgs[this->m_VGameMap[i][j] - 1]);
			}
		}
	}

	// 当前方块渲染
	this->m_CurBlock->draw(this->m_TopMargin, NULL, this->m_LeftMargin, NULL, 30);

	// 预告方块渲染
	this->m_NextBlock->draw(this->m_TopMargin, NULL, this->m_LeftMargin + 700, NULL, 30);


	// 结束批量绘制，并执行指定区域内未完成的绘制任务
	EndBatchDraw();
}

// 获取上一次调用该函数间隔了多少毫秒
int Tetris::getDrawDelay()
{
	// 上次时间，局部静态变量，只初始化一次
	static unsigned long long lastCurrentTime = 0;

	// 检索自系统启动以来经过的毫秒数，最长为 49.7 天。
	unsigned long long currentTime =
		GetTickCount();

	if (lastCurrentTime == 0)
	{
		// 之后将不是第一次调用
		lastCurrentTime = currentTime;

		// 第一次调用返回0
		return 0;
	}

	// 不是第一次调用
	int ret = currentTime - lastCurrentTime;
	lastCurrentTime = currentTime;
	return ret;
}

// 下降
void Tetris::drop()
{
	// 下降前保存当前位置
	this->m_BakBlock = *this->m_CurBlock;

	// 下降
	this->m_CurBlock->drop();

	// 检查方块位置是否合法
	//if (!this->m_CurBlock->blockInMap(this->m_VGameMap))
	if (this->m_CurBlock->blockInMap(this->m_VGameMap) == false)
	{
		// 非法
		// 固化方块，让备用方块来固化
		this->m_BakBlock.solidify(this->m_VGameMap);

		// 当前方块没用了
		delete this->m_CurBlock;

		// 需要下一个方块
		this->m_CurBlock = this->m_NextBlock;

		// 生成新方块
		this->m_NextBlock = new Block(100);
	}

}

// 清行
void Tetris::clearLine()
{
}
