
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

		4 类和对象

		5 文件操作

			程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放

			通过文件可以将数据持久化

			C++中对文件操作需要包含头文件 < fstream > (文件 流)

			文件类型分为两种：

				文本文件 - 文件以文本的ASCII码形式存储在计算机中
				二进制文件 - 文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

			操作文件的三大类:

				ofstream： 写操作
				ifstream： 读操作
				fstream ： 读写操作

			5.1文本文件

				5.1.1写文件

					写文件步骤如下：

						包含头文件
							#include <fstream>

						创建流对象
							ofstream ofs;

						打开文件
							ofs.open("文件路径",打开方式);

						写数据
							ofs << "写入的数据";

						关闭文件
							ofs.close();


					文件打开方式：

						| 打开方式    | 解释                       |
						| ----------- | -------------------------- |
						| ios::in     | 为读文件而打开文件         |
						| ios::out    | 为写文件而打开文件         |
						| ios::ate    | 初始位置：文件尾           |
						| ios::app    | 追加方式写文件             |
						| ios::trunc  | 如果文件存在先删除，再创建 |
						| ios::binary | 二进制方式                 |

					注意： 文件打开方式可以配合使用，利用|操作符

					例如：用二进制方式写文件 ios::binary |  ios:: out

					总结：
						文件操作必须包含头文件 fstream
						读文件可以利用 ofstream ，或者fstream类
						打开文件时候需要指定操作文件的路径，以及打开方式
						利用<<可以向文件中写数据
						操作完毕，要关闭文件
*/

// fopen("..\\测试文件操作\\文件2.txt", "r");

#include <iostream>
#include <fstream>// 包含头文件
#include "Function.h"

using namespace std;

void test1()
{
	// 创建流对象
	ofstream ofs;

	// 打开文件
	ofs.open("..\\测试文件操作\\143-61-C++文件操作-文本文件-写文件.txt", ios::out);

	// 写数据
	ofs << "143-61-C++文件操作-文本文件-写文件.txt" << endl;
	ofs << "abc" << endl;
	ofs << "def" << endl;

	// 关闭文件
	ofs.close();
}

int main()
{
	//fileAccess("..\\测试文件操作\\143-61-C++文件操作-文本文件-写文件.txt", 0);

	return 0;
}