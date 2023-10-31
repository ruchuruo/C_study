
#include "main.h"
#include "speechManager-演讲管理类.h"

void test1()
{
	speechManager sm;

	// 显示菜单
	sm.show_Menu();

	// 用户选择
	int choice = 0;

	do
	{
		cout << "┏ 选择" << endl;
		cout << "┗ ";

		// 输入
		cin >> choice;

		switch (choice)
		{
		case 1:// 开始演讲比赛
			sm.start();
			break;
		case 2:// 查看往届记录
			break;
		case 3:// 清空比赛记录
			break;

		case 0:// 退出比赛程序
			sm.exitSystem();
			break;

		default:
			cout << "输入错误" << endl;
			break;
		}

	} while (choice);
}

int main()
{
	srand((unsigned int)time(NULL));

	test1();
	
	return 0;
}

// system("cls");
// system("pause");