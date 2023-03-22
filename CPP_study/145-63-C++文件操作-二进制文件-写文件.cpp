
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

			5.2 二进制文件

				以二进制的方式对文件进行读写操作

				打开方式要指定为 ios::binary

				5.2.1 写文件

					二进制方式写文件主要利用流对象调用成员函数write

					函数原型 ：ostream& write(const char * buffer,int len);

					参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

					总结：
						文件输出流对象 可以通过write函数，以二进制方式写数据

					写字符串时用 string 类型可能会出问题，可以用 字符数组 char ch[64]，
					来自弹幕：C++string本质是一个类，所以会把类写进去
*/

#include <iostream>
#include <fstream>// 包含头文件
#include "Function.h"
using namespace std;

class Person
{
public:
	char m_FileName[64];
	char m_Name[64];
	int m_Age;
};

void test1()
{
	// 判断文件是否存在，判断文件权限
	if (fileAccess("..\\测试文件操作\\CPP_study_145-63-C++文件操作-二进制文件-写文件.txt", 0) == 0) { return; }

	// 创建流对象
	ofstream ofs;
	//ofstream ofs("..\\测试文件操作\\CPP_study_145-63-C++文件操作-二进制文件-写文件.txt", ios::out | ios::binary);

	// 打开文件
	ofs.open("..\\测试文件操作\\CPP_study_145-63-C++文件操作-二进制文件-写文件.txt", ios::out | ios::binary);

	// 写文件
	Person p = { "CPP_study_145-63-C++文件操作-二进制文件-写文件", "张三", 18 };

	// 强制类型转换，因为函数需要传入 const char* 这个类型
	ofs.write((const char*)&p, sizeof(Person));

	// 关闭文件
	ofs.close();
}

int main()
{
	test1();

	return 0;
}