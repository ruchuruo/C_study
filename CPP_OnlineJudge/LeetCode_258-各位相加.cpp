
/*
	258. ��λ��� https://leetcode.cn/problems/add-digits/description/

	��

		��ʾ
			����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����������������

		ʾ�� 1:
			����: num = 38
			���: 2 
			����: ��λ��ӵĹ���Ϊ��
			38 --> 3 + 8 --> 11
			11 --> 1 + 1 --> 2
			���� 2 ��һλ�������Է��� 2��

		ʾ�� 2:
			����: num = 0
			���: 0
 

		��ʾ��
			0 <= num <= 2^31 - 1

		���ף�����Բ�ʹ��ѭ�����ߵݹ飬�� O(1) ʱ�临�Ӷ��ڽ�����������
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int addDigits(int num)
	{
		if (num < 10)
		{
			return num;
		}

		vector<int> v;

		int counter = 0;

		do
		{
			int tmp = 0;
			counter = 0;

			while (num > 0)
			{
				tmp = num % 10;
				num = num / 10;

				v.push_back(tmp);
			}

			for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
			{
				counter += *(it);
			}

			num = counter;
			v.clear();

		} while (counter >= 10);
		
		return counter;
	}
};

int main()
{
	Solution().addDigits(388);

	return 0;
}