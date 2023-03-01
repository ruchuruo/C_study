
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

_Bool canConstruct(char* ransomNote, char* magazine)
{
	/*
		暴力查找

		ransomNote[0] 位置的值去比较 magazine[0] 到 magazine[n] 位置的值
		ransomNote[1] 位置的值去比较 magazine[0] 到 magazine[n] 位置的值
		ransomNote[2] 位置的值去比较 magazine[0] 到 magazine[n] 位置的值
		......
		ransomNote[n] 位置的值去比较 magazine[0] 到 magazine[n] 位置的值

		如果找到了，就将 magazine[n] 位置的值替换成 '1'，避免重复，计数器++
	*/

	int n = strlen(ransomNote);
	int m = strlen(magazine);

	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (ransomNote[i] == magazine[j])
			{
				magazine[j] = '1';
				k++;
				break;
			}
		}
	}

	if (k == n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	// 383. 赎金信 https://leetcode.cn/problems/fizz-buzz/
	char ransomNote[] = "abc";
	char magazine[] = "dddcba";
	int ret = canConstruct(ransomNote, magazine);
	if (ret == 1)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}

	return 0;
}