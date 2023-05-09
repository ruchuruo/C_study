
/*
	125. 验证回文串 https://leetcode.cn/problems/valid-palindrome/

	难度：简单

		如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

		字母和数字都属于字母数字字符。

		给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

		示例 1：
			输入: s = "A man, a plan, a canal: Panama"
			输出：true
			解释："amanaplanacanalpanama" 是回文串。

		示例 2：
			输入：s = "race a car"
			输出：false
			解释："raceacar" 不是回文串。

		示例 3：
			输入：s = " "
			输出：true
			解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
			由于空字符串正着反着读都一样，所以是回文串。


		提示：
			1 <= s.length <= 2 * 105
			s 仅由可打印的 ASCII 字符组成
*/

#include <stdio.h>
#include <stdlib.h>
#define bool _Bool
#define true 1
#define false 0

bool isPalindrome(char* s)
{
	/*
		思路：
			A,bcDEfG0,

			移除所有非字母数字字符，小写转换，存放到数组中

			abcdefg0

			在数组尾添加\0

			abcdefg0\0

			从数组 头 和 尾 开始比较

			|   左			右
			|   ↓			 ↓
			|   a b c d e f g 0

			比较一次 左++，右--

			|	 左		右
			|	 ↓		 ↓
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

	// 存放处理好的字符
	char* pc = (char*)malloc(sizeof(char) * 200000);



	// 移除所有非字母数字字符，小写转换
	int size = 0;
	// for(int i = 0; *cur != 0; i++)
	while (*cur != 0)
	{
		// 转小写
		if (*cur >= 65 && *cur <= 90)
		{
			*cur += 32;
		}

		// 小写字母 数字 打印和存放
		if (*cur >= 97 && *cur <= 122 || *cur >= 48 && *cur <= 57)
		{
			printf("%c", *cur);

			// 存放到数组中
			pc[size] = *cur;
			size++;
		}

		cur++;
	}

	// 数组末尾填充\0
	pc[size] = 0;

	printf("\n%s", pc);






	// 开始对比
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