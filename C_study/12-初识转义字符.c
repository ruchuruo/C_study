



/*
	转义字符

	printf在打印数据的时候，可以指定打印的格式

*/
#include <stdio.h>

int main()
{
	// \t的效果就是打印八个空格，相等与tab键
	printf("c:\\test\\test.c");

	printf("\n");

	printf("(are you ok??)");// ??) -- ] 三字母词

	printf("\n");

	printf("%c", '\'');

	printf("\a");

	printf("\n");

	printf("%c", '\130');// 8进制的130是10进制的X
						// X - ASCII码值是88

	printf("\n");

	printf("%d", strlen("abc"));

	return 0;
}