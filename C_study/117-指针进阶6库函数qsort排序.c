/*
	指针进阶
		1.字符指针
		2.数组指针
		3.指针数组
		4.数组传参和指针传参
		5.函数指针
		6.函数指针数组
		7.指向函数指针数组的指针
		8.回调函数
		9.指针和数组面试题的解析

		======== ======== ======== ======== ========
		-------- -------- -------- -------- --------

		8.回调函数
			回调函数就是一个通过函数指针调用的函数。如果你把函数的指针(地址)作为参数传递给另一个函数，
			当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。
			回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，
			由于对该事件或条件进行响应。


			qsort()库函数的使用

				void qsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*));
				有4个参数
					void* base									base中存放的是待排序数据中第一个对象的地址，void*无具体类型的指针，任意数据的地址都能放到base中
					size_t num									排序数据元素的个数
					size_t size									排序数据中一个元素的大小，单位是字节，这样指针就知道能访问多大空间了

					int (*compar)(const void*, const void*)		是用来比较待排序数据中的2个元素的函数
																const表示不可以在函数内部修改，void*表示类型是泛型
																int (*compar)(const void* e1, const void* e2)
																e1里面存的是待比较的第一个元素的地址
																e2里面存的是待比较的第二个元素的地址
																升降序取决于回调函数的返回值，将减号两边表达式互换

					指向空类型的指针，
					接收正数的变量，
					接收正数的变量，
					指向函数的指针（函数参数为不能换指向的指向空类型的指针）

				快速排序的实现
				整形数据	，字符串数据，结构体数据......都能排序

				自己写的冒泡排序不够通用

		-------- -------- -------- -------- --------
		======== ======== ======== ======== ========
*/

#include "define.h"

#include <stdlib.h>
#include <string.h>

// 是用来比较待排序数据中的2个元素的函数
int compar_int(const void* e1, const void* e2)
{
	// 不能直接*e1 *e2，无类型的指针解引用 不知道访问几个字节
	// 先强制类型转换成整形指针，再解引用
	return *(int*)e1 - *(int*)e2;

	// 如果e1指向的元素 > e2指向的元素，相减返回大于0的数字
	// 如果e1指向的元素 = e2指向的元素，相减返回等于0的数字
	// 如果e1指向的元素 < e2指向的元素，相减返回小于0的数字
}
void 打印整形数据(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void 整形数据排序()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	// 使用qsort排序
	qsort(arr, sz, sizeof(arr[0]), compar_int);

	打印整形数据(arr, sz);
}



struct 学生
{
	char name[20];
	int age;
};
int 比较年龄(const void* e1, const void* e2)
{
	// 强制类型转换，结构体指针，再整体括起来
	return ((struct 学生*)e1)->age - ((struct 学生*)e2)->age;
}
int 比较名字(const void* e1, const void* e2)
{
	// strcmp()比较的是ascii码
	return strcmp(((struct 学生*)e1)->name, ((struct 学生*)e2)->name);
}
void 结构体数据排序()
{
	struct 学生 s[] = { {"zhangsan", 30}, {"lisi", 34}, {"wangwu", 20} };
	int sz = sizeof(s) / sizeof(s[0]);

	// 按照年龄排序
	// 使用qsort排序
	//qsort(s, sz, sizeof(s[0]), 比较年龄);

	// 按照名字排序
	qsort(s, sz, sizeof(s[0]), 比较名字);
}

int main()
{
	整形数据排序();

	printf("\n");

	结构体数据排序();

	return 0;
}