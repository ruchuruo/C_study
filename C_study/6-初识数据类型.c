






/*
	数据类型
		char		字符数据类型
		short		短整形
		int			整形
		long		长整形
		long long	更长的整形
		float		单精度浮点数
		double		双精度浮点数

	计算机中的单位
		bit		- 比特位
		byte	- 字节 = 8bit
		kb		- 1024byte
		mb		- 1024kb
		gb		- 1024mb
		tb		- 1024gb
		pb		- 1024tb

	C语言标准
		为什么long没有大于int？
		sizeof(long) >= sizeof(int)

	C语言为什么有那么多类型？
		选择合适的类型空间利用率更高
*/
#include <stdio.h>

int main()
{
	// 字符a
	char ch = "a";

	//整形
	int age = 20;
	short num = 10;

	//小数
	float weight = 55.5;
	double d = 0.0;


	printf("%d\n", 100);// 打印一个整数 - %d

	// sizeof - 关键字 - 操作符 - 计算类型或者变量所占空间的大小
	// sizeof单位是字节byte
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));

	return 0;
}