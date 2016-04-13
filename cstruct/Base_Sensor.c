#include "Base_Sensor.h"
#include "common.h"
#include <stdlib.h>
#include <stdio.h>

Base_FctnTable Base_vmt = { Base_FctnInit, Base_Init, Base_Configure, Base_PreProcessing, Base_Collect, Base_Error };

Abstract_FctnTable Abstract_vmt = {
    Base_VTinit,
    Base_init,
    Base_reset,
    Base_getType
};

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
    printf("Base Pre\n");
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
    p->abstract = New_Base_Device();
	p->test_num = num;
    Base_FctnInit(p);
    Base_VTinit(p);
	return p;
}

void Base_VTinit( BaseSensor* this)
{
    this->abstract->device_vt = &Abstract_vmt;
}

int Base_init( BaseSensor* this)
{
    printf("Base Sensor Init\n");
    return 0;
}

int Base_reset( BaseSensor* this)
{
    // virtual function
    return 0;
}

int Base_getType( BaseSensor* this)
{
    return TYPE_BASE_SENSOR;
}


