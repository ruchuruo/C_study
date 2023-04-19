
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

				3.2.1 vector��������

					���ܣ�

						vector���ݽṹ������ǳ����ƣ�Ҳ��Ϊ��������

					vector����ͨ��������

						��֮ͬ�����������Ǿ�̬�ռ䣬��vector���Զ�̬��չ

					��̬��չ��

						��������ԭ�ռ�֮�������¿ռ䣬�����Ҹ�����ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ�

							|        vector����
							|                                                 push_back() ��
							|             front()                 back()                    �K
							|        +--------------------------------------                �L
							|        |                    -------------��                  ��
							|        |    [ 1 ][ 2 ]     [ 3 ][ 4 ][ 5 ]
							|        |                ��                                   ��
							|        +----------------|---------------------                �K
							|      ��        ��         |              ��       ��              �L
							|      |        |       [ 6 ]            |       | pop_back() ��
							|      |    v.begin()  insert()     v.rbegin()   |
							|   v.rend()                                  v.end()

						vector�����ĵ�������֧��������ʵĵ�����

				3.2.2 vector���캯��

					����������

						����vector����

					����ԭ�ͣ�

						vector<T> v;                //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
						vector(v.begin(), v.end()); //��v[begin(), end())�����е�Ԫ�ؿ���������
						vector(n, elem);            //���캯����n��elem����������
						vector(const vector &vec);  //�������캯����

					�ܽ᣺vector�Ķ��ֹ��췽ʽû�пɱ��ԣ����ʹ�ü���
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v)
{

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	//����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
	vector<int> v1; //�޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//��v[begin(), end())�����е�Ԫ�ؿ���������
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	//���캯����n��elem����������
	vector<int> v3(10, 100);
	printVector(v3);

	//�������캯����
	vector<int> v4(v3);
	printVector(v4);
}

int main()
{
	test01();

	return 0;
}