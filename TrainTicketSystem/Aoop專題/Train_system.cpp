#include<iostream>
#include"stdafx.h"
#include"Train_system.h"

Train_system::Train_system()
{
}
void Train_system::new_ticket_memory()
{
	Ticket *tt = new Ticket;
	t.push_back(tt);
}
void Train_system::User_interface()
{

}
