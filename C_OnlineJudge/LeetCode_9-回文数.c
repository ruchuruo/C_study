
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

_Bool isPalindrome(int x)
{
	// 负数直接不是
	if (x < 0)
	{
		printf("不是回文数\n");
		return;
	}

	int tmp = 0;
	int 计数器 = 0;

	// 计算位数
	tmp = x;
	while (tmp)
	{
		tmp /= 10;
		计数器++;
	}

	// 申请空间
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int) * 计数器);
	if (arr == NULL)
	{
		return;
	}


	// 输入到 空间
	tmp = x;
	for (int i = 0; tmp; i++)
	{
		//printf("%d\n", tmp % 10);	//每次输出个位
		//tmp /= 10;					//缩小10倍，去除原来的个位。

		arr[i] = tmp % 10;
		tmp /= 10;
		printf("%d ", arr[i]);
	}


	// 比较
	int left = 0;
	int right = 计数器 - 1;

	for (int i = 0; i < 计数器; i++)
	{
		// 最左边下标 和 最右边下标 比较
		if (left < right)
		{
			// 开始比较
			if (arr[left] != arr[right])
			{
				printf("不是回文数\n");
				return;
			}
		}

		left++;
		right--;
	}

	printf("是回文数\n");


	// 释放
	free(arr);
	arr = NULL;
}

_Bool isPalindrome_2(int x)
{
	// 力扣官方题解

	// 特殊情况：
	// 如上所述，当 x < 0 时，x 不是回文数。
	// 同样地，如果数字的最后一位是 0，为了使该数字为回文，
	// 则其第一位数字也应该是 0
	// 只有 0 满足这一属性
	if (x < 0 || (x % 10 == 0 && x != 0)) {
		return 0;
	}

	int revertedNumber = 0;
	while (x > revertedNumber) {
		revertedNumber = revertedNumber * 10 + x % 10;
		x /= 10;
	}

	// 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
	// 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
	// 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
	return x == revertedNumber || x == revertedNumber / 10;
}

int main()
{
	// 9. 回文数 https://leetcode.cn/problems/palindrome-number/
	isPalindrome(1112111);
	isPalindrome_2(1112111);

	return 0;
}