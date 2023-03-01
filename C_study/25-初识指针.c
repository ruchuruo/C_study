




/*
	指针
		内存
			1.内存是怎么编号的？
			2.一个这样的内存单元是多大空间？
				最终一个内存单元是一个字节，然后分配地址

		32位	 - 32根地址线 - 物理线 - 通电 - 正1 负0
		64位 - 
		-------------------------------------------
		电信号转换成数字信息：1和0组成的二进制序列
		2的32次方个内存单元


		假设
			一个内存单元是1bit
			4,294,967,296比特 / 8 = 536,870,912字节 / 1024 = 524,288KB / 1024 = 512MB / 1024 = 0.5GB

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 10;// a在内存中要分配空间 - 4字节
	// 取出
	printf("%p\n", &a);// 只会拿到从前往后第一个字节的地址	%p专门用来打印地址


	// 存放
	int* pa = &a;//pa是用来存放地址的，在c语言中pa叫指针变量。* 说明pa是指针变量。int说明pa执行的对象是int类型

	
	char ch = 'w';
	char* pc = &ch;





	// 指针就是地址

	int b = 10;
	int* pb = &b;
	// 存放不是为了存放，是为了以后能找到
	*pb = 20;//* 解引用操作，*pb就是通过pb里面的地址找到b
	printf("%d\n", b);







	// 指针变量大小
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(long*));
	printf("%d\n", sizeof(long long*));
	printf("%d\n", sizeof(float*));
	/*
		指针大小是相同的
			指针是用来存放地址的
			指针需要多大空间，取决于地址的存储需要多大空间


			32位		32bit	4byte
			64位		64bit	8byte
	*/









	return 0;
}