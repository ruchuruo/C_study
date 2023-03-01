
/*
	67. 二进制求和 https://leetcode.cn/problems/add-binary/

	难度：简单

	给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

	示例 1：
		输入:a = "11", b = "1"
		输出："100"

	示例 2：
		输入：a = "1010", b = "1011"
		输出："10101"

	提示：
		1 <= a.length, b.length <= 104
		a 和 b 仅由字符 '0' 或 '1' 组成
		字符串如果不是 "0" ，就不含前导零
*/

#include <stdlib.h>
#include <string.h>

// a，b 等长时才能计算
char* addBinary(char* a, char* b)
{
	/*
		输入：a = "1010", b = "1011"
		输出："10101"

		a = "1010"
		b = "1011"
			 2021

		申请内存，
		从 a[0] b[0] 开始走，

		如果 a[i] + b[i] 等于2，
		将10后插到新数组中

		如果 a[i] + b[i] 小于2，
		将 a[i] + b[i]的计算结果 后插到新数组中

		最后 在字符串末尾添加'\0'

	*/

	char* newChar = (char*)malloc(sizeof(char) * 128);

	// 记录 新字符串 的长度
	//int newChar_len = 0;

	int i = 0;
	for (i = 0; a[i] && b[i]; i++)
	{
		// ASCII码
		if (a[i] + b[i] - 96 == 2)
		{
			newChar[i] = 49;		// 1
			newChar[i + 1] = 48;	// 0
			//newChar_len = newChar_len + 2;
		}
		else
		{
			//	ASCII码
			if (a[i] + b[i] - 96 == 0)
			{
				//newChar[newChar_len] = 48;// 0
				newChar[i + 1] = 48;// 0
			}
			else
			{
				//newChar[newChar_len] = 49;// 1
				newChar[i + 1] = 49;// 1
			}

			//newChar_len = newChar_len + 1;
		}

	}

	newChar[i + 1] = '\0';
}

// 超长字符串不能解决
char* addBinary2(char* a, char* b)
{
	/*
		思路2：二进制 十进制 互相转换

			公式简介

				先了解熟悉的十进制转二进制。
				要用这种方法首先得会十进制转二级制的除以2取余的方法。

			十进制转二进制操作

				将余数和最后的1从下向上倒序写 就是结果

				例如302

				302 / 2 = 151 余0
				151 / 2 = 75  余1
				75  / 2 = 37  余1
				37  / 2 = 18  余1
				18  / 2 = 9   余0
				9   / 2 = 4   余1
				4   / 2 = 2   余0
				2   / 2 = 1   余0
				1   / 2 = 0   余1

				故二进制为100101110

			二进制转十进制操作

				二进制转为十进制的时候，先把二进制从高位（最左边的“1”）开始按从上到下的顺序写出 ，
				第一位就是最后的商 “2 2 = 1 余0 “，余数肯定是加零。其他位数如果有”1“（原来的余数），就先乘以”2“再加”1“。
				( (被除数-余数)÷除数=商 )( 被除数÷除数=商··· ···余数 )

				下面就是从第一位开始乘以2加余数的方法算回去

				例如 100101110

				1	0   * 2 + 1 = 1		余数为1
				0	1   * 2 + 0 = 2		余数为0
				0	2   * 2 + 0 = 4		余数为0
				1	4   * 2 + 1 = 9		余数为1
				0	9   * 2 + 0 = 18	余数为0
				1	18  * 2 + 1 = 37	余数为1
				1	37  * 2 + 1 = 75	余数为1
				1	75  * 2 + 1 = 151	余数为1
				0	151 * 2 + 0 = 302	余0

				所以得到十进制数302

				另：1*2^8+0*2^7+0*2^6+1*2^5+0*2^4+1*2^3+1*2^2+1*2^1+0=302（最后一位应为加法）
			
	*/

	// 二进制转十进制操作
	int a_DEC = 0;
	int b_DEC = 0;

	for (int i = 0; a[i]; i++)
	{
		a_DEC = a_DEC * 2 + (a[i] - 48);
	}

	for (int i = 0; b[i]; i++)
	{
		b_DEC = b_DEC * 2 + (b[i] - 48);
	}

	// 十进制 相加
	int and_DEC = a_DEC + b_DEC;

	// 特判
	if (and_DEC == 0)
	{
		return "0";
	}

	// 十进制转二进制操作
	char* newChar = (char*)malloc(sizeof(char) * 128);
	int newChar_len = 0;
	for (int i = 0; and_DEC; i++)
	{
		newChar[i] = (and_DEC % 2) + 48;
		and_DEC = and_DEC / 2;
		newChar_len++;
	}

	newChar[newChar_len] = '\0';

	// 翻转字符串
	int left = 0;
	int right = (strlen(newChar)) - 1;
	char tmp;
	while (left < right)
	{
		tmp = newChar[left];
		newChar[left] = newChar[right];
		newChar[right] = tmp;

		left++;
		right--;
	}

	return newChar;
}

char* addBinary3(char* a, char* b)
{
	/*
		解题思路：
			二进制求和，满二进一

			1. 首先让两个字符串等长，若不等长，在短的字符串前补零，否则之后的操作会超出索引。

			2. 然后从后到前遍历所有的位数，同位相加，这里有一个点，用的是字符相加，
			   利用 ASCII 码，字符在内部都用数字表示，我们不需要知道具体数值，但可知 ‘0’-‘0’ = 0， ‘0’+1=‘1’，以此类推 。
			   字符的加减，大小比较，实际上都是内部数字的加减，大小比较。

			3. 判断相加后的字符，若大于等于字符 ‘2’‘2’‘2’，下一位需要进一。

			4. 第 000 位数的相加在这里是单独处理的，因为它可能涉及到字符的插入（即是否需要在最前面加一位数 ‘1’‘1’‘1’。

			作者：YouLookDeliciousC
			链接：https://leetcode.cn/problems/add-binary/solutions/7497/c-xiang-xi-ti-jie-bu-zou-qing-xi-by-youlookdelicio/
			来源：力扣（LeetCode）
			著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	*/

	int a_len = strlen(a);
	int b_len = strlen(b);


	if (a_len < b_len)
	{
		// 申请内存 大小等于 b_len
		char* a_tmp = malloc(sizeof(char) * (b_len + 1));

		// 计算 a 和 b 相差多少
		int difference = b_len - a_len;

		// a_tmp 从头开始放入0
		int i = 0;
		for (i = 0; i < difference; i++)
		{
			a_tmp[i] = '0';
		}

		// 补齐完成，拷贝 a 到 a_tmp;
		int j = 0;
		for (j = 0; j <= a_len; j++)
		{
			a_tmp[i + j] = a[j];
		}
		
		// 交换
		a = a_tmp;

		// 计算
		char* and_ = malloc(sizeof(char) * (b_len + i + j) + 1);

		and_[b_len + i + j] = 0;
		int and_len = strlen(and_);

		for (int k = and_len; k >= 0; k--)
		{
			if (1)
			{

			}
		}

	}
	else if (a_len > b_len)
	{

	}
	else
	{
		// 等长情况
	}
	
}

char* addBinary4(char* a, char* b)
{
	//参考评论区@银河也是河
	
	/*
		思路：
			
	*/

	int lena = strlen(a);
	int lenb = strlen(b);

	int len = lena > lenb ? lena : lenb;
	char* res = (char*)malloc(sizeof(char) * (len + 2));	//+2防进位
	res[++len] = 0;

	char carry = '0';
	char pa, pb;
	while (len > 1 || carry == '1')
	{
		pa = lena > 0 ? a[--lena] : '0';
		pb = lenb > 0 ? b[--lenb] : '0';						//处理长度不一的情况

		res[--len] = pa ^ pb ^ carry; 						// 当前位
		carry = (pa & carry) | (pb & carry) | (pa & pb); 	//进位
	}

	return res + len;										//返回 res 的第 len 到末尾的字符
}

char* addBinary5(char* a, char* b)
{
	//参考评论区@银河也是河

	/*
		思路：

	*/

	int lena = strlen(a);
	int lenb = strlen(b);

	int len = 0;
	if (lena > lenb)
	{
		len = lena;
	}
	else
	{
		len = lenb;
	}


	char* res = (char*)malloc(sizeof(char) * (len + 2));	//+2防进位
	res[len + 1] = 0;

	char carry = '0';
	char pa, pb;
	while (len > 1 || carry == '1')
	{
		//处理长度不一的情况
		if (lena > 0)
		{
			pa = a[lena - 1];
		}
		else
		{
			pa = '0';
		}

		if (lenb > 0)
		{
			pa = b[lenb - 1];
		}
		else
		{
			pa = '0';
		}
		
		res[len - 1] = pa ^ pb ^ carry; 					// 当前位
		carry = (pa & carry) | (pb & carry) | (pa & pb); 	//进位
	}

	return res + len;										//返回 res 的第 len 到末尾的字符
}


int main()
{
	//char* a = "10111";// 23
	//char* b = "101";  // 5

	//char* a = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
	//char* b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";

	char* a = "101";	//
	char* b = "10111";	//

	//char* ret = addBinary(a, b);

	//char* ret = addBinary2(a, b);

	char* ret = addBinary4(a, b);

	return 0;
}