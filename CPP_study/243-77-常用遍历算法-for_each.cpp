
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

		1 ģ��

		2 STL��ʶ

		3 STL- ��������

		4 STL- ��������

		5 STL- �����㷨

			����:

				�㷨��Ҫ����ͷ�ļ� <algorithm> <functional> <numeric> ��ɡ�
				<algorithm> ������STLͷ�ļ�������һ������Χ�漰���Ƚϡ� ���������ҡ��������������ơ��޸ĵȵ�
				<numeric> �����С��ֻ��������������������м���ѧ�����ģ�庯��
				<functional> ������һЩģ����,����������������

			5.1 ���ñ����㷨

				ѧϰĿ�꣺

					���ճ��õı����㷨

				�㷨��飺

					for_each  //��������
					transform //������������һ��������

				5.1.1 for_each

					����������

						ʵ�ֱ�������

					����ԭ�ͣ�

						for_each(iterator beg, iterator end, _func);
							// �����㷨 ��������Ԫ��
							// beg   ��ʼ������
							// end   ����������
							// _func �������ߺ�������

					�ܽ᣺for_each��ʵ�ʿ���������ñ����㷨����Ҫ��������
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ��ͨ����
void print01(int val)
{
	cout << val << " ";
}

// �º���
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v;

	// ������ݵ�����
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// �������� ʹ����ͨ����
	for_each(v.begin(), v.end(), print01);

	cout << endl;

	// �������� ʹ�÷º���
	for_each(v.begin(), v.end(), print02());
}

int main()
{
	test01();

	return 0;
}