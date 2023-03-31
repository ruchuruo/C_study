
#include "workerManager.h";

static int createFile()
{
	if (_access(DATAFILE, 0) != 0)
	{
		// �ļ� �� ����

		char select;
		cout << "�����ļ������� �Ƿ񴴽��ļ�(y/n)>";
		cin >> select;

		if (select != 89 && select != 121)
		{
			cout << "�⽫�޷��������� �Ƿ񴴽��ļ�(y/n)>";
			cin >> select;

			if (select != 89 && select != 121)
			{
				return 0;
			}
			else
			{
				ofstream ofs;
				ofs.open(DATAFILE, ios::out | ios::binary);
				ofs.close();
				return 1;
			}
		}

		ofstream ofs;
		ofs.open(DATAFILE, ios::out | ios::binary);
		ofs.close();
		return 1;
	}

	return 1;
}



WorkerManager::WorkerManager():initialization(0), m_EmpNum(0)
{
	setEmpListPhead(en.ListInit());
}

WorkerManager::~WorkerManager()
{
	//en.ListDestroy(m_EmpListPhead);
}

// ��ʾ�˵�
void WorkerManager::ShowMenu()
{
	cout << "�� -------- ��ӭʹ��ְ������ϵͳ -      -" << endl;
	cout << "|                               -    -" << endl;
	cout << "|            0.  �˳��������      -"<< endl;
	cout << "|            1.  ����ְ����Ϣ   -     -" << endl;
	cout << "|            2.  ��ʾְ����Ϣ      -" << endl;
	cout << "|            3.  ɾ����ְְ��   -     -" << endl;
	cout << "|            4.  �޸�ְ����Ϣ      -" << endl;
	cout << "|            5.  ����ְ����Ϣ   -     -" << endl;
	cout << "|            6.  ���ձ������      -" << endl;
	cout << "|            7.  ��������ĵ�   -     -" << endl;
	cout << "|            8.  ��ȡԱ������      -" << endl;
	cout << "|            9.  ����Ա������   -     -" << endl;
	cout << "�� --------  -------- --------  -      " << m_EmpNum << endl;
}

// �˳��������
void WorkerManager::exitSystem()
{
	en.ListDestroy(m_EmpListPhead);
}

// ����ְ��
void WorkerManager::Add_Emp()
{
	int tmpId;      //ְ�����
	string tmpName; //ְ������
	int tmpDeptId;  //ְ�����ڲ������Ʊ��

	
	Worker* worker = NULL;

	cout << "����ְ��-ְ�����>";
	cin >> tmpId;

	cout << "����ְ��-ְ������>";
	cin >> tmpName;

	cout << "����ְ��-ְ������(3.�ϰ� 2.���� 1.Ա��)>";
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
		cout << "���ʧ��" << endl;
		break;
	}
	
}

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (m_EmpNum == 0)
	{
		cout << "����ϵͳΪ��" << endl;
		return;
	}

	cout << "ɾ��ְ��-ְ�����>";
	int tmpId;// ְ�����
	cin >> tmpId;

	EmpListNode* retNode = en.ListFind(m_EmpListPhead, tmpId);

	if (retNode == NULL)
	{
		cout << "δ�ҵ�" << endl;
		return;
	}

	en.ListErase(retNode);

	m_EmpNum--;
	cout << "ɾ���ɹ�" << endl;
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (m_EmpNum == 0)
	{
		cout << "����ϵͳΪ��" << endl;
		return;
	}

	cout << "���ҷ�ʽ(1.��ְ����Ų��� 2.����������)>";
	int select = 0;
	cin >> select;

	switch (select)
	{
	case 1:
	{
		cout << "���� ְ�����>";
		int tmpId;
		cin >> tmpId;

		EmpListNode* retNode = en.ListFind(m_EmpListPhead, tmpId);

		if (retNode == NULL)
		{
			cout << "δ�ҵ�" << endl;
			return;
		}

		retNode->getData()->showInfo();
	}
		break;

	case 2:
	{
		cout << "���� ְ������>";
		string tmpName;
		cin >> tmpName;

		EmpListNode* retNode = en.ListFind(m_EmpListPhead, tmpName);

		if (retNode == NULL)
		{
			cout << "δ�ҵ�" << endl;
			return;
		}

		retNode->getData()->showInfo();
	}
		break;

	default:
		cout << "����ʧ��" << endl;
		break;
	}
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (m_EmpNum == 0)
	{
		cout << "����ϵͳΪ��" << endl;
		return;
	}

	cout << "�޸� ְ�����>";
	int tmpId;
	cin >> tmpId;

	EmpListNode* retNode = en.ListFind(m_EmpListPhead, tmpId);

	if (retNode == NULL)
	{
		cout << "δ�ҵ�" << endl;
		return;
	}

	Worker* worker = NULL;

	int id;
	cout << "�޸� �� ְ�����>";
	cin >> id;

	string name;
	cout << "�޸� �� ְ������>";
	cin >> name;

	int deptId;
	cout << "�޸� �� ְ����λ>";
	cin >> deptId;

	switch (deptId)
	{
	case 1:
		worker = new Employee(id, name, deptId);
		en.ListInsert(m_EmpListPhead->getNextNode(), worker);
		m_EmpNum++;
		break;

	case 2:
		worker = new Manager(id, name, deptId);
		en.ListInsert(m_EmpListPhead->getNextNode(), worker);
		m_EmpNum++;
		break;

	case 3:
		worker = new Boss(id, name, deptId);
		en.ListInsert(m_EmpListPhead->getNextNode(), worker);
		m_EmpNum++;
		break;

	default:
		cout << "�޸�ʧ��" << endl;
		return;
		//break;
	}

	retNode->ListErase(retNode);
	m_EmpNum--;
	cout << "�޸ĳɹ�" << endl;
}

//����ְ��
void WorkerManager::Sort_Emp()
{
	if (m_EmpNum == 0)
	{
		cout << "����ϵͳΪ��" << endl;
		return;
	}

	en.ListBubbleSort(m_EmpListPhead, m_EmpNum);

	cout << "����ɹ�" << endl;
}

//����ļ�
void WorkerManager::Clean_File()
{
	en.ListClear(m_EmpListPhead);
	m_EmpNum = 0;

	cout << "��ճɹ�" << endl;
}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	if (m_EmpNum == 0)
	{
		cout << "����ϵͳΪ��" << endl;
		return;
	}

	en.ListPrint(m_EmpListPhead);
}

//���ļ�
void WorkerManager::Read_Emp()
{
	if (initialization != 0)
	{
		cout << "�Ѿ���ȡ��" << endl;
		return;
	}

	if (_access(DATAFILE, 0) != 0)
	{
		cout << "�����ļ�������" << endl;
		return;
	}

	cout << "��ʼ��ȡ" << endl;

	ifstream ifs;

	//ifs.open(DATAFILE, ios::in | ios::binary);
	ifs.open(DATAFILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	
	Worker* worker = NULL;

	int tmpid;
	string tmpName;
	int tmpDId;

	while (ifs >> tmpid && ifs >> tmpName && ifs >> tmpDId)
	{
		switch (tmpDId)
		{
		case 1:
			worker = new Employee(tmpid, tmpName, tmpDId);
			en.ListInsert(m_EmpListPhead->getNextNode(), worker);
			m_EmpNum++;
			break;

		case 2:
			worker = new Manager(tmpid, tmpName, tmpDId);
			en.ListInsert(m_EmpListPhead->getNextNode(), worker);
			m_EmpNum++;
			break;

		case 3:
			worker = new Boss(tmpid, tmpName, tmpDId);
			en.ListInsert(m_EmpListPhead->getNextNode(), worker);
			m_EmpNum++;
			break;

		default:
			cout << "��ȡʧ��" << endl;
			break;
		}
	}

	worker = NULL;
	ifs.close();
	initialization = 1;
	cout << "��ȡ�ɹ�" << endl;
}

//д�ļ�
void WorkerManager::Write_Emp()
{
	if (m_EmpNum == 0)
	{
		char select;
		cout << "����ϵͳΪ�� �Ƿ񱣴��ļ�(y/n)>";
		cin >> select;

		if (select != 78 && select != 110)
		{
			cout << "�⽫����֮ǰ���� �Ƿ񱣴��ļ�(y/n)>";
			cin >> select;

			if (select != 78 && select != 110)
			{
				;
			}
			else
			{
				cout << "ȡ������" << endl;
				return;
			}
		}
		else
		{
			cout << "ȡ������" << endl;
			return;
		}
	}

	if (createFile() == 0)
	{
		return;
	}

	cout << "��ʼ����" << endl;

	ofstream ofs;

	//ofs.open(DATAFILE, ios::out | ios::binary);
	ofs.open(DATAFILE, ios::out);

	EmpListNode* cur = m_EmpListPhead->getNextNode();

	while (cur != m_EmpListPhead)
	{
		ofs << cur->getData()->m_Id << " "
			<< cur->getData()->m_Name << " "
			<< cur->getData()->m_DeptId << endl;

		cur = cur->getNextNode();
	}

	ofs.close();

	cout << "����ɹ�" << endl;
}

// ���� Ա������ͷ
void WorkerManager::setEmpListPhead(EmpListNode* EmpListPhead)
{
	m_EmpListPhead = EmpListPhead;
}

// ��ȡ Ա������ͷ
EmpListNode* WorkerManager::getEmpListPhead()
{
	return m_EmpListPhead;
}