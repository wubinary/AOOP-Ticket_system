#pragma once
#include<iostream>
#include"Ticket.h"
#include"time.h"
class Season_ticket:public Ticket 
{
public:
	Season_ticket();
	/*time get_start_time(){}
	time get_arrive_times(){}
	time set_start_time(){}
	time set_arrive_times(){}*/
private:
	int *stations_to_stop;
	//time start_time;
	//time *arrive_times;
};