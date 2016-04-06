#include "Sensor.h"
#include <stdlib.h>
#include <stdio.h>

Base_FctnTable E_vmt = { Base_FctnInit, Base_Init, Base_Configure, Base_PreProcessing, Base_Collect, Base_Error };

void Base_FctnInit(Sensor *this)
{
	this->vmt = &E_vmt;
}

void Base_Init(Sensor *this )
{
	this->test_num = 10;
}

void Base_Configure(Sensor *this )
{
	// virtual function
}

void Base_PreProcessing(Sensor *this )
{
	// virtual function
}

void Base_Collect(Sensor *this )
{
	// virtual function
}

void Base_Error(Sensor *this )
{
	// virtual function
}

Sensor* New_Sensor( int num)
{
	Sensor *p = malloc(sizeof(Sensor));
	p->test_num = num;
	return p;
}

