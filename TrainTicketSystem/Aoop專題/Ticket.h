#pragma once
#include<iostream>
#ifndef TICKET_H
#define TICKET_H																
class Ticket
{
public:
	static int ticket_flow_num;
	Ticket *ticket_next;
	Ticket *ticket_pre;
	Ticket();
	void set_money(int mm);
	void set_boarding(int bb);
private:
	int money;
	int boarding;
	int get_off;
};
#endif