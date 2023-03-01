
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
	// 是否是空字符
	if (strsSize == 0)
	{
		return "";
	}

	//分配128个字节的内存，来存储公共前缀
	char* str = (char*)calloc(128, sizeof(char));

	// 最长公共前缀不会超过第一个字符串，*strs 解引用找到第一个字符串，并计算长度
	int i = 0;
	int j = 0;
	for (i = 0; i < strlen(*strs); i++)// 外循环，找到字母
	{
		// 内循环，找到字符串
		for (j = 0; j < strsSize - 1; j++)
		{
			// 常量字符串末尾默认添加'\0'，判断到'\0'就无了
			if (strs[j][i] != strs[j + 1][i])
			{
				return str;
			}
		}

		//一次内循环结束，判断通过，将通过的字符存入str
		str[i] = strs[j][i];
	}

	return str;
}

char* longestCommonPrefix2(char** strs, int strsSize)
{
	//输入可能为空，如果答案消耗时间很短的话，很有可能输入的是空字符
	if (strsSize == 0)
	{
		return "";
	}

	//分配128个字节的内存，来存储公共前缀
	char* str = (char*)calloc(128, sizeof(char));

	//外循环，以第一个字符串的长度为循环次数，因为最长公共前缀的长度小于等于它
	for (int i = 0, j; i < strlen(*strs); i++)
	{
		//内循环，以字符串个数为循环次数，减1的原因是因为循环内有j+1，不减的话，会发生内存越界
		for (j = 0; j < strsSize - 1; j++)
		{
			//如果下一个字符串的i位不等于当前字符串的i位，说明循环结束，i-1位是最长公共前缀的最后一个字符
			if (strs[j][i] != strs[j + 1][i])
			{
				return str;
			}
		}

		//一次内循环结束，说明当前字符这一轮判断通过了，将通过的字符存入str   
		str[i] = strs[j][i];
	}

	return str;
}

int main()
{
	// 14. 最长公共前缀
	//char *strs[] = { "flower","flow","flight" };
	//char* strs[] = { "aflower","bflow","cflight" };
	//char* strs[] = { "abcdefg","abcd","abcd" };
	//char* strs[] = { "abcdefg","abcdefg","abcdefg" };
	char* strs[] = { "abcdefg","abcd","abcd","abcd","abcd","abcd" };

	int sz = sizeof(strs) / sizeof(strs[0]);

	char* ret = longestCommonPrefix(&strs, sz);
	printf("%s\n", ret);
	free(ret);
	ret = NULL;

	char* ret = longestCommonPrefix2(&strs, sz);
	printf("%s\n", ret);
	free(ret);
	ret = NULL;

	return 0;
}