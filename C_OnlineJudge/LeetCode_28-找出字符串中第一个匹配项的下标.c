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

int strStr(char* haystack, char* needle)
{
	int h_len = strlen(haystack);
	int n_len = strlen(needle);

	// needle Ϊ�շ��� 0
	if (n_len == 0)
	{
		return 0;
	}

	// ���� haystack��Ѱ���� needle ƥ����Ӵ�
	int i = 0;
	int j = 0;
	for (i = 0; i <= h_len - n_len; i++)
	{
		for (j = 0; j < n_len; j++)
		{
			if (haystack[i + j] != needle[j])
			{
				break;
			}
		}

		if (j == n_len)
		{
			// �ҵ�ƥ����Ӵ�
			return i;
		}
	}

	// û���ҵ�ƥ����Ӵ�
	return -1;
}

int main()
{
	strStr("sadbutsad", "sad");

	return 0;
}