/*


*/
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main()
{
	//// 函数

	//printf("输入\n");

	//int num1 = 0;
	//int num2 = 0;

	//scanf("%d%d", &num1, &num2);

	//// int sum = num1 + num2;
	//// 函数的方式解决
	//int sum = Add(num1, num2);

	//printf("%d\n", sum);









	// 数组 - 一组相同类型的元素的集合
	// 10个整形1-10存起来
	// 数组名字[10个] = {}
	// 数组是用下标来访问的
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	char ch[5] = { 'a','b','c' };// 不完全初始化 剩余的默认为0

	int i = 0;
	while (i < 10)
	{
		printf("%d", arr[i]);
		i++;
	}

	return 0;
}

/*
	创建数组只能用常量
	C99标准中引入了一个概念：变长数组
		支持数组创建的时候，用变量指定大小，但是这个数组不能初始化
*/
