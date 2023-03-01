/*
	字符串左旋
		实现一个函数，可以左旋字符串中的K个字符

		例如：
			ABCD左旋一个字符得到BCDA
			ABCD左旋两个字符得到CDAB

		—————————————————————————————————————
		左旋一个字符 方法1
		[A][B][C][D][E][F]

		拿出一个字符的空间，将A放到这个空间内
		[ ][B][C][D][E][F]
		 ↓
		[A]
		-------------------------------------
		将后面的元素一个个的往前移动
		[B][C][D][E][F][ ]

		[A]
		-------------------------------------
		再将A放到最后一个位置
		[B][C][D][E][F][A]
		                ↑
		               [A]
		—————————————————————————————————————
		左旋一个字符 方法2
		[A][B][C][D][E][F]

		将要旋转的两个字符看成一个整体
		[A][B]   [C][D][E][F]

		逆序左边
		[B][A]   [C][D][E][F]

		逆序右边
		[B][A]   [F][E][D][C]

		最后整体逆序
		[C][D][E][F][A][B]
		-------------------------------------
		三次逆序
		写上一个逆序函数调用三次
		—————————————————————————————————————
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

/**************************************************************************************************************************************************/

void 左旋(char* str, int k)
{
	int i = 0;
	int len = strlen(str);// 求字符串长度
	for (i = 0; i < k; i++)
	{
		// 每次左旋一个字符

		// str指向的是字符串的起始位置，*str就是第一个字符
		char tmp = *str;
		
		// 后面的n-1个字符往前移动
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(str + j) = *(str + j + 1);
		}

		// tmp放在最后
		*(str + len - 1) = tmp;
	}
}

void 方法1()
{
	char arr[10] = "ABCDEF";
	//char* p = "ABCDEF";// 不能使用常量字符串，因为不能修改
	int k = 2;
	左旋(arr, k);
	printf("%s\n", arr);
}

/**************************************************************************************************************************************************/

void 逆序(char* 左, char* 右)// 左边起始地址，右边结束地址
{
	assert(左);
	assert(右);
	while (左 < 右)
	{
		char tmp = *左;
		*左 = *右;
		*右 = tmp;
		左++;
		右--;
	}
}

void 左旋2(char* str, int k)
{
	assert(str);

	int len = strlen(str);

	逆序(str, str + k - 1);// 左
	逆序(str + k, str + len - 1);// 右
	逆序(str, str + len - 1);// 整体
}

void 方法2()
{
	char arr[10] = "ABCDEF";
	//char* p = "ABCDEF";// 不能使用常量字符串，因为不能修改
	int k = 2;
	左旋2(arr, k);
	printf("%s\n", arr);
}

/**************************************************************************************************************************************************/

int main()
{
	方法1();

	方法2();

	return 0;
}