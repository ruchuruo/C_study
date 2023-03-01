
/*
	1 C++初识

	2 数据类型

	3 运算符

	4 程序流程结构

	5 数组

	6 函数

	7 指针

	8 结构体

		8.1 结构体基本概念

		8.2 结构体定义和使用

		8.3 结构体数组

		8.4 结构体指针

		8.5 结构体嵌套结构体

		8.6 结构体做函数参数

		8.7 结构体中 const使用场景

		8.8 结构体案例

			8.8.1 案例1

			8.8.2 案例2

				案例描述：

					设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

					通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。

					五名英雄信息如下：

						{"刘备",23,"男"},
						{"关羽",22,"男"},
						{"张飞",20,"男"},
						{"赵云",21,"男"},
						{"貂蝉",19,"女"},

					示例：

						//英雄结构体
						struct hero
						{
							string name;
							int age;
							string sex;
						};
						//冒泡排序
						void bubbleSort(hero arr[] , int len)
						{
							for (int i = 0; i < len - 1; i++)
							{
								for (int j = 0; j < len - 1 - i; j++)
								{
									if (arr[j].age > arr[j + 1].age)
									{
										hero temp = arr[j];
										arr[j] = arr[j + 1];
										arr[j + 1] = temp;
									}
								}
							}
						}
						//打印数组
						void printHeros(hero arr[], int len)
						{
							for (int i = 0; i < len; i++)
							{
								cout << "姓名： " << arr[i].name << " 性别： " << arr[i].sex << " 年龄： " << arr[i].age << endl;
							}
						}

						int main() {

							struct hero arr[5] =
							{
								{"刘备",23,"男"},
								{"关羽",22,"男"},
								{"张飞",20,"男"},
								{"赵云",21,"男"},
								{"貂蝉",19,"女"},
							};

							int len = sizeof(arr) / sizeof(hero); //获取数组元素个数

							bubbleSort(arr, len); //排序

							printHeros(arr, len); //打印

							system("pause");

							return 0;
						}
*/

#include <iostream>

using namespace std;

struct hero
{
	string name;
	int age;
	string sex;
};

void BubbleSort(struct hero arr[], int arrLen)
{
	// 开始排序
	// 排序总轮数 = 元素个数 - 1
	for (int i = 0; i < arrLen - 1; i++)
	{
		// 每轮对比次数 = 元素个数 - 排序轮数 - 1
		for (int j = 0; j < arrLen - 1 - i; j++)
		{
			if (arr[j].age > arr[j + 1].age)
			{
				struct hero temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void heroPrint(struct hero arr[], int arrLen)
{
	for (int i = 0; i < arrLen; i++)
	{
		cout << arr[i].name << arr[i].age << arr[i].sex << endl;
	}
}

int main()
{
	struct hero heroArr[5] =
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};

	int heroArrLen = sizeof(heroArr) / sizeof(heroArr[0]);

	BubbleSort(heroArr, heroArrLen);

	heroPrint(heroArr, heroArrLen);

	return 0;
}