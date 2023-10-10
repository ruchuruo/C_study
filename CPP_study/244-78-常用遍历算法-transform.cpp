
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

			5.1 ���ñ����㷨

				5.1.1 for_each

				5.1.2 transform

					����������

						������������һ��������

					����ԭ�ͣ�

						transform(iterator beg1, iterator end1, iterator beg2, _func);
							//beg1  Դ������ʼ������
							//end1  Դ��������������
							//beg2  Ŀ��������ʼ������
							//_func �������ߺ�������(�����ڼ������һЩ����)

					�ܽ᣺ ���˵�Ŀ����������Ҫ��ǰ���ٿռ䣬�����޷���������
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// �º��� ����
class transf
{
public:
	int operator()(int val)
	{
		// �����ڼ䲻��Ҫ�����㣬ֱ�ӷ���
		//return val;

		// �����ڼ��������
		return val + 100;
	}
};

// �º��� ��ӡ
class print01
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	// Դ����
	vector<int> v;

	// ������ݵ� Դ����
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// Ŀ������
	vector<int> v2;

	// ����ǰ��Ҫ��չ�ռ�
	v2.resize(v.size());

	// ����
	transform(v.begin(), v.end(), v2.begin(), transf());

	// ����
	for_each(v2.begin(), v2.end(), print01());

	cout << endl;
}

int main()
{
	test01();

	return 0;
}