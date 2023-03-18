
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
*/

#include <iostream>

using namespace std;

class Animal
{
public:
	//Speak函数就是虚函数
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:

	// 子类函数可以不加关键字 virtual
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


//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编
//(如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段绑定)
void DoSpeak(Animal& animal)// Animal & animal = cat
{
	// C++ 中允许父子之间的类型转换，不需要做强制类型转换

	animal.speak();// 现在 speak() 函数是多态的，传谁的就执行谁的说话
}
//
//多态满足条件： 
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象


void test01()
{
	Cat cat;
	DoSpeak(cat);


	Dog dog;
	DoSpeak(dog);
}


int main()
{
	test01();

	return 0;
}
