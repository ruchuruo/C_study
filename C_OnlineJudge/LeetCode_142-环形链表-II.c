
/*
	142. 环形链表 II https://leetcode.cn/problems/linked-list-cycle-ii/

	难度：中等

	给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

	如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
	为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
	如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

	不允许修改 链表。


	示例 1：

		[3] → [2] → [0] → [-4] →
			   ↑                ↓
				----------------

		输入：head = [3,2,0,-4], pos = 1
		输出：返回索引为 1 的链表节点
		解释：链表中有一个环，其尾部连接到第二个节点。

	示例 2：

		[1] → [2] →
		 ↑         ↓
		  ---------

		输入：head = [1,2], pos = 0
		输出：返回索引为 0 的链表节点
		解释：链表中有一个环，其尾部连接到第一个节点。

	示例 3：

		[1]

		输入：head = [1], pos = -1
		输出：返回 null
		解释：链表中没有环。


	提示：
		链表中节点的数目范围在范围 [0, 104] 内
		-105 <= Node.val <= 105
		pos 的值为 -1 或者链表中的一个有效索引

	进阶：你是否可以使用 O(1) 空间解决此题？
*/

#include <stdlib.h>


// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* detectCycle(struct ListNode* head)
{
	/*
		思路1：
			慢指针 走1步，快指针 走2步，一定会相遇。如何求环的入口点？
			结论：一个指针从相遇点开始走，一个指针从链表头开始走，他们会在环的入口点相遇。
			
			快指针 fast
			慢指针 slow
			相遇点 meetNode
			头节点 head

			                                    入口点
			head                                  ↓
			→                           →    →    →
			[][][][][][][][][][][][][][][]        [][][]
											[][][]		[][][]
									↗  [][]					  [][]  ↘
									  []						  []
									[]								[]
									[]								[]
								  []								  []
								 ↑[]								  []↓
								  []								  []
									[]								[]
									[]								[]
									  []						  []
									↖  [][]					  [][]  ↙
										   ↑[][][]		[][][]
										   ↑	  [][][]
										   ↑		 ←
										   ↑
										  fast
										  slow
										  meetNode

			头节点 到 入口点 的距离				  L
			入口点 到 相遇点 的距离				  X
			环 的长度							  C
			快慢指针 相遇之前 快指针 在环内走的圈数 n

			相遇的过程中
			慢指针 走的距离 L + X
			快指针 走的距离 L + n * C + X	(n 一定 大于等于 1)

			快指针 走的路程是 慢指针 的2倍
			2(L+X) = L+n*C+X
			L+X    = n*C
			L      = n*C-X
			L      = (n-1)*C + C-X
			
			(n-1)*C 从 相遇点 走回到 相遇点
	*/

	struct ListNode* fast = head;
	struct ListNode* slow = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			// 相遇

			struct ListNode* meetNode = slow;

			// 公式证明，结论：一个指针从相遇点开始走，一个指针从链表头开始走，他们会在环的入口点相遇。
			while (meetNode != head)
			{
				meetNode = meetNode->next;
				head = head->next;
			}

			return meetNode;
		}
	}

	return NULL;
}

struct ListNode* detectCycle2(struct ListNode* head)
{
	/*
		思路2：转换成链表相交
			相比 思路1 ，思路2 思想简单，实现复杂一点点。

			相遇点->next 的节点作为另一个链表的头，起名list。
			将 相遇点 的next置空，也可以不置空，但是要 记录 和 判断 长度。
			
			一个指针从 head 开始走，一个指针从 list 开始走，求交点。
	*/
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

	struct ListNode* ret = detectCycle(n1);

	return 0;
}