#pragma once
#include<iostream>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class employee
{
public:
	employee();
private:
	char name[50];
	int position;
	int salary;
	int old;
};
#endif