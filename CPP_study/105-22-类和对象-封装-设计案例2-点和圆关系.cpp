
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

				练习案例1：设计立方体类

				练习案例2：点和圆的关系

					设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。

					(点在圆外，点在圆上，点在圆内)
					(点到圆心的距离)
*/

#include "105-22-类和对象-封装-设计案例2-点和圆关系.h"






/*
	点到圆心距离公式：(圆X - 点X)的平方 + (圆Y - 点Y)的平方 再 开根号

	点到圆心距离 和 半径 比较

	简化：(圆X - 点X)的平方 + (圆Y - 点Y)的平方 和 半径的平方 比较
*/
// 判断 点和圆的关系
void isInCircle(Circle& c, Point& p)
{
	// 计算 两点之间距离 的平方
	int distance = 
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	// 计算 半径 的平方
	int rDistance = c.getR() * c.getR();

	// 判断关系
	if (distance == rDistance)
	{
		cout << "点在圆 上" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "点在圆 外" << endl;
	}
	else
	{
		cout << "点在圆 内" << endl;
	}
}


int main()
{
	// 创建圆
	Circle c;
	Point center;// 圆心

	center.setX(10);
	center.setY(0);

	c.setR(10);
	c.setCenter(center);

	// 创建点
	Point p;
	//p.setX(10);// 点在圆 上
	//p.setY(10);// 点在圆 上
	//p.setX(11);// 点在圆 外
	//p.setY(11);// 点在圆 外
	p.setX(9);// 点在圆 内
	p.setY(9);// 点在圆 内

	// 判断关系
	isInCircle(c, p);

	return 0;
}