
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

		4 类和对象

			4.1 封装

				4.1.1 封装的意义

				4.1.2 struct和class区别

				4.1.3 成员属性设置为私有

					优点1：将所有成员属性设置为私有，可以自己控制读写权限

					优点2：对于写权限，我们可以检测数据的有效性
*/

#include <iostream>

using namespace std;

class Person
{
public:

    //姓名设置可读可写
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }


    //获取年龄 
    int getAge()
    {
        return m_Age;
    }
    //设置年龄
    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            cout << "你个老妖精!" << endl;
            return;
        }
        m_Age = age;
    }

    //情人设置为只写
    void setLover(string lover)
    {
        m_Lover = lover;
    }

private:
    string m_Name; //可读可写  姓名

    int m_Age; //只读  年龄

    string m_Lover; //只写  情人
};


int main()
{
    Person p;
    //姓名设置
    p.setName("张三");
    cout << "姓名： " << p.getName() << endl;

    //年龄设置
    p.setAge(50);
    cout << "年龄： " << p.getAge() << endl;

    //情人设置
    p.setLover("苍井");
    //cout << "情人： " << p.m_Lover << endl;  //只写属性，不可以读取

    /*
        来自弹幕：老师您堕落了
        来自弹幕：小甲鱼附体
    */

    return 0;
}