
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程
		
		本阶段主要针对C++ 泛型编程 和 STL 技术做详细讲解，探讨C++更深层的使用

		1 模板

			1.1 模板的概念

			1.2 函数模板

					1.2.1 函数模板语法

					1.2.2 函数模板注意事项

					1.2.3 函数模板案例

						案例描述：

							利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
							排序规则从大到小，排序算法为选择排序
							分别利用char数组和int数组进行测试

						总结：模板可以提高代码复用，需要熟练掌握
*/

#include <iostream>

using namespace std;

//交换的函数模板
template<typename T>
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}


template<class T> // 也可以替换成typename
//利用选择排序，进行对数组从大到小的排序
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; //最大数的下标

        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j])// 认定的最大值 比 遍历出的数值 要小，说明 j 下标的元素才是真正的最大值
            {
                max = j;// 更新最大值下标
            }
        }

        if (max != i) //如果最大数的下标不是i，交换两者
        {
            mySwap(arr[max], arr[i]);
        }
    }
}


template<typename T>
void printArray(T arr[], int len)
{

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


void test01()
{
    //测试char数组
    char charArr[] = "bdcfeagh";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num);
}

void test02()
{
    //测试int数组
    int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArray(intArr, num);
}

int main()
{
    test01();
    test02();

    return 0;
}