
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

			4.1 ��������

			4.2 ν��

				4.2.1 ν�ʸ���

					���

						����bool���͵ķº�����Ϊν��
						���operator()����һ����������ô����һԪν��
						���operator()����������������ô������Ԫν��

				4.2.2 һԪν��

					�ܽ᣺����ֻ��һ����ν�ʣ���ΪһԪν��
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// ���������д���5������
	// find_if(_InIt _First, const _InIt _Last, _Pr _Pred)
	// find_if(��һ, �ڶ�, ν��)
	// �����п��� Pred ��ʾ��Ҫν��
	// ���ﴫ��һ�������ĺ������� GreaterFive()
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());

	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ� " << *it << endl;
	}
}

int main()
{
	test01();

	return 0;
}