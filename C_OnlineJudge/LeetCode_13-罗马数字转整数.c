
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char* s)
{
	// 力扣官方题解

	/*
		输入: s = "LVIII"
		输出: 58
		解释: L = 50, V= 5, III = 3.

		一言蔽之，把一个小值放在大值的左边，就是做减法，否则为加法。
	*/

	int symbolValues[26];

	// ASCII码运算
	symbolValues['I' - 'A'] = 1;	// symbolValues[8]
	symbolValues['V' - 'A'] = 5;	// symbolValues[21]
	symbolValues['X' - 'A'] = 10;	// symbolValues[23]
	symbolValues['L' - 'A'] = 50;	// symbolValues[11]
	symbolValues['C' - 'A'] = 100;	// symbolValues[2]
	symbolValues['D' - 'A'] = 500;	// symbolValues[3]
	symbolValues['M' - 'A'] = 1000;	// symbolValues[12]

	int ans = 0;
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
	{
		int value = symbolValues[s[i] - 'A'];

		if (i < n - 1 && value < symbolValues[s[i + 1] - 'A'])
		{
			ans -= value;
		}
		else
		{
			ans += value;
		}
	}

	return ans;

	/*
		作者：力扣官方题解
			链接：https ://leetcode.cn/problems/roman-to-integer/solutions/774992/luo-ma-shu-zi-zhuan-zheng-shu-by-leetcod-w55p/
		来源：力扣（LeetCode）
			著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	*/
}

int romanToInt_2(char* s)
{
	int form[26];

	// 转换表
	form['I' - 'A'] = 1;
	form['V' - 'A'] = 5;
	form['X' - 'A'] = 10;
	form['L' - 'A'] = 50;
	form['C' - 'A'] = 100;
	form['D' - 'A'] = 500;
	form['M' - 'A'] = 1000;

	// 计算字符串长度
	int s_len = strlen(s);

	// 遍历字符串
	int sum = 0;
	int val = 0;

	int i = 0;
	for (i = 0; i < s_len; i++)
	{
		// 从 转换表 获取 值
		val = form[s[i] - 'A'];

		// 判断：一言蔽之，把一个小值放在大值的左边，就是做减法，否则为加法。
		// 当前值 和 后一个值比较
		if (i < s_len - 1 && val < form[s[i + 1] - 'A'])
		{
			// 左小右大，减法
			sum = sum - val;
		}
		else
		{
			// 左大右小，加法
			sum = sum + val;
		}
	}

	return sum;
}

int main()
{
	// 13. 罗马数字转整数
	char* roman = "LIV";
	//char roman[] = "LVIII";
	//romanToInt(roman);
	romanToInt_2(roman);

	return 0;
}