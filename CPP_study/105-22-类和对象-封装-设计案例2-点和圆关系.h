#pragma once

#include <iostream>

using namespace std;

// 点类（Point）
class Point
{
public:
	// 设置 坐标X
	void setX(int x);

	// 设置 坐标Y
	void setY(int y);

	// 获取 坐标X
	int getX();

	// 获取 坐标Y
	int getY();

private:
	int m_X;
	int m_Y;
};

// 圆形类（Circle）
class Circle
{
public:
	// 设置 半径
	void setR(int r);

	// 设置 圆心
	void setCenter(Point& center);

	// 获取 半径
	int getR();

	// 获取 圆心
	Point& getCenter();

private:
	int m_R;		// 半径
	Point m_Center;	// 圆心坐标，圆心也是一个点
};