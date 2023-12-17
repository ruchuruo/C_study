
#include "my_h.h"
#include easyx_h

// 窗口创建
void test1()
{
	// 创建窗口
	//        宽 , 高
	//initgraph(800, 600);

	// 创建图形窗口时保留控制台窗口
	initgraph(800, 600, EX_SHOWCONSOLE);

	// 禁用关闭按钮
	//initgraph(800, 600, EX_NOCLOSE);

	// 禁用最小化按钮
	//initgraph(800, 600, EX_NOMINIMIZE);

	// 如果都要使用
	//initgraph(800, 600, EX_SHOWCONSOLE | EX_NOCLOSE | EX_NOMINIMIZE);

	/*
		// EasyX Window Properties // EasyX窗口属性
		#define EX_SHOWCONSOLE		1		// Maintain the console window when creating a graphics window // 创建图形窗口时保留控制台窗口
		#define EX_NOCLOSE			2		// Disable the close button                                    // 禁用关闭按钮
		#define EX_NOMINIMIZE		4		// Disable the minimize button                                 // 禁用最小化按钮
		#define EX_DBLCLKS			8		// Support double-click events                                 // 支持双击事件
	*/
}

// 窗口背景颜色
void test2()
{
	// 创建图形窗口时保留控制台窗口
	initgraph(800, 600, EX_SHOWCONSOLE);

	// 这个函数用于设置当前设备绘图背景色。
	// 白色
	//setbkcolor(WHITE);

	// 自定义颜色
	// ＃FFC0CB	rgb（255,192,203）
	//setbkcolor(0XFFC0CB);
	setbkcolor(RGB(255, 192, 203));

	// 此时还不会显示颜色
	// 需要
	// 这个函数使用当前背景色清空绘图设备。
	cleardevice();

	/*
		// Color constant // 颜色常数
		#define	BLACK			0
		#define	BLUE			0xAA0000
		#define	GREEN			0x00AA00
		#define	CYAN			0xAAAA00
		#define	RED				0x0000AA
		#define	MAGENTA			0xAA00AA
		#define	BROWN			0x0055AA
		#define	LIGHTGRAY		0xAAAAAA
		#define	DARKGRAY		0x555555
		#define	LIGHTBLUE		0xFF5555
		#define	LIGHTGREEN		0x55FF55
		#define	LIGHTCYAN		0xFFFF55
		#define	LIGHTRED		0x5555FF
		#define	LIGHTMAGENTA	0xFF55FF
		#define	YELLOW			0x55FFFF
		#define	WHITE			0xFFFFFF
	*/
}

// 窗口坐标体系
void test3()
{
	/*
		窗口左上角是坐标原点
		标题栏不算在坐标内

		|   +-------------+
		|   |window    -○×|
		|   +-------------+--→ X
		|   |             |
		|   |             |
		|   |             |
		|   |             |
		|   |             |
		|   +-------------+
		|   |
		|   ↓
		|   Y
	*/
}

int main()
{
	// 窗口创建
	//test1();

	// 窗口背景颜色
	test2();

	// 窗口坐标体系
	//test3();

	// 按任意键继续
	system("pause");

	return 0;
}