
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

		2 STL初识

		3 STL- 常用容器

			3.1 string容器

			3.2 vector容器

			3.3 deque容器

			3.4 案例-评委打分

			3.5 stack容器

			3.6 queue 容器

			3.7 list容器

			3.8 set/ multiset 容器

			3.9 map/ multimap容器

			3.10 案例-员工分组

				3.10.1 案例描述

					公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
					员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
					随机给10名员工分配部门和工资
					通过multimap进行信息的插入 key(部门编号) value(员工)
					分部门显示员工信息

				3.10.2 实现步骤

					1. 创建10名员工，放到vector中
					2. 遍历vector容器，取出每个员工，进行随机分组
					3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
					4. 分部门显示员工信息

					总结：

						当数据以键值对形式存在，可以考虑用map 或 multimap
*/

#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

// 员工类
class Worker
{
public:
	string m_Name;// 名字
	int m_Salary; // 工资
};

// 创建员工
void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";

	for (int i = 0; i < 10; i++)
	{
		// 设置名字
		Worker w;
		w.m_Name = "员工";
		w.m_Name += nameSeed[i];

		// 随机工资
		w.m_Salary = rand() % 10000 + 10000;// 10000 到 19999

		// 放入 vector容器
		v.push_back(w);
	}
}

// 员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 随机部门编号
		int deptId = rand() % 3;// 0 1 2

		// 部门编号和员工放到 multimap容器
		m.insert(make_pair(deptId, *it));
	}
}

// 显示分组员工
void showWorkerByGourp(multimap<int, Worker>& m)
{
	// 0 策划、1 美术、2 研发

	for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
	{
		int deptId = it->first;

		switch (deptId)
		{
		case 0:
			cout << deptId << "策划部门 " << it->second.m_Name << " " << it->second.m_Salary << endl;
			break;

		case 1:
			cout << deptId << "美术部门 " << it->second.m_Name << " " << it->second.m_Salary << endl;
			break;

		case 2:
			cout << deptId << "研发部门 " << it->second.m_Name << " " << it->second.m_Salary << endl;
			break;

		default:
			break;
		}
	}
}

int main()
{
	// 随机数种子
	srand((unsigned int)time(NULL));

	vector<Worker> vWorker;

	// 创建员工并放入vector容器
	createWorker(vWorker);

	multimap<int, Worker>mWorker;

	// 员工分组
	setGroup(vWorker, mWorker);

	// 显示分组员工
	showWorkerByGourp(mWorker);

	return 0;
}