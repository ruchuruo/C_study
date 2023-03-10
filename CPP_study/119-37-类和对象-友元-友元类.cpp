
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

				4.4.1 全局函数做友元

				4.4.2 类做友元
*/

#include <iostream>

using namespace std;

class Building;// 声明 Building 类

class goodGay
{
public:

    goodGay();
    void visit();

private:
    Building* building;
};


class Building
{
    //告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
    friend class goodGay;

public:
    Building();

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom;//卧室
};



Building::Building()
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

goodGay::goodGay()
{
    // 来自弹幕：
    //     如果不用new，单纯只用Building building ；则在  goodGay gg ;  之后building将被释放
    //     之后再调用building里的属性就会访问到空指针然后出错，所以要用new开辟堆区数据
    building = new Building;
}

void goodGay::visit()
{
    cout << "好基友正在访问" << building->m_SittingRoom << endl;
    cout << "好基友正在访问" << building->m_BedRoom << endl;
}



void test01()
{
    goodGay gg;
    gg.visit();
}

int main()
{
    test01();

    return 0;
}