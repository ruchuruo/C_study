/*
#include<stdint.h>
int main()
{
	printf("hello world");

	getchar();//防止程序闪退，观看运行结果
	return 0;
}
*/

/*
#include <stdio.h>

int main(void) {
	printf("4.1.2和4.1.3反了，自学的的朋友注意一下);
	return 0;
}
*/


/*
#include <stdio.h>

int main()
{
	// %d 说明后面有一个整数要输出在这个位置上
	// printf("12 + 34=%d\n" , 12 + 34);
	// printf("100-23=%d\n", 100 - 23);

	int 价格 = 0;

	printf("请输入金额");
	scanf("%d", &价格);

	int 改变 = 100 - 价格;

	printf("找您%d元\n", 改变);

	return 0;
}


*/


#include <stdio.h>

int main()
{
	// const 是关键字，加上去就代表后面的名称是常量名
	/*	const是一个修饰符，加在int的前面，
		用来给这个变量加上一个const(不变的)的属性。
		这个const的属性表示这个变量的值一旦初始化，
		就不能再修改了
		const int AMOUNT = 100;
	*/
	int 金额 = 100;
	int 价格 = 0;

	printf("请输入金额（元）：");
	// vs要用scanf_s不然会报错
	// 在scanf里面要让它读取什么东西，一定要把&加在变量名字前面
	scanf_s("%d", &价格);

	printf("请输入票面");
	scanf_s("%d", &金额);

	int 改变 = 金额 - 价格;

	printf("找您%d元。\n", 改变);








	int a;
	int b;

	printf("请输入两个整数");
	scanf_s("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a + b);

	return 0;
}

/*
	变量初始化
		<类型名称><变量名称> = <初始值>
		int 价格 = 0;

	组合变量定义的时候 也可也在这个定义中单独给单个变量赋初始值
		int 价格,数量;
		int 价格 = 0, 数量 = 100;
*/