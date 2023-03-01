
/*
	剑指 Offer II 027. 回文链表 https://leetcode.cn/problems/aMhZSa/

	难度：简单

	给定一个链表的 头节点 head ，请判断其是否为回文链表。

	如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。

	示例 1：
		输入: head = [1,2,3,3,2,1]
		输出: true

	示例 2：
		输入: head = [1,2]
		输出: false

	提示：
		链表 L 的长度范围为 [1, 105]
		0 <= node.val <= 9

	进阶：能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

	注意：本题与主站 234 题相同：https://leetcode-cn.com/problems/palindrome-linked-list/
*/

#include <stdio.h>
#include <stdlib.h>


// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

// 206. 反转链表 https://leetcode.cn/problems/reverse-linked-list/
struct ListNode* reverseList(struct ListNode* head)
{
	/*
		思路1：
			改变箭头方向

				[1] → [2] → [3] → [4] → [5]
							 ↓
				[1] ← [2] ← [3] ← [4] ← [5]

			先创建3个变量，n1之前位置，n2当前位置，n3下一位置。初始条件

				n1    n2    n3
				↓     ↓     ↓
					 [1] → [2] → [3] → [4] → [5]

			n2 指向 n1。核心逻辑

				n1      n2    n3
				↓       ↓     ↓
				NULL ← [1]   [2] → [3] → [4] → [5]

			n2给n1。迭代条件

						n1
						n2    n3
						↓     ↓
				NULL ← [1]   [2] → [3] → [4] → [5]

			n3给n2。迭代条件

							  n2
						n1    n3
						↓     ↓
				NULL ← [1]   [2] → [3] → [4] → [5]

			n3等于n3->next。迭代条件

						n1    n2    n3
						↓     ↓     ↓
				NULL ← [1]   [2] → [3] → [4] → [5]

			n2 为 空。结束条件

												n1    n2    n3
												↓     ↓     ↓
				NULL ← [1] ← [2] ← [3] ← [4] ← [5]

			n1 是链表新的头
	*/

	// 链表为空
	if (head == NULL)
	{
		return NULL;
	}

	// 先创建3个变量，n1之前位置，n2当前位置，n3下一位置
	struct ListNode* n1;
	struct ListNode* n2;
	struct ListNode* n3;

	// 初始条件
	n1 = NULL;
	n2 = head;
	n3 = head->next;

	while (n2)// 结束条件
	{
		// 核心逻辑，翻转
		n2->next = n1;

		// 迭代条件，往后走
		n1 = n2;
		n2 = n3;

		// n3 最后为空就停止
		if (n3)
		{
			n3 = n3->next;
		}
	}

	return n1;
}

// 876. 链表的中间结点 https://leetcode.cn/problems/middle-of-the-linked-list/
struct ListNode* middleNode(struct ListNode* head)
{
	/*
		思路1：
			遍历一遍计算长度，长度除2

			再遍历一遍找到中间节点

			时间复杂度O(N)

		思路2：
			要求：只能遍历链表一次

			用双指针，快慢指针

				fast
				 ↓
				[1] → [2] → [3] → [4] → [5]
				 ↑
				slow

			快指针一次走2步，慢指针一次走1步

							fast
							 ↓
				[1] → [2] → [3] → [4] → [5]
					   ↑
					  slow

			停止条件，fast 为 空 并且 fast->next 为 空
	*/

	// 思路2 快慢指针
	struct ListNode* fast = head;
	struct ListNode* slow = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

_Bool isPalindrome(struct ListNode* head)
{
	/*
		思路1：
			每个节点的 val 放到数组里，然后 前后遍历

		思路2：
			找到链表中间节点，逆置后半段，之后 head 和 reverseHead 往后比较

			[1] → [2] → [3] → [2] → [1]

			head       middle
			 ↓           ↓
			[1] → [2] → [3] → [2] → [1]

			head       reverseHead
			 ↓           ↓
			[1] → [2]   [1] → [2] → [3] → NULL
			       ↓                 ↑
				    -----------------
	*/

	// 思路2

	// 链表的中间结点
	struct ListNode* middle = middleNode(head);

	// 反转链表
	struct ListNode* reverseHead = reverseList(middle);
		
	// 比较
	struct ListNode* curHead = head;
	struct ListNode* curReverseHead = reverseHead;

	while (curHead && curReverseHead)
	{
		if (curHead->val != curReverseHead->val)
		{
			return 0;
		}
		else
		{
			curHead = curHead->next;
			curReverseHead = curReverseHead->next;
		}
	}

	return 1;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 3;
	n5->val = 2;
	n6->val = 1;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;

	_Bool ret = isPalindrome(n1);

	return 0;
}