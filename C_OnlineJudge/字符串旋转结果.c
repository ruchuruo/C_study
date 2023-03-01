/*
	字符串旋转结果
		写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串

		例如：
			给定 s1 = AABCD 和 s2 = BCDAA，返回1
			给定 s1 = ABCD  和 s2 = ACBD， 返回0

		AABCD左旋一个字符得到ABCDA
		AABCD左旋两个字符得到BCDAA
		AABCD右旋一个字符得到DAABC

		———————————————————————————————————————————————————————————
		穷举

		判断arr1旋转后能否得到arr2

		将arr1旋转一个字符后和arr2比较

		旋转一次比较一次

		AABCD
		ABCDA != BCDAA
		BCDAA == BCDAA
		CDAAB != BCDAA
		DAABC != BCDAA
		AABCD != BCDAA

		———————————————————————————————————————————————————————————
		方法2

		在字符串AABCD后面追加一份自己
		AABCDAABCD

		这包含了以下所有可能性
		AABCD
		ABCDA
		BCDAA
		CDAAB
		DAABC

		用字符串BCDAA在AABCDAABCD里面找

*/
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

/**************************************************************************************************************************************************/

int 是旋转(char* str1, char* str2)
{
	int i = 0;
	int len = strlen(str1);// 求字符串长度
	for (i = 0; i < len; i++)
	{
		// 每次左旋一个字符

		// str指向的是字符串的起始位置，*str就是第一个字符
		char tmp = *str1;

		// 后面的n-1个字符往前移动
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(str1 + j) = *(str1 + j + 1);
		}

		// tmp放在最后
		*(str1 + len - 1) = tmp;

		// 判断字符串是否相等
		if (strcmp(str1, str2) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void 方法1()
{
	char arr1[] = "AABCD";
	char arr2[] = "BCDAA";

	int ret = 是旋转(arr1, arr2);

	if (ret == 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

/**************************************************************************************************************************************************/

int 是旋转2(char* str1, char* str2)
{
	// 长度不相等，肯定不是旋转得到的
	if (strlen(str1) != strlen(str2))
	{
		return 0;
	}
	// str1字符串后面追加一个str1，AABCDAABCD
	//strcat();// 库函数，可以追加字符串，strcat(数组名, "字符串")，但是不能追加自己
	//strncat();//库函数，可以追加字符串，strncat(数组名, 数组名, 追加字符个数)
	int len = strlen(str1);
	strncat(str1, str1, len);

	// 判断str2是否为str1的子串
	char* ret = strstr(str1, str2);// 库函数，判断一个字符串是否是另一个字符串的子串，找到返回字符串中首次出现子串的地址，找不到返回空指针

	//if (ret == NULL)
	//{
	//	return 0;
	//}
	//else
	//{
	//	return 1;
	//}
	return ret != NULL;// 条件为真返回1
}

void 方法2()
{
	char arr1[20] = "AABCD";// 给更大空间才能追加
	char arr2[] = "BCDAA";

	int ret = 是旋转2(arr1, arr2);

	if (ret == 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

/**************************************************************************************************************************************************/

int main()
{ 
	方法1();

	方法2();

	return 0;
}