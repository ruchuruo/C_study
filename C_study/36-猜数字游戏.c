

/*
	猜数字游戏
		1.自动产生一个1-100之间的随机数
		2.猜数字
			猜对，就恭喜，游戏结束
			猜错，告诉猜大了还是小了，并继续猜
		3.游戏可以一直完，除非退出游戏


	rand函数返回了一个0-32767之间的数字
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// rand函数需要
#include <stdlib.h>

//time函数需要
#include <time.h>





void 菜单()
{
	printf("******** ******** ******** ******** ********\n");
	printf("******** ********  1.开始  ******** ********\n");
	printf("******** ********  0.退出  ******** ********\n");
	printf("******** ******** ******** ******** ********\n");
}

// 猜数字游戏过程
void 游戏()
{
	// 1.先生成随机数
	int ret = rand() % 100 + 1;//%100的余数是0-99，然后+1，范围就是1-100

	//printf("%d\n", ret);



	// 2.猜数字
	int 猜测 = 0;
	while (1)
	{
		printf("请猜数字>");
		scanf("%d", &猜测);

		if (猜测 < ret)
		{
			printf("猜小了\n");
		}
		else if(猜测 > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}








int main()
{
	int 输入 = 0;

	// 设置随机数起点
	// srand(要随机值)
	// 时间是变化的 - 时间戳
	//srand(1000);
	// time()里面本来有参数的，但是我们不想用它的参数，所以传个 空null 进去..不需要使用time（）函数里的参数，所以参数填为NULL
	// 强制转换成unsigned类型,unsigned就是srand需要的值
	// 只需要开始游戏前设置一次,不需要频繁设置，在rand()前
	srand((unsigned int)time(NULL));

	do
	{
		菜单();
		printf("请选择>");
		scanf("%d", &输入);
		switch (输入)
		{
			case 1:
				printf("猜数字\n");
				游戏();
				break;

			case 0:
				printf("退出游戏\n");
				break;

			default:
				printf("请输入数字选择\n");
				break;
		}
	} while (输入);












	return 0;
}