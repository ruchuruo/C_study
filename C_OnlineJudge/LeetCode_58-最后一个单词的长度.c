
/*
	58. 最后一个单词的长度 https://leetcode.cn/problems/length-of-last-word/description/

	给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

	单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

	示例 1：
		输入：s = "Hello World"
		输出：5
		解释：最后一个单词是“World”，长度为5。

	示例 2：
		输入：s = "   fly me   to   the moon  "
		输出：4
		解释：最后一个单词是“moon”，长度为4。

	示例 3：
		输入：s = "luffy is still joyboy"
		输出：6
		解释：最后一个单词是长度为6的“joyboy”。

	提示：
		1 <= s.length <= 104
		s 仅有英文字母和空格 ' ' 组成
		s 中至少存在一个单词
*/

#include <string.h>

int lengthOfLastWord(char* s)
{
	/*
		思路1：
			从字符串末尾开始找

										   ↓
				"   fly me   to   the moon  ";

																							   i
																							   ↓
				[ ][ ][ ][f][l][y][ ][m][e][ ][ ][ ][t][o][ ][ ][ ][t][h][e][ ][m][o][o][n][ ][ ][\0]

			是空格就往前走

																						 i
																						 ↓
				[ ][ ][ ][f][l][y][ ][m][e][ ][ ][ ][t][o][ ][ ][ ][t][h][e][ ][m][o][o][n][ ][ ][\0]

			走到不是空格时，counter++ 后再继续往前走

																			 i
																			 ↓
				[ ][ ][ ][f][l][y][ ][m][e][ ][ ][ ][t][o][ ][ ][ ][t][h][e][ ][m][o][o][n][ ][ ][\0]

			走到 i小于0 或 空格 时跳出循环，返回 counter
	*/
	int s_len = strlen(s);

	int i = s_len - 1;
	int counter = 0;

	for (;;)
	{
		// 是空格就往前走
		if (s[i] == ' ' && i != 0)
		{
			i--;
		}
		else
		{
			counter++;
			i--;

			if (i < 0 || s[i] == ' ')
			{
				break;
			}
		}
	}

	return counter;
}

int main()
{
	char* s = "   fly me   to   the moon  ";

	int ret = lengthOfLastWord(s);

	return 0;
}