#include <iostream>
#include <cstdio>
#include <malloc.h>
#include<fstream>
#include <stdlib.h>
#include<string>
#include "manager.h" 
#include "�ɼ�.h"

using namespace std;

void print();

int main()
{
	int a;
	int flag = 1;
	manager stu;
	//stu.Display();
	//cout << endl << endl;
	while (flag==1) {
		flag = 1;
		cout << endl;
		print();
		cout << "������ѡ��"<<endl;
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1:
			stu.inputStudent();
			stu.InputFile();
			break;
		case 2:
			stu.Delete();
			stu.InputFile();
			break;
		case 3:
			stu.revisee();
			stu.InputFile();
			break;
		case 4:
			stu.Search();
			break;
		case 5:
			stu.Display();
			break;
		case 6:
			stu.sort();
			stu.InputFile();
			stu.Display();
			break;
		case 7:
			stu.InputFile();
			break;
		case 8:
			stu.entergrade();
			stu.InputFile();
			break;
		case 9:
			stu.number();
			break;
		case 0:flag = 0;
			break;
		default:break;
		}
	}
	system("pause");
	return 0;
}

void print()
{
	cout << "-------------------------------------------------------------" << endl;
	cout << "---------------------------���˵�----------------------------" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "-------------------����1.����ѧ����Ϣ����--------------------" << endl;
	cout << "-------------------����2.ɾ��ѧ����Ϣ����--------------------" << endl;
	cout << "--------------------����3.�޸�ѧ������-----------------------" << endl;
	cout << "--------------------����4.��ѯѧ������-----------------------" << endl;
	cout << "--------------------����5.���ѧ������---------------------" << endl;
	cout << "--------------------����6.ѧ��������-----------------------" << endl;
	cout << "-------------------����7.���뵽�ļ��С���--------------------" << endl;
	cout << "------------------����8.���/�޸�ѧ���ɼ�����----------------" << endl;
	cout << "-------------------����9.�鿴ѧ����������--------------------" << endl;
	cout << "----------------------����0.�˳�����-------------------------" << endl;

}