


/*
	字符串
		就是一串字符-用双引号括起来的一串字符

		字符串在结尾的位置隐藏了一个\0的字符
		\0是字符串的结束标志

		字符串的结束标志是一个\0的转义字符，在计算字符串长度的时候\0是结束标志，不算做字符串内容
*/
#include <stdio.h>
#include <string.h>

int main()
{
	// 字符数组 - 数组是一组相同类型的元素
	char arr[] = "abcd";
	char arr1[] = "abc";
	char arr2[] = { 'a', 'b', 'c', '\0'};

	// 打印字符串
	printf("%s\n", arr1);
	printf("%s\n", arr2);

	// 字符串长度
	// : warning C4013: “strlen”未定义； 没有引用头文件#include <string.h>
	int len = strlen("abc");// string length
	printf("%d\n", len);

	printf("%d\n", strlen(arr1));
	printf("%d\n", strlen(arr2));

	return 0;
}