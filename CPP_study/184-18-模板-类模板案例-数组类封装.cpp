
#include "184-18-ģ��-��ģ�尸��-�������װmyArray.hpp"

// ָ����������� --- ֱ����ʾ�������������
void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void test01()
{
	MyArray<int> arr1(5);
	MyArray<int> arr2(arr1);

	MyArray<int> arr3(100);
	arr3 = arr1;
}

void test02()
{
	MyArray<int> arr1(5);

	for (int i = 0; i < 5; i++)
	{
		// β��
		arr1.PushBack(i);
	}

	cout << "arr1����" << arr1.getCapacity() << endl;
	cout << "arr1��С" << arr1.getSize() << endl;

	// ��ӡ
	cout << "arr1����:";
	printIntArray(arr1);



	cout << endl;



	MyArray<int> arr2(arr1);

	cout << "arr2����" << arr2.getCapacity() << endl;
	cout << "arr2��С" << arr2.getSize() << endl;

	cout << "arr2����:";
	printIntArray(arr2);

	// βɾ
	arr2.PopBack();

	cout << "arr2����" << arr2.getCapacity() << endl;
	cout << "arr2��С" << arr2.getSize() << endl;

	cout << "arr2����:";
	printIntArray(arr2);
}





// �Զ����������͵����ݽ��д洢
class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

public:
	string m_Name;
	int m_Age;
};

// ָ����������� --- ֱ����ʾ�������������
void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "������" << arr[i].m_Name << " "
			<< "���䣺" << arr[i].m_Age <<
			endl;
	}

	cout << endl;
}

void test03()
{
	MyArray<Person> arr(10);

	Person p1("����", 11);
	Person p2("����", 21);
	Person p3("����", 31);
	Person p4("����", 41);
	Person p5("����", 51);

	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);


	cout << "arr����" << arr.getCapacity() << endl;
	cout << "arr��С" << arr.getSize() << endl;

	printPersonArray(arr);

	/*
		��һ �¶� ���� ���� ���� ���� ���� �ܰ� ��� ֣ʮ
	*/
}

int main()
{
	//test01();

	//test02();

	// �Զ����������͵����ݽ��д洢
	test03();

	return 0;
}