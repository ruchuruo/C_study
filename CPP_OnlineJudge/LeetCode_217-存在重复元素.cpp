
/*
	217. �����ظ�Ԫ�� https://leetcode.cn/problems/contains-duplicate/description/
	
	��

		����һ���������� nums �������һֵ�������г��� �������� ������ true �����������ÿ��Ԫ�ػ�����ͬ������ false ��

		ʾ�� 1��
			���룺nums = [1,2,3,1]
			�����true

		ʾ�� 2��
			���룺nums = [1,2,3,4]
			�����false

		ʾ�� 3��
			���룺nums = [1,1,1,3,3,4,3,2,4,2]
			�����true

		��ʾ��
			1 <= nums.length <= 10^5
			-10^9 <= nums[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
	/*
		�� vector �����е����ŵ� set �����У�
		��Ϊ set �������ܲ�����ͬԪ�أ�
		�������Ա����������Ĵ�С��
	*/
public:
	bool containsDuplicate(vector<int>& nums)
	{
		set<int> s;

		for (auto i : nums)
		{
			s.insert(i);
		}

		if (nums.size() != s.size())
		{
			return true;
		}

		return false;
	}
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);

	Solution().containsDuplicate(v);

	return 0;
}