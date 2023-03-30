
//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>

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
			system("cls");
			wm.ShowMenu();
			wm.Read_Emp();
			break;

		case 9: //写文件
			system("cls");
			wm.ShowMenu();
			wm.Write_Emp();
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

	//_CrtDumpMemoryLeaks();
	return 0;
}





/*
	VS检测内存泄漏，定位泄漏代码位置方法 https://blog.csdn.net/mfcing/article/details/42673393

		C Run-Time (CRT)库可以帮助我们检测内存泄露

			定义宏
				#define _CRTDBG_MAP_ALLOC

			包含相应头文件 
				#include <crtdbg.h>

			在程序退出地方，加上
				_CrtDumpMemoryLeaks();

			程序结束后在输出窗口（注意，是输出窗口）查看输出：

				取其中一条详细说明：{453} normal block at 0x02432CA8, 868 bytes long. 

				被{}包围的453就是我们需要的内存泄漏定位值，868 bytes long就是说这个地方有868比特内存没有释放。

			接下来，定位代码位置：

				在main函数第一行加上：_CrtSetBreakAlloc(453); 意思就是在申请453这块内存的位置中断。然后调试程序，……程序中断了。查看调用堆栈

				双击我们的代码调用的最后一个函数，这里是CDbQuery::UpdateDatas()，就定位到了申请内存的代码：


			最后要注意一点的，并不是所有normal block一定就有内存泄漏，
			当你的程序中有全局变量的时候，全局变量的释放示在main函数退出后，
			所以在main函数最后_CrtDumpMemoryLeaks（）会认为全局申请的内存没有释放，造成内存泄漏的假象。
			如何规避呢？我通常是把全局变量声明成指针在main函数中new 在main函数中delete，
			然后再调用_CrtDumpMemoryLeaks（），这样就不会误判了。
*/
