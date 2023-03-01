

/*
	数组
		1.一维数组的创建和初始化
		2.一维数组的使用
		3.一维数组在内存中的存储

		4.二维数组的创建和初始化
		5.二维数组的使用
		6.二维数组在内存中的存储

		7.数组作为函数参数
		8.数组的应用实例1：三子棋
		9.数组的应用实例2：扫雷游戏

		==================================================

		1.一维数组的创建和初始化

			数组的创建
				数组是一组相同类型元素的集合。数组的创建方式：

					元素类型		数组名字		[数组大小];
					type_t		arr_name	[const_n];
					// const_n 是一个常量表达式，用来指定数组的大小

					int arr[8];
					char ch[5];

					C99语法支持 变长数组 - 数组的大小是变量
					int n = 8;
					int arr[n];

			数组的初始化
				数组的初始化是指，在创建数组的同时给数组的内容一些合理初始值(初始化)

					完全初始化
					int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

					不完全初始化
					int arr[10] = { 1,2,3,4,5 };

					不指定数组大小初始化，会根据元素个数确定数组大小
					int arr[] = { 1,2,3,4,5 };	等价于	int arr[5] = { 1,2,3,4,5 };

					字符数组初始化
					char ch1[5] = { 'a', 'b', 'c' };
					char ch2[] = { 'a', 'b', 'c' };

					char ch3[5] = "abc";// a b c \0 0
					char ch4[] = "abc";// a b c \0

					以下数组有区别，ch6后面找到\0才停止打印
					char ch5[] = "abc";// 4个元素
					char ch6[] = { 'a', 'b', 'c' };// 3个元素
					printf("%s\n", ch5); // abc
					printf("%s\n", ch6); // abc烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫虜愹利

					字符数组才有\0
					字符数组不完全初始化后面补\0

		--------------------------------------------------

		2.一维数组的使用
			对于数组的使用，操作符：[]，下标引用操作符。它其实就是数组访问的操作符

			数组是使用下标来访问的，下标从0开始

			数组大小可以通过计算得到
			int sz = sizeof(arr) / sizeof(arr[0]);

		--------------------------------------------------

		3.一维数组在内存中的存储
			一维数组在内存中是连续存放的
			随着数组下标的增长，地址是由低到高变化的

				int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
				int* p = arr2;// 数组名是数组首元素的地址，所以可以放到一个指针变量里
				int i2 = 0;
				for (i2 = 0; i2 < 10; i2++)
				{
					printf("%d ", *p);
					p++;
				}

			数组名不是指针，只是编译器会把数组名隐式转换为一个指向数组首元素的指针处理

		--------------------------------------------------

		4.二维数组的创建和初始化

			数组的创建
				//	   3行 4列
				int arr[3][4];
				char arr[3][5];
				double arr[2][4];

						 4
					[] [] [] []
				3	[] [] [] []
					[] [] [] []

			数组的初始化
				创建的同时给赋值
				int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
										[1] [2 ] [3 ] [4 ]
										[5] [6 ] [7 ] [8 ]
										[9] [10] [11] [12]

				不完全初始化 - 后面补0
				int arr[3][4] = { 1,2,3,4,5 };

				可以看做是3行一维数组
				int arr[3][4] = { {1,2}, {3,4}, {5,6} };
										[1] [2] [] []
										[3] [4] [] []
										[5] [6] [] []

				二维数组初始化 行 可以省略

		--------------------------------------------------

		5.二维数组的使用
			二维数组的使用也是通过下标的方式
				//	   3行 4列
				int arr[3][4] = { {1,2}, {3,4}, {5,6} };

				int x = 0;
				int y = 0;
				for (x = 0; x < 3; x++)
				{
					for (y = 0; y < 4; y++)
					{
						printf("%d ", arr[x][y]);
					}
					printf("\n");
				}

		--------------------------------------------------

		6.二维数组在内存中的存储
			二维数组在内存中也是连续存放的
			一行内部连续，跨行也是连续的
			所以列不能省略，不然不知道下一个元素放哪
				//	   3行 4列
				int arr[3][4] = { {1,2}, {3,4}, {5,6} };

				int x = 0;
				int y = 0;
				for (x = 0; x < 3; x++)
				{
					for (y = 0; y < 4; y++)
					{
						printf("&arr[%d][%d] = %p\n",x, y, &arr[x][y]);
					}
					printf("\n");
				}

				[] [] [] [] [] [] [] [] [] [] [] []



			指针访问
				int arr[3][4] = { {1,2}, {3,4}, {5,6} };
				int x = 0;
				int y = 0;
				int* p = &arr[0][0];

				for (x = 0; x < 12; x++)
				{
					printf("%d ", *p);
					// 指针变量*p，指针的p是存储的指向的地址，p++就是指向p的下一个地址，，带上*是可以操作修改这个地址里面的内容
					p++;
				}

		--------------------------------------------------


*/

/*
		7.数组作为函数参数
			往往写代码的时候，会将数组作为参数传个函数，比如：我要实现一个冒泡排序 函数将一个整形数组排序。
				冒泡排序
					两两相邻的元素进行比较，并且可能的话需要交换

					最大的数或最小的数像水里的泡泡一样升上去
					9 8 7 6 5 4 3 2 1 0
					8 9 7 6 5 4 3 2 1 0
					8 7 9 6 5 4 3 2 1 0
					8 7 6 9 5 4 3 2 1 0
					8 7 6 5 9 4 3 2 1 0			一趟冒泡排序
					8 7 6 5 4 9 3 2 1 0
					8 7 6 5 4 3 9 2 1 0
					8 7 6 5 4 3 2 9 1 0
					8 7 6 5 4 3 2 1 9 0
					8 7 6 5 4 3 2 1 0 9

					8 7 6 5 4 3 2 1 0 | 9
					7 8 6 5 4 3 2 1 0 | 9
					7 6 8 5 4 3 2 1 0 | 9
					7 6 5 8 4 3 2 1 0 | 9
					7 6 5 4 8 3 2 1 0 | 9		二趟
					7 6 5 4 3 8 2 1 0 | 9
					7 6 5 4 3 2 8 1 0 | 9
					7 6 5 4 3 2 1 8 0 | 9
					7 6 5 4 3 2 1 0 8 | 9

					10个数字 - 9趟
					n		  n - 1

					1趟
						10个数字待排序	9对比较

					2趟
						9个数字待排序	8对比较


		==================================================

		数组名就是首元素地址
			但是有两个例外
				1.sizeof(数组名) - 数组名表示整个数组 - 计算的是整个数组的大小 单位是字节
				2.&数组名 - 数组名表示整个数组 - 取出的是整个数组的地址

		数组的地址就是数组首元素地址



		数组作为函数传参的时候 形参可以写成两种形式
			1.数组形式
			2.指针形式

			int arr[10]
			char ch[3][5]

			数组形式
				test1(arr);
				void test1(int arr[10]){}
				void test1(int arr[]){}

				test2(ch);
				void test2(ch ch[3][5]){}
				void test2(ch ch[][5]){}
				
			指针形式
				test1(arr);
				void test1(int *arr){}

				test2(ch);
				// 暂时不考虑

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void 泡泡(int arr[], int sz)// 形参arr本质是指针
{


	// 确定趟数
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		// 一趟冒泡排序的过程
		int j = 0;
		for (j = 0; j < sz-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };

	// 计算数组元素个数
	int sz = sizeof(arr) / sizeof(arr[0]);

	// 排序为升序 - 冒泡排序
	泡泡(arr, sz);// 数组传参的时候，传递的是首元素地址，数组名就是首元素地址


	return 0;
}