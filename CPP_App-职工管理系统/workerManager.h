#pragma once

/*
	职工管理系统 类
*/

#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
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

	// 增加职工
	void Add_Emp();

	//删除职工
	void Del_Emp();

	//查找职工
	void Find_Emp();

	//修改职工
	void Mod_Emp();

	//显示职工
	void Show_Emp();

	// 设置 员工链表头
	void setEmpListPhead(EmpListNode* EmpListPhead);

	// 获取 员工链表头
	EmpListNode* getEmpListPhead();

	~WorkerManager();

private:

	// 为0则未初始化
	int initialization;

	// 记录人数个数
	int m_EmpNum;

	// 链表
	EmpListNode en;

	// 员工链表头
	EmpListNode* m_EmpListPhead;
};

