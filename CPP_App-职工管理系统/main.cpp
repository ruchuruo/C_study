
#include "workerManager.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"



void test1()
{
	WorkerManager wm;

	wm.ShowMenu();

	int choice = 0;

	do
	{
		//wm.ShowMenu();
		cout << ">";
		cin >> choice;

		switch (choice)
		{
		case 1: //添加职工
			system("cls");
			wm.ShowMenu();
			wm.Add_Emp();
			break;

		case 2: //显示职工
			system("cls");
			wm.ShowMenu();
			wm.Show_Emp();
			break;

		case 3: //删除职工
			//system("cls");
			//wm.ShowMenu();
			wm.Del_Emp();
			break;

		case 4: //修改职工
			//system("cls");
			//wm.ShowMenu();
			wm.Mod_Emp();
			break;

		case 5: //查找职工
			system("cls");
			wm.ShowMenu();
			wm.Find_Emp();
			break;

		case 6: //排序职工
			system("cls");
			wm.ShowMenu();
			wm.Sort_Emp();
			break;

		case 7: //清空文件
			system("cls");
			wm.ShowMenu();
			wm.Clean_File();
			break;

		case 8: //读文件
			break;

		case 9: //写文件
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

void test4()
{
	WorkerManager wm;

	// 添加
	wm.Add_Emp();
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
	//wm.Clean_File();
	//wm.Add_Emp();
	//wm.Show_Emp();
	//wm.exitSystem();

	// 写文件
	wm.Write_Emp();

	// 读文件
	wm.Read_Emp();
}

int main()
{
	//test1();

	//test2();

	//test3();

	test4();

	return 0;
}