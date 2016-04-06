#include "My_Sensor.h"
#include <stdlib.h>
#include <stdio.h>

My_FctnTable My_vmt = { My_FctnInit, My_Init, My_Configure, My_PreProcessing, My_Collect, My_Error };

void My_FctnInit(MySensor *this)
{
	this->inherited.vmt = &My_vmt;
}

void My_Init(MySensor *this )
{
	this->inherited.test_num = 10;
}

void My_Configure(MySensor *this )
{
	// virtual function
}

void My_PreProcessing(MySensor *this )
{
	// virtual function
}

void My_Collect(MySensor *this )
{
	// virtual function
}

void My_Error(MySensor *this )
{
	// virtual function
}

MySensor* New_My_Sensor( int num)
{
	MySensor *p = malloc(sizeof(MySensor));
	p->inherited.test_num = num;
	return p;
}

