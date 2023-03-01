
#include "通讯录.h"

// 显示菜单
void showMenu(int arbSize)
{
	cout << "======== ======== ========" << endl;
	cout << "|      1 添加联系人      |" << endl;
	cout << "|      2 显示联系人      |" << endl;
	cout << "|      3 删除联系人      |" << endl;
	cout << "|      4 查找联系人      |" << endl;
	cout << "|      5 修改联系人      |" << endl;
	cout << "|      6 清空联系人      |" << endl;
	cout << "|      7 保存联系人      |" << endl;
	cout << "|      8 读取联系人      |" << endl;
	cout << "|      0 退出通讯录      |" << endl;
	cout << "======== ======== =======" << arbSize << endl;
}

// 添加联系人
void addPerson(addressBook* arb)
{
	string name;      // 名字
	string phone;     // 电话
	string addr;      // 住址
	string sex;       // 性别
	unsigned int age; // 年龄

	cout << "名字>";
	cin >> name;
	cout << "电话>";
	cin >> phone;
	cout << "住址>";
	cin >> addr;
	cout << "性别>";
	cin >> sex;
	cout << "年龄>";
	cin >> age;

	//string name = "张三";             // 名字
	//string phone = "12345678901";     // 电话
	//string addr = "北京";             // 住址
	//string sex = "女";                // 性别
	//unsigned int age = 35;            // 年龄

	// 通讯录中没人才需要 初始化联系人链表
	if (arb->size == 0)
	{
		arb->per = ListInit();
	}

	// 尾插
	ListInsert(arb->per, name, phone, addr, sex, age);

	arb->size++;
	cout << "添加成功" << endl;
}

// 显示联系人
int showPerson(addressBook* arb)
{
	if (arb->size == 0)
	{
		cout << "通讯录空" << endl;
		return 0;
	}

	// 双向链表打印
	ListPrint(arb->per);
}

// 删除联系人
int delPerson(addressBook* arb)
{
	if (arb->size == 0)
	{
		cout << "通讯录空" << endl;
		return 0;
	}

	string name;
	cout << "输入要 删除 的 联系人 的名字>";
	cin >> name;

	// 双向链表查找
	Person* delper = ListFind(arb->per, name);

	if (delper == NULL)
	{
		cout << "无联系人" << endl;
		return 0;
	}

	// 双向链表删除pos位置的节点
	ListErase(delper);

	arb->size--;
	cout << "删除成功" << endl;
}

// 查找联系人
int findPerson(addressBook* arb)
{
	if (arb->size == 0)
	{
		cout << "通讯录空" << endl;
		return 0;
	}

	string name;
	cout << "输入要 查找 的 联系人 的名字>";
	cin >> name;

	// 双向链表查找
	Person* findper = ListFind(arb->per, name);

	if (findper == NULL)
	{
		cout << "查 无 此人" << endl;
		return 0;
	}

	cout << "查 有 此人" << endl;
}

// 修改联系人
int modifyPerson(addressBook* arb)
{
	if (arb->size == 0)
	{
		cout << "通讯录空" << endl;
		return 0;
	}

	string findName;
	cout << "输入要 修改 的 联系人 的名字>";
	cin >> findName;

	// 双向链表查找
	Person* modifyper = ListFind(arb->per, findName);

	if (modifyper == NULL)
	{
		cout << "查 无 此人" << endl;
		return 0;
	}

	string name;      // 名字
	string phone;     // 电话
	string addr;      // 住址
	string sex;       // 性别
	unsigned int age; // 年龄

	cout << "修改 名字>";
	cin >> name;
	cout << "修改 电话>";
	cin >> phone;
	cout << "修改 住址>";
	cin >> addr;
	cout << "修改 性别>";
	cin >> sex;
	cout << "修改 年龄>";
	cin >> age;

	modifyper->name = name;
	modifyper->phone = phone;
	modifyper->addr = addr;
	modifyper->sex = sex;
	modifyper->age = age;

	cout << "修改成功" << endl;
}

// 清空通讯录
void destroyPerson(addressBook* arb)
{
	if (arb->size == 0)
	{
		cout << "通讯录空" << endl;
		return;
	}

	char select;
	cout << "是否删除所有联系人(y/n)>";
	cin >> select;

	if (select != 89 && select != 121)
	{
		cout << "取消删除" << endl;
		return;
	}

	// 双向链表销毁
	ListDestroy(arb->per);

	arb->size = 0;
}

// 退出通讯录
void exitAddressBook(addressBook* arb)
{
	if (arb->size == 0)
	{
		return;
	}

	// 双向链表销毁
	ListDestroy(arb->per);

	arb->size = 0;
}

/*======== ======== ======== ======== ======== ======== ======== ========*/

// 双向链表初始化
Person* ListInit()
{
	// 哨兵位的头节点
	Person* phead = (Person*)malloc(sizeof(Person));

	// 循环链表，next 指向自己
	phead->next = phead;
	phead->prev = phead;

	phead->age = 5201314;

	return phead;
}

// 双向链创建节点
Person* BuyListNode
(
	string name,      // 名字
	string phone,     // 电话
	string addr,      // 住址
	string sex,       // 性别
	unsigned int age  // 年龄
)
{
	// 创建节点
	//Person* newNode = (Person*)malloc(sizeof(Person));

	// 0x00007FFC6B09140C (vcruntime140d.dll)处(位于 CPP_App-通讯录.exe 中)引发的异常: 0xC0000005: 读取位置 0xFFFFFFFFFFFFFFFF 时发生访问冲突。
	//newNode->name = name;
	//newNode->phone = phone;
	//newNode->addr = addr;
	//newNode->sex = sex;
	//newNode->age = age;

	// new除了分配内存还会调用构造函数的。
	//newNode = new Person;
	Person* newNode = new Person;
	newNode->name = name;
	newNode->phone = phone;
	newNode->addr = addr;
	newNode->sex = sex;
	newNode->age = age;

	// 好习惯
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

// 双向链表在pos的前面进行插入
void ListInsert
(
	Person* pos,

	string name,      // 名字
	string phone,     // 电话
	string addr,      // 住址
	string sex,       // 性别
	unsigned int age  // 年龄
)
{
	assert(pos);

	Person* newNode = BuyListNode(name, phone, addr, sex, age);

	// 记录 pos 上一个节点
	Person* PosPrev = pos->prev;
	
	PosPrev->next = newNode;
	newNode->prev = PosPrev;
	newNode->next = pos;
	pos->prev = newNode;
}

// 双向链表删除pos位置的节点
void ListErase(Person* pos)
{
	assert(pos);

	// 记录 pos 上一个 下一个 节点
	Person* PosPrev = pos->prev;
	Person* PosNext = pos->next;

	free(pos);
	pos = NULL;

	PosPrev->next = PosNext;
	PosNext->prev = PosPrev;
}

// 双向链表打印
void ListPrint(Person* phead)
{
	assert(phead);

	// cur 从 phead->next 开始遍历
	// cur 等于 phead 时停止

	Person* cur = phead->next;

	while (cur != phead)
	{
		cout
			<< cur->name << " "
			<< cur->phone << " "
			<< cur->addr << " "
			<< cur->sex << " "
			<< cur->age << " "
		;
		cout << endl;

		cur = cur->next;
	}
}

// 双向链表查找
Person* ListFind(Person* phead, string name)
{
	assert(phead);

	// cur 从 phead->next 开始遍历
	// cur 等于 phead 时停止

	Person* cur = phead->next;

	while (cur != phead)
	{
		if (cur->name == name)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// 双向链表销毁
void ListDestroy(Person* phead)
{
	assert(phead);

	Person* cur = phead->next;

	while (cur != phead)
	{
		Person* curNext = cur->next;
		delete cur;
		//free(cur);
		cur = curNext;
	}

	free(phead);
	phead = NULL;
}

/*======== ======== ======== ======== ======== ======== ======== ========*/

// 判断文件是否存在
int FileWhetherExist(char* FileSrc)
{
	FILE* pfff = fopen(FileSrc, "r");

	if (pfff == NULL)
	{
		return 0;
	}

	fclose(pfff);
	pfff = NULL;

	return 1;
}

// 创建文件
int createFile()
{
	char ch[21] = "addressBook.txt";
	if (FileWhetherExist(ch) == 0)
	{
		char select;
		cout << "数据文件不存在 是否创建文件(y/n)>";
		cin >> select;

		if (select != 89 && select != 121)
		{
			cout << "这将无法保存联系人数据 是否创建文件(y/n)>";
			cin >> select;

			if (select != 89 && select != 121)
			{
				return 0;
			}
			else
			{
				FILE* pf = fopen("addressBook.txt", "w");
				fclose(pf);
				pf = NULL;
				return 1;
			}
		}

		FILE* pf = fopen("addressBook.txt", "w");
		fclose(pf);
		pf = NULL;
		return 1;
	}
}

// 写文件(特殊 需要访问 Person* per)
void saveFile(addressBook* arb)
{
	if (arb->size == 0)
	{
		cout << "通讯录空" << endl;
		return;
	}

	if (createFile() == 0)
	{
		cout << "取消保存文件" << endl;
		return;
	}

	cout << "开始保存" << endl;

	//FILE* pf = fopen("addressBook.txt", "w");
	FILE* pf = fopen("addressBook.txt", "w");

	Person* phead = arb->per;
	assert(phead);

	// cur 从 phead->next 开始遍历
	// cur 等于 phead 时停止

	Person* cur = phead->next;

	while (cur != phead)
	{
		// printf输出字符串是针对char *的，换言之，printf只能输出C语言中的内置数据，string不是c语言内置数据。
		// printf(“%s” , s.c_str());//string中c_str()成员方法返回当前字符串的首字符地址
		fprintf(pf, "%s\n\t%s\n\t%s\n\t%s\n\t%d\n\n", cur->name.c_str(), cur->phone.c_str(), cur->addr.c_str(), cur->sex.c_str(), cur->age);
		/*
			名 字
				电话
				住址
				性别
				年龄

			名 字
				电话
				住址
				性别
				年龄
		*/

		cur = cur->next;
	}

	fclose(pf);
	pf = NULL;
	cout << "保存完成" << endl;
}

// 读文件
void readFile(addressBook* arb)
{
	//if (arb->size == 0)
	//{
	//	cout << "通讯录空" << endl;
	//	return;
	//}

	char ch[21] = "addressBook.txt";
	if (FileWhetherExist(ch) == 0)
	{
		cout << "无数据文件" << endl;
		return;
	}

	if (arb->initialization == 1)
	{
		cout << "已经读取过数据文件" << endl;
		return;
	}

	cout << "读取数据" << endl;

	FILE* pf = fopen("addressBook.txt", "r");

	// 通讯录中没人才需要 初始化联系人链表
	if (arb->size == 0)
	{
		arb->per = ListInit();
	}

	string name = "0";      // 名字
	string phone = "0";     // 电话
	string addr = "0";      // 住址
	string sex = "0";       // 性别
	unsigned int age = 0;   // 年龄

	while (fscanf(pf, "%s %s %s %s %d", name.c_str(), phone.c_str(), addr.c_str(), sex.c_str(), &age) != EOF)
	{
		// 尾插
		ListInsert(arb->per, name, phone, addr, sex, age);

		arb->size++;
	}

	// 设置为 已初始化
	arb->initialization = 1;
	cout << "读取完成" << endl;
}