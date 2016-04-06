#include "Sensor.h"
#include <stdlib.h>
#include <stdio.h>

Base_FctnTable E_vmt = { Base_FctnInit, Base_Init, Base_MyPrint };

void Base_FctnInit(Sensor *this)
{
	this->vmt = &E_vmt;
}

void Base_Init(Sensor *this )
{
	this->test_num = 10;
}

void Base_MyPrint(Sensor *this )
{
	printf("num = %d\n",this->test_num);
}


Sensor* New_Sensor( int num)
{
	Sensor *p = malloc(sizeof(Sensor));
	p->test_num = num;
	return p;
}

