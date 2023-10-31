
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

// ��ʼ
void speechManager::start()
{
	vector<int> v1;// ��̭��ҡ��
	vector<int> v2;// ����ҡ��

	// ҡ�ţ��Ȳ���һ��
	int num = 1 + rand() % 12;
	cout << num << endl;

	v1.push_back(num);

	while (v1.size() != 12)
	{
		// ����ҡ��
		num = 1 + rand() % 12;
		cout << num << endl;

		// ���Ŵ�������v1
		// �Ȳ����Ƿ�����ͬ����
		vector<int>::iterator v1It =
			find(v1.begin(), v1.end(), num);

		if (v1It == v1.end())
		{
			v1.push_back(num);
		}
		else
		{
			cout << "��ͬ" << endl;
		}
	}

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
