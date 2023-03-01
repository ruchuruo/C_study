
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				printf("i = %d, j = %d\n", i, j);

				//int* ret = malloc(sizeof(int) * 2);
				//ret[0] = i, ret[1] = j;
				//*returnSize = 2;
				//return ret;
			}
		}
	}

	//*returnSize = 0;
	//return NULL;
}

int main()
{
	// 1. 两数之和 https://leetcode.cn/problems/two-sum/
	//int arr[] = { 3,2,4 };
	int arr[] = { 2,5,5,11 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//int target = 6;
	int target = 10;
	twoSum(arr, sz, target, NULL);

	return 0;
}