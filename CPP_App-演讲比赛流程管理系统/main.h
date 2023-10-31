#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void myPrintInt(int val);

class MyNum
{
public:
	MyNum()
	{
		this->m_Num = 0;
	}

	~MyNum()
	{
		cout << "MyNum.m_Num " << this->m_Num << endl;
	}

	void numPp()
	{
		m_Num++;
	}

	int getNum()
	{
		return m_Num;
	}

private:
	int m_Num;
};