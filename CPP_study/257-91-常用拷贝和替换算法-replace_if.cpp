
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

			5.2 ���ò����㷨

			5.3 ���������㷨

			5.4 ���ÿ������滻�㷨

				5.4.1 copy

				5.4.2 replace

				5.4.3 replace_if

					��������:

						������������������Ԫ�أ��滻��ָ��Ԫ��

					����ԭ�ͣ�

						replace_if(iterator beg, iterator end, _pred, newvalue);
							// �������滻Ԫ�أ������������滻��ָ��Ԫ��
							// beg      ��ʼ������
							// end      ����������
							// _pred    ν��
							// newvalue �滻����Ԫ��

					�ܽ᣺replace_if���������ң��������÷º������ɸѡ���������
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

// ν��
class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(10);
	v.push_back(20);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(40);

	// ���� ��ӡ
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	// ������20�����滻��999

	replace_if(v.begin(), v.end(), Greater20(), 999);

	// ���� ��ӡ
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}