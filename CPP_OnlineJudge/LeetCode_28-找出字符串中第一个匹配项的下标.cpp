/*
	28. �ҳ��ַ����е�һ��ƥ������±� https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

	��

	˵��
		���������ַ��� haystack �� needle ��
		������ haystack �ַ������ҳ� needle �ַ����ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ����
		��� needle ���� haystack ��һ���֣��򷵻�  -1 ��

	ʾ�� 1��
		���룺haystack = "sadbutsad", needle = "sad"
		�����0
		���ͣ�"sad" ���±� 0 �� 6 ��ƥ�䡣
		��һ��ƥ������±��� 0 �����Է��� 0 ��

	ʾ�� 2��
		���룺haystack = "leetcode", needle = "leeto"
		�����-1
		���ͣ�"leeto" û���� "leetcode" �г��֣����Է��� -1 ��


	��ʾ��
		1 <= haystack.length, needle.length <= 104
		haystack �� needle ����СдӢ���ַ����
*/

#include <string>

using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		// Ϊ��
		if (haystack.empty() || needle.empty())
		{
			return 0;
		}

		// ��ȡ�����ַ����ĳ���
		int n = haystack.size();
		int m = needle.size();

		// ���� haystack �ַ���
		for (int i = 0; i <= n - m; ++i)
		{
			// ���ӵ�ǰ������ʼ�����ַ����Ƿ��� needle ƥ��
			if (haystack.substr(i, m) == needle)
			{
				// ƥ��ɹ������ص�ǰ����
				return i;
			}
		}

		// δ�ҵ�ƥ������� -1
		return -1;
	}
};

int main()
{
	//Solution().strStr("sadbutsad", "sad");
	Solution().strStr("aaaaabbbbbcccccabcccccc", "abc");

	return 0;
}