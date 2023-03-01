#define _CRE_SECURE_NO_WARNINGS 1
/*
	.c源文件
	.h头文件


	写代码
		1 写出主函数(main函数)
			c语言是从主函数的第一行开始执行的 所以c语言代码中得有main函数-入口
			一个工程中可以有多个.c文件 但是多个.c文件中只能有一个main函数

			int				main()
			函数返回类型		函数名

			{
				return 0;
			}
			函数体



			printf-库函数-在屏幕上打印信息
				printf 的使用也要打招呼(引用头文件 stdio.h)

			#include-包含头文件
				#include <stdio.h>
				包含		 <文件名>
*/
#include <stdio.h>

int main()
{
	printf("123");

	return 0;
}