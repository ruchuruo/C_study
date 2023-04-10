#pragma once

#include <iostream>

using namespace std;

// 数组类
template <typename T>
class MyArray
{
public:

	// 有参构造 (容量)
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;

		// 根据参数初始化数组容量
		this->pAddress = new T[this->m_Capacity];
	}

	// 拷贝构造
	MyArray(const MyArray& arr)
	{
		// 编译器提供的
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;// 浅拷贝，需要深拷贝

		this->pAddress = new T[arr.m_Capacity];// 深拷贝

		// 将 arr 中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// 运算符重载=，防止浅拷贝带来的问题
	
	// 析构
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			// 来自弹幕：这里是对象数组而不是对象指针数组，所以不需要写for循环去释放每一个数组元素
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress;	// 数组指针
	int m_Size;		// 元素个数
	int m_Capacity;	// 容量
};
