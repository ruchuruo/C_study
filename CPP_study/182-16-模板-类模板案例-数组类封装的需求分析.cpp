
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程
		
		本阶段主要针对C++ 泛型编程 和 STL 技术做详细讲解，探讨C++更深层的使用

		1 模板

			1.1 模板的概念

			1.2 函数模板

			1.3 类模板

				1.3.1 类模板语法

				1.3.2 类模板与函数模板区别

				1.3.3 类模板中成员函数创建时机

				1.3.4 类模板对象做函数参数

				1.3.5 类模板与继承

				1.3.6 类模板成员函数类外实现

				1.3.7 类模板分文件编写

				1.3.8 类模板与友元

				1.3.9 类模板案例

					案例描述: 实现一个通用的数组类，要求如下：

						可以对内置数据类型以及自定义数据类型的数据进行存储
						将数组中的数据存储到堆区
						构造函数中可以传入数组的容量
						提供对应的拷贝构造函数以及operator=防止浅拷贝问题
						提供尾插法和尾删法对数组中的数据进行增加和删除
						可以通过下标的方式访问数组中的元素
						可以获取数组中当前元素个数和数组的容量

					总结：

						能够利用所学知识点实现通用的数组

					分析：
						
						数组类
							公共
								构造(容量)
								拷贝构造
								析构
								运算符重载=
								通过下标的方式访问数组中的元素
								尾插
								尾删
								获取数组容量
								获取数组大小

							私有
								数组指针 T* pAddress
								容量
								大小
*/