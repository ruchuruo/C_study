
/*
	66. 加一 https://leetcode.cn/problems/plus-one/

	给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

	最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

	你可以假设除了整数 0 之外，这个整数不会以零开头。

	示例 1：
		输入：digits = [1,2,3]
		输出：[1,2,4]
		解释：输入数组表示数字 123。

	示例 2：
		输入：digits = [4,3,2,1]
		输出：[4,3,2,2]
		解释：输入数组表示数字 4321。

	示例 3：
		输入：digits = [0]
		输出：[1]

	提示：
		1 <= digits.length <= 100
		0 <= digits[i] <= 9
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    /*
        思路1：
            从数组尾开始找9

                       ↓
                [8][9][9]

            如果是9，将9变成0，继续往前找

                       ↓
                [8][9][0]

                    ↓
                [8][0][0]

            如果不是9，将加一

                 ↓
                [9][0][0]

            最后返回

            -------- --------

            另一情况，数组都是9
            从数组尾开始找9

                       ↓
                [9][9][9]

            如果是9，将9变成0，继续往前找

                      ↓
                [9][9][0]

                 ↓
                [0][0][0]

            如果数组首元素是0，申请内存，大小是 原数组长度+1

                [ ][ ][ ][ ]

            将新数组首元素变成1

                [1][ ][ ][ ]

            再将 原数组 的元素 拷贝到 新数组

                   [0][0][0]
                    ↓  ↓  ↓
                [1][ ][ ][ ]

            返回新数组
    */

    // 从数组尾开始找9
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        // 如果是9，将9变成0，继续往前找
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else// 如果不是9，将加一
        {
            digits[i] += 1;
            *returnSize = digitsSize;
            return digits;
        }
    }

    // 走到这里说明，数组首元素是0，申请内存，大小是 原数组长度+1
    int* ret = malloc(sizeof(int) * (digitsSize + 1));

    // 将新数组首元素变成1
    ret[0] = 1;

    // 再将 原数组 的元素 拷贝到 新数组
    for (int j = 1; j <= digitsSize; j++)
    {
        ret[j] = digits[j - 1];
    }

    *returnSize = digitsSize + 1;
    return ret;
}

int main()
{
	int arr[] = { 1,2,3 };
	int arr2[] = { 8,9,9 };
	int arr3[] = { 0 };

	int* ret = plusOne(arr3, 1, NULL);

	return 0;
}