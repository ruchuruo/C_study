
#include "main.h"

// ҡ�� (�ŵ�������, ҡ����, �Ӽ�, ����)
static void lottery(vector<int>& v, int num, int from, int to)
{
	// ���ҡ0�����Ǿͱ�ҡ��
	if (num <= 0)
	{
		return;
	}
	else if (from > to) // form ����� to С
	{
		// ����
		from = from ^ to;
		to = from ^ to;
		from = from ^ to;

		//a = a ^ b;
		//b = a ^ b;// a ^ b ^ b
		//a = a ^ b;// a ^ b ^ a
	}
	else if ((to - from + 1) < num) // ��� �Ӽ�, ���� �Ĳ����num���Ǿͱ�ҡ��
	{
		return;
	}

	// �г� �Ӽ�, �����������滻��ͬ�������
	vector<int> vRep;

	for (int i = from; i <= to; i++)
	{
		vRep.push_back(i);
	}

	// ��ʼҡ��
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