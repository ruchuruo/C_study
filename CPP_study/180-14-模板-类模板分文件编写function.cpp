
#include "180-14-ģ��-��ģ����ļ���д.h"

template<typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<typename T1, typename T2>
void Person<T1, T2>::showPerson()
{
	cout << "����: " << this->m_Name << " ����:" << this->m_Age << endl;
}