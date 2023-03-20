
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

		4 类和对象

			4.1 封装

			4.2 对象的初始化和清理

			4.3 C++对象模型和this指针

			4.4 友元

			4.5 运算符重载

			4.6 继承

			4.7 多态(多种形态)

				4.7.1 多态的基本概念

				多态的原理剖析

				4.7.2 多态案例一-计算器类

				4.7.3 纯虚函数和抽象类

				4.7.4 多态案例二-制作饮品

				4.7.5 虚析构和纯虚析构

				4.7.6 多态案例三-电脑组装

					案例描述：

						电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）

						将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商

						创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口

						测试时组装三台不同的电脑进行工作

						思路：

							电脑类
								构造函数，传入3个零件指针
								工作函数

							CPU类
								抽象函数

							显卡类
								抽象函数

							内存类
								抽象函数

							具体零件厂商
								厂商 1 CPU
								厂商 1 GPU
								厂商 1 RAM
*/

#include <iostream>

using namespace std;

// 抽象不同零件类

// 抽象 CPU 类
class CPU
{
public:
	virtual void calculate() = 0;
};

// 抽象 显卡 类
class GPU
{
public:
	virtual void display() = 0;
};

// 抽象 内存 类
class RAM
{
public:
	virtual void storage() = 0;
};



// 电脑类
class Computer
{
public:
	Computer(CPU* cpu, GPU* gpu, RAM* ram)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_ram = ram;
	}

	// 工作函数
	void work()
	{
		m_cpu->calculate();
		m_gpu->display();
		m_ram->storage();
	}

	// 释放3个零件
	~Computer()
	{
		if (m_cpu != NULL) { delete m_cpu; m_cpu = NULL; }
		if (m_gpu != NULL) { delete m_gpu; m_gpu = NULL; }
		if (m_ram != NULL) { delete m_ram; m_ram = NULL; }
	}


private:
	// 抽象类不能实例化，但是可以定义一个指向该类的指针
	CPU* m_cpu;
	GPU* m_gpu;
	RAM* m_ram;
};



// 具体厂商

// 厂商1
class manufacturer_1_CPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "manufacturer_1_CPU" << endl;
	}
};

class manufacturer_1_GPU : public GPU
{
public:
	virtual void display()
	{
		cout << "manufacturer_1_GPU" << endl;
	}
};

class manufacturer_1_RAM : public RAM
{
public:
	virtual void storage()
	{
		cout << "manufacturer_1_RAM" << endl;
	}
};

// 厂商2
class manufacturer_2_CPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "manufacturer_2_CPU" << endl;
	}
};

class manufacturer_2_GPU : public GPU
{
public:
	virtual void display()
	{
		cout << "manufacturer_2_GPU" << endl;
	}
};

class manufacturer_2_RAM : public RAM
{
public:
	virtual void storage()
	{
		cout << "manufacturer_2_RAM" << endl;
	}
};





void test1()
{
	// 多态使用条件：父类指针或引用指向子类对象

	// 第一台电脑 零件
	CPU* _1_CPU = new manufacturer_1_CPU;
	GPU* _1_GPU = new manufacturer_1_GPU;
	RAM* _1_RAM = new manufacturer_1_RAM;

	// 第一台电脑 组装
	Computer* computer_1 = new Computer(_1_CPU, _1_GPU, _1_RAM);
	computer_1->work();
	delete computer_1;

	cout << "----" << endl;

	// 第二台电脑 零件
	//CPU* _2_CPU = new manufacturer_2_CPU;
	//GPU* _2_GPU = new manufacturer_2_GPU;
	//RAM* _2_RAM = new manufacturer_2_RAM;

	// 第二台电脑 组装
	Computer* computer_2 = new Computer(new manufacturer_2_CPU, new manufacturer_2_GPU, new manufacturer_2_RAM);
	computer_2->work();
	delete computer_2;

	cout << "----" << endl;

	// 第三台电脑 组装
	Computer* computer_3 = new Computer(new manufacturer_2_CPU, new manufacturer_1_GPU, new manufacturer_2_RAM);
	computer_3->work();
	delete computer_3;
}

int main()
{
	test1();

	return 0;
}