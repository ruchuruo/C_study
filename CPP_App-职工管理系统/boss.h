#pragma once

/*
	老板 类
*/

#include<iostream>
#include "worker.h"

using namespace std;


class Boss :public Worker
{
public:

	Boss(int id, string name, int dId);
	~Boss();

	//显示个人信息
	virtual void showInfo();

	//获取职工岗位名称
	virtual string getDeptName();
};