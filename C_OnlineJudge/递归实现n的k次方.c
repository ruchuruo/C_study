/*
	递归实现n的k次方
		编写一个函数实现n的k次方，使用递归实现

		公式
						|- k = 0, 1
			次方(n, k)-	|
						|- k > 0, n * 次方(n, k - 1)




		递归实现n的k次方.c(26): warning C4715: “次方”: 不是所有的控件路径都返回值
		代码考虑得不全，n是负数怎么办

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int 次方(int n,int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	if (k > 0)
//	{
//		return n * 次方(n, k - 1);
//	}
//}
// 改进
double 次方(int n, int k)
{
	if (k == 0)
	{
		return 1.0;
	}
	else if (k > 0)
	{
		return n * 次方(n, k - 1);
	}
	else
	{
		// 计算负数			  -k就是正数
		return 1.0 / (次方(n, -k));
	}
}

int main()
{
	int n = 0;
	int k = 0;
	printf("请输入数字>");
	scanf("%d %d", &n, &k);

	double ret = 次方(n, k);
	printf("%lf\n", ret);




	return 0;
}