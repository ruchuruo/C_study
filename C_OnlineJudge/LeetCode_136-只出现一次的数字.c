
/*
	136. 只出现一次的数字 https://leetcode.cn/problems/single-number/

	难度：简单

		给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

		你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

 
		示例 1 ：
			输入：nums = [2,2,1]
			输出：1

		示例 2 ：
			输入：nums = [4,1,2,1,2]
			输出：4

		示例 3 ：
			输入：nums = [1]
			输出：1


		提示：
			1 <= nums.length <= 3 * 104
			-3 * 104 <= nums[i] <= 3 * 104
			除了某个元素只出现一次以外，其余每个元素均出现两次。
*/
/*
    思路：
        暴力查找 两次循环

        内循环如果找到相同的数字 count++

        内循环结束后查看是否有 count 为 1 的数字
*/

#include <stdio.h>

int singleNumber(int* nums, int numsSize)
{
    if (nums == NULL)
    {
        return;
    }

    // 暴力查找 两次循环
    int i = 0;
    int j = 0;
    int count = 0;// 计数器

    for (i = 0; i < numsSize; i++)
    {
        count = 0;

        for (j = 0; j < numsSize; j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }

        printf("%d\n", count);

        if (count == 1)
        {
            printf("找到 %d\n", nums[i]);

            return nums[i];
        }
    }

    return 666;
}

int main()
{

    return 0;
}