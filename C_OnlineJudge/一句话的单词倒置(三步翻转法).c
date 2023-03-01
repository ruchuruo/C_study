/*
	题目描述
		将一句话的单词进行倒置，标点不倒置，比如i like beijing. 经过函数后变为：beijing. like i

	输入描述
		每个测试输入包含一个测试用例：i like beijing. 输入用例长度不超过100

	输出描述
		依次输出倒置之后的字符串，以空格分割

*/

#include <stdio.h>
#include <string.h>

void 翻转(char* left, char* right)
{
	while (left < right)
	{
		char tmp = 0;
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[100] = { 0 };

	//输入
	gets(arr);

	//三步翻转法
	//1.字符串整体翻转
	//.gnijieb ekil i
	int len = strlen(arr);
	翻转(arr, arr + len - 1);
	


	// 2.每个单词逆序
	// beijing. like i
	char* start = arr;
	while (*start)// 不是\0继续
	{
		char* end = start;
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		// 逆序一个单词
		翻转(start, end - 1);

		if (*end == ' ')
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}

	printf("%s\n", arr);

	return 0;
}