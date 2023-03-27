
#include "workerManager.h";



WorkerManager::WorkerManager():initialization(0), m_EmpNum(0)
{
	setEmpListPhead(en.ListInit());
}

WorkerManager::~WorkerManager()
{
}

// 显示菜单
void WorkerManager::ShowMenu()
{
	cout << "● -------- 欢迎使用职工管理系统 -      -" << endl;
	cout << "|                               -    -" << endl;
	cout << "|            0.  退出管理程序      -"<< endl;
	cout << "|            1.  增加职工信息   -     -" << endl;
	cout << "|            2.  显示职工信息      -" << endl;
	cout << "|            3.  删除离职职工   -     -" << endl;
	cout << "|            4.  修改职工信息      -" << endl;
	cout << "|            5.  查找职工信息   -     -" << endl;
	cout << "|            6.  按照编号排序      -" << endl;
	cout << "|            7.  清空所有文档   -     -" << endl;
	cout << "● --------  -------- --------  -      -" << endl;
}

// 退出管理程序
void WorkerManager::exitSystem()
{

}

// 增加职工
void WorkerManager::Add_Emp()
{
	int tmpId;      //职工编号
	string tmpName; //职工姓名
	int tmpDeptId;  //职工所在部门名称编号

	
	Worker* worker = NULL;

	cout << "增加职工-职工编号>";
	cin >> tmpId;

	cout << "增加职工-职工姓名>";
	cin >> tmpName;

	cout << "增加职工-职工部门(3.老板 2.经理 1.员工)>";
	cin >> tmpDeptId;
	switch (tmpDeptId)
	{
	case 1:
		worker = new Employee(tmpId, tmpName, tmpDeptId);
		en.ListInsert(m_EmpListPhead->getNextNode(), worker);
		m_EmpNum++;
		break;

	case 2:
		worker = new Manager(tmpId, tmpName, tmpDeptId);
		en.ListInsert(m_EmpListPhead->getNextNode(), worker);
		m_EmpNum++;
		break;

	case 3:
		worker = new Boss(tmpId, tmpName, tmpDeptId);
		en.ListInsert(m_EmpListPhead->getNextNode(), worker);
		m_EmpNum++;
		break;

	default:
		cout << "添加失败" << endl;
		break;
	}
	
}

//删除职工
void WorkerManager::Del_Emp()
{
	cout << "删除职工-职工编号>";
	int tmpId;// 职工编号
	cin >> tmpId;

	en.ListErase(en.ListFind(m_EmpListPhead, tmpId));

	m_EmpNum--;
}

//查找职工
void WorkerManager::Find_Emp()
{
	cout << "查找方式(1.按职工编号查找 2.按姓名查找)>";
	int select = 0;
	cin >> select;

	switch (select)
	{
	case 1:
	{
		cout << "查找 职工编号>";
		int tmpId;
		cin >> tmpId;

		EmpListNode* retNode = en.ListFind(m_EmpListPhead, tmpId);

		if (retNode == NULL)
		{
			cout << "未找到" << endl;
			return;
		}

		retNode->getData()->showInfo();
	}
		break;

	case 2:
	{
		cout << "查找 职工姓名>";
		string tmpName;
		cin >> tmpName;

		EmpListNode* retNode = en.ListFind(m_EmpListPhead, tmpName);

		if (retNode == NULL)
		{
			cout << "未找到" << endl;
			return;
		}

		retNode->getData()->showInfo();
	}
		break;

	default:
		cout << "查找失败" << endl;
		break;
	}
}

//修改职工
void WorkerManager::Mod_Emp()
{
	cout << "修改 职工编号>";
	int tmpId;
	cin >> tmpId;

	EmpListNode* retNode = en.ListFind(m_EmpListPhead, tmpId);

	if (retNode == NULL)
	{
		cout << "未找到" << endl;
		return;
	}

	Worker* worker = NULL;

	int id;
	cout << "修改 新 职工编号>";
	cin >> id;

	string name;
	cout << "修改 新 职工姓名>";
	cin >> name;

	int deptId;
	cout << "修改 新 职工岗位>";
	cin >> deptId;

	switch (deptId)
	{
	case 1:
		worker = new Employee(tmpId, name, deptId);
		en.ListInsert(m_EmpListPhead->getNextNode(), worker);
		m_EmpNum++;
		break;

	case 2:
		worker = new Manager(tmpId, name, deptId);
		en.ListInsert(m_EmpListPhead->getNextNode(), worker);
		m_EmpNum++;
		break;

	case 3:
		worker = new Boss(tmpId, name, deptId);
		en.ListInsert(m_EmpListPhead->getNextNode(), worker);
		m_EmpNum++;
		break;

	default:
		cout << "修改失败" << endl;
		break;
	}

	retNode->ListErase(retNode);
	m_EmpNum--;
}

//显示职工
void WorkerManager::Show_Emp()
{
	en.ListPrint(m_EmpListPhead);
}

// 设置 员工链表头
void WorkerManager::setEmpListPhead(EmpListNode* EmpListPhead)
{
	m_EmpListPhead = EmpListPhead;
}

// 获取 员工链表头
EmpListNode* WorkerManager::getEmpListPhead()
{
	return m_EmpListPhead;
}