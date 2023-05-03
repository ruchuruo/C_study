
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

				3.5.1 stack ��������

				3.5.2 stack ���ýӿ�

					����������ջ�������õĶ���ӿ�

					���캯����

						stack<T> stk;            //stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ
						stack(const stack &stk); //�������캯��

					��ֵ������

						stack& operator=(const stack &stk); //���صȺŲ�����

					���ݴ�ȡ��

						push(elem); //��ջ�����Ԫ��
						pop();      //��ջ���Ƴ���һ��Ԫ��
						top();      //����ջ��Ԫ��

					��С������

						empty(); //�ж϶�ջ�Ƿ�Ϊ��
						size();  //����ջ�Ĵ�С

					�ܽ᣺

						��ջ          --- push
						��ջ          --- pop
						����ջ��      --- top
						�ж�ջ�Ƿ�Ϊ�� --- empty
						����ջ��С     --- size
*/

#include <iostream>
#include <stack>

using namespace std;

void test01()
{
	stack<int> s;

	// ��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "ջ��С " << s.size() << endl;

	// ջ��Ϊ�վͲ鿴ջ��������ջ
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

	cout << "ջ��С " << s.size() << endl;
}

int main()
{
	test01();

	return 0;
}