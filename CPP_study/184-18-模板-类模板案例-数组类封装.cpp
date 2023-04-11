
#include "184-18-模板-类模板案例-数组类封装myArray.hpp"

// 指定传入的类型 --- 直接显示对象的数据类型
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
		// 尾插
		arr1.PushBack(i);
	}

	cout << "arr1容量" << arr1.getCapacity() << endl;
	cout << "arr1大小" << arr1.getSize() << endl;

	// 打印
	cout << "arr1内容:";
	printIntArray(arr1);



	cout << endl;



	MyArray<int> arr2(arr1);

	cout << "arr2容量" << arr2.getCapacity() << endl;
	cout << "arr2大小" << arr2.getSize() << endl;

	cout << "arr2内容:";
	printIntArray(arr2);

	// 尾删
	arr2.PopBack();

	cout << "arr2容量" << arr2.getCapacity() << endl;
	cout << "arr2大小" << arr2.getSize() << endl;

	cout << "arr2内容:";
	printIntArray(arr2);
}





// 自定义数据类型的数据进行存储
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

// 指定传入的类型 --- 直接显示对象的数据类型
void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Name << " "
			<< "年龄：" << arr[i].m_Age <<
			endl;
	}

	cout << endl;
}

void test03()
{
	MyArray<Person> arr(10);

	Person p1("张三", 11);
	Person p2("李四", 21);
	Person p3("王五", 31);
	Person p4("赵六", 41);
	Person p5("孙七", 51);

	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);


	cout << "arr容量" << arr.getCapacity() << endl;
	cout << "arr大小" << arr.getSize() << endl;

	printPersonArray(arr);

	/*
		刘一 陈二 张三 李四 王五 赵六 孙七 周八 吴九 郑十
	*/
}

int main()
{
	//test01();

	//test02();

	// 自定义数据类型的数据进行存储
	test03();

	return 0;
}