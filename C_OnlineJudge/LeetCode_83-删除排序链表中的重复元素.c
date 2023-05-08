
/*
	83. 删除排序链表中的重复元素 https://leetcode.cn/problems/remove-duplicates-from-sorted-list/

	难度：简单

		给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。

		示例 1：
			|   (1) → (1) → (2)
			|		  ↓
			|   (1) → (2)
			输入：head = [1,1,2]
			输出：[1,2]

		示例 2：
			|   (1) → (1) → (2) → (3) → (3)
			|		  ↓
			|   (1) → (2) → (3)
			输入：head = [1,1,2,3,3]
			输出：[1,2,3]

		提示：
			链表中节点数目在范围 [0, 300] 内
			-100 <= Node.val <= 100
			题目数据保证链表已经按升序 排列
*/
/*
	思路：
		由于给定的链表是排好序的，因此重复的元素在链表中出现的位置是连续的，因此我们只需要对链表进行一次遍历，就可以删除重复的元素。
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};



struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL)
	{
		return head;
	}

	struct ListNode* cur = head;

	while (cur != NULL && cur->next != NULL)
	{
		if (cur->val == cur->next->val)
		{
			struct ListNode* curNext;
			curNext = cur->next;

			cur->next = curNext->next;
			free(curNext);
		}
		else
		{
			cur = cur->next;
		}
	}

	return head;
}

int main()
{

	return 0;
}