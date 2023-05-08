
/*
	83. ɾ�����������е��ظ�Ԫ�� https://leetcode.cn/problems/remove-duplicates-from-sorted-list/

	�Ѷȣ���

		����һ��������������ͷ head �� ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�� ������ ����������� ��

		ʾ�� 1��
			|   (1) �� (1) �� (2)
			|		  ��
			|   (1) �� (2)
			���룺head = [1,1,2]
			�����[1,2]

		ʾ�� 2��
			|   (1) �� (1) �� (2) �� (3) �� (3)
			|		  ��
			|   (1) �� (2) �� (3)
			���룺head = [1,1,2,3,3]
			�����[1,2,3]

		��ʾ��
			�����нڵ���Ŀ�ڷ�Χ [0, 300] ��
			-100 <= Node.val <= 100
			��Ŀ���ݱ�֤�����Ѿ������� ����
*/
/*
	˼·��
		���ڸ������������ź���ģ�����ظ���Ԫ���������г��ֵ�λ���������ģ��������ֻ��Ҫ���������һ�α������Ϳ���ɾ���ظ���Ԫ�ء�
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