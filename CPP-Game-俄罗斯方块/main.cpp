
/*
	https://blog.csdn.net/pzjdoytt/article/details/125325753

	开发日志

		1.创建项目
		2.导入素材
		3.c++开发
		4.设计c++项目的模块
		  设计类(方块类、游戏类)

		5.设计接口
		6.启动游戏

宽800*高600

P8
8-实现游戏场景
26:50
*/

#include "Tetris-游戏类.h"
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));

	//Tetris t
	//	(
	//		20,// 行
	//		10,// 列
	//		10,// 上边界距离
	//		10,// 下边界距离
	//		10,// 左边界距离
	//		10,// 右边界距离
	//		78,// 方块大小
	//		30 // 渲染延时
	//	);

	Tetris t
		(
			20,// 行
			10,// 列
			10,// 上边界距离
			10,// 下边界距离
			10,// 左边界距离
			10,// 右边界距离
			78,// 方块大小
			500 // 渲染延时
		);

	t.play();

	return 0;
}