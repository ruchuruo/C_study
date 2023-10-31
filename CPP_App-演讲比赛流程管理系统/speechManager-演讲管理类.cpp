
#include "main.h"
#include "speechManager-演讲管理类.h"
#include "speaker-选手类.h"

speechManager::speechManager()
{
	// 比赛次数
	this->NumberOfMatches = 0;
}

speechManager::~speechManager()
{
}

// 显示菜单
void speechManager::show_Menu()
{
	cout << endl;
	cout << "==== 欢迎参加演讲比赛 ====" << endl;
	cout << "|     1.开始演讲比赛     |" << endl;
	cout << "|     2.查看往届记录     |" << endl;
	cout << "|     3.清空比赛记录     |" << endl;
	cout << "|     0.退出比赛程序     |" << endl;
	cout << "==== ================ ====" << endl;
	cout << endl;
}

// 开始
void speechManager::start()
{
	vector<int> v1;// 淘汰赛摇号
	vector<int> v2;// 决赛摇号

	// 摇号，先插入一次
	int num = 1 + rand() % 12;
	cout << num << endl;

	v1.push_back(num);

	while (v1.size() != 12)
	{
		// 继续摇号
		num = 1 + rand() % 12;
		cout << num << endl;

		// 将号存入数组v1
		// 先查找是否有相同的数
		vector<int>::iterator v1It =
			find(v1.begin(), v1.end(), num);

		if (v1It == v1.end())
		{
			v1.push_back(num);
		}
		else
		{
			cout << "相同" << endl;
		}
	}

	// 创建选手并将号分配给选手
	map<int, Speaker> m;
	Speaker s;

	for (int i = 0; i < 12; i++)
	{
		s.m_Name = "选手";
		s.m_Name += 65 + i;
		s.m_Score[0] = 0;
		s.m_Score[1] = 0;
		m.insert(pair<int, Speaker>(*(v1.begin() + i), s));
	}

	// 输出看看
	for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout
			<< it->first << " "
			<< (*it).second.m_Name << " "
			<< (*it).second.m_Score[0] << " "
			<< (*it).second.m_Score[1] <<
			endl;
	}
	cout << endl;
}

// 退出
void speechManager::exitSystem()
{
	cout << "退出" << endl;
}
