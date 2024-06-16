#include <fstream>
#include <string>
#include "manager.h"
#include <iostream>
#include <cstdio>
#include <iomanip>
#include "�ɼ�.h"
using namespace std;

int numCollege;
int numGrade;
int numSystem;
manager::manager()
{
	OutputFile();
}

//����ļ�
void manager::OutputFile() 
{
	Max = 0;
	//��ȡ�ļ�����
	ifstream ifs;
	ifs.open("ѧ��.txt",ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ��򿪴���" << endl;
	}
	//��������
	Q = new GRADE1;
	Q->next = NULL;
	first = new Node;
	first->next = NULL;
	Node* s=NULL;
	Node* r = first;
	GRADE1* O = Q;
	GRADE1* b=NULL;
	int flag = 1;                         //���жϱ�׼���Ա��˳�ѭ��
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
	//�ر��ļ�
	ifs.close();
}

//�����ļ�
void manager::InputFile() {
	ofstream ofs;

	ofs.open("ѧ��.txt", ios::out);

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
			cout << "������ѧ��" << endl;
			cin >> num;
			Node* s = first->next;
			while (s!=NULL)
			{
				if (num==s->data.s_number  ) {
					cout << "���û��Ѵ�������������" << endl;
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
		cout << "������Ҫ��ӵ�ѧ������" << endl;
		cin >> p->data.name;
		cout << "�������Ա�" << endl;
		cin >> p->data.sex;
		cout << "�������꼶" << endl;
		cin >> p->data.grade;
		cout << "������ѧԺ" << endl;
		cin >> p->data.college;
		cout << "������ϵ" << endl;
		cin >> p->data.system;
		cout << "������༶" << endl;
		cin >> p->data.classs;
		cout << "�������������ƺ�" << endl;
		cin >> p->data.door;
		cout << "�����뼮��" << endl;
		cin >> p->data.home;
		cout << "������绰����" << endl;
		cin >> p->data.phone_number;
		cout << "��ӳɹ�" << endl << endl;
		cout << "��ѡ��������Ĳ�����1.������ӣ�2.�˳�" << endl;
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
			cout << "������Ҫɾ����ѧ��ѧ��" << endl;
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
				cout << "δ�ҵ��û�����������" << endl;
				flag = 0;
			}
		}
			cout << "ɾ���ɹ�����ѡ��������Ĳ��� 1.����ɾ�� 2.�˳�" << endl;
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
		cout << "������ѧ��" << endl;
		cin >> num;
		Node* s = first->next;
		while (s != NULL)
		{
			if (num == s->data.s_number) {
				p = s;
				cout << "���ҵ�ѧ��" << endl;
				cout << "����:" << p->data.name << "�Ա�" << p->data.sex << "ѧ�ţ�" << p->data.s_number << "�꼶��" << p->data.grade << "ѧԺ��" << p->data.college << "ϵ��" << p->data.system << "�༶��" << p->data.classs << "�������ƺţ�" << p->data.door << "���᣺" << p->data.home << "�绰���룺" << p->data.phone_number << endl;
				break;
			}
			s = s->next;
		}
		if (s == NULL)
		{
			cout << "���˲����ڣ�����������" << endl;
			flag = 0;
		}
	}
}

void manager::Display()
{
	Node* p= first->next;
	while (p ->next!= NULL)//<< setw(10)
	{
		//cout << "����\t\t�Ա�" << endl;
		cout << "����:" << p->data.name  << "\t\t�Ա�:" << p->data.sex << setw(3) << "\t\tѧ��:" << p->data.s_number << setw(12) << "\t\t�꼶:" << p->data.grade << setw(3) << "\t\tѧԺ:" << p->data.college <<endl;
		cout<< "ϵ:" << p->data.system << setw(10) << "\t\t�༶:" << p->data.classs<<setw(3) << "\t\t�������ƺ�:" << p->data.door <<setw(5)<< "\t\t����:" << p->data.home << "\t�绰����:" << p->data.phone_number << endl;
		cout << "����:" << p->data1.wuli<<setw(14) << "\t\tӢ��:" <<p->data1.english<<setw(14)<< "\t\t������������Ƴɼ�:" << p->data1.c <<setw(10)<<"\t\t�ܷ�:"<<p->data1.sum<< endl;
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
			cout << "������Ҫ�޸�ѧ����ѧ��" << endl;
			cin >> num;
			Node* p = first->next;
			while (p != NULL)
			{
				if (num == p->data.s_number) {
				cout << "��ѡ��Ҫ�޸ĵ����ࣺ1.���� 2.�Ա� 3.ѧ�� 4.�꼶 5.ѧԺ 6.ϵ 7.�༶ 8.�������ƺ� 9.���� 10.�绰" << endl;	
				cin >> a;
				cout << "������Ҫ�޸ĵ���Ϣ" << endl;
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
		cout << "�޸ĳɹ�" << endl;
		cout << "��ѡ��������Ĳ�����1.�����޸� 2.�˳�" << endl;
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
		cout << "��ѡ��Ҫ���е�����:1.ѧ������ 2.ѧ������ 3.�ɼ� 4.�ܷ�" << endl;
		cin >> a;
		switch (a) {
		case 1:paixu(first, a);
			break;
		case 2:paixu(first, a);
			break;
		case 3:cout << "������Ҫ��������Ŀ�Ŀ:1.���� 2.Ӣ�� 3.�������������" << endl;
			cin >> b;
			cjsort(first, b);
			break;
		case 4:
			SUM(first);
			break;
		}
		Display();
		cout << "��ѡ��������Ĳ���:1.�������� 2.�˳�" << endl;
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
			cout << "������ѧ��" << endl;
			cin >> num;
			Node* p = first->next;
			GRADE1* q = Q->next;
			while (p != NULL)
			{
				if (num == p->data.s_number) {
					cout << "�������ѧ����ɼ�" << endl;
					cin >>q->data2.wuli1 ;
					 p->data1.wuli= q->data2.wuli1;
					cout << "������Ӣ��ɼ�" << endl;
					cin >> q->data2.english1;
						p->data1.english= q->data2.english1;
					cout << "������������������Ƴɼ�" << endl;
					cin >> q->data2.c1;
						p->data1.c= q->data2.c1;
					cout << "��ӳɹ�" << endl;
					p->data1.sum = p->data1.wuli + p->data1.english + p->data1.c;break;
				}
					p= p->next;
					q = q->next;
				}
			Node* s=p;
			if (s == NULL) {
				flag = 0;
				cout << "���˲���������������" << endl;
			}
		}
		cout << "��ѡ��������Ĳ�����1.������ӣ�2.�˳�" << endl;
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
		cout << "������Ҫ�鿴����Ŀ��1.�꼶���� 2.ѧԺ���� 3.ϵ����" << endl;
		cin >> a;
		cout << "����鿴�ľ���Ŀ��" << endl;
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
		cout <<"������:" << numGrade << "����ҿ�����:" << WG << "Ӣ��ҿ�����:" << EG << "������������ƹҿ�����" << CG << endl;
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
		cout << "������:" << numCollege <<"����ҿ�����:"<< WG <<"Ӣ��ҿ�����:" << EG <<"������������ƹҿ�����"<< CG << endl;
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
			cout << "������:" << numSystem << "����ҿ�����:" << WG << "Ӣ��ҿ�����:" << EG << "������������ƹҿ�����" << CG << endl;
			break;
		}
		cout << endl;
		cout <<"������������Ĳ���:1.�����鿴 2.�˳�" << endl;
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
	cout << "��ѡ��Ҫ���е�����: 1.˳�� 2.����" << endl;
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
	//����
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
	//����
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
	cout << "��ѡ��Ҫ���е�˳��:1.˳�� 2.����" << endl;
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



