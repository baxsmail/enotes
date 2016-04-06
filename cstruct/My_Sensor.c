#include "Sensor.h"
#include "My_Sensor.h"
#include <stdlib.h>
#include <stdio.h>

Base_FctnTable My_vmt = { Base_FctnInit, Base_Init, Base_Configure, Base_PreProcessing, Base_Collect, Base_Error };

void My_FctnInit( MySensor *this)
{
    this->inherited.vmt = & My_vmt;
}

void My_Init(MySensor *this )
{
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

MySensor* New_MySensor( int num)
{
	Sensor *p = malloc(sizeof(MySensor));
	p->test_num = num;
	return p;
}

