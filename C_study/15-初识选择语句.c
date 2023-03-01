

/*


*/
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int input = 0;// 输入的值
	printf("学习(1/0)?\n");
	scanf("%d", &input);

	if (input == 1) {
		printf("好offer");
	}
	else {
		printf("卖红薯");
	}

	return 0;
}