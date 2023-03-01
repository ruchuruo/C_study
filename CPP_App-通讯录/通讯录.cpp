
/*
	C++结构体里面string类型赋值问题
	来自：https://blog.51cto.com/liuzhangheng/1436164

		struct temp
		{
			string s;
		};
		int main()
		{
			const string p="aaa";
			temp *q;
			q=(struct temp*)malloc(sizeof(struct temp));
			q->s=p;
		}

		上述那种情况的赋值会导致程序中断
		需要用用new来分配内存，malloc不会调用结构函数
		结构体内的string不定长，不能动态分配内存。

		struct temp
		{
			string s;
		};
		int main()
		{
			const string p="aaa";
			temp *q;
			q = new temp;
			q->s=p;
		}

		C++的结构体和类都有默认构造函数的，不写都会自动实现一个。
		malloc只是分配内存。
		new除了分配内存还会调用构造函数的。
*/

#include "通讯录.h"

void test1()
{
	int select = 0;
	addressBook arb;
	arb.size = 0;
	arb.initialization = 0;

	//readFile(&arb);

	showMenu(arb.size);

	do
	{
		cout << ">";
		cin >> select;

		switch (select)
		{
		case 1:  //添加联系人
			system("cls");
			showMenu(arb.size);
			addPerson(&arb);
			break;

		case 2:  //显示联系人
			system("cls");
			showMenu(arb.size);
			showPerson(&arb);
			break;

		case 3:  //删除联系人
			//system("cls");
			//showMenu(arb.size);
			delPerson(&arb);
			break;

		case 4:  //查找联系人
			system("cls");
			showMenu(arb.size);
			findPerson(&arb);
			break;

		case 5:  //修改联系人
			//system("cls");
			//showMenu(arb.size);
			modifyPerson(&arb);
			break;

		case 6:  //清空联系人
			system("cls");
			showMenu(arb.size);
			destroyPerson(&arb);
			break;

		case 7:  // 保存数据
			system("cls");
			showMenu(arb.size);
			saveFile(&arb);
			break;

		case 8:// 读取数据
			system("cls");
			showMenu(arb.size);
			readFile(&arb);
			break;

		case 0:  //退出通讯录
			exitAddressBook(&arb);
			cout << "欢迎下次使用" << endl;
			system("pause");
			break;

		default:
			system("cls");
			showMenu(arb.size);
			cout << "输入错误" << endl;
			break;
		}

	} while (select);
}

int main()
{
	test1();

	return 0;
}