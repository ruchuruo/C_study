


/*
	c语音是结构化的程序设计语言
		顺序结构

		++++++++++++++++++++++++++++++++++++++++

		选择结构
			分支语句
				if
					// 单分支
					if(表达式)
					{
						语句;
					};

					// 双分支
					if(表达式)
					{
						语句1;
					}else{
						语句2;
					}

					// 多分支
					if(表达式)
					{
						语句1;
					}else if(表达式2){
						语句2;
					}else{
						语句3;
					}

				非0就是真：-1
				0  就是假

		........................................
				switch(翻译：开关)

		++++++++++++++++++++++++++++++++++++++++
		循环结构
			循环语句
				while
				for
				do while


	goto语句



	什么是语句？
		c语言中由一个分号;隔开的就是一条语句 比如：
			printf("hello");
			1 + 2;
			;// 空语句
		
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	//选择结构
	//	分支语句
	//	if
	int 年龄 = 0;
	printf("请输入年龄\n");
	scanf("%d", &年龄);
	if (年龄 < 18)
	{
		printf("少年\n");
	}
	else if(年龄 >= 18 && 年龄 < 26)
	{
		printf("青年\n");
	}
	else if(年龄 >= 26 && 年龄 < 40)
	{
		printf("中年\n");
	}
	else if (年龄 >= 40 && 年龄 < 60)
	{
		printf("壮年\n");
	}
	else
	{
		printf("老年\n");
	}

	// 悬空else	不打印
	// else和最近的if匹配
	int a = 0;
	int b = 2;
	if (a == 1)
		if (b == 2)
			printf("呵呵");
		else
			printf("哈哈");


	// 好的书写习惯
	int num = 3;
	// 常量放在左边，如果写成 5 = num 的时候编译报错
	if (5 == num)
	{
		printf("hehe\n");
	}


	// 练习
	// 1.判断一个数是否为奇数
	int 数 = 15;
	if (数 % 2 == 1)
	{
		printf("奇数\n");
	}


	// 2.输出1-100之间的奇数
	int i = 0;// 初始化
	while (i < 100)// 判断部分
	{
		i++;// 调整部分

		if (i % 2 == 1)
		{
			printf("%d\n", i);
		}
	}
	// C++ 和 C99支持这样写，声明变量在括号里面
	// for(int i = 1; i < 100; i++)
	//
	//还可以不用判断
	// for(int i = 1; i < 100; i+=2)
	

	return 0;
}