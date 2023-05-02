
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

				3.4.1 案例描述

					有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

				3.4.2 实现步骤

					1. 创建五名选手，放到vector中
					2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
					3. sort算法对deque容器中分数排序，去除最高和最低分
					4. deque容器遍历一遍，累加总分
					5. 获取平均分

					总结： 选取不同的容器操作数据，可以提升代码的效率
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

//选手类
class Player
{
public:
	Player(string name, int score):
		m_Name(name), 
		m_Score(score)
	{}

public:
	string m_Name;// 姓名
	int m_Score;  // 平均分
};

// 创建选手
void createPerson(vector<Player>& v)
{
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += i + 65;// A 65

		int score = 0;

		Player p(name, score);

		v.push_back(p);
	}
}

// 打分
void setScore(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 把10个评分打分存到deque容器中
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;// 随机数

			d.push_back(score);
		}

		// sort算法对deque容器中分数排序
		sort(d.begin(), d.end());

		// 去除最高和最低分
		d.pop_front();
		d.pop_back();

		// deque容器遍历一遍，累加总分
		int sum = 0;

		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		// 获取平均分
		int avg = sum / d.size();

		// 平均分给选手
		it->m_Score = avg;
	}
}

void showScore(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout
			<< it->m_Name << " "
			<< it->m_Score
			<< 
		endl;
	}
}

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	// 1. 创建五名选手，放到vector中
	vector<Player> v;
	createPerson(v);// 创建选手
	
	// 2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
	// 3. sort算法对deque容器中分数排序，去除最高和最低分
	// 4. deque容器遍历一遍，累加总分
	// 5. 获取平均分
	setScore(v);// 打分
	
	// 显示得分
	showScore(v);

	return 0;
}