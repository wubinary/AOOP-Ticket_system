#pragma once
#include<iostream>
#include"Person.h"
#ifndef STAFF_H
#define STAFF_H
class Staff:public Person
{
public:
	Staff();
	void show_all_detail();
	void buy();
private:		
	int buy_method;
};
#endif




