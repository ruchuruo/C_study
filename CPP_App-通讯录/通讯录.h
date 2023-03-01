#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

// 屏幕中输入输出
#include <iostream>

// 断言
#include <assert.h>

// 引用标准的命名空间
using namespace std;

/*======== ======== ======== ========*/

// 联系人
struct Person
{
	string name;      // 名字
	string phone;     // 电话
	string addr;      // 住址
	string sex;       // 性别
	unsigned int age; // 年龄

	Person* next;
	Person* prev;
};


// 通讯录
struct addressBook
{
	Person* per; // 联系人
	int size;    // 通讯录中人员个数
	int initialization;// 是否已经初始化(1已经初始化，0还没初始化)
};

/*======== ======== ======== ========*/

// 显示菜单
void showMenu(int arbSize);

// 添加联系人
void addPerson(addressBook* arb);

// 显示联系人
int showPerson(addressBook* arb);

// 删除联系人
int delPerson(addressBook* arb);

// 查找联系人
int findPerson(addressBook* arb);

// 修改联系人
int modifyPerson(addressBook* arb);

// 清空通讯录
void destroyPerson(addressBook* arb);

// 退出通讯录
void exitAddressBook(addressBook* arb);

/*======== ======== ======== ========*/

// 双向链表初始化
Person* ListInit();

// 双向链创建节点
Person* BuyListNode
(
	string name,      // 名字
	string phone,     // 电话
	string addr,      // 住址
	string sex,       // 性别
	unsigned int age  // 年龄
);

// 双向链表在pos的前面进行插入
void ListInsert
(
	Person* pos,

	string name,      // 名字
	string phone,     // 电话
	string addr,      // 住址
	string sex,       // 性别
	unsigned int age  // 年龄
);

// 双向链表删除pos位置的节点
void ListErase(Person* pos);

// 双向链表打印
void ListPrint(Person* phead);

// 双向链表查找
Person* ListFind(Person* phead, string name);

// 双向链表销毁
void ListDestroy(Person* phead);

/*======== ======== ======== ========*/

// 判断文件是否存在
int FileWhetherExist(char* FileSrc);

// 创建文件
int createFile();

// 写文件(特殊 需要访问 Person* per)
void saveFile(addressBook* arb);

// 读文件
void readFile(addressBook* arb);