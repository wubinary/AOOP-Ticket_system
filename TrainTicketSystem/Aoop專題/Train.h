#pragma once
#include<iostream>
#include"Train_simulation.h"
class Train:public Train_simulation
{
public:
	Train();
	void set_station();
private:
	int *stations;
	int station_num;

};