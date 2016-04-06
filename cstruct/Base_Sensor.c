#include "Base_Sensor.h"
#include <stdlib.h>
#include <stdio.h>

Base_FctnTable Base_vmt = { Base_FctnInit, Base_Init, Base_Configure, Base_PreProcessing, Base_Collect, Base_Error };

void Base_FctnInit(BaseSensor *this)
{
	this->vmt = &Base_vmt;
}

void Base_Init(BaseSensor *this )
{
	this->test_num = 10;
}

void Base_Configure(BaseSensor *this )
{
	// virtual function
}

void Base_PreProcessing(BaseSensor *this )
{
	// virtual function
}

void Base_Collect(BaseSensor *this )
{
	// virtual function
}

void Base_Error(BaseSensor *this )
{
	// virtual function
}

BaseSensor* New_Base_Sensor( int num)
{
	BaseSensor *p = malloc(sizeof(BaseSensor));
	p->test_num = num;
	return p;
}

