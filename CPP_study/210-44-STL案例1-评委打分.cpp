
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

				3.4.1 ��������

					��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�

				3.4.2 ʵ�ֲ���

					1. ��������ѡ�֣��ŵ�vector��
					2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
					3. sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
					4. deque��������һ�飬�ۼ��ܷ�
					5. ��ȡƽ����

					�ܽ᣺ ѡȡ��ͬ�������������ݣ��������������Ч��
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

//ѡ����
class Player
{
public:
	Player(string name, int score):
		m_Name(name), 
		m_Score(score)
	{}

public:
	string m_Name;// ����
	int m_Score;  // ƽ����
};

// ����ѡ��
void createPerson(vector<Player>& v)
{
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += i + 65;// A 65

		int score = 0;

		Player p(name, score);

		v.push_back(p);
	}
}

// ���
void setScore(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		// ��10�����ִ�ִ浽deque������
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;// �����

			d.push_back(score);
		}

		// sort�㷨��deque�����з�������
		sort(d.begin(), d.end());

		// ȥ����ߺ���ͷ�
		d.pop_front();
		d.pop_back();

		// deque��������һ�飬�ۼ��ܷ�
		int sum = 0;

		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		// ��ȡƽ����
		int avg = sum / d.size();

		// ƽ���ָ�ѡ��
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
	//���������
	srand((unsigned int)time(NULL));

	// 1. ��������ѡ�֣��ŵ�vector��
	vector<Player> v;
	createPerson(v);// ����ѡ��
	
	// 2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
	// 3. sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
	// 4. deque��������һ�飬�ۼ��ܷ�
	// 5. ��ȡƽ����
	setScore(v);// ���
	
	// ��ʾ�÷�
	showScore(v);

	return 0;
}