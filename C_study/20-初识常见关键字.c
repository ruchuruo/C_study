/*
	c语言提供的关键字
		1. c语言提供的，不能自己创建关键字
		2. 关键字不能做变量名

	常见关键字
		auto		自动 - 每个局部变量都是auto修饰的(新的c语言语法中也有其他用法)
		break		break跳出循环的
		case	

		char		字符类型

		const		常变量 不能修改
		continue	继续
		default		默认
		do			do...while 循环

		double		双精度浮点型

		else		if...else语句
		enum		枚举
		extern		声明外部符号

		float		单精度浮点型

		for			for循环
		goto	
		if

		int			整形
		logn		长整形

		register	寄存器关键字
		return		返回

		short		短整形
		signed		有符号的		10		-10

		sizeof		求大小
		static		静态的	1.修饰局部变量 2.修饰全局变量 3.修饰函数
		struct		结构
		switch		
		typedef		类型定义		类型重定义
		union		联合体(共用体)

		unsigned	无符号的
		void		无(空)

		volatile	
		while		while循环



		define		不是关键字	预处理指令
		include		不是关键字	预处理指令



*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// typedef将unsigned重新起名为u_int
typedef unsigned int u_int;





// static		静态的	1.修饰局部变量 
//							改变了局部变量的生命周期(本质上改变了变量的存储类型)
							//				   内存
							//		|=======================|
							//		|-----------------------|
							//		|-局部变量				|
							//		|-函数的参数				|
							//栈区	|-(临时的变量都放在这)	|
							//		|-						|
							//		|-						|
							//		|-----------------------|
							//		|=======================|
							//		|-----------------------|
							//		|-动态内存分配			|
							//		|-						|
							//堆区	|-						|
							//		|-						|
							//		|-						|
							//		|-----------------------|
							//		|=======================|
							//		|-----------------------|
							//		|-全局变量				|
							//		|-static修饰的静态变量	|
							//静态区	|-						|
							//		|-						|
							//		|-						|
							//		|-----------------------|
							//		|=======================|
//
// 
//						2.修饰全局变量 
//							static修饰全局变量，使得这个全局变量只能在自己所在的源文件(.c)内部使用，其他源文件不能使用
// 
//							全局变量在其他源文件内部可以被使用，是因为全局变量具有 外部链接 属性，
//							但是被static修饰之后，就变成了 内部链接 属性，其他源文件就不能链接到这个静态的全局变量了
// 
//						3.修饰函数
//							static修饰函数，使得函数只能在自己所在的源文件内部使用，不能在其他源文件内部使用
//							
//							本质上：static是将函数的 外部链接 属性变成了 内部链接 属性(和static修饰全局变量一样)
//
//
//
//
void test()
{
	static int c = 1;
	c++;
	printf("%d\n", c);
}



// 2.修饰全局变量 
// 全局变量在整个工程都可以使用
// 声明
// extern 声明外部符号
extern int g_val;



// 3.修饰函数
// 声明函数
// 只需要告诉 返回类型 函数名 (返回参数类型
extern int Add(int x, int y);

int main()
{
	int a = 10;// 自动创建，自动销毁 - 自动变量(auto int a = 10;)

	register int num = 100;// 建议num的值存放在寄存器中 - 大量频繁被使用的数据，想放在寄存器中，提升效率
						   /*
							  计算机中数据可以存放在
								硬盘			500g
								内存			16g
								高速缓存		几十mb
								寄存器		更小
						   
						   */ 


	// typedef将unsigned重新起名为u_int
	unsigned int num2 = 100;
	u_int num3 = 100;



	// static		静态的	1.修饰局部变量 2.修饰全局变量 3.修饰函数
	// 1.修饰局部变量
	int b = 0;
	while (b < 10)
	{
		test();
		b++;
	}


	// 2.修饰全局变量
	//printf("%d\n", g_val);


	// 3.修饰函数
	int d = 10;
	int e = 20;
	int sum = Add(d, e);
	printf("sum = %d\n", sum);



	return 0;
}