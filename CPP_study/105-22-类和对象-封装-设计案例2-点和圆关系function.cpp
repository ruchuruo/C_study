
#include "105-22-类和对象-封装-设计案例2-点和圆关系.h"

/*
	头文件中声明类之后，实现只需要写 成员函数 的实现，
	但是 成员函数名 前需要加上 是哪个类的作用域，比如：
		返回值类型 作用域::函数名()

*/

// 点类（Point）

// 设置 坐标X
void Point::setX(int x)
{
	m_X = x;
}

// 设置 坐标Y
void Point::setY(int y)
{
	m_Y = y;
}

// 获取 坐标X
int Point::getX()
{
	return m_X;
}

// 获取 坐标Y
int Point::getY()
{
	return m_Y;
}



// 圆形类（Circle）

// 设置 半径
void Circle::setR(int r)
{
	m_R = r;
}

// 设置 圆心
void Circle::setCenter(Point& center)
{
	m_Center = center;
}

// 获取 半径
int Circle::getR()
{
	return m_R;
}

// 获取 圆心
Point& Circle::getCenter()
{
	return m_Center;
}
