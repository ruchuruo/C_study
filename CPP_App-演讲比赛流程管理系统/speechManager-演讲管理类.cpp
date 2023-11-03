
#include "main.h"
#include "speechManager-�ݽ�������.h"
#include "speaker-ѡ����.h"

speechManager::speechManager()
{
	// ��������
	this->NumberOfMatches = 0;
}

speechManager::~speechManager()
{
}

// ��ʾ�˵�
void speechManager::show_Menu()
{
	cout << endl;
	cout << "==== ��ӭ�μ��ݽ����� ====" << endl;
	cout << "|     1.��ʼ�ݽ�����     |" << endl;
	cout << "|     2.�鿴�����¼     |" << endl;
	cout << "|     3.��ձ�����¼     |" << endl;
	cout << "|     0.�˳���������     |" << endl;
	cout << "==== ================ ====" << endl;
	cout << endl;
}

// ҡ�� (�ŵ�������, ҡ����, �Ӽ�, ����)
static void lottery(vector<int> &v, int num, int from, int to)
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

// ��ʼ
void speechManager::start()
{
	vector<int> v1;// ��̭��ҡ��
	vector<int> v2;// ����ҡ��

	//ҡ��
	lottery(v1, 12, 1, 12);

	// ����ѡ�ֲ����ŷ����ѡ��
	map<int, Speaker> m;
	Speaker s;

	for (int i = 0; i < 12; i++)
	{
		s.m_Name = "ѡ��";
		s.m_Name += 65 + i;
		s.m_Score[0] = 0;
		s.m_Score[1] = 0;
		m.insert(pair<int, Speaker>(*(v1.begin() + i), s));
	}

	// �������
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

// �˳�
void speechManager::exitSystem()
{
	cout << "�˳�" << endl;
}
