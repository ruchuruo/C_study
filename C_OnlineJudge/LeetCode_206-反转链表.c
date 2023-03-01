
/*
	206. 反转链表

		给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

		示例 1：
			输入：head = [1,2,3,4,5]
			输出：[5,4,3,2,1]

		示例 2：
			输入：head = [1,2]
			输出：[2,1]

		示例 3：
			输入：head = []
			输出：[]

		提示：
			链表中节点的数目范围是 [0, 5000]
			-5000 <= Node.val <= 5000

		进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};



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

struct ListNode* reverseList2(struct ListNode* head)
{
	/*
		思路2：
			取原链表中的节点，头插到 新链表newHead 中

			newHead = NULL

			cur指向开始的位置，next保存下一个节点。初始条件

				cur  next
				 ↓     ↓
				[1] → [2] → [3] → [4] → [5]

			迭代处理逻辑

				     next
				       ↓
				[1]   [2] → [3] → [4] → [5]

									  newHead
										cur
										 ↓
										[1]

			迭代处理逻辑。next给cur

				      cur
				     next
					   ↓
				[1]   [2] → [3] → [4] → [5]

									  newHead
										 ↓
										[1]

			迭代处理逻辑。next往后走

				      cur  next
					   ↓     ↓
				[1]   [2] → [3] → [4] → [5]

									  newHead
										 ↓
										[1]

			迭代处理逻辑。
				cur->next 指向 newHead
				cur给newHead。
				next给cur。
				next往后走。

			结束条件。cur为空

			栈区出了函数不就销毁了吗，这里不用malloc吗？
			这个链表原本就是在堆上面的，现在只是拿它的结点来头插变成新的链表。
	*/

	struct ListNode* cur = head;
	struct ListNode* newhead = NULL;

	while (cur)
	{
		// 保存下一个节点
		struct ListNode* next = cur->next;

		// 头插
		cur->next = newhead;
		newhead = cur;

		// 迭代往后
		cur = next;
	}

	return newhead;
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
	n5->next = NULL;

	struct ListNode* ret = reverseList(n1);	// 思路1 改变箭头方向

	struct ListNode* ret = reverseList2(n1);// 思路2 头插

	return 0;
}