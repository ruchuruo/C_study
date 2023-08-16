
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

		2 STL��ʶ

		3 STL- ��������

			3.1 string����

			3.2 vector����

			3.3 deque����

			3.4 ����-��ί���

			3.5 stack����

			3.6 queue ����

			3.7 list����

			3.8 set/ multiset ����

			3.9 map/ multimap����

			3.10 ����-Ա������

				3.10.1 ��������

					��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
					Ա����Ϣ��: ���� ������ɣ����ŷ�Ϊ���߻����������з�
					�����10��Ա�����䲿�ź͹���
					ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
					�ֲ�����ʾԱ����Ϣ

				3.10.2 ʵ�ֲ���

					1. ����10��Ա�����ŵ�vector��
					2. ����vector������ȡ��ÿ��Ա���������������
					3. ����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
					4. �ֲ�����ʾԱ����Ϣ

					�ܽ᣺

						�������Լ�ֵ����ʽ���ڣ����Կ�����map �� multimap
*/

#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

// Ա����
class Worker
{
public:
	string m_Name;// ����
	int m_Salary; // ����
};

// ����Ա��
void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";

	for (int i = 0; i < 10; i++)
	{
		// ��������
		Worker w;
		w.m_Name = "Ա��";
		w.m_Name += nameSeed[i];

		// �������
		w.m_Salary = rand() % 10000 + 10000;// 10000 �� 19999

		// ���� vector����
		v.push_back(w);
	}
}

// Ա������
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		// ������ű��
		int deptId = rand() % 3;// 0 1 2

		// ���ű�ź�Ա���ŵ� multimap����
		m.insert(make_pair(deptId, *it));
	}
}

// ��ʾ����Ա��
void showWorkerByGourp(multimap<int, Worker>& m)
{
	// 0 �߻���1 ������2 �з�

	for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
	{
		int deptId = it->first;

		switch (deptId)
		{
		case 0:
			cout << deptId << "�߻����� " << it->second.m_Name << " " << it->second.m_Salary << endl;
			break;

		case 1:
			cout << deptId << "�������� " << it->second.m_Name << " " << it->second.m_Salary << endl;
			break;

		case 2:
			cout << deptId << "�з����� " << it->second.m_Name << " " << it->second.m_Salary << endl;
			break;

		default:
			break;
		}
	}
}

int main()
{
	// ���������
	srand((unsigned int)time(NULL));

	vector<Worker> vWorker;

	// ����Ա��������vector����
	createWorker(vWorker);

	multimap<int, Worker>mWorker;

	// Ա������
	setGroup(vWorker, mWorker);

	// ��ʾ����Ա��
	showWorkerByGourp(mWorker);

	return 0;
}