
/*
	125. ��֤���Ĵ� https://leetcode.cn/problems/valid-palindrome/

	�Ѷȣ���

		����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�� ���Ĵ� ��

		��ĸ�����ֶ�������ĸ�����ַ���

		����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��

		ʾ�� 1��
			����: s = "A man, a plan, a canal: Panama"
			�����true
			���ͣ�"amanaplanacanalpanama" �ǻ��Ĵ���

		ʾ�� 2��
			���룺s = "race a car"
			�����false
			���ͣ�"raceacar" ���ǻ��Ĵ���

		ʾ�� 3��
			���룺s = " "
			�����true
			���ͣ����Ƴ�����ĸ�����ַ�֮��s ��һ�����ַ��� "" ��
			���ڿ��ַ������ŷ��Ŷ���һ���������ǻ��Ĵ���


		��ʾ��
			1 <= s.length <= 2 * 105
			s ���ɿɴ�ӡ�� ASCII �ַ����
*/

#include <stdio.h>
#include <stdlib.h>
#define bool _Bool
#define true 1
#define false 0

bool isPalindrome(char* s)
{
	/*
		˼·��
			A,bcDEfG0,

			�Ƴ����з���ĸ�����ַ���Сдת������ŵ�������

			abcdefg0

			������β���\0

			abcdefg0\0

			������ ͷ �� β ��ʼ�Ƚ�

			|   ��			��
			|   ��			 ��
			|   a b c d e f g 0

			�Ƚ�һ�� ��++����--

			|	 ��		��
			|	 ��		 ��
			|   a b c d e f g 0
	*/
	/*
		97  a
		65  A
		122 z
		90  Z

		48  0
		57  9
	*/

	char* cur = s;

	// ��Ŵ���õ��ַ�
	char* pc = (char*)malloc(sizeof(char) * 200000);



	// �Ƴ����з���ĸ�����ַ���Сдת��
	int size = 0;
	// for(int i = 0; *cur != 0; i++)
	while (*cur != 0)
	{
		// תСд
		if (*cur >= 65 && *cur <= 90)
		{
			*cur += 32;
		}

		// Сд��ĸ ���� ��ӡ�ʹ��
		if (*cur >= 97 && *cur <= 122 || *cur >= 48 && *cur <= 57)
		{
			printf("%c", *cur);

			// ��ŵ�������
			pc[size] = *cur;
			size++;
		}

		cur++;
	}

	// ����ĩβ���\0
	pc[size] = 0;

	printf("\n%s", pc);






	// ��ʼ�Ա�
	int left = 0;
	int right = size - 1;

	while (left < right)
	{
		if (pc[left] != pc[right])
		{
			return false;
		}

		left++;
		right--;
	}

	free(pc);
	return true;
}

int main()
{

	return 0;
}