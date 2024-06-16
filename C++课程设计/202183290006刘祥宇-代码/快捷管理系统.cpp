#include <fstream>
#include <string>
#include "manager.h"
#include <iostream>
#include <cstdio>
#include <iomanip>
#include "成绩.h"
using namespace std;

int numCollege;
int numGrade;
int numSystem;
manager::manager()
{
	OutputFile();
}

//输出文件
void manager::OutputFile() 
{
	Max = 0;
	//读取文件操作
	ifstream ifs;
	ifs.open("学生.txt",ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开错误" << endl;
	}
	//建立链表
	Q = new GRADE1;
	Q->next = NULL;
	first = new Node;
	first->next = NULL;
	Node* s=NULL;
	Node* r = first;
	GRADE1* O = Q;
	GRADE1* b=NULL;
	int flag = 1;                         //做判断标准，以便退出循环
	while (flag == 1)
	{	
		s = new Node;
		b = new GRADE1;
		r->next = s; r = s;
		O->next = b; O = b;
		if (ifs >> s->data.name >> s->data.sex >> s->data.s_number >> s->data.grade >> s->data.college >> s->data.system >> s->data.classs >> s->data.door >> s->data.home >> s->data.phone_number >> s->data1.wuli >> s->data1.english >> s->data1.c>>s->data1.sum)
		{
			b->data2.Grade = s->data.grade;
			b->data2.College = s->data.college;
			b->data2.System = s->data.system;
			b->data2.wuli1 = s->data1.wuli;
			b->data2.english1 = s->data1.english;
			b->data2.c1 = s->data1.c;
			s->data1.sum = s->data1.wuli + s->data1.english + s->data1.c;
			flag = 1;
			Max++;
		}
			else {
				r->next = NULL;
				O->next = NULL;
				flag = 0;
			}
	}
	//关闭文件
	ifs.close();
}

//输入文件
void manager::InputFile() {
	ofstream ofs;

	ofs.open("学生.txt", ios::out);

	Node* p;
		p= first->next;
	while (p->next!=NULL)
	{
		ofs<< p->data.name << " " << p->data.sex << " " << p->data.s_number << " " << p->data.grade << " "   << p->data.college << " " << p->data.system<< " " << p->data.classs<< " " << p->data.door << " " << p->data.home << " " << p->data.phone_number <<" " << p->data1.wuli << " " << p->data1.english << " " << p->data1.c <<" "<<p->data1.sum<< endl;
		p = p->next;
	}
	ofs.close();
}

void manager::inputStudent()
{
	int c;
	int flag = 0;
	int flagg =1;
	string num;
	while (flagg == 1) 
	{
		while (flag == 0) 
		{
			flag = 1;
			cout << "请输入学号" << endl;
			cin >> num;
			Node* s = first->next;
			while (s!=NULL)
			{
				if (num==s->data.s_number  ) {
					cout << "此用户已存在请重新输入" << endl;
					flag = 0;
					break;
				}
				s = s->next;
			}
		}
		Node* p;
		p = new Node;
		p->next = first->next;
		first->next = p;
		p->data.s_number = num;
		cout << "请输入要添加的学生姓名" << endl;
		cin >> p->data.name;
		cout << "请输入性别" << endl;
		cin >> p->data.sex;
		cout << "请输入年级" << endl;
		cin >> p->data.grade;
		cout << "请输入学院" << endl;
		cin >> p->data.college;
		cout << "请输入系" << endl;
		cin >> p->data.system;
		cout << "请输入班级" << endl;
		cin >> p->data.classs;
		cout << "请输入宿舍门牌号" << endl;
		cin >> p->data.door;
		cout << "请输入籍贯" << endl;
		cin >> p->data.home;
		cout << "请输入电话号码" << endl;
		cin >> p->data.phone_number;
		cout << "添加成功" << endl << endl;
		cout << "请选择接下来的操作：1.继续添加，2.退出" << endl;
		cin >> c;
		flagg = c;
		flag = 0;
		
	}
}

void manager::Delete()

{
	string num;
	int flagg = 1, flag = 0;
	Node* q;
	q = new Node;
	int a;
	while (flagg == 1) {
		while (flag == 0) {
			flag = 1;
			cout << "请输入要删除的学生学号" << endl;
			cin >> num;
			Node* p = first;
			GRADE1* s = Q;
			while (p->next != NULL) {
				if (p->next->data.s_number == num) {
					p->next = p->next->next;
					s->next = s->next->next;
					break;
				}
				p = p->next;
				s = s->next;
			}
			if (p->next == NULL) {
				cout << "未找到用户请重新输入" << endl;
				flag = 0;
			}
		}
			cout << "删除成功，请选择接下来的操作 1.继续删除 2.退出" << endl;
			cin >> flagg;
			flag = 0;
	}
}

void manager::Search()
{
	int flag = 0;
	string num;
	Node* p;
	while (flag == 0) {
		flag = 1;
		cout << "请输入学号" << endl;
		cin >> num;
		Node* s = first->next;
		while (s != NULL)
		{
			if (num == s->data.s_number) {
				p = s;
				cout << "已找到学生" << endl;
				cout << "姓名:" << p->data.name << "性别：" << p->data.sex << "学号：" << p->data.s_number << "年级：" << p->data.grade << "学院：" << p->data.college << "系：" << p->data.system << "班级：" << p->data.classs << "宿舍门牌号：" << p->data.door << "籍贯：" << p->data.home << "电话号码：" << p->data.phone_number << endl;
				break;
			}
			s = s->next;
		}
		if (s == NULL)
		{
			cout << "此人不存在，请重新输入" << endl;
			flag = 0;
		}
	}
}

void manager::Display()
{
	Node* p= first->next;
	while (p ->next!= NULL)//<< setw(10)
	{
		//cout << "姓名\t\t性别" << endl;
		cout << "姓名:" << p->data.name  << "\t\t性别:" << p->data.sex << setw(3) << "\t\t学号:" << p->data.s_number << setw(12) << "\t\t年级:" << p->data.grade << setw(3) << "\t\t学院:" << p->data.college <<endl;
		cout<< "系:" << p->data.system << setw(10) << "\t\t班级:" << p->data.classs<<setw(3) << "\t\t宿舍门牌号:" << p->data.door <<setw(5)<< "\t\t籍贯:" << p->data.home << "\t电话号码:" << p->data.phone_number << endl;
		cout << "物理:" << p->data1.wuli<<setw(14) << "\t\t英语:" <<p->data1.english<<setw(14)<< "\t\t面向对象程序设计成绩:" << p->data1.c <<setw(10)<<"\t\t总分:"<<p->data1.sum<< endl;
		p = p->next;
	}
	cout << endl;
}


void manager::revisee()
{
	string num;
	int a, c;
	string message;
	int flagg = 1;
	int flag = 0;
	while (flagg == 1) {
		while (flag == 0) {
			flag = 1;
			cout << "请输入要修改学生的学号" << endl;
			cin >> num;
			Node* p = first->next;
			while (p != NULL)
			{
				if (num == p->data.s_number) {
				cout << "请选择要修改的种类：1.姓名 2.性别 3.学号 4.年级 5.学院 6.系 7.班级 8.宿舍门牌号 9.籍贯 10.电话" << endl;	
				cin >> a;
				cout << "请输入要修改的信息" << endl;
				cin >> message;
			switch (a) {
				case 1:
					p->data.name = message;
					break;
				case 2:
					p->data.sex = message;
					break;
				case 3:
					p->data.s_number = message;
					break;
				case 4:
					p->data.grade = message;
					break;
				case 5:
					p->data.college = message;
					break;
				case 6:
					p->data.system = message;
					break;
				case 7:
					p->data.classs = message;
					break;
				case 8:
					p->data.door = message;
					break;
				case 9:
					p->data.home = message;
					break;
				case 10:
					p->data.phone_number = message;
					break;
				default:break;
				}
			break;
				}
				p = p->next;
			}
		}
		cout << "修改成功" << endl;
		cout << "请选择接下来的操作：1.继续修改 2.退出" << endl;
		cin >> c;
		flagg = c;
		flag = 0;
	}
}
void paixu(Node* L,int a);
void cjsort(Node* L, int a);
void SUM(Node* L);
void manager::sort()
{
	Node* p=first->next;
	int a,b;
	int flag = 1;
	while (flag ==1) {
		cout << "请选择要进行的排序:1.学号正序 2.学号逆序 3.成绩 4.总分" << endl;
		cin >> a;
		switch (a) {
		case 1:paixu(first, a);
			break;
		case 2:paixu(first, a);
			break;
		case 3:cout << "请输入要进行排序的科目:1.物理 2.英语 3.面向对象程序设计" << endl;
			cin >> b;
			cjsort(first, b);
			break;
		case 4:
			SUM(first);
			break;
		}
		Display();
		cout << "请选择接下来的操作:1.继续排序 2.退出" << endl;
		cin >> flag;
	}
}

void manager::entergrade()
{
	int c;
	int flag = 0;
	int flagg = 1;
	string num;
	while (flagg == 1) {
		while (flag == 0) {
			flag = 1;
			cout << "请输入学号" << endl;
			cin >> num;
			Node* p = first->next;
			GRADE1* q = Q->next;
			while (p != NULL)
			{
				if (num == p->data.s_number) {
					cout << "请输入大学物理成绩" << endl;
					cin >>q->data2.wuli1 ;
					 p->data1.wuli= q->data2.wuli1;
					cout << "请输入英语成绩" << endl;
					cin >> q->data2.english1;
						p->data1.english= q->data2.english1;
					cout << "请输入面向对象程序设计成绩" << endl;
					cin >> q->data2.c1;
						p->data1.c= q->data2.c1;
					cout << "添加成功" << endl;
					p->data1.sum = p->data1.wuli + p->data1.english + p->data1.c;break;
				}
					p= p->next;
					q = q->next;
				}
			Node* s=p;
			if (s == NULL) {
				flag = 0;
				cout << "此人不存在请重新输入" << endl;
			}
		}
		cout << "请选择接下来的操作：1.继续添加，2.退出" << endl;
			cin >> c;
			flagg = c;
			flag = 0;
	}
}


void manager::number()
{
	int flagg=1;
	string message;
	while (flagg == 1) 
	{
		int WG=0, EG=0, CG=0;
		Node* p = first->next,*s;
		int a;
		s = new Node;
		GRADE1* q = Q->next;
		cout << "请输入要查看的项目：1.年级人数 2.学院人数 3.系人数" << endl;
		cin >> a;
		cout << "输入查看的具体目标" << endl;
		cin >> message;
		switch(a) {
		case 1:
			numGrade = 0;
			while (p!= NULL) {
				if (message== p->data.grade)
			{
				numGrade++;
				if(p->data1.wuli<60)
				WG++;
				if (p->data1.english < 60)
					EG++;
				if (p->data1.c < 60)
					CG++;
			}
				p = p->next;
		}
		cout <<"总人数:" << numGrade << "物理挂科人数:" << WG << "英语挂科人数:" << EG << "面向对象程序设计挂科人数" << CG << endl;
			  break;
		case 2:
			numCollege = 0;
			while (p != NULL) {
				if  (message == p->data.college)
				{
					numCollege++;
					if (p->data1.wuli < 60)
						WG++;
					if (p->data1.english < 60)
						EG++;
					if (p->data1.c < 60)
						CG++;
				}
				p = p->next;
			}
		cout << "总人数:" << numCollege <<"物理挂科人数:"<< WG <<"英语挂科人数:" << EG <<"面向对象程序设计挂科人数"<< CG << endl;
			break;
		case 3:
			numSystem = 0;
			while (p != NULL) {
				if (message == p->data.system)
				{
					numSystem++;
					if (p->data1.wuli < 60)
						WG++;
					if (p->data1.english < 60)
						EG++;
					if (p->data1.c < 60)
						CG++;
				}
				p= p->next;
			}
			cout << "总人数:" << numSystem << "物理挂科人数:" << WG << "英语挂科人数:" << EG << "面向对象程序设计挂科人数" << CG << endl;
			break;
		}
		cout << endl;
		cout <<"请输入加下来的操作:1.继续查看 2.退出" << endl;
		cin >> flagg;
		
	}
}
void CJSORT(Node* L,int m,int n);
void paixu(Node *L,int a)
{
	string temp;
	Node* p = L->next;
	if (a == 1) {
	while (p->next != NULL)
		{
			Node* s = p->next;
			while (s->next != NULL) {
				if (s->data.s_number < p->data.s_number)
				{
					temp = p->data.s_number;
					p->data.s_number = s->data.s_number;
					s->data.s_number = temp;
				}
				s = s->next;
			}
			p = p->next;
		}
	}
	else if (a == 2) {
		while (p->next != NULL)
		{
			Node* s = p->next;
			while (s->next != NULL) {
				if (s->data.s_number > p->data.s_number)
				{
					temp = p->data.s_number;
					p->data.s_number = s->data.s_number;
					s->data.s_number = temp;
				}
				s = s->next;
			}
			p = p->next;
		}
	}
}

void cjsort(Node* L, int a)
{
	int i = 0;
	int m;
	Node* p = L->next;
	Node* s=L;
	cout << "请选择要进行的排序: 1.顺序 2.逆序" << endl;
	cin >> m;
	if (a == 1)
		CJSORT(s, m, 1);
	else if (a == 2)
		CJSORT(s, m, 2);
	else if (a == 3)
		CJSORT(s, m, 3);
}

void CJSORT(Node* L, int m, int n)
{
	Node* p = L->next;
	int temp;
	//正序
	if (m == 1) {
		if (n == 1) {
			while (p->next != NULL) {
				Node* s = p->next;
				while (s->next != NULL) {
					if (p->data1.wuli > s->data1.wuli)
					{
						temp = p->data1.wuli;
						p->data1.wuli = s->data1.wuli;
						s->data1.wuli = temp;
					}
					s = s->next;
				}
				p = p->next;
			}
		}
		else if (n == 2)
		{
			while (p->next != NULL) {
				Node* s = p->next;
				while (s->next != NULL) {
					if (p->data1.english > s->data1.english)
					{
						temp = p->data1.english;
						p->data1.english = s->data1.english;
						s->data1.english = temp;
					}
					s = s->next;
				}
				p = p->next;
			}
		}
		else if (n == 3)
		{
			while (p->next != NULL) {
				Node* s = p->next;
				while (s->next != NULL) {
					if (p->data1.c > s->data1.c)
					{
						temp = p->data1.c;
						p->data1.c = s->data1.c;
						s->data1.c = temp;
					}
					s = s->next;
				}
				p = p->next;
			}
		}
	}
	//逆序
	if (m == 2) {
		if (n == 1) {
			while (p->next != NULL) {
				Node* s = p->next;
				while (s->next != NULL) {
					if (p->data1.wuli < s->data1.wuli)
					{
						temp = p->data1.wuli;
						p->data1.wuli = s->data1.wuli;
						s->data1.wuli = temp;
					}
					s = s->next;
				}
				p = p->next;
			}
		}
		else if (n == 2)
		{
			while (p->next != NULL) {
				Node* s = p->next;
				while (s->next != NULL) {
					if (p->data1.english < s->data1.english)
					{
						temp = p->data1.english;
						p->data1.english = s->data1.english;
						s->data1.english = temp;
					}
					s = s->next;
				}
				p = p->next;
			}
		}
		else if (n == 3)
		{
			while (p->next != NULL) {
				Node* s = p->next;
				while (s->next != NULL) {
					if (p->data1.c < s->data1.c)
					{
						temp = p->data1.c;
						p->data1.c = s->data1.c;
						s->data1.c = temp;
					}
					s = s->next;
				}
				p = p->next;
			}
		}
	}
}
void SUM(Node* L)
{
	int temp;
	int a;
	cout << "请选择要进行的顺序:1.顺序 2.逆序" << endl;
	cin >> a;
	Node* p = L->next;
	while (p->next != NULL) {
		Node* s = p->next;
		while (s->next != NULL)
		{
			if (a == 1) {
				if (p->data1.sum > s->data1.sum) {
					temp = p->data1.sum;
					p->data1.sum = s->data1.sum;
					s->data1.sum = temp;
				}
			}
			else if (a == 2) {
				if (p->data1.sum < s->data1.sum) {
					temp = p->data1.sum;
					p->data1.sum = s->data1.sum;
					s->data1.sum = temp;
				}
			}
			s = s->next;
		}
		p = p->next;
	}
}



