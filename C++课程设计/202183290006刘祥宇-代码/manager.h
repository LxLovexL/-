#pragma once
#include<iostream>
#include<string>
#include "�ɼ�.h"
using namespace std;
#include <vector>


struct student {
	string name;
	string sex;
	string s_number;
	string grade;
	string college;
	string system;
	string classs;
	string door;
	string home;
	string phone_number;
};


struct GRADE {
	int english;
	int wuli;
	int c;
	int sum;
};

class Node {
public:
	student data;
	Node* next;
	GRADE data1;
};

class manager {
public:
	friend class chengji;
	friend class  GRADE1;
	manager();
	//����ļ�
	void OutputFile();
	//�����ļ�
	void InputFile();
	//luru
	void inputStudent();
	void Delete();
	void Search();
	void Display();
	void revisee();
	void sort();
	void entergrade();
	void number();
	//	~manager();
private:
	Node* first;
	int Max;
	GRADE1* Q;
}; 

