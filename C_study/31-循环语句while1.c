
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
	int i = 1;
	// 在while循环中，break用于永久的终止循环
	while (i <= 10)
	{
		if (i == 5)
		{
			break;
		}
		printf("%d\n", i);
		i++;
	}

	// 在while循环中，continue跳过本次循环continue后面的代码，直接去判断部分
	//while (i <= 10)
	//{
	//	if (i == 5)
	//	{
	//		continue;// 继续
	//	}
	//	printf("%d\n", i);
	//	i++;
	//}


	// getchar
	// 获取 字符 get char
	// stdin(getchar,getwchar)
	// 标准输入 - 键盘
	//int ch = getchar();

	////printf("%c\n", ch);

	//// 输出 一个字符
	//putchar(ch);




	// EOF - end of file - 文件结束标志




	int cha = 0;
	// ctrl+z - getchar就读取结束
	while ((cha = getchar()) != EOF)
	{
		putchar(cha);
	}

	/*
	*				缓冲区
			     ...........
				 .a/n	   .
		 getchar .		   .	键盘 
				 .		   .		输入a然后回车,
				 ...........		就相当于输入了a和\n
									然后
										获取a
										输出a
										获取\n
										输出\n

	*/
	
	return 0;
}