
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

					多态是C++面向对象三大特性之一

					多态分为两类

						静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
						动态多态: 派生类和虚函数实现运行时多态

					静态多态和动态多态区别：

						静态多态的函数地址早绑定 - 编译阶段确定函数地址
						动态多态的函数地址晚绑定 - 运行阶段确定函数地址

					下面通过案例进行讲解多态

					总结：

						多态满足条件

							有继承关系
							子类重写父类中的虚函数
								(重写 和 重载 不一样，重写是函数返回值相同 函数名相同 形参相同，重载是函数名相同 参数不一样)

						多态使用条件

							父类指针或引用指向子类对象
								(void DoSpeak(Animal& animal)// Animal & animal = cat)

						重写：函数返回值类型 函数名 参数列表 完全一致称为重写


				多态的原理剖析

					父类中有虚函数，子类继承父类，子类会拿到父类中所有内容
						|   +--------------+
						|   | class Animal |
						|   |     vfptr →→→→→ +-------vftable------+
						|   +--------------+  |   &Animal::speak   |
						|                     +--------------------+
						|   +-----------+
						|   | class Cat |
						|   |     vfptr →→→→→ +-------vftable------+
						|   +-----------+     |   &Animal::speak   |
						|                     +--------------------+


					父类中有虚函数，子类继承父类，子类重写父类中的虚函数，
					子类中的 虚函数表 内部会替换成 子类的虚函数地址
						|   +--------------+
						|   | class Animal |
						|   |     vfptr →→→→→ +-------vftable------+
						|   +--------------+  |   &Animal::speak   |
						|                     +--------------------+
						|   +-----------+
						|   | class Cat |
						|   |     vfptr →→→→→ +-----vftable-----+
						|   +-----------+     |   &Cat::speak   |
						|                     +-----------------+


					父类 指针 或 引用 指向 子类对象 的时候，发生多态
						void DoSpeak(Animal& animal)// Animal & animal = cat
						{
							animal.speak();
						}

						当 父类对象animal 调用 speak() 函数的时候，
						因为指向的是 Cat 对象，所以会从 Cat 的虚函数表中找 speak() 函数，
						相当于是在运行阶段发生的动态的多态，
						传的是 Cat 对象，就找 Cat 的 虚函数表中的 speak() 函数的地址


					vfptr 虚函数指针(虚函数表指针)
						v   - virtual  虚
						f   - function 函数
						ptr - pointer  指针

						vfptr 虚函数指针 会指向 vftable 虚函数表

					vftable 虚函数表
						v     - virtual  虚
						f     - function 函数
						table - table    表

						表内部记录 虚函数 的地址

							+--------------------+
							|   &Animal::speak   |
							+--------------------+

*/

#include <iostream>

using namespace std;

class Animal
{
public:

	//void speak()
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:

	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:

	void speak()
	{
		cout << "小狗在说话" << endl;
	}

};


void DoSpeak(Animal& animal)
{
	animal.speak();
}



void test01()
{
	Cat cat;
	DoSpeak(cat);


	Dog dog;
	DoSpeak(dog);
}

void test02()
{
	cout << "Animal size:" << sizeof(Animal) << endl;

	// 非静态成员函数 不属于对象上 Animal size:1
	// 虚函数                     Animal size:8

	/*
		加上 virtual 关键字后多了些许字节，是指针 vfptr
	*/
}


int main()
{
	//test01();

	test02();

	return 0;
}
