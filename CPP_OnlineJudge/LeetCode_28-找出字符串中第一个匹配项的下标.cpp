/*
	28. 找出字符串中第一个匹配项的下标 https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

	简单

	说明
		给你两个字符串 haystack 和 needle ，
		请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
		如果 needle 不是 haystack 的一部分，则返回  -1 。

	示例 1：
		输入：haystack = "sadbutsad", needle = "sad"
		输出：0
		解释："sad" 在下标 0 和 6 处匹配。
		第一个匹配项的下标是 0 ，所以返回 0 。

	示例 2：
		输入：haystack = "leetcode", needle = "leeto"
		输出：-1
		解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。


	提示：
		1 <= haystack.length, needle.length <= 104
		haystack 和 needle 仅由小写英文字符组成
*/

#include <string>

using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		// 为空
		if (haystack.empty() || needle.empty())
		{
			return 0;
		}

		// 获取两个字符串的长度
		int n = haystack.size();
		int m = needle.size();

		// 遍历 haystack 字符串
		for (int i = 0; i <= n - m; ++i)
		{
			// 检查从当前索引开始的子字符串是否与 needle 匹配
			if (haystack.substr(i, m) == needle)
			{
				// 匹配成功，返回当前索引
				return i;
			}
		}

		// 未找到匹配项，返回 -1
		return -1;
	}
};

int main()
{
	//Solution().strStr("sadbutsad", "sad");
	Solution().strStr("aaaaabbbbbcccccabcccccc", "abc");

	return 0;
}