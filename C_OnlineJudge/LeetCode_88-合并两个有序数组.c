
/*
	给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
	请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
	注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

	示例 1：
		输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
		输出：[1,2,2,3,5,6]
		解释：需要合并 [1,2,3] 和 [2,5,6] 。
		合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

	示例 2：
		输入：nums1 = [1], m = 1, nums2 = [], n = 0
		输出：[1]
		解释：需要合并 [1] 和 [] 。
		合并结果是 [1] 。

	示例 3：
		输入：nums1 = [0], m = 0, nums2 = [1], n = 1
		输出：[1]
		解释：需要合并的数组是 [] 和 [1] 。
		合并结果是 [1] 。
		注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

	提示：
		nums1.length == m + n
		nums2.length == n
		0 <= m, n <= 200
		1 <= m + n <= 200
		-109 <= nums1[i], nums2[j] <= 109

	进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？

	来源：力扣（LeetCode）
	链接：https://leetcode.cn/problems/merge-sorted-array
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	/*
		思路1：
			输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
			输出：[1,2,2,3,5,6]
			解释：需要合并 [1,2,3] 和 [2,5,6] 。
			合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

			创建临时数组
			先 nums1 和 nums2 的元素比较大小拷贝到 临时 数组
			再将 临时 数组的元素拷贝回 nums1

			空间复杂度O(N)

		思路2：
			输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
			输出：[1,2,2,3,5,6]
			解释：需要合并 [1,2,3] 和 [2,5,6] 。
			合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

			从 nums1 和 nums2 的最后位置开始

					   ↓
				[2][5][6]

					   ↓
				[1][2][3][ ][ ][ ]

			比大小，哪个元素大就放后面

					   ↓
				[2][5][6]

					   ↓
				[1][2][3][ ][ ][ ]

			6:3，6放最后，指向nums2元素的位置减减

					↓
				[2][5][6]

					   ↓
				[1][2][3][ ][ ][6]

			5:3，5放最后，指向nums2元素的位置减减

				 ↓
				[2][5][6]

					   ↓
				[1][2][3][ ][5][6]

			2:3，3放最后，指向nums1元素的位置减减

				 ↓
				[2][5][6]

					↓
				[1][2][3][3][5][6]

			2:2，2放，结束

				 ↓
				[2][5][6]

					↓
				[1][2][2][3][5][6]

			时间复杂度O(M+N)
			空间复杂度O(1)

			注意：
				如果 nums1 剩余数据，就结束，
				nums2 剩余数据，就拷贝到 nums1
	*/

	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;

	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}

	// 如果 nums2 剩余数据，就拷贝到 nums1
	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}
}

int main()
{
	int nums1[6] = { 1,2,3 };
	int nums2[3] = { 2,5,6 };
	int m = 3;
	int n = 3;
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
	merge(nums1, nums1Size, m, nums2, nums2Size, n);
	for (int i = 0; i < m + n; i++)
	{
		printf("%d ", nums1[i]);
	}

	return 0;
}