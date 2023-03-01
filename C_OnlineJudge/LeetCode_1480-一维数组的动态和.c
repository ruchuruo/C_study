
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int* runningSum(int* nums, int numsSize, int* returnSize)
{
	assert(nums != NULL);

	//*returnSize = numsSize;

	int i = 1;
	for (i = 1; i < numsSize; i++)
	{
		nums[i] = nums[i] + nums[i - 1];
	}

	for (i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}

	return nums;
}

int main()
{
	// 1480. 一维数组的动态和 https://leetcode.cn/problems/fizz-buzz/
	int arr[] = { 1,1,1,1,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	runningSum(arr, sz, NULL);

	return 0;
}