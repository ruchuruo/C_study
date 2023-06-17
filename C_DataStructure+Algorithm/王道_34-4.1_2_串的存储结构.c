
/*
	串
		存储结构

			顺序存储
				静态数组
				动态数组

			链式存储
				可让每个节点存多个字符，没有字符的位置用'\0'或其他字符补足

			基于顺序存储实现基本操作
				求子串
				串的比较
				求串在主串中的位置


		串的顺序存储

			定长顺序存储

				#define MAXLEN 255   // 预定义最大串长为255
				typedef struct
				{
					char ch[MAXLEN]; // 每个分量存储一个字符(静态数组实现)(定长顺序存储)
					int length;      // 串的实际长度
				}SString;

			堆分配存储

				typedef struct
				{
					char* ch;   // 按串长分配存储区，ch指向串的基地址(动态数组实现)(堆分配存储)
					int length; // 串的长度
				}HString;

				HString S;
				S.ch = (char*)malloc(MAXLEN * sizeof(char));
				S.length = 0;

			|     内存
			|   +-------+
			|   |       |
			|   +-------+
			|   |       |
			|   +-------+
			|   | ch[0] |
			|   +-------+
			|   | ch[1] |
			|   +-------+
			|   | ch[2] |
			|   +-------+
			|   | ch[3] | < 分配连续的存储空间，每个 char 字符占 1B
			|   +-------+
			|   | ch[4] |
			|   +-------+
			|   |  ...  |
			|   +-------+
			|   |  ...  |
			|   +-------+
			|   |       |
			|   +-------+
			|   |       |
			|   +-------+
			|   |ch[254]|
			|   +-------+
			|   |length |
			|   +-------+
			|   |       |
			|   +-------+

			结合顺序表的知识思考优缺点

			实现方案

				方案一 额外变量记录长度
					|   [w][a][n][g][d][a][o][ ][ ][ ][7]
					|                                  ↑
					|                                  变量Length

				方案二 ch[0]充当Length
					|   [7][w][a][n][g][d][a][o][ ][ ]
					优点：字符的位序和数组下标相同
					缺点：字符串长度不能超过255，1B(字节) = 8bit

				方案三 字符'\0'结尾
					|   [w][a][n][g][d][a][o][\0][ ][ ]
					没有Length变量，以字符'\0'表示结尾(对应ASCII码的0)
					缺点：想要知道字符串长度需要遍历

				方案四 舍弃ch[0]
					|   [ ][w][a][n][g][d][a][o][ ][ ][7]
					|                                  ↑
					|                                  变量Length


		串的链式存储

			每个节点存1个字符

				typedef struct StringNode
				{
					char ch;// 每个节点存1个字符
					struct StringNode* next;
				}StringNode, * String;

				|   S → [(a)()] → [(b)()] → [(c)()] → [(d)()] → [(e)()] → NULL
				存储密度低，每个字符1B，每个指针4B(32位)

			每个节点存多个字符

				typedef struct StringNode
				{
					char ch[4];// 每个节点存多个字符
					struct StringNode* next;
				}StringNode, * String;

				|   S → [(a)(b)(c)(d)()] → [(e)(#)(#)(#)()] → NULL
				存储密度提高
				当末尾存不满可以用其他字符填充

			结合链表的知识思考优缺点


		基于顺序存储实现基本操作

			方案四 舍弃ch[0]
				|   [ ][w][a][n][g][d][a][o][ ][ ][7]
				|                                  ↑
				|                                  变量Length

			定长顺序存储

				#define MAXLEN 255   // 预定义最大串长为255
				typedef struct
				{
					char ch[MAXLEN]; // 每个分量存储一个字符(静态数组实现)(定长顺序存储)
					int length;      // 串的实际长度
				}SString;

			赋值   StrAssign(&T, chars)         把串 T 赋值为 chars
			复制   StrCopy(&T, S)               由串 S 复制得到串 T
			判空   StrEmpty(S)                  若 S 为空串，则返回 TRUE，否则返回 FALSE
			求串长 StrLength(S)                 返回串 S 的元素个数
			清空   ClearString(&S)              将串 S 清为空串
			销毁   DestroyString(&S)            将串 S 销毁(回收存储空间)
			串联接 Concat(&T, S1, S2)           用 T 返回由 S1 和 S2 联接而成的新串
			求子串 SubString(&Sub, S, pos, len) 用 Sub 返回串 S 的第 pos 个字符起长度为 len 的子串
			比较   StrCompare(S, T)             若 S>T，则返回值>0；若 S=T，则返回值=0；若 S<T，则返回值<0
			定位   Index(S, T)                  若主串 S 中存在与串 T 值相同的子串，则返回它在主串 S 中第一次出现的位置，否则函数值为0

			求子串

				|   S [ ][w][a][n][g][d][a][o][ ][ ]
				|      0  1  2  3  4  5  6  7  8  9

				S.ch = "wangdao"
				S.length = 7

				假设从第4个字符起，往后3个长度的子串，"gda"

				#define MAXLEN 255   // 预定义最大串长为255
				typedef struct
				{
					char ch[MAXLEN]; // 每个分量存储一个字符(静态数组实现)(定长顺序存储)
					int length;      // 串的实际长度
				}SString;

				_Bool SubString(SString* Sub, SString S, int pos, int len)
				{
					// 子串范围越界
					if (pos + len - 1 > S.length)
					{
						// (假设从第6个字符起，往后4个长度的子串，后面没有字符，需要制止)
						return 0;
					}

					for (int i = pos; i < pos + len; i++)
					{
						Sub->ch[i - pos + 1] = S.ch[i];
					}

					Sub->length = len;
					return 1;
				}

			比较

				|   S.ch [ ][w][a][n][g][d][a][o][ ][ ]
				|         0  1  2  3  4  5  6  7  8  9

				S.ch = "wangdao"
				S.length = 7

				|   T1 [ ][w][b][n][g][d][a][o][ ][ ]
				|       0  1  2  3  4  5  6  7  8  9

				|   T2 [ ][w][a][n][g][ ][ ][ ][ ][ ]
				|       0  1  2  3  4  5  6  7  8  9

				#define MAXLEN 255   // 预定义最大串长为255
				typedef struct
				{
					char ch[MAXLEN]; // 每个分量存储一个字符(静态数组实现)(定长顺序存储)
					int length;      // 串的实际长度
				}SString;

				int StrCompare(SString S, SString T)
				{
					for (int i = 1; i < S.length && i <= T.length; i++)
					{
						if (S.ch[i] != T.ch[i])
						{
							// 比如 'a' - 'b'
							return S.ch[i] - T.ch[i];
						}

						// 扫描过的所有字符都相同，则长度长的串更大
						return S.length - T.length;
					}
				}

			定位

				|   S.ch [ ][w][a][n][g][d][a][o][ ][ ]
				|         0  1  2  3  4  5  6  7  8  9

				S.ch = "wangdao"
				S.length = 7

				|   T [ ][w][b][n][g][d][a][o][ ][ ]
				|      0  1  2  3  4  5  6  7  8  9

				假设找子串 "gda"
				从主串 S[1] S[2] S[3] 开始找，之后
				S[2] S[3] S[4]
				S[3] S[4] S[5]
				......
				S[5] S[6] S[7]

				#define MAXLEN 255   // 预定义最大串长为255
				typedef struct
				{
					char ch[MAXLEN]; // 每个分量存储一个字符(静态数组实现)(定长顺序存储)
					int length;      // 串的实际长度
				}SString;

				int StrLength(S){}
				void SubString(SString Sub, SString S, int pos, int len){}
				int StrCompare(SString S, SString T){}

				int Index(SString S, SString T)
				{
					int i = 1;
					int n = StrLength(S);
					int m = StrLength(T);

					SString sub;// 用于暂存子串

					while (i <= n - m + 1)
					{
						SubString(sub, S, i, m);
						if (StrCompare(sub, T) != 0)
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
*/