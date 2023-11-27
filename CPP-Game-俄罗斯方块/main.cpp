
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

P5
5-创建方块的图像纹理
22:08
*/

#include "Tetris-游戏类.h"
#include <stdlib.h>
#include <time.h>

int main(void)
{
	//srand(time(NULL));

	Tetris t(20, 10, 10, 10, 10, 10, 78, 30);

	t.play();

	return 0;
}