
/*
	��1�׶�C++ ����֮�� ��0��1����

	��2�׶�ʵս-ͨѶ¼����

	��3�׶�-C++���ı��

	��4�׶�ʵս-���ڶ�̬����ҵְ��ϵͳ

	��5�׶�-C++��߱��

	��6�׶�ʵս-����STL������̵��ݽ�����

		�ݽ��������̹���ϵͳ

			1�� �ݽ�������������

				1.1 ��������

					�� ѧУ����һ���ݽ�����������12���˲μӡ����������֣���һ��Ϊ��̭�����ڶ���Ϊ������
					�� ������ʽ�����������ÿ��6���ˣ�ѡ��ÿ��Ҫ������飬���б���
					�� ÿ��ѡ�ֶ��ж�Ӧ�ı�ţ��� 10001 ~ 10012
					�� ��һ�ַ�Ϊ����С�飬ÿ��6���ˡ� ���尴��ѡ�ֱ�Ž��г�ǩ��˳���ݽ���
					�� ��С���ݽ������̭����������������ѡ�֣�ǰ����������������һ�ֵı�����
					�� �ڶ���Ϊ������ǰ����ʤ��
					�� ÿ�ֱ���������Ҫ��ʾ����ѡ�ֵ���Ϣ

				1.2 ������

					�� ��ʼ�ݽ����������������������̣�ÿ�������׶���Ҫ���û�һ����ʾ���û���������������һ���׶�
					�� �鿴�����¼���鿴֮ǰ����ǰ���������ÿ�α��������¼���ļ��У��ļ���.csv��׺������
					�� ��ձ�����¼�����ļ����������
					�� �˳��������򣺿����˳���ǰ����

				1.3 ����Ч��ͼ��

					|   **********************
					|   **** 1 ��ʼ�ݽ����� ****
					|   **** 2 �鿴�����¼ ****
					|   **** 3 ��ձ�����¼ ****
					|   **** 0 �˳��������� ****
					|   **********************


			2�� ��Ŀ����

				������Ŀ�������£�

					��������Ŀ
					����ļ�

				2.1 ������Ŀ

					��vs2017�󣬵����������Ŀ�������µ�C++��Ŀ
					��д��Ŀ�����Լ�ѡȡ��Ŀ·�������ȷ��������Ŀ

				2.2 ����ļ�

					�Ҽ�Դ�ļ�����������ļ�����
					��д�ļ����ƣ�������
					�����ļ��ɹ���Ч������ͼ

				���ˣ���Ŀ�Ѵ������


			3�� ����������

				����������

					�ṩ�˵��������û�����
					���ݽ��������̽��п���
					���ļ��Ķ�д����

				3.1�����ļ�

					��ͷ�ļ���Դ�ļ����ļ����·ֱ𴴽�speechManager.h �� speechManager.cpp�ļ�

				3.2 ͷ�ļ�ʵ��

					��speechManager.h����ƹ�����

					�������£�

						#pragma once
						#include<iostream>
						using namespace std;
						//�ݽ�������
						class SpeechManager
						{
						public:
							//���캯��
							SpeechManager();
							//��������
							~SpeechManager();
						};

				3.3 Դ�ļ�ʵ��

					��speechManager.cpp�н����������������ʵ�ֲ�ȫ

						#include "speechManager.h"
						SpeechManager::SpeechManager()
						{
						}
						SpeechManager::~SpeechManager()
						{
						}

				�����ݽ��������Դ������


			4�� �˵�����

				�������������û��Ĺ�ͨ����

				4.1 ��ӳ�Ա����

					�ڹ�����speechManager.h����ӳ�Ա���� void show_Menu();

						//�ݽ�������
						class SpeechManager
						{
						public:
							//���캯��
							SpeechManager();
							//��������
							~SpeechManager();
					|   	// �˵�
					|   	void show_Menu();
						};

				4.2 �˵�����ʵ��

					�ڹ�����speechManager.cpp��ʵ�� show_Menu()����

						void SpeechManager::show_Menu()
						{
							cout << "********************************************" << endl;
							cout << "************* ��ӭ�μ��ݽ����� ************" << endl;
							cout << "************* 1.��ʼ�ݽ����� *************" << endl;
							cout << "************* 2.�鿴�����¼ *************" << endl;
							cout << "************* 3.��ձ�����¼ *************" << endl;
							cout << "************* 0.�˳��������� *************" << endl;
							cout << "********************************************" << endl;
							cout << endl;
						}

				4.3 ���Բ˵�����

					���ݽ��������̹���ϵͳ.cpp�в��Բ˵�����

					���룺

						#include<iostream>
						using namespace std;
						#include "speechManager.h"
						int main() {
							SpeechManager sm;
							sm.show_Menu();
							system("pause");
							return 0;
						}

					����Ч����ͼ��

						|   **********************
						|   **** ��ӭ�μ��ݽ����� **
						|   **** 1.��ʼ�ݽ����� ****
						|   **** 2.�鿴�����¼ ****
						|   **** 3.��ձ�����¼ ****
						|   **** 0.�˳��������� ****
						|   **********************
						|   
						|   �밴���������...

					�˵��������


			5�� �˳�����

				5.1 �ṩ���ܽӿ�

					��main�������ṩ��֧ѡ���ṩÿ�����ܽӿ�

					���룺

						int main() {
							SpeechManager sm;
							int choice = 0; //�����洢�û���ѡ��
							while (true)
							{
								sm.show_Menu();
								cout << "����������ѡ�� " << endl;
								cin >> choice; // �����û���ѡ��
								switch (choice)
								{
								case 1: //��ʼ����
									break;
								case 2: //�鿴��¼
									break;
								case 3: //��ռ�¼
									break;
								case 0: //�˳�ϵͳ
									break;
								default:
									system("cls"); //����
									break;
								}
							}
							system("pause");
							return 0;
						}

				5.2 ʵ���˳�����

					��speechManager.h���ṩ�˳�ϵͳ�ĳ�Ա���� void exitSystem();
					��speechManager.cpp���ṩ����Ĺ���ʵ��

						void SpeechManager::exitSystem()
						{
							cout << "��ӭ�´�ʹ��" << endl;
							system("pause");
							exit(0);
						}

				5.3���Թ���

					��main������֧ 0 ѡ���У������˳�����Ľӿ�

						while (true)
						{
							sm.show_Menu();
							cout << "����������ѡ�� " << endl;
							cin >> choice; // �����û���ѡ��
							switch (choice)
							{
							case 1: //��ʼ����
								break;
							case 2: //�鿴��¼
								break;
							case 3: //��ռ�¼
								break;
							case 0: //�˳�ϵͳ
					|   		sm.exitSystem();
								break;
							default:
								system("cls"); //����
								break;
							}
						}

					���в���Ч����ͼ��

						|   **********************
						|   **** ��ӭ�μ��ݽ����� **
						|   **** 1.��ʼ�ݽ����� ****
						|   **** 2.�鿴�����¼ ****
						|   **** 3.��ձ�����¼ ****
						|   **** 0.�˳��������� ****
						|   **********************
						|   
						|   ����������ѡ��
						|   0
						|   ��ӭ�´�ʹ��
						|   �밴���������...


			6���ݽ���������

				6.1 ���ܷ���

					�������̷�����

						��ǩ �� ��ʼ�ݽ����� �� ��ʾ��һ�ֱ������ ��
						��ǩ �� ��ʼ�ݽ����� �� ��ʾǰ������� �� �������

				6.2 ����ѡ����

					ѡ�����е����԰�����ѡ������������
					ͷ�ļ��д��� speaker.h�ļ�������Ӵ��룺

						#pragma once
						#include<iostream>
						using namespace std;
						class Speaker
						{
						public:
							string m_Name; //����
							double m_Score[2]; //���� ��������ֵ÷�
						};

				6.3 ����

					6.3.1 ��Ա�������

						��speechManager.h���������

						//����ѡ�� ���� 12��
						vector<int>v1;
						//��һ�ֽ������� 6��
						vector<int>v2;
						//ʤ��ǰ�������� 3��
						vector<int>vVictory;
						//��ű�� �Լ���Ӧ�� ����ѡ�� ����
						map<int, Speaker> m_Speaker;

					6.3.2 ��ʼ������

						��speechManager.h���ṩ��ʼ�����ĵĳ�Ա���� void initSpeech();

							//��ʼ������
							void initSpeech();

						��speechManager.cpp��ʵ�� void initSpeech();

							void SpeechManager::initSpeech()
							{
								//������֤Ϊ��
								this->v1.clear();
								this->v2.clear();
								this->vVictory.clear();
								this->m_Speaker.clear();
								//��ʼ����������
								this->m_Index = 1;
							}

						SpeechManager���캯���е��� void initSpeech();

							SpeechManager::SpeechManager()
							{
							//��ʼ������
							this->initSpeech();
							}

					6.3.3 ����ѡ��

						��speechManager.h���ṩ��ʼ�����ĵĳ�Ա���� void createSpeaker();

							//��ʼ������12��ѡ��
							void createSpeaker();

						��speechManager.cpp��ʵ�� void createSpeaker();

							void SpeechManager::createSpeaker()
							{
								string nameSeed = "ABCDEFGHIJKL";
								for (int i = 0; i < nameSeed.size(); i++)
								{
									string name = "ѡ��";
									name += nameSeed[i];
									Speaker sp;
									sp.m_Name = name;
									for (int i = 0; i < 2; i++)
									{
										sp.m_Score[i] = 0;
									}
									//12��ѡ�ֱ��
									this->v1.push_back(i + 10001);
									//ѡ�ֱ�� �Լ���Ӧ��ѡ�� ��ŵ�map������
									this->m_Speaker.insert(make_pair(i + 10001, sp));
								}
							}

						SpeechManager��� ���캯���е��� void createSpeaker();

							SpeechManager::SpeechManager()
							{
								//��ʼ������
								this->initSpeech();
								//����ѡ��
								this->createSpeaker();
							}

						���� ��main�����У������ڴ������������ʹ�����д������12��ѡ�ֳ�ʼ״̬

							for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
							{
								cout << "ѡ�ֱ�ţ�" << it->first
								<< " ������ " << it->second.m_Name
								<< " �ɼ��� " << it->second.m_Score[0] << endl;
							}

							���£�

							int main() {
								SpeechManager sm;

							|   for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
							|   {
							|   	cout << "ѡ�ֱ�ţ�" << it->first
							|   	<< " ������ " << it->second.m_Name
							|   	<< " �ɼ��� " << it->second.m_Score[0] << endl;
							|   }

								int choice = 0; //�����洢�û���ѡ��
								while (true)
								{
									sm.show_Menu();
									cout << "����������ѡ�� " << endl;
									cin >> choice; // �����û���ѡ��
									switch (choice)
									{
									case 1: //��ʼ����
									......
									case 0: //�˳�ϵͳ
										break;
									default:
										system("cls"); //����
										break;
									}
								}
								system("pause");
								return 0;
							}

						����Ч����ͼ��

						|   |   ѡ�ֱ��:10001  ����:ѡ��A �ɼ�:0
						|   |   ѡ�ֱ��:10002  ����:ѡ��B �ɼ�:0
						|   |   ѡ�ֱ��:10003  ����:ѡ��C �ɼ�:0
						|   |   ѡ�ֱ��:10004  ����:ѡ��D �ɼ�:0
						|   |   ѡ�ֱ��:10005  ����:ѡ��E �ɼ�:0
						|   |   ѡ�ֱ��:10006  ����:ѡ��F �ɼ�:0
						|   |   ѡ�ֱ��:10007  ����:ѡ��G �ɼ�:0
						|   |   ѡ�ֱ��:10008  ����:ѡ��H �ɼ�:0
						|   |   ѡ�ֱ��:10009  ����:ѡ��I �ɼ�:0
						|   |   ѡ�ֱ��:100010 ����:ѡ��J �ɼ�:0
						|   |   ѡ�ֱ��:100011 ����:ѡ��K �ɼ�:0
						|   |   ѡ�ֱ��:100012 ����:ѡ��L �ɼ�:0
							|   **********************
							|   **** ��ӭ�μ��ݽ����� **
							|   **** 1.��ʼ�ݽ����� ****
							|   **** 2.�鿴�����¼ ****
							|   **** 3.��ձ�����¼ ****
							|   **** 0.�˳��������� ****
							|   **********************
							|
							|   ����������ѡ��

						������Ϻ󣬿��Խ����Դ���ɾ����ע�͡�

					6.3.4 ��ʼ������Ա�������

						��speechManager.h���ṩ��ʼ�����ĵĳ�Ա���� void startSpeech();
						�ú�����������Ҫ���Ʊ���������

							//��ʼ���� - �������̿���
							void startSpeech();

						��speechManager.cpp�н�startSpeech�Ŀ�ʵ����д��
						���ǿ����Ƚ��������������� д��������

							//��ʼ����
							void SpeechManager::startSpeech()
							{
								//��һ�ֱ���
								//1����ǩ
								//2������
								//3����ʾ�������
								//�ڶ��ֱ���
								//1����ǩ
								//2������
								//3����ʾ���ս��
								//4���������
							}

					6.3.5 ��ǩ

						����������

							��ʽ����ǰ������ѡ�ֵı���˳����Ҫ���ң�����ֻ��Ҫ�����ѡ�ֱ�ŵ����� ���Ҵ��򼴿�
							��speechManager.h���ṩ��ǩ�ĵĳ�Ա���� void speechDraw();

								//��ǩ
								void speechDraw();

							��speechManager.cpp��ʵ�ֳ�Ա���� void speechDraw();

								void SpeechManager::speechDraw()
								{
									cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ"<<endl;
									cout << "---------------------" << endl;
									cout << "��ǩ���ݽ�˳�����£�" << endl;
									if (this->m_Index == 1)
									{
										random_shuffle(v1.begin(), v1.end());
										for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
										{
											cout << *it << " ";
										}
										cout << endl;
									}
									else
									{
										random_shuffle(v2.begin(), v2.end());
										for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
										{
											cout << *it << " ";
										}
										cout << endl;
									}
									cout << "---------------------" << endl;
									system("pause");
									cout << endl;
								}

							��startSpeech�������̿��Ƶĺ����У����ó�ǩ����

								void SpeechManager::startSpeech()
								{
									//��һ�ֱ���
									//1����ǩ
								|   speechDraw();
									//2������
									//3����ʾ�������
									//�ڶ��ֱ���
									//1����ǩ
									//2������
									//3����ʾ���ս��
									//4���������
								}

							��main�����У���֧1ѡ���У����ÿ�ʼ�����Ľӿ�

								int main() {
									SpeechManager sm;

									for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
									{
									......
									}

									int choice = 0; //�����洢�û���ѡ��
									while (true)
									{
										sm.show_Menu();
										cout << "����������ѡ�� " << endl;
										cin >> choice; // �����û���ѡ��
										switch (choice)
										{
										case 1: //��ʼ����
											sm.startSpeech();
											break;
										......
										case 0: //�˳�ϵͳ
											break;
										default:
											system("cls"); //����
											break;
										}
									}
									system("pause");
									return 0;
								}

							����

								|   **********************
								|   **** ��ӭ�μ��ݽ����� **
								|   **** 1.��ʼ�ݽ����� ****
								|   **** 2.�鿴�����¼ ****
								|   **** 3.��ձ�����¼ ****
								|   **** 0.�˳��������� ****
								|   **********************
								|
								|   ����������ѡ��
								|   1
								|   �� << 1 >> �ֱ���ѡ�����ڳ�ǩ
								|   ----------------
								|   ��ǩ���ݽ�˳������:
								|   10005 10008 10010 10012 10001 10003 10009 10004 10007 10002 10006 10011
								|   ----------------
								|   �밴���������...

					6.3.6 ��ʼ����

						��speechManager.h���ṩ�����ĵĳ�Ա���� void speechContest();

							//����
							void speechContest();

						��speechManager.cpp��ʵ�ֳ�Ա���� void speechContest();

							void SpeechManager::speechContest()
							{
								cout << "------------- ��" << this->m_Index << "����ʽ������ʼ��------------- " << endl;
								multimap<double, int, greater<int>> groupScore; //��ʱ����������key���� value ѡ�ֱ��
								int num = 0; //��¼��Ա����6��Ϊ1��
								vector <int>v_Src; //��������Ա����
								if (this->m_Index == 1)
								{
									v_Src = v1;
								}
								else
								{
									v_Src = v2;
								}
								//�������в���ѡ��
								for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
								{
									num++;
									//��ί���
									deque<double>d;
									for (int i = 0; i < 10; i++)
									{
										double score = (rand() % 401 + 600) / 10.f; // 600 ~ 1000
										//cout << score << " ";
										d.push_back(score);
									}
									sort(d.begin(), d.end(), greater<double>()); //����
									d.pop_front(); //ȥ����߷�
									d.pop_back(); //ȥ����ͷ�
									double sum = accumulate(d.begin(), d.end(), 0.0f); //��ȡ�ܷ�
									double avg = sum / (double)d.size(); //��ȡƽ����
									//ÿ����ƽ����
									//cout << "��ţ� " << *it << " ѡ�֣� " << this->m_Speaker[*it].m_Name << " ��ȡƽ��
									��Ϊ�� " << avg << endl; //��ӡ����
										this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
									//6����һ�飬����ʱ��������
									groupScore.insert(make_pair(avg, *it));
									if (num % 6 == 0)
									{
										cout << "��" << num / 6 << "С��������Σ�" << endl;
										for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it
											!= groupScore.end(); it++)
										{
											cout << "���: " << it->second << " ������ " << this->m_Speaker[it -> second].m_Name << " �ɼ��� " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] <<
												endl;
										}
										int count = 0;
										//ȡǰ����
										for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
										{
											if (this->m_Index == 1)
											{
												v2.push_back((*it).second);
											}
											else
											{
												vVictory.push_back((*it).second);
											}
										}
										groupScore.clear();
										cout << endl;
									}
								}
								cout << "------------- ��" << this->m_Index << "�ֱ������ ------------- " << endl;
								system("pause");
							}

						��startSpeech�������̿��Ƶĺ����У����ñ�������

							void SpeechManager::startSpeech()
							{
								//��һ�ֱ���
								//1����ǩ
								speechDraw();
								//2������
							|   speechContest();
								//3����ʾ�������
								//�ڶ��ֱ���
								//1����ǩ
								//2������
								//3����ʾ���ս��
								//4���������
							}

						�ٴ����д��룬���Ա���

							|   **********************
							|   **** ��ӭ�μ��ݽ����� **
							|   **** 1.��ʼ�ݽ����� ****
							|   **** 2.�鿴�����¼ ****
							|   **** 3.��ձ�����¼ ****
							|   **** 0.�˳��������� ****
							|   **********************
							|
							|   ����������ѡ��
							|   1
							|   �� << 1 >> �ֱ���ѡ�����ڳ�ǩ
							|   ----------------
							|   ��ǩ���ݽ�˳������:
							|   10011 10002 10010 10003 10001 10012 10008 10004 10005 10007 10009 10006
							|   ----------------
							|   �밴���������...
							|   ----------------��1����ʽ������ʼ----------------
							|   ��1С���������:
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   
							|   ��2С���������:
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ----------------��1����ʽ�������----------------
							|   �밴���������...

					6.3.7 ��ʾ��������

						��speechManager.h���ṩ�����ĵĳ�Ա���� void showScore();

							//��ʾ�������
							void showScore();

						��speechManager.cpp��ʵ�ֳ�Ա���� void showScore();

							void SpeechManager::showScore()
							{
								cout << "---------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
								vector<int>v;
								if (this->m_Index == 1)
								{
									v = v2;
								}
								else
								{
									v = vVictory;
								}
								for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
								{
									cout << "ѡ�ֱ�ţ�" << *it << " ������ " << m_Speaker[*it].m_Name << " �÷֣� " <<
										m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
								}
								cout << endl;
								system("pause");
								system("cls");
								this->show_Menu();
							}

						��startSpeech�������̿��Ƶĺ����У�������ʾ������������

							void SpeechManager::startSpeech()
							{
								//��һ�ֱ���
								//1����ǩ
								speechDraw();
								//2������
								speechContest();
								//3����ʾ�������
							|   showScore();
								//�ڶ��ֱ���
								//1����ǩ
								//2������
								//3����ʾ���ս��
								//4���������
							}

						���д��룬����Ч��

							|   ----------------��1����ʽ������ʼ----------------
							|   ��1С���������:
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|
							|   ��2С���������:
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ----------------��1����ʽ�������----------------
							|   �밴���������...
							|   ----------------��1�ֽ���ѡ����Ϣ����----------------
							|   ѡ�ֱ��:100** ����:ѡ��* �÷�:*
							|   ѡ�ֱ��:100** ����:ѡ��* �÷�:*
							|   ѡ�ֱ��:100** ����:ѡ��* �÷�:*
							|   ѡ�ֱ��:100** ����:ѡ��* �÷�:*
							|   ѡ�ֱ��:100** ����:ѡ��* �÷�:*
							|   ѡ�ֱ��:100** ����:ѡ��* �÷�:*
							|   �밴���������...

					6.3.8 �ڶ��ֱ���

						�ڶ��ֱ�������ͬ��һ�֣�ֻ�Ǳ���������+1���������̲���

						��startSpeech�������̿��Ƶĺ����У�����ڶ��ֵ�����

							void SpeechManager::startSpeech()
							{
								//��һ�ֱ���
								//1����ǩ
								speechDraw();
								//2������
								speechContest();
								//3����ʾ�������
								showScore();
								//�ڶ��ֱ���
							|   this->m_Index++;
								//1����ǩ
								//2������
								//3����ʾ���ս��
								//4���������
							}

						���ԣ��������������̶���ͨ

							|   **********************
							|   **** ��ӭ�μ��ݽ����� **
							|   **** 1.��ʼ�ݽ����� ****
							|   **** 2.�鿴�����¼ ****
							|   **** 3.��ձ�����¼ ****
							|   **** 0.�˳��������� ****
							|   **********************
							|   
							|   �� << 2 >> �ֱ���ѡ�����ڳ�ǩ
							|   ----------------
							|   ��ǩ���ݽ�˳������:
							|   100** 100** 100** 100** 100** 100** 
							|   ----------------
							|   �밴���������...
							|   ----------------��2����ʽ������ʼ----------------
							|   ��1С���������:
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|   ���:100** ����:ѡ��* �ɼ�:*
							|
							|   ----------------��2����ʽ�������----------------
							|   �밴���������...
							|   ----------------��2�ֽ���ѡ����Ϣ����----------------
							|   ѡ�ֱ��:100** ����:ѡ��* �÷�:*
							|   ѡ�ֱ��:100** ����:ѡ��* �÷�:*
							|   ѡ�ֱ��:100** ����:ѡ��* �÷�:*
							|   �밴���������...

				6.4 �������

					����������

						��ÿ���ݽ������ĵ÷ּ�¼���ļ���

					����ʵ�֣�

						��speechManager.h����ӱ����¼�ĳ�Ա���� void saveRecord();

							//�����¼
							void saveRecord();

						��speechManager.cpp��ʵ�ֳ�Ա���� void saveRecord();

							void SpeechManager::saveRecord()
							{
								ofstream ofs;
								ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ� -- д�ļ�
								//��ÿ��������д�뵽�ļ���
								for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
								{
									ofs << *it << ","
										<< m_Speaker[*it].m_Score[1] << ",";
								}
								ofs << endl;
								//�ر��ļ�
								ofs.close();
								cout << "��¼�Ѿ�����" << endl;
							}

						��startSpeech�������̿��Ƶĺ����У������ñ����¼��������

							void SpeechManager::startSpeech()
							{
								//��һ�ֱ���
								//1����ǩ
								speechDraw();
								//2������
								speechContest();
								//3����ʾ�������
								showScore();
								//�ڶ��ֱ���
								this->m_Index++;
								//1����ǩ
								speechDraw();
								//2������
								speechContest();
								//3����ʾ���ս��
								showScore();
								//4���������
							|   saveRecord();
							|   cout << "����������" << endl;
							|   system("pause")
							|   system("cls");
							}

						���ԣ�����������Ϻ��¼�������

							|   **********************
							|   **** ��ӭ�μ��ݽ����� **
							|   **** 1.��ʼ�ݽ����� ****
							|   **** 2.�鿴�����¼ ****
							|   **** 3.��ձ�����¼ ****
							|   **** 0.�˳��������� ****
							|   **********************
							|   
							|   ��¼�ѱ���
							|   ����������
							|   �밴���������...

						���ü��±����ļ� speech.csv�����汣����ǰ����ѡ�ֵı���Լ��÷�

							100**,*,100**,*100**,*,

					���ˣ������ݽ���������������ϣ�


			7�� �鿴��¼

				7.1 ��ȡ��¼����

					��speechManager.h����ӱ����¼�ĳ�Ա���� void loadRecord();
					����ж��ļ��Ƿ�Ϊ�յı�־ bool fileIsEmpty;
					��������¼������ map<int, vector<string>> m_Record;

					����m_Record �е�key����ڼ��죬value��¼�������Ϣ

						//��ȡ��¼
						void loadRecord();
						//�ļ�Ϊ�յı�־
						bool fileIsEmpty;
						//�����¼
						map<int, vector<string>> m_Record;

					��speechManager.cpp��ʵ�ֳ�Ա���� void loadRecord();

						void SpeechManager::loadRecord()
						{
							ifstream ifs("speech.csv", ios::in); //���������� ��ȡ�ļ�
							if (!ifs.is_open())
							{
								this->fileIsEmpty = true;
								cout << "�ļ������ڣ�" << endl;
								ifs.close();
								return;
							}
							char ch;
							ifs >> ch;
							if (ifs.eof())
							{
								cout << "�ļ�Ϊ��!" << endl;
								this->fileIsEmpty = true;
								ifs.close();
								return;
							}
							//�ļ���Ϊ��
							this->fileIsEmpty = false;
							ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ
							string data;
							int index = 0;
							while (ifs >> data)
							{
								//cout << data << endl;
								vector<string>v;
								int pos = -1;
								int start = 0;
								while (true)
								{
									pos = data.find(",", start); //��0��ʼ���� ','
									if (pos == -1)
									{
										break; //�Ҳ���break����
									}
									string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã���
									��2 ��ȡ����
										v.push_back(tmp);
									start = pos + 1;
								}
								this->m_Record.insert(make_pair(index, v));
								index++;
							}
							ifs.close();
						}

					��SpeechManager���캯���е��û�ȡ�����¼����

						SpeechManager::SpeechManager()
						{
							//��ʼ������
							this->initSpeech();
							//����ѡ��
							this->createSpeaker();
							//��ȡ�����¼
							this->loadRecord();
						}

				7.2 �鿴��¼����

					��speechManager.h����ӱ����¼�ĳ�Ա���� void showRecord();

						//��ʾ����÷�
						void showRecord();

					��speechManager.cpp��ʵ�ֳ�Ա���� void showRecord();

						void SpeechManager::showRecord()
						{
							for (int i = 0; i < this->m_Record.size(); i++)
							{
								cout << "��" << i + 1 << "�� " <<
									"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
									"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
									"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
							}
							system("pause");
							system("cls");
						}

					7.3 ���Թ���

						��main������֧ 2 ѡ���У����ò鿴��¼�Ľӿ�

							int main() {
								SpeechManager sm;

								for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
								{
								......
								}

								int choice = 0; //�����洢�û���ѡ��
								while (true)
								{
									sm.show_Menu();
									cout << "����������ѡ�� " << endl;
									cin >> choice; // �����û���ѡ��
									switch (choice)
									{
									case 1: //��ʼ����
										sm.startSpeech();
										break;
									case 2: //�鿴��¼
							|       	sm.showRecord();
										break;
									......
									case 0: //�˳�ϵͳ
										break;
									default:
										system("cls"); //����
										break;
									}
								}
								system("pause");
								return 0;
							}

						��ʾЧ����ͼ�������β��������4����¼��

							|   **********************
							|   **** ��ӭ�μ��ݽ����� **
							|   **** 1.��ʼ�ݽ����� ****
							|   **** 2.�鿴�����¼ ****
							|   **** 3.��ձ�����¼ ****
							|   **** 0.�˳��������� ****
							|   **********************
							|   
							|   ����������ѡ��:
							|   2
							|   ��1�� �ھ����:100** �÷�:* �Ǿ����:100** �÷�:* �������:100** �÷�:*
							|   ��2�� �ھ����:100** �÷�:* �Ǿ����:100** �÷�:* �������:100** �÷�:*
							|   ��3�� �ھ����:100** �÷�:* �Ǿ����:100** �÷�:* �������:100** �÷�:*
							|   ��4�� �ھ����:100** �÷�:* �Ǿ����:100** �÷�:* �������:100** �÷�:*
							|   �밴���������...

					7.4 bug���

						Ŀǰ�������м���bugδ�����

							1. �鿴�����¼�����ļ������ڻ�Ϊ�գ���δ��ʾ
								�����ʽ����showRecord�����У���ʼ�ж��ļ�״̬�������ж�

									void SpeechManager::showRecord()
									{
									|   if(this->fileIsEmpty)
									|   {
									|   	cout << "�ļ������ڣ����¼Ϊ��" << endl;
									|   }
									|   else
									|   {
											for (int i = 0; i < this->m_Record.size(); i++)
											{
												cout << "��" << i + 1 << "�� " <<
													"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
													"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
													"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
											}
									|   }
										
										system("pause");
										system("cls");
									}

							2. ����¼Ϊ�ջ򲻴��ڣ�����������Ȼ��ʾ��¼Ϊ��
								�����ʽ��saveRecord�и����ļ�Ϊ�յı�־

									void SpeechManager::saveRecord()
									{
										ofstream ofs;
										ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ� -- д�ļ�
										//��ÿ��������д�뵽�ļ���
										for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
										{
											ofs << *it << ","
												<< m_Speaker[*it].m_Score[1] << ",";
										}
										ofs << endl;
										//�ر��ļ�
										ofs.close();
										cout << "��¼�Ѿ�����" << endl;

									|   //�м�¼�ˣ��ļ���Ϊ��
									|   this->fileIsEmpty = false;
									}

							3. ��������鲻����������ļ�¼��û��ʵʱ����
								�����ʽ��������Ϻ�������������

									void SpeechManager::startSpeech()
									{
										//��һ�ֱ���
										//1����ǩ
										speechDraw();
										//2������
										speechContest();
										//3����ʾ�������
										showScore();
										//�ڶ��ֱ���
										this->m_Index++;
										//1����ǩ
										speechDraw();
										//2������
										speechContest();
										//3����ʾ���ս��
										showScore();
										//4���������
										saveRecord();

									|   //���ñ���
									|   //��ʼ������
									|   this->initSpeech();
									|   
									|   //����ѡ��
									|   this->createSpeaker();
									|   
									|   //��ȡ�����¼
									|   this->loadRecord();
										
										cout << "����������" << endl;
										system("pause")
										system("cls");
									}

							4. �ڳ�ʼ��ʱ��û�г�ʼ����¼����
								�����ʽ��initSpeech����� ��ʼ����¼����

									void SpeechManager::initSpeech()
									{
										//������֤Ϊ��
										this->v1.clear();
										this->v2.clear();
										this->vVictory.clear();
										this->m_Speaker.clear();
										//��ʼ����������
										this->m_Index = 1;
									|   //��ʼ����¼����
									|   this->m_Record.clear();
									}

							5. ÿ�μ�¼����һ����
								�����ʽ����main����һ��ʼ ������������

									srand((unsigned int)time(NULL));

							����bug����� ���ԣ�

								|   **********************
								|   **** ��ӭ�μ��ݽ����� **
								|   **** 1.��ʼ�ݽ����� ****
								|   **** 2.�鿴�����¼ ****
								|   **** 3.��ձ�����¼ ****
								|   **** 0.�˳��������� ****
								|   **********************
								|   
								|   ����������ѡ��:
								|   2
								|   ��1�� �ھ����:100** �÷�:* �Ǿ����:100** �÷�:* �������:100** �÷�:*
								|   ��2�� �ھ����:100** �÷�:* �Ǿ����:100** �÷�:* �������:100** �÷�:*
								|   ��3�� �ھ����:100** �÷�:* �Ǿ����:100** �÷�:* �������:100** �÷�:*
								|   ��4�� �ھ����:100** �÷�:* �Ǿ����:100** �÷�:* �������:100** �÷�:*
								|   ��4�� �ھ����:100** �÷�:* �Ǿ����:100** �÷�:* �������:100** �÷�:*
								|   �밴���������...


			8�� ��ռ�¼

				8.1 ��ռ�¼����ʵ��

					��speechManager.h����ӱ����¼�ĳ�Ա���� void clearRecord();

						//��ռ�¼
						void clearRecord();

					��speechManager.cpp��ʵ�ֳ�Ա���� void clearRecord();

						void SpeechManager::clearRecord()
						{
							cout << "ȷ����գ�" << endl;
							cout << "1��ȷ��" << endl;
							cout << "2������" << endl;
							int select = 0;
							cin >> select;
							if (select == 1)
							{
								//��ģʽ ios::trunc �������ɾ���ļ������´���
								ofstream ofs("speech.csv", ios::trunc);
								ofs.close();
								//��ʼ������
								this->initSpeech();
								//����ѡ��
								this->createSpeaker();
								//��ȡ�����¼
								this->loadRecord();
								cout << "��ճɹ���" << endl;
							}
							system("pause");
							system("cls");
						}

				8.2 �������

					��main������֧ 3 ѡ���У�������ձ�����¼�Ľӿ�

						int main() {
							SpeechManager sm;

							for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
							{
							......
							}

							int choice = 0; //�����洢�û���ѡ��
							while (true)
							{
								sm.show_Menu();
								cout << "����������ѡ�� " << endl;
								cin >> choice; // �����û���ѡ��
								switch (choice)
								{
								case 1: //��ʼ����
									sm.startSpeech();
									break;
								case 2: //�鿴��¼
									sm.showRecord();
									break;
								case 3: //��ռ�¼
									sm.clearRecord();
									break;
								case 0: //�˳�ϵͳ
									break;
								default:
									system("cls"); //����
									break;
								}
							}
							system("pause");
							return 0;
						}

					���г��򣬲�����ռ�¼��

						|   **********************
						|   **** ��ӭ�μ��ݽ����� **
						|   **** 1.��ʼ�ݽ����� ****
						|   **** 2.�鿴�����¼ ****
						|   **** 3.��ձ�����¼ ****
						|   **** 0.�˳��������� ****
						|   **********************
						|
						|   ����������ѡ��
						|   3
						|   ȷ����գ�
						|   1 ȷ��
						|   2 ����
						|   1
						|   ��ճɹ���
						|   �밴���������...

					speech.csv�м�¼ҲΪ��


			���˱����������� ^_^
*/