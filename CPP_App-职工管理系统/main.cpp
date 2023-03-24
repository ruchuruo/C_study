
#include "workerManager.h"

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
			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
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

int main()
{
	test1();

	return 0;
}