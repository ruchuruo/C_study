
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

		4 类和对象

			C++面向对象的三大特性为： 封装、继承、多态

			C++认为 万事万物都皆为对象 ，对象上有其属性和行为

			例如：

				人可以作为对象，属性有姓名、年龄、身高、体重...，行为有走、跑、跳、吃饭、唱歌...

				车也可以作为对象，属性有轮胎、方向盘、车灯...,行为有载人、放音乐、放空调...

				具有相同性质的 对象 ，我们可以抽象称为 类 ，人属于人类，车属于车类

			4.1 封装

				4.1.1 封装的意义

					封装是C++面向对象三大特性之一

					封装的意义：

						将属性和行为作为一个整体，表现生活中的事物
						将属性和行为加以权限控制

					封装意义一：

						在设计类的时候，属性和行为写在一起，表现事物

					封装意义二：

						类在设计时，可以把属性和行为放在不同的权限下，加以控制

						访问权限有三种：

							public 公共权限
							protected 保护权限
							private 私有权限

					语法： class 类名{ 访问权限： 属性 / 行为 };
*/

#include <iostream>

using namespace std;

/* ======== ======== ======== ======== ======== ======== ======== ======== */

// 示例1：设计一个圆类，求圆的周长
// 圆周长公式：2 * PI * 半径
//圆周率
const double PI = 3.14;

//1、封装的意义
//将属性和行为作为一个整体，用来表现生活中的事物

//封装一个圆类，求圆的周长
//class代表设计一个类，后面跟着的是类名
class Circle
{
public:  //访问权限  公共的权限

	//属性
	int m_r;//半径

	//行为
	//获取到圆的周长
	double calculateZC()
	{
		//2 * pi  * r
		//获取圆的周长
		return  2 * PI * m_r;
	}

	// 属性一般用变量，行为一般用函数
};

void test1()
{
	//通过圆类，创建圆的对象
	// c1就是一个具体的圆
	Circle c1;
	c1.m_r = 10; //给圆对象的半径 进行赋值操作

	//2 * pi * 10 = = 62.8
	cout << "圆的周长为： " << c1.calculateZC() << endl;
}

/* ======== ======== ======== ======== ======== ======== ======== ======== */

// 示例2：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
//学生类
class Student
{
	/*
		类中的 属性 和 行为，统一称为 成员

		类中的 属性 也可以叫做：成员属性 成员变量
		类中的 行为 也可以叫做：成员函数 成员方法
	*/

public:
	void setName(string name)
	{
		m_name = name;
	}
	void setID(int id)
	{
		m_id = id;
	}

	void showStudent()
	{
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
public:
	string m_name;
	int m_id;
};

void test2()
{
	Student stu;
	stu.setName("德玛西亚");
	stu.setID(250);
	stu.showStudent();
}

/* ======== ======== ======== ======== ======== ======== ======== ======== */

// 类在设计时，可以把属性和行为放在不同的权限下，加以控制
//三种权限
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问
//私有权限  private    类内可以访问  类外不可以访问
/*
	保护权限 和 私有权限 有区别，之后会学到 继承，就能体会到区别了。

	继承有父子关系，父类 和 子类，
	如果是 保护权限，父类 中的内容 子类 也可以访问
	如果是 私有权限，父类 中的内容 子类 不可以访问，来自弹幕：《 他 也 不 想 让 儿 子 知 道 》
*/

class Person
{
	//姓名  公共权限
public:
	string m_Name;

	//汽车  保护权限
protected:
	string m_Car;

	//银行卡密码  私有权限
private:
	int m_Password;

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;
	}
};

void test3()
{
	Person p;
	p.m_Name = "李四";
	//p.m_Car = "奔驰";		//保护权限类外访问不到
	//p.m_Password = 123;	//私有权限类外访问不到
	// 来自弹幕：无视风险！继续访问！
}

/* ======== ======== ======== ======== ======== ======== ======== ======== */

int main()
{
	// 示例1：设计一个圆类，求圆的周长
	test1();

	// 示例2：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
	test2();

	// 类在设计时，可以把属性和行为放在不同的权限下，加以控制
	test3();

	return 0;
}