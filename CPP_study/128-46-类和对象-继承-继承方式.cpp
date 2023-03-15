
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

				4.6.1 继承的基本语法

				4.6.2 继承方式

					继承的语法：class 子类 : 继承方式 父类

					继承方式一共有三种：

						公共继承
						保护继承
						私有继承

					|                                 |------------|
					|                                 | class A    |
					|                                 | {          |
					|                                 | public:    |
					|                                 |     int a; |
					|                                 | protected: |
					|                                 |     int b; |
					|                                 | private:   |
					|                                 |     int c; |
					|                                 | };         |
					|                                 |------------|
					|
					|                   公                  保                    私
					|                 有                    护                      有
					|               继                      继                        继
					|             承                        承                          承
					|
					|   |--------------------|    |-----------------------|    |---------------------|
					|   | class B : public A |    | class B : protected A |    | class B : private A |
					|   | {                  |    | {                     |    | {                   |
					|   | public:            |    | protected:            |    | private:            |
					|   |     int a;         |    |     int a;            |    |     int a;          |
					|   | protected:         |    |     int b;            |    |     int b;          |
					|   |     int b;         |    |                       |    |                     |
					|   | 不可访问:          |    | 不可访问:             |    | 不可访问:           |
					|   |     int c;         |    |     int c;            |    |     int c;          |
					|   | };                 |    | };                    |    | };                  |
					|   |--------------------|    |-----------------------|    |---------------------|
*/

//公共继承

class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_A; // 父类中的公共权限成员 到子类中依然是公共权限
		m_B; // 父类中的保护权限成员 到子类中依然是保护权限
		//m_C; //不可访问
	}
};

void myClass()
{
	Son1 s1;
	s1.m_A; //其他类只能访问到公共权限
}



//保护继承

class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_A; // 父类中公共成员，到子类中变为保护权限
		m_B; // 父类中保护成员，到子类中还是保护权限
		//m_C; //不可访问
	}
};

void myClass2()
{
	Son2 s;
	//s.m_A; //不可访问
}



//私有继承

class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 :private Base3
{
public:
	void func()
	{
		m_A; // 父类中公共成员 到子类中变为 私有成员
		m_B; // 父类中保护成员 到子类中变为 私有成员
		//m_C; //不可访问
	}
};

class GrandSon3 :public Son3
{
public:
	void func()
	{
		//Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
		//m_A;
		//m_B;
		//m_C;
	}
};
/*
	来自弹幕：一代不如一代啊啊
	来自弹幕：好难啊，生活艰难啊
	来自弹幕：说明了父亲以私有的方式传承，传承不过两代，到孙子就会失传
	来自弹幕：可怜的私生子，啥也没有
*/