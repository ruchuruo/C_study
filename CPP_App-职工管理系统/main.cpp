
#include "workerManager.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"



void test1()
{
	WorkerManager wm;

	int choice = 0;

	do
	{
		wm.ShowMenu();
		cout << ">";
		cin >> choice;

		switch (choice)
		{
		case 1: //添加职工
			wm.Add_Emp();
			break;

		case 2: //显示职工
			wm.Show_Emp();
			break;

		case 3: //删除职工
			wm.Del_Emp();
			break;

		case 4: //修改职工
			wm.Mod_Emp();
			break;

		case 5: //查找职工
			wm.Find_Emp();
			break;

		case 6: //排序职工
			wm.Sort_Emp();
			break;

		case 7: //清空文件
			break;

		case 0: //退出系统
			wm.exitSystem();
			break;

		default:
			cout << "输入错误" << endl;
			break;
		}

	} while (choice);
}

void test2()
{
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}

void test3()
{
	Worker* worker = NULL;

	EmpListNode en;
	EmpListNode* phead = en.ListInit();

	worker = new Employee(1, "张三", 1);
	en.ListInsert(phead->getNextNode(), worker);

	worker = new Manager(2, "李四", 2);
	en.ListInsert(phead->getNextNode(), worker);

	worker = new Boss(3, "王五", 3);
	en.ListInsert(phead->getNextNode(), worker);

	en.ListPrint(phead);
	
	delete worker;
}

int main()
{
	//test1();

	//test2();

	//test3();

	WorkerManager wm;

	// 添加
	wm.Add_Emp();
	wm.Add_Emp();
	//wm.Add_Emp();
	//wm.Add_Emp();
	//wm.Add_Emp();

	wm.Show_Emp();

	// 删除
	//wm.Del_Emp();
	//wm.Show_Emp();
	//wm.Del_Emp();
	//wm.Show_Emp();

	// 查找
	//wm.Find_Emp();
	//wm.Find_Emp();
	//wm.Find_Emp();

	// 修改
	//wm.Mod_Emp();
	//wm.Show_Emp();
	//wm.Mod_Emp();
	//wm.Show_Emp();
	//wm.Mod_Emp();
	//wm.Show_Emp();
	//wm.Mod_Emp();
	//wm.Show_Emp();
	//wm.Mod_Emp();
	//wm.Show_Emp();

	// 排序
	//wm.Sort_Emp();
	//wm.Show_Emp();
	//wm.Sort_Emp();
	//wm.Show_Emp();

	// 删除所有
	wm.Clean_File();
	//wm.Add_Emp();
	//wm.Show_Emp();
	wm.exitSystem();

	return 0;
}