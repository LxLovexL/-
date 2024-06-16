#include <iostream>
#include <cstdio>
#include <malloc.h>
#include<fstream>
#include <stdlib.h>
#include<string>

using namespace std; 

typedef struct LNode
{
	string name;
	string street;
	string city;
	string eip;
	string state;
	string num;
	struct LNode *next;
	struct LNode *prior;
}LNode,DoubleList;
DoubleList p0={"0","0","0","0","0","0",NULL,NULL};
DoubleList pn={"0","0","0","0","0","0",NULL,NULL};
//DoubleList *L=&p0;

void input_listfiile()
{
	ifstream ifs;
	ifs.open("address_book.txt",ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ��򿪴���" << endl;
	}
	DoubleList *p,*s;
	p=&p0;
	int flag = 1;                         
	while (flag == 1)
	{	
		s = new LNode;
		p->next = s; p = s;
		if (ifs >> s->name >> s->street >> s->city >> s->eip >> s->state>>s->num)
		{
			flag = 1;
		}
			else {
				p->next = NULL;
				flag = 0;
			}
	}
	ifs.close();
}

void display_listfiile()
{
    DoubleList *p;  
	p=&p0;                                                                    
    int i = 1;                                      
    ofstream fout("address_book.txt");                   
	p = p->next; 
    while(p->next != NULL)                          
    {
        fout << p->name <<endl;          
        fout << p->street <<endl;
        fout  << p->city <<endl;
        fout << p->eip <<endl;
        fout << p->state <<endl;
        fout  <<p->num<<endl;
        fout <<endl;
        p = p->next;                                
        i++;
    }
    fout.close();                                   
}

void ADD_ONE(DoubleList *p)
{	
	string name;
	string street;
	string city;
	string eip;
	string state;
	string num;
	cout<<"����������";
	cin>>name; 
	cout<<"����ֵ���";
	cin>>street;
	cout<<"������У�";
	cin>>city;
	cout<<"�����ʱࣺ";
	cin>>eip;
	cout<<"������ң�";
	cin>>state;
	cout<<"������绰���룺";
	cin>>num;
	p->name=name;
	p->street=street;
	p->city=city;
	p->eip=eip;
	p->state=state;
	p->num=num;
}

DoubleList* ADD()
{
	DoubleList *p=new LNode,*L;
	L=&p0;
	ADD_ONE(p);
			p->next=L->next;
			L->next->prior=p;
			L->next=p;
			p->prior=L;	
	return p;
}

void Delete()
{
	string name; 
	string street;
	string city;
	string eip;
	string state;
	string num;
	int flag=0;
	DoubleList *p,*L;
	p=&p0;
		cout<<"������Ҫɾ���Ķ�������,�绰����"<<endl;
		cin>>name>>num;
		for(p;p->next!=NULL;p=p->next)
	{
		if(p->next->name==name&&p->next->num==num)
		{
			L=p->next;
			L->next->prior=p;
			p->next=L->next;	
		flag=1;
		break;
		}
		
	}
	if(flag==0) cout<<"no find"<<endl;
	else if(flag==1) cout<<"ɾ���ɹ�"<<endl;
}
void display(DoubleList *p);
void search(string name)
{
	string street;
	string city;
	string eip;
	string state;
	string num;
	int count=0;
	DoubleList *p;
	p=&p0;
	p=p->next;
	for(p;p->next!=NULL;p=p->next)
	{
		if(p->name==name)
		{
			count++;
			display(p);
			//cout<<"������"<<p->name<<" "<<"�ֵ���"<<p->street<<" "<<"���У�"<<p->city<<" "<<"�ʱࣺ"<<p->eip<<" "<<"���ң�"<<p->state<<" "<<"�绰���룺"<<p->num<<endl;
		}
	}
	if(count==0)
	cout<<"no find"<<endl;
 } 
 
void display(DoubleList *p)
{
	if(p==NULL)
	cout<<"no find"<<endl;
//	cout<<"������"<<p->name<<" "<<"�ֵ���"<<p->street<<" "<<"���У�"<<p->city<<" "<<"�ʱࣺ"<<p->eip<<" "<<"���ң�"<<p->state<<"�绰���룺"<<p->num<<endl;
cout<<"������"<<p->name<<"\t"<<"�ֵ���"<<p->street<<"\t"<<"���У�"<<p->city<<"\t"<<"�ʱࣺ"<<p->eip<<"\t"<<"���ң�"<<p->state<<"\t"<<"�绰���룺"<<p->num<<endl;
	//cout<<p->name<<","<<p->street<<"," <<p->city <<","<<p->eip<<"," <<p->state<<endl;
}

void display_list()
{
	DoubleList *p;
	p=&p0;
	p=p->next;
	int i=1;
	if(p==NULL)
	cout<<"��û��ͨѶ¼����������Ϣ"<<endl; 
	cout<<"ĿǰͨѶ¼Ϊ"<<endl; 
	while(p->next!=NULL)
	{
		
		cout<<i<<":"<<"������"<<p->name<<"\t"<<"�ֵ���"<<p->street<<"\t"<<"���У�"<<p->city<<"\t"<<"�ʱࣺ"<<p->eip<<"\t"<<"���ң�"<<p->state<<"\t"<<"�绰���룺"<<p->num<<endl;
		p=p->next;
		i++;
	}
	cout<<endl;
}

int main()
{
	int a=0;
	int flag=0;
	string message;
//	DoubleList *L;
	 p0.next=&pn;
	 pn.prior=&p0;
	 input_listfiile();
	while(1)
	{	
	flag=0;
		while(flag==0){
			flag=1;
		cout<<"����Ҫ���еĲ���"<<endl;
	cout << "***************************" << endl;
	cout << "*****	1.�����ϵ��  *****" << endl;
	cout << "*****	2.ɾ����ϵ��  *****" << endl;
	cout << "*****	3.������ϵ��  *****" << endl;
	cout << "*****	4.�����ϵ��  *****" << endl;
	cout << "*****	5.���뵽�ļ�  *****" << endl;
	cout << "*****	6.�˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
		cin>>a;
		if (a<1||a>6) {
				cout << "���������������������"<<endl;
				flag=0;
			} 
	}
		cout<<endl;
		switch(a)
		{
			case 1:ADD();
			cout<<"��ӳɹ�"<<endl;
			cout<<endl;
			
			break;
			case 2:
			Delete();
			cout<<endl;
			break;
			case 3:
			cout<<"����Ҫ���ҵ�����"<<endl;
			cin>>message;
			//display(search(message));
			search(message);
			cout<<endl;
			break;
			case 4:
			display_list();
			break;
			case 5:
			display_listfiile();
			cout<<"�������"<<endl;
			cout<<endl; 
			break;
			case 6:
			break; 
			default:
			break;
		}
		if(a==6)
		break;
	}
	return 0;
}
