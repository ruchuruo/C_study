
/*
	��
		�洢�ṹ

			˳��洢
				��̬����
				��̬����

			��ʽ�洢
				����ÿ���ڵ�����ַ���û���ַ���λ����'\0'�������ַ�����

			����˳��洢ʵ�ֻ�������
				���Ӵ�
				���ıȽ�
				���������е�λ��


		����˳��洢

			����˳��洢

				#define MAXLEN 255   // Ԥ������󴮳�Ϊ255
				typedef struct
				{
					char ch[MAXLEN]; // ÿ�������洢һ���ַ�(��̬����ʵ��)(����˳��洢)
					int length;      // ����ʵ�ʳ���
				}SString;

			�ѷ���洢

				typedef struct
				{
					char* ch;   // ����������洢����chָ�򴮵Ļ���ַ(��̬����ʵ��)(�ѷ���洢)
					int length; // ���ĳ���
				}HString;

				HString S;
				S.ch = (char*)malloc(MAXLEN * sizeof(char));
				S.length = 0;

			|     �ڴ�
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
			|   | ch[3] | < ���������Ĵ洢�ռ䣬ÿ�� char �ַ�ռ 1B
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

			���˳����֪ʶ˼����ȱ��

			ʵ�ַ���

				����һ ���������¼����
					|   [w][a][n][g][d][a][o][ ][ ][ ][7]
					|                                  ��
					|                                  ����Length

				������ ch[0]�䵱Length
					|   [7][w][a][n][g][d][a][o][ ][ ]
					�ŵ㣺�ַ���λ��������±���ͬ
					ȱ�㣺�ַ������Ȳ��ܳ���255��1B(�ֽ�) = 8bit

				������ �ַ�'\0'��β
					|   [w][a][n][g][d][a][o][\0][ ][ ]
					û��Length���������ַ�'\0'��ʾ��β(��ӦASCII���0)
					ȱ�㣺��Ҫ֪���ַ���������Ҫ����

				������ ����ch[0]
					|   [ ][w][a][n][g][d][a][o][ ][ ][7]
					|                                  ��
					|                                  ����Length


		������ʽ�洢

			ÿ���ڵ��1���ַ�

				typedef struct StringNode
				{
					char ch;// ÿ���ڵ��1���ַ�
					struct StringNode* next;
				}StringNode, * String;

				|   S �� [(a)()] �� [(b)()] �� [(c)()] �� [(d)()] �� [(e)()] �� NULL
				�洢�ܶȵͣ�ÿ���ַ�1B��ÿ��ָ��4B(32λ)

			ÿ���ڵ�����ַ�

				typedef struct StringNode
				{
					char ch[4];// ÿ���ڵ�����ַ�
					struct StringNode* next;
				}StringNode, * String;

				|   S �� [(a)(b)(c)(d)()] �� [(e)(#)(#)(#)()] �� NULL
				�洢�ܶ����
				��ĩβ�治�������������ַ����

			��������֪ʶ˼����ȱ��


		����˳��洢ʵ�ֻ�������

			������ ����ch[0]
				|   [ ][w][a][n][g][d][a][o][ ][ ][7]
				|                                  ��
				|                                  ����Length

			����˳��洢

				#define MAXLEN 255   // Ԥ������󴮳�Ϊ255
				typedef struct
				{
					char ch[MAXLEN]; // ÿ�������洢һ���ַ�(��̬����ʵ��)(����˳��洢)
					int length;      // ����ʵ�ʳ���
				}SString;

			��ֵ   StrAssign(&T, chars)         �Ѵ� T ��ֵΪ chars
			����   StrCopy(&T, S)               �ɴ� S ���Ƶõ��� T
			�п�   StrEmpty(S)                  �� S Ϊ�մ����򷵻� TRUE�����򷵻� FALSE
			�󴮳� StrLength(S)                 ���ش� S ��Ԫ�ظ���
			���   ClearString(&S)              ���� S ��Ϊ�մ�
			����   DestroyString(&S)            ���� S ����(���մ洢�ռ�)
			������ Concat(&T, S1, S2)           �� T ������ S1 �� S2 ���Ӷ��ɵ��´�
			���Ӵ� SubString(&Sub, S, pos, len) �� Sub ���ش� S �ĵ� pos ���ַ��𳤶�Ϊ len ���Ӵ�
			�Ƚ�   StrCompare(S, T)             �� S>T���򷵻�ֵ>0���� S=T���򷵻�ֵ=0���� S<T���򷵻�ֵ<0
			��λ   Index(S, T)                  ������ S �д����봮 T ֵ��ͬ���Ӵ����򷵻��������� S �е�һ�γ��ֵ�λ�ã�������ֵΪ0

			���Ӵ�

				|   S [ ][w][a][n][g][d][a][o][ ][ ]
				|      0  1  2  3  4  5  6  7  8  9

				S.ch = "wangdao"
				S.length = 7

				����ӵ�4���ַ�������3�����ȵ��Ӵ���"gda"

				#define MAXLEN 255   // Ԥ������󴮳�Ϊ255
				typedef struct
				{
					char ch[MAXLEN]; // ÿ�������洢һ���ַ�(��̬����ʵ��)(����˳��洢)
					int length;      // ����ʵ�ʳ���
				}SString;

				_Bool SubString(SString* Sub, SString S, int pos, int len)
				{
					// �Ӵ���ΧԽ��
					if (pos + len - 1 > S.length)
					{
						// (����ӵ�6���ַ�������4�����ȵ��Ӵ�������û���ַ�����Ҫ��ֹ)
						return 0;
					}

					for (int i = pos; i < pos + len; i++)
					{
						Sub->ch[i - pos + 1] = S.ch[i];
					}

					Sub->length = len;
					return 1;
				}

			�Ƚ�

				|   S.ch [ ][w][a][n][g][d][a][o][ ][ ]
				|         0  1  2  3  4  5  6  7  8  9

				S.ch = "wangdao"
				S.length = 7

				|   T1 [ ][w][b][n][g][d][a][o][ ][ ]
				|       0  1  2  3  4  5  6  7  8  9

				|   T2 [ ][w][a][n][g][ ][ ][ ][ ][ ]
				|       0  1  2  3  4  5  6  7  8  9

				#define MAXLEN 255   // Ԥ������󴮳�Ϊ255
				typedef struct
				{
					char ch[MAXLEN]; // ÿ�������洢һ���ַ�(��̬����ʵ��)(����˳��洢)
					int length;      // ����ʵ�ʳ���
				}SString;

				int StrCompare(SString S, SString T)
				{
					for (int i = 1; i < S.length && i <= T.length; i++)
					{
						if (S.ch[i] != T.ch[i])
						{
							// ���� 'a' - 'b'
							return S.ch[i] - T.ch[i];
						}

						// ɨ����������ַ�����ͬ���򳤶ȳ��Ĵ�����
						return S.length - T.length;
					}
				}

			��λ

				|   S.ch [ ][w][a][n][g][d][a][o][ ][ ]
				|         0  1  2  3  4  5  6  7  8  9

				S.ch = "wangdao"
				S.length = 7

				|   T [ ][w][b][n][g][d][a][o][ ][ ]
				|      0  1  2  3  4  5  6  7  8  9

				�������Ӵ� "gda"
				������ S[1] S[2] S[3] ��ʼ�ң�֮��
				S[2] S[3] S[4]
				S[3] S[4] S[5]
				......
				S[5] S[6] S[7]

				#define MAXLEN 255   // Ԥ������󴮳�Ϊ255
				typedef struct
				{
					char ch[MAXLEN]; // ÿ�������洢һ���ַ�(��̬����ʵ��)(����˳��洢)
					int length;      // ����ʵ�ʳ���
				}SString;

				int StrLength(S){}
				void SubString(SString Sub, SString S, int pos, int len){}
				int StrCompare(SString S, SString T){}

				int Index(SString S, SString T)
				{
					int i = 1;
					int n = StrLength(S);
					int m = StrLength(T);

					SString sub;// �����ݴ��Ӵ�

					while (i <= n - m + 1)
					{
						SubString(sub, S, i, m);
						if (StrCompare(sub, T) != 0)
						{
							i++;
						}
						else
						{
							return i;// �����Ӵ��������е�λ��
						}
					}

					return 0;// S �в������� T ��ȵ��Ӵ�
				}
*/