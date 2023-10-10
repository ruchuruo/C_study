
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

					����������

						ʵ�ֹ�ϵ�Ա�

					�º���ԭ�ͣ�
					
						template<class T> bool equal_to<T>      //����
						template<class T> bool not_equal_to<T>  //������
						template<class T> bool greater<T>       //����
						template<class T> bool greater_equal<T> //���ڵ���
						template<class T> bool less<T>          //С��
						template<class T> bool less_equal<T>    //С�ڵ���

					�ܽ᣺

						��ϵ�º�������õľ���greater<>����

						��Ϊ sort Դ�������������ذ汾��һ������Ҫ ν��(Pred)��
						��һ������Ҫ������Ҫν�ʵ� sort ������ less<T>С�ڣ�
						���� sort Ĭ���Ǵ�С������ΪĬ����С�ڣ����Դ��ڸ�����
*/

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

// ����
void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// ���� ����ʹ���Զ��庯������
	//sort(v.begin(), v.end(), MyCompare());

	// ���� ����ʹ���ڽ���������
	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	// ����
	test01();

	return 0;
}