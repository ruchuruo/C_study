#pragma once

/*
	职工管理系统 类
*/

#include <iostream>
#include "my_List.h"

using namespace std;


class WorkerManager
{
public:
	WorkerManager();

	// 显示菜单
	void ShowMenu();

	// 退出管理程序
	void exitSystem();

	~WorkerManager();

private:

	// 为0则未初始化
	int initialization;
};

