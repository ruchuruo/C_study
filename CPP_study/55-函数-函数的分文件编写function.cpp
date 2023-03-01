
#include "55-函数-函数的分文件编写.h"

void my_swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}