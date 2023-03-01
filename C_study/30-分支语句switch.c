
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
					switch语句也是一种分支语句。常常用于多分支的情况
					比如：
						输入1，输出星期一
						输入2，输出星期二
						输入3，输出星期三
						输入4，输出星期四
						输入5，输出星期五
					写成if....else形式太复杂

					switch(整形常量表达式)
					{
						语句项;
					}

					// 语句项
					// 是一些case语句:
					// 如下:
					case 整形常量表达式:
						语句;

					default 子句
						如果表达的值与所有的case标签的值都不匹配，就会执行default下的语句


					Switch没有顺序
					Switch允许嵌套使用

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
	int 天 = 0;
	printf("请输入天数\n");
	scanf("%d", &天);
	switch (天)
	{
		case 1://case("入口")
			printf("星期一\n");
			break;//break("出口")
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
	}


	// 1-5 工作日
	// 6-7 休息日
	int 天2 = 0;
	printf("输入天数\n");
	scanf("%d", &天2);
	switch (天2)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			printf("工作日");
			break;

		case 6:
		case 7:
			printf("休息日");
			break;

		default:
			printf("输入错误\n");
			break;
	}


	return 0;
}