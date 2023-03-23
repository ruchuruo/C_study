
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

				5.2.2 读文件

					二进制方式读文件主要利用流对象调用成员函数read

					函数原型：istream& read(char *buffer,int len);

					参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

					文件输入流对象 可以通过read函数，以二进制方式读数据
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

// 写文件
void writeFile()
{
	// 判断文件是否存在，判断文件权限
	if (fileAccess("..\\测试文件操作\\CPP_study_146-64-C++文件操作-二进制文件-读文件.txt", 0) == 0) { return; }

	// 创建流对象
	ofstream ofs;
	//ofstream ofs("..\\测试文件操作\\CPP_study_145-63-C++文件操作-二进制文件-写文件.txt", ios::out | ios::binary);

	// 打开文件
	ofs.open("..\\测试文件操作\\CPP_study_146-64-C++文件操作-二进制文件-读文件.txt", ios::out | ios::binary);

	// 写文件
	Person p = { "CPP_study_146-64-C++文件操作-二进制文件-读文件", "张三", 18 };

	// 强制类型转换，因为函数需要传入 const char* 这个类型
	ofs.write((const char*)&p, sizeof(Person));

	// 关闭文件
	ofs.close();
}

// 读文件
void readFile()
{
	// 判断文件是否存在，判断文件权限
	if (fileAccess("..\\测试文件操作\\CPP_study_146-64-C++文件操作-二进制文件-读文件.txt", 0) == 0) { return; }

	// 创建流对象
	ifstream ifs;

	// 打开文件 判断文件是否打开成功
	ifs.open("..\\测试文件操作\\CPP_study_146-64-C++文件操作-二进制文件-读文件.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	// 读文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));

	cout << p.m_FileName << endl;
	cout << p.m_Name << endl;
	cout << p.m_Age << endl;

	// 关闭文件
	ifs.close();
}

int main()
{
	// 写文件
	writeFile();

	// 读文件
	readFile();

	return 0;
}