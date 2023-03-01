
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
						初始化	判断		调整
					for(表达式; 表达式2; 表达式3)
					{
						循环语句;
					}

					一些建议
						1.不可在for循环体内修改循环变量，防止for循环失去控制
						2.建议for语句的循环控制变量的取值采用"前闭后开区间"写法
		........................................
				do while
					do
					{
						循环语句;
					} while (表达式);

					先执行再判断
		========================================

	goto语句



	什么是语句？
		c语言中由一个分号;隔开的就是一条语句 比如：
			printf("hello");
			1 + 2;
			;// 空语句

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
	//int i = 1;
	//do
	//{
	//	if (i == 5)
	//	{
	//		break;
	//	}
	//	printf("%d\n", i);
	//	i++;
	//} while (i < 10);



	//// 练习
	//// 1.计算n的阶乘
	//// 
	//// 产生1 - n的数字
	//int a = 0;
	//int b = 0;
	//int ret = 1;
	//printf("阶乘-输入数字:");
	//scanf("%d", &b);

	//for (a = 1; a <= b; a++)
	//{
	//	ret = ret * a;
	//	printf("%d\n", ret);
	//}
	//printf("%d\n", ret);




	//// 2.计算 1!+2!+3!+......+10!
	//// 
	//int a1 = 0;
	//int b1 = 0;
	//int c1 = 1;
	//int 和 = 0;
	//printf("阶乘相加-输入数字:");
	////scanf("%d", &d);

	////for (b1 = 1; b1 <= 3; b1++)
	////{
	////	// 计算c1阶乘之前，吧c1初始为1
	////	c1 = 1;
	////	for (a1 = 1; a1 <= b1; a1++)
	////	{
	////		c1 = c1 * a1;
	////	}
	////	和 = 和 + c1;
	////}
	////printf("%d\n", 和);

	//// 优化
	//for (b1 = 1; b1 <= 3; b1++)
	//{
	//	c1 = c1 * b1;
	//	和 = 和 + c1;
	//}
	//printf("%d\n", 和);









	// 3.在一个有序数组中查找具体的某个数字n。编写int binsearch(int x, int v[], int n);功能：在v[] <= v[1] <= v[2] <=...<= v[n-1]的数组中查找x
	// 假如 1 2 3 4 5 6 7 8 9 10 中找 7
	// 二分查找
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;//要查找的数字

	// 在arr这个有序数组中查找k的值

	//计算数组元素个数
	int sz = sizeof(arr) / sizeof(arr[0]);
	// 确定左下标
	int left = 0;
	// 确定右下标
	int right = sz - 1;

	// 找到数组平均值的下标
	//arr[mid]


	while (left <= right)
	{
		// 计算数组下标平均值
		int mid = (left + right) / 2;

		// 比较 小右大左
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到：%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到\n");
	}






	// 4.编写代码，演示多个字符从两端移动，向中间汇聚
	// welcome to bit!!!!!!
	// w..................!
	// we................!!
	// wel..............!!!
	char arr1[] = "welcome to bit!!!!!!";
	char arr2[] = "....................";
	int left2 = 0;
	int right2 = strlen(arr1) - 1;

	while (left2 <= right2)
	{
		arr2[left2] = arr1[left2];
		arr2[right2] = arr1[right2];

		printf("%s\n", arr2);
		Sleep(100);// 间隔
		system("cls");// 清空屏幕

		left2++;
		right2--;
	}
	printf("%s\n", arr2);










	// 5.编写代码实现，模拟用户登录情景，并且只能登录3次。(只允许输入3次密码，如果密码错误3次退出程序)
	int z = 0;
	char password[20] = { 0 };
	// 假设正确的密码是字符串"123456"

	for (z = 0; z < 3; z++)
	{
		printf("请输入密码:");
		scanf("%s", password);

		// 两个字符串比较不能使用==，应该使用strcmp
		if (strcmp(password,"123456") == 0)
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
	}


	if (z == 3)
	{
		printf("退出程序\n");
	}





	return 0;
}