
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

			4.3 �ڽ���������

				4.3.1 �ڽ�������������

				4.3.2 �����º���

				4.3.3 ��ϵ�º���

				4.3.4 �߼��º���

					����������

						ʵ���߼�����

					����ԭ�ͣ�

						template<class T> bool logical_and<T> //�߼���
						template<class T> bool logical_or<T>  //�߼���
						template<class T> bool logical_not<T> //�߼���

					�ܽ᣺�߼��º���ʵ��Ӧ�ý��٣��˽⼴��
*/

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

// �߼���
void test01()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// ȡ�����ŵ�����v2��

	vector<bool> v2;

	// ����v2�ռ䣬���򱨴�
	v2.resize(v.size());

	// v���˵�v2��transform����֮�����
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());

	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	// �߼���
	test01();

	return 0;
}