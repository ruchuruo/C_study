
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

				继承是面向对象三大特性之一

				有些类与类之间存在特殊的关系，例如下图中：

					|                          动物
					|                        ↙    ↘
					|                      猫        狗
					|                    ↙            ↘
					|   加菲猫 布偶猫 ... 波斯猫    哈士奇 京巴 ... 德国牧羊犬

				我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特性。

				这个时候我们就可以考虑利用继承的技术，减少重复代码


				4.6.1 继承的基本语法

					例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同

					接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处

					普通实现：

						//Java页面
                        class Java 
                        {
                        public:
                            void header()
                            {
                                cout << "首页、公开课、登录、注册...（公共头部）" << endl;
                            }
                            void footer()
                            {
                                cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
                            }
                            void left()
                            {
                                cout << "Java,Python,C++...(公共分类列表)" << endl;
                            }
                            void content()
                            {
                                cout << "JAVA学科视频" << endl;
                            }
                        };
                        //Python页面
                        class Python
                        {
                        public:
                            void header()
                            {
                                cout << "首页、公开课、登录、注册...（公共头部）" << endl;
                            }
                            void footer()
                            {
                                cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
                            }
                            void left()
                            {
                                cout << "Java,Python,C++...(公共分类列表)" << endl;
                            }
                            void content()
                            {
                                cout << "Python学科视频" << endl;
                            }
                        };
                        //C++页面
                        class CPP 
                        {
                        public:
                            void header()
                            {
                                cout << "首页、公开课、登录、注册...（公共头部）" << endl;
                            }
                            void footer()
                            {
                                cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
                            }
                            void left()
                            {
                                cout << "Java,Python,C++...(公共分类列表)" << endl;
                            }
                            void content()
                            {
                                cout << "C++学科视频" << endl;
                            }
                        };

                        void test01()
                        {
                            //Java页面
                            cout << "Java下载视频页面如下： " << endl;
                            Java ja;
                            ja.header();
                            ja.footer();
                            ja.left();
                            ja.content();
                            cout << "--------------------" << endl;

                            //Python页面
                            cout << "Python下载视频页面如下： " << endl;
                            Python py;
                            py.header();
                            py.footer();
                            py.left();
                            py.content();
                            cout << "--------------------" << endl;

                            //C++页面
                            cout << "C++下载视频页面如下： " << endl;
                            CPP cp;
                            cp.header();
                            cp.footer();
                            cp.left();
                            cp.content();

                        }

                        int main() {

                            test01();

                            system("pause");

                            return 0;
                        }

                    总结：

                        继承的好处：可以减少重复的代码

                        class A : public B;

                        A 类称为子类 或 派生类

                        B 类称为父类 或 基类

                        派生类中的成员，包含两大部分：

                        一类是从基类继承过来的，一类是自己增加的成员。

                        从基类继承过过来的表现其共性，而新增的成员体现了其个性。
*/

#include <iostream>

using namespace std;

// 继承实现：

//公共页面
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }

    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java,Python,C++...(公共分类列表)" << endl;
    }

};

//Java页面
class Java : public BasePage
{
public:
    void content()
    {
        cout << "JAVA学科视频" << endl;
    }
};
//Python页面
class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python学科视频" << endl;
    }
};
//C++页面
class CPP : public BasePage
{
public:
    void content()
    {
        cout << "C++学科视频" << endl;
    }
};

void test01()
{
    //Java页面
    cout << "Java下载视频页面如下： " << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "--------------------" << endl;

    //Python页面
    cout << "Python下载视频页面如下： " << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "--------------------" << endl;

    //C++页面
    cout << "C++下载视频页面如下： " << endl;
    CPP cp;
    cp.header();
    cp.footer();
    cp.left();
    cp.content();
}

int main()
{
    test01();

    return 0;
}