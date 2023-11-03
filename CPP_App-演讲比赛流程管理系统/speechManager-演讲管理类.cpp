
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

// 摇号 (放到的容器, 摇几个, 从几, 到几)
static void lottery(vector<int> &v, int num, int from, int to)
{
	// 如果摇0个，那就别摇了
	if (num <= 0)
	{
		return;
	}
	else if (from > to) // form 必须比 to 小
	{
		// 交换
		from = from ^ to;
		to = from ^ to;
		from = from ^ to;

		//a = a ^ b;
		//b = a ^ b;// a ^ b ^ b
		//a = a ^ b;// a ^ b ^ a
	}
	else if ((to - from + 1) < num) // 如果 从几, 到几 的差不等于num，那就别摇了
	{
		return;
	}

	// 列出 从几, 到几，用于替换相同的随机数
	vector<int> vRep;

	for (int i = from; i <= to; i++)
	{
		vRep.push_back(i);
	}

	// 开始摇号
	int tto = to;

	for (int i = 0; i < num; i++)
	{
		int ret_rand =
			from + rand() % tto;
		cout << ret_rand << endl;

		v.push_back(*(vRep.begin() + (ret_rand - 1)));

		vRep.erase(vRep.begin() + (ret_rand - 1));

		tto--;
	}
}

// 开始
void speechManager::start()
{
	vector<int> v1;// 淘汰赛摇号
	vector<int> v2;// 决赛摇号

	//摇号
	lottery(v1, 12, 1, 12);

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
