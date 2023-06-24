
/*
	串
		朴素模式匹配算法

			算法思想
				主串长度n，模式串长度m。
				将主串中所有长度为m的子串与模式串对比
				找到第一个模式串匹配的子串，并返回子串起始位置
				若所有子串都不匹配，则返回0

			最坏时间复杂度
				O(nm)


		什么是模式匹配

			主串：S=‘wangdao’

			子串：’wang’、’ang’、’ao’ …… (一定是主串中存在的才叫“子串”)

			模式串：’gda’、’bao’         (想尝试在主串中找到的串，未必存在)

			串的模式匹配：在主串中找到与模式串相同的子串，并返回其所在位置。


		两种模式匹配算法

			字符串模式匹配
				朴素模式匹配算法
				KMP算法


		朴素模式匹配算法

			|   主串S  [a][b][a][a][b][a][a][b][c][a][b][a][a][b][b]
			|           1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
			|                                      1  1  1  1  1  1
			|
			|   模式串T [a][b][a][a][b][c]
			|            1  2  3  4  5  6

			既然名字是朴素，开始暴力解决问题，
			主串中所有长度为6的子串，依次和模式串对比。

			主串长度为n，模式串长度为m；
			朴素模式匹配算法：将 主串 中所有长度为m的 子串 依次与 模式串 对比，直到找到一个完全匹配的 子串，或所有的 子串 都不匹配为止。

			最多对比 n - m + 1 个子串

			Index(S,T)：定位操作。若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置；否则函数值为0。

				int Index(SString S, SString T)
				{
					int i = 1;
					int n = StrLength(S);
					int m = StrLength(T);

					SString sub;// 用于暂存子串

					while (i <= n - m + 1)
					{
						SubString(sub, S, i, m);// 取出从位置i开始，长度为m的子串
						if (StrCompare(sub, T) != 0)// 子串和模式串对比，若不匹配，则匹配下一个子串
						{
							i++;
						}
						else
						{
							return i;// 返回子串在主串中的位置
						}
					}

					return 0;// S 中不存在与 T 相等的子串
				}

			接下来，不使用字符串的基本操作，直接通过数组下标实现朴素模式匹配算法

				|           i
				|           ↓
				|   主串S  [a][b][a][a][b][a][a][b][c][a][b][a][a][b][b]
				|           1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
				|                                      1  1  1  1  1  1
				|
				|            j
				|            ↓
				|   模式串T [a][b][a][a][b][c]
				|            1  2  3  4  5  6

				若 i 和 j 的字符相同，则同时++

				若当前子串匹配失败，则主串指针 i 指向下一个子串的第一个位置，模式串指针 j 回到模式串的第一个位置。
				写成代码是：
					i = i - j + 2;
					j = 1;

				来自弹幕：这里讲的很不好说实话压根没说清楚算法思想，公式的由来应该是i-(j-1)+1，(j-1)表示当前已匹配次数

				若 j > T.length，则当前 子串 匹配成功，返回当前子串第一个字符的位置：i - T.length

				int Index(SString S, SString T)
				{
					int i = 1;
					int j = 1;

					while (i <= S.length && j <= T.length)
					{
						if (S.ch[i] == T.ch[j])
						{
							// 继续比较后继字符
							++i;
							++j;
						}
						else
						{
							// 指针后退从新开始匹配
							i = i - j + 2;
							j = 1;
						}
					}

					if (j > T.length)
					{
						return i - T.length;
					}
					else
					{
						return 0;
					}
				}

				设主串长度为n，模式串长度为m，则最坏时间复杂度 = O(nm)

				最坏的情况，每个子串都要对比m个字符，共 n-m+1 个子串，复杂度 = O((n-m+1)m) = O(nm-m*m+m) = O(nm)
				为什么可以吧 m平方 和 m 去掉，因为很多时候 n 远大于 m
*/

#define MAXLEN 255   // 预定义最大串长为255
typedef struct
{
	char ch[MAXLEN]; // 每个分量存储一个字符(静态数组实现)(定长顺序存储)
	int length;      // 串的实际长度
}SString;

int Index(SString S, SString T)
{
	int i = 1;
	int j = 1;

	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			// 继续比较后继字符
			++i;
			++j;
		}
		else
		{
			// 指针后退从新开始匹配
			i = i - j + 2;
			j = 1;
		}
	}

	if (j > T.length)
	{
		return i - T.length;
	}
	else
	{
		return 0;
	}
}