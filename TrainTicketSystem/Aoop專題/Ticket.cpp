#include "stdafx.h"
#include<iostream>
#include"Ticket.h"
Ticket::Ticket()
{
	//ticket_flow_num++;
}
void Ticket::set_money(int mm)
{
	money = mm;
}
void Ticket::set_boarding(int bb)
{
	boarding = bb;
}
