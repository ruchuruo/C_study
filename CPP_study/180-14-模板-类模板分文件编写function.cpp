
#include "180-14-模板-类模板分文件编写.h"

template<typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<typename T1, typename T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}