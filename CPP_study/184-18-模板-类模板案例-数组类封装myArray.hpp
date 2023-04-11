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
		//cout << "MyArray 有参构造 调用" << endl;

		this->m_Capacity = capacity;
		this->m_Size = 0;

		// 根据参数初始化数组容量
		this->pAddress = new T[this->m_Capacity];
	}

	// 拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray 拷贝构造 调用" << endl;

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

		/*
			关于释放旧数据问题：
				来自弹幕：个人觉得是因为拷贝构造函数一般是创建对象时用的，刚创建肯定没有东西，所以不需要清除
		*/
	}

	// 运算符重载=，防止浅拷贝带来的问题
	// 返回引用，链式编程，a = b = c
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray 运算符重载= 调用" << endl;

		// 判断原来堆区是否有数据
		if (this->pAddress != NULL)
		{
			// 如果有先释放
			delete[]pAddress;
			pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// 深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];// 深拷贝

		// 将 arr 中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}
	
	// 析构
	~MyArray()
	{
		//cout << "MyArray 析构 调用" << endl;

		if (this->pAddress != NULL)
		{
			//cout << "MyArray 析构 调用 释放" << endl;

			// 来自弹幕：这里是对象数组而不是对象指针数组，所以不需要写for循环去释放每一个数组元素
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}

	// 尾插
	void PushBack(const T& val)
	{
		// 判断容量是否满
		if (this->m_Capacity == this->m_Size)
		{
			cout << "满" << endl;
			return;
		}

		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	// 尾删
	void PopBack()
	{
		// 判断是否有元素
		if (this->m_Size == 0)
		{
			cout << "空" << endl;
			return;
		}

		this->m_Size--;
	}

	// 通过下标的方式访问数组中的元素
	// 运算符重载[]
	// 返回引用，链式编程，arr[0] = 100
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	// 获取数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	
	// 获取数组大小
	int getSize()
	{
		return this->m_Size;
	}

private:
	T* pAddress;	// 数组指针
	int m_Size;		// 元素个数
	int m_Capacity;	// 容量
};
