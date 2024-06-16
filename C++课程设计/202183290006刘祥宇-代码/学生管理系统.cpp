#include <iostream>
#include <cstdio>
#include <malloc.h>
#include<fstream>
#include <stdlib.h>
#include<string>
#include "manager.h" 
#include "成绩.h"

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
		cout << "请输入选择"<<endl;
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
	cout << "---------------------------主菜单----------------------------" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "-------------------》》1.输入学生信息《《--------------------" << endl;
	cout << "-------------------》》2.删除学生信息《《--------------------" << endl;
	cout << "--------------------》》3.修改学生《《-----------------------" << endl;
	cout << "--------------------》》4.查询学生《《-----------------------" << endl;
	cout << "--------------------》》5.输出学生表《《---------------------" << endl;
	cout << "--------------------》》6.学生表排序《-----------------------" << endl;
	cout << "-------------------》》7.输入到文件中《《--------------------" << endl;
	cout << "------------------》》8.添加/修改学生成绩《《----------------" << endl;
	cout << "-------------------》》9.查看学生人数《《--------------------" << endl;
	cout << "----------------------》》0.退出《《-------------------------" << endl;

}