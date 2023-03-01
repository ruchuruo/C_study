
/*
	141. 环形链表 https://leetcode.cn/problems/linked-list-cycle/description/

	难度：简单

	给你一个链表的头节点 head ，判断链表中是否有环。

	如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
	为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
	注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

	如果链表中存在环 ，则返回 true 。 否则，返回 false 。


	示例 1：

		[3] → [2] → [0] → [-4] → 
		       ↑                ↓
			    ----------------

		输入：head = [3,2,0,-4], pos = 1
		输出：true
		解释：链表中有一个环，其尾部连接到第二个节点。

	示例 2：
		
		[1] → [2] → 
		 ↑         ↓
		  ---------
		
		输入：head = [1,2], pos = 0
		输出：true
		解释：链表中有一个环，其尾部连接到第一个节点。

	示例 3：

		[1]

		输入：head = [1], pos = -1
		输出：false
		解释：链表中没有环。


	提示：
		链表中节点的数目范围是 [0, 104]
		-105 <= Node.val <= 105
		pos 为 -1 或者链表中的一个 有效索引 。

	进阶：你能用 O(1)（即，常量）内存解决此问题吗？
*/

#include <stdlib.h>


// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};


_Bool hasCycle(struct ListNode* head)
{
	/*
		思路1：快慢指针

			slow
			fast
			 ↓
			[3] → [2] → [0] → [-4] →
				   ↑                ↓
					----------------

			输入：head = [3,2,0,-4], pos = 1
			输出：true
			解释：链表中有一个环，其尾部连接到第二个节点。

			slow 一次走1步，fast 一次走2步，
			不带环，fast 会为空。
			带环，fast 会追上 slow。

				      slow
				       ↓    fast
				       ↓     ↓
				[3] → [2] → [0] → [-4] →
					   ↑                ↓
						----------------

					        slow
					  fast   ↓
					   ↓     ↓
				[3] → [2] → [0] → [-4] →
					   ↑                ↓
						----------------

							       slow
							       fast
							        ↓
				[3] → [2] → [0] → [-4] →
					   ↑                ↓
						----------------
	*/

	struct ListNode* fast = head;
	struct ListNode* slow = head;

	while (fast && fast->next)// 可能不带环，都不为空才进循环
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;
	n5->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n1;

	_Bool ret = hasCycle(n1);

	return 0;
}