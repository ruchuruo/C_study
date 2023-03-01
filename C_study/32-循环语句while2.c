
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
					while(表达式)
					{
						循环语句;
					}

					在while循环中，break用于永久的终止循环
					在while循环中，continue跳过本次循环continue后面的代码，直接去判断部分
		........................................
				for
		........................................
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
	// getchar
	// scanf
	// 输入函数 是去缓冲区拿数据
	//
	char 密码[20] = { 0 };
	printf("请输入密码\n");

	// 数组的数组名本来就是地址，所以不用取地址
	// 以下程序有bug，
	//		假如输入密码123
	//		回车\n
	//		scanf拿走了123
	//		getchar拿走了\n
	//		确认失败
	//
	//scanf("%s", 密码);

	//printf("请确认密码(Y/N)\n");

	//int ch = getchar();
	//if (ch == 'Y')
	//{
	//	printf("确认成功\n");
	//}
	//else
	//{
	//	printf("确认失败\n");
	//}


	// 改进
	// 
	scanf("%s", 密码);

	printf("请确认密码(Y/N)\n");

	// 清理缓冲区 里的 \n,只读不存
	// getchar(); 如果密码是'123 abc' 读取一次不够
	int tmp = 0;
	while ((tmp = getchar()) != '\n')
	{
		;
	}

	int ch = getchar();
	if (ch == 'Y')
	{
		printf("确认成功\n");
	}
	else
	{
		printf("确认失败\n");
	}

	// getchar读取的是一个字符为什么用int整形变量来存？
	// 因为getchar返回类型就是int
	// getchar读取的是字符 而字符本身是ASCII码值形式存储的 ASCII是整形
	// getchar读取的时候不一定返回的是ASCII码值 有可能返回EOF EOF本质上是一个-1
	//

	return 0;
}