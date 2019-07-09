#pragma once
#include<iostream>
#ifndef PERSON_H
#define PERSON_H
class Person
{
public:
	Person();
	void set_work();
private:
	int *works;
	int *on_works;
	int *off_work;
};
#endif