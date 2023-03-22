
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

		4 类和对象

		5 文件操作

			5.1文本文件

				5.1.1写文件

				5.1.2读文件

					读文件与写文件步骤相似，但是读取方式相对于比较多

					读文件步骤如下：

						包含头文件
							#include <fstream>

						创建流对象
							ifstream ifs;

						打开文件并判断文件是否打开成功
							ifs.open("文件路径",打开方式);

						读数据
							四种方式读取

						关闭文件
							ifs.close();

					总结：
						读文件可以利用 ifstream ，或者fstream类
						利用is_open函数可以判断文件是否打开成功
						close 关闭文件
*/

#include <iostream>
#include <fstream>// 包含头文件
#include <string>
#include "Function.h"

using namespace std;

void test1()
{
	// 判断文件是否存在，判断文件权限
	if (fileAccess("..\\测试文件操作\\CPP_study_144-62-C++文件操作-文本文件-读文件.txt", 0) == 0) { return; }

	// 创建流对象
	ifstream ifs;

	// 打开文件
	ifs.open("..\\测试文件操作\\CPP_study_144-62-C++文件操作-文本文件-读文件.txt", ios::in);

	// 并判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;

		return;
	}

	// 读数据
	
	// 第一种
	//char buf[1024] = { 0 };
	//while (ifs >> buf)// 读到文件尾返回 假
	//{
	//	cout << buf << endl;
	//}

	// 第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	/*
	//		ifs.getline(buf, sizeof(buf))
	//		ifs.获取一行(放哪, 最多读多少字节)
	//	*/

	//	cout << buf << endl;
	//}

	// 第三种
	string buf;
	while (getline(ifs, buf))
	{
		/*
			getline(基础输入流, 放哪)
			全局函数
			在 <string> 中
		*/

		cout << buf << endl;
	}

	// 第四种 不推荐用
	//char c;
	//while ( (c = ifs.get()) != EOF )
	//{
	//	/*
	//		ifs.get()
	//		一次读一个字符

	//		EOF 文件末尾 end of file
	//	*/
	//	cout << c;
	//}


	// 关闭文件
	ifs.close();
}


int main()
{
	test1();

	return 0;
}