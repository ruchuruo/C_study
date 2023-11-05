
/*
	217. 存在重复元素 https://leetcode.cn/problems/contains-duplicate/description/
	
	简单

		给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。

		示例 1：
			输入：nums = [1,2,3,1]
			输出：true

		示例 2：
			输入：nums = [1,2,3,4]
			输出：false

		示例 3：
			输入：nums = [1,1,1,3,3,4,3,2,4,2]
			输出：true

		提示：
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
		将 vector 容器中的数放到 set 容器中，
		因为 set 容器不能插入相同元素，
		所以最后对比两个容器的大小。
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