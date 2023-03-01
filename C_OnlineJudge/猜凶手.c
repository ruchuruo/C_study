/*
	猜凶手
		通过排查确定杀人凶手必为4个嫌疑犯中的一个

		A：不是我
		B：是C
		C：是D
		D：C在胡说

		已知3个人说了真话，1个人说了假话
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	char kill = 0;
	for (kill = 'A'; kill <= 'D'; kill++)// ABCD差值是1
	{
		if ((kill != 'A') + (kill == 'C') + (kill == 'D') + (kill != 'D') == 3)
		{
			printf("%c", kill);
		}
	}

	return 0;
}