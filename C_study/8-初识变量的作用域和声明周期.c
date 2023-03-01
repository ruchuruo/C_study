




/*
	初识变量的作用域和声明周期

		作用域
			局部变量的作用域：变量所在的局部范围
			全局变量的作用域：整个工程

		生命周期
			变量的生命周期：变量的创建和销毁之间的时间段

			局部变量：进入局部范围 到 出局部范围
			全局变量：程序的生命周期
			
*/

#include <stdio.h>


// 声明变量
extern int g_val;

int main()
{
	{
		int a = 10;
		printf("a = %d\n", a);
	}

	printf("%d\n", g_val);

	return 0;
}