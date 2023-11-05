
#include "main.h"

// 摇号 (放到的容器, 摇几个, 从几, 到几)
static void lottery(vector<int>& v, int num, int from, int to)
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