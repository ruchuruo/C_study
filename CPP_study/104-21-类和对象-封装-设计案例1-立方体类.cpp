
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

					设计立方体类(Cube)

					求出立方体的面积和体积

					分别用全局函数和成员函数判断两个立方体是否相等。
*/

#include <iostream>

using namespace std;


class Cube
{
public:

	// 设置 长
	void setLength(int L)
	{
		m_L = L;
	}

	// 设置 宽
	void setWidth(int W)
	{
		m_W = W;
	}

	// 设置 高
	void setHeight(int H)
	{
		m_H = H;
	}

	// 获取 长
	int getLength()
	{
		return m_L;
	}

	// 获取 宽
	int getWidth()
	{
		return m_W;
	}

	// 获取 高
	int getHeight()
	{
		return m_H;
	}

	// 计算立方体面积：S = 2(ab + ac + bc)
	int cubeS()
	{
		return 2 * ( (m_L * m_W) + (m_L * m_H) + (m_W * m_H) );
	}

	// 计算立方体体积：
	int cubeV()
	{
		return m_L * m_W * m_H;
	}

	// 成员函数 判断两个立方体是否相等
	int isSameByClass(Cube& c)
	{
		if
		(
			m_L == c.getLength() &&
			m_W == c.getWidth() &&
			m_H == c.getHeight()
		)
		{
			return 1;// 相等
		}
		else
		{
			return 0;
		}
	}

private:
	int m_L;// 长
	int m_W;// 宽
	int m_H;// 高
};


// 全局函数 判断两个立方体是否相等
int isSame(Cube &c1, Cube &c2)
{
	if
	(
		c1.getLength() == c2.getLength() && 
		c1.getWidth() == c2.getWidth() && 
		c1.getHeight() == c2.getHeight()
	)
	{
		return 1;// 相等
	}
	else
	{
		return 0;
	}
}

int main()
{
	Cube c1;
	Cube c2;

	c1.setLength(10);
	c1.setWidth(10);
	c1.setHeight(10);

	c2.setLength(10);
	c2.setWidth(10);
	c2.setHeight(10);

	cout << "c1的面积" << c1.cubeS() << endl;
	cout << "c1的体积" << c1.cubeV() << endl;

	cout << "c2的面积" << c2.cubeS() << endl;
	cout << "c2的体积" << c2.cubeV() << endl;

	cout << isSame(c1, c2) << endl;
	cout << c1.isSameByClass(c2) << endl;

	
	/*
		来自弹幕：确实main里写简单了，然后后期开发扩充立方体的功能（旋转，对角线，投影，外接球类，甚至是继承正方体类等等）就有你好受的了
	*/

	return 0;
}