/*
	模仿 库函数qsort 实现一个冒泡排序的通用算法
*/

#include "define.h"

void 交换(char* buf1, char* buf2, int 元素大小)
{
	int i = 0;
	for (i = 0; i < 元素大小; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void 冒泡排序(void* 待排序, int 元素个数, int 元素大小, int (*比较方法)(const void* e1, const void* e2))
{
	// 趟数
	int i = 0;
	for (i = 0; i < 元素个数 - 1; i++)
	{
		// 一趟的排序
		int j = 0;
		for (j = 0; j < 元素个数 - 1 - i; j++)
		{
			// 两个元素比较，强制类型转换，char以一个字节为单位，如果是数据类型是int就再乘以4就可以到下一位了，char*最小
			if (比较方法((char*)待排序 + j * 元素大小, (char*)待排序 + (j + 1) * 元素大小) > 0)
			{
				// 交换
				交换((char*)待排序 + j * 元素大小, (char*)待排序 + (j + 1) * 元素大小, 元素大小);
			}
		}
	}
}




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
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	冒泡排序(arr, sz, sizeof(arr[0]), compar_int);

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

	//冒泡排序(s, sz, sizeof(s[0]), 比较年龄);

	冒泡排序(s, sz, sizeof(s[0]), 比较名字);
}

int main()
{
	整形数据排序();

	printf("\n");

	结构体数据排序();

	return 0;
}