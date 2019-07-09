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
	int start_station_tmp;   //儲存顧客在介面中點選的起站
	int arrive_station_tmp;  //儲存顧客在介面中點選的終點站
	int tmp_year;			 //儲存顧客在介面中點選的 年
	int tmp_month;			 //儲存顧客在介面中點選的 月
	int tmp_day;			 //儲存顧客在介面中點選的 日
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