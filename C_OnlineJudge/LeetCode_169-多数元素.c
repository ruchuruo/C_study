
/*
	169. 多数元素 https://leetcode.cn/problems/majority-element/

	难度：简单

		给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ( n/2 ) 的元素。

		你可以假设数组是非空的，并且给定的数组总是存在多数元素。


		示例 1：
			输入：nums = [3,2,3]
			输出：3

		示例 2：
			输入：nums = [2,2,1,1,1,2,2]
			输出：2


		提示：
			n == nums.length
			1 <= n <= 5 * 104
			-109 <= nums[i] <= 109


		进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
*/
/*
	思路：
		将 nums 的元素放到 顺序表 中查找
		找不到 就添加到 顺序表
		找到 就将这个 nums 的元素在 顺序表 内出现的次数++

		最后 打擂台 找出出现次数最多的元素
*/

#include <stdio.h>
#include <stdlib.h>

struct element
{
	int m_Val;// 值
	int m_Num;// 次数
};

struct SeqList
{
	struct element* m_ElmArr;
	int m_Size;
	int m_Capacity;
};



void SeqListInit(struct SeqList* psl);                  // 顺序表初始化
void SeqListPushBack(struct SeqList* psl, int x);       // 顺序表尾插
struct element* SeqListFind(struct SeqList* psl, int x);// 顺序表查找

// 顺序表初始化
void SeqListInit(struct SeqList* psl)
{
	psl->m_ElmArr = (struct element*)malloc(sizeof(struct element) * 50000);
	psl->m_Size = 0;
	psl->m_Capacity = 50000;
}

// 顺序表尾插
void SeqListPushBack(struct SeqList* psl, int val)
{
	psl->m_ElmArr[psl->m_Size].m_Val = val;
	psl->m_ElmArr[psl->m_Size].m_Num = 1;
	psl->m_Size++;
}

// 顺序表查找 值
struct element* SeqListFind(struct SeqList* psl, int val)
{
	for (int i = 0; i < psl->m_Size; i++)
	{
		if (psl->m_ElmArr[i].m_Val == val)
		{
			return &psl->m_ElmArr[i];
		}
	}

	return NULL;
}



int majorityElement(int* nums, int numsSize)
{
	struct SeqList sl;

	SeqListInit(&sl);// 顺序表初始化

	for (int i = 0; i < numsSize; i++)
	{
		struct element* ret = SeqListFind(&sl, nums[i]);// 顺序表查找

		// 没有则添加
		if (ret == NULL)
		{
			SeqListPushBack(&sl, nums[i]);// 顺序表尾插
		}
		else
		{
			// 有则次数++
			ret->m_Num++;
		}
	}

	// 找到出现最多的数字
	int numMax = 0;
	struct element* elmMax = NULL;

	for (int i = 0; i < sl.m_Size; i++)
	{
		if (sl.m_ElmArr[i].m_Num > numMax)
		{
			numMax = sl.m_ElmArr[i].m_Num;
			elmMax = &sl.m_ElmArr[i];
		}
	}

	return elmMax->m_Val;
}

int main()
{

	return 0;
}