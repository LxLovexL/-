#pragma once
#include<iostream>
#include<string>
#include "manager.h"

using namespace std;
#include <vector>
struct xinxi {
	
	string College;
	string Grade;
	string System;
	int english1;
	int wuli1;
	int c1;
};

class GRADE1
{
public:
	GRADE1* next;
	xinxi data2;
};
class chengji{	
public:
friend class manager;
	GRADE1* Q;
};
