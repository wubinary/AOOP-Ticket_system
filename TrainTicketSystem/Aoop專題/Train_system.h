#ifndef Train_system_H
#define Train_system_H
#include<iostream>
#include"Ticket.h"
#include <vector>
using namespace std;
class Train_system
{
public:
	Train_system();	
	vector <Ticket *> t;	
	int start_station_tmp;   //�x�s�U�Ȧb�������I�諸�_��
	int arrive_station_tmp;  //�x�s�U�Ȧb�������I�諸���I��
	int tmp_year;			 //�x�s�U�Ȧb�������I�諸 �~
	int tmp_month;			 //�x�s�U�Ȧb�������I�諸 ��
	int tmp_day;			 //�x�s�U�Ȧb�������I�諸 ��
	void User_interface();
	void new_ticket_memory();
private:
	Ticket *t_front;
	Ticket *t_tail;
	int train_type;
	int train_id;
	int seat;
	int max_station;
	char *stations[30];
	
};



#endif