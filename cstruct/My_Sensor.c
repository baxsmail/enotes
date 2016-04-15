#include "My_Sensor.h"
#include <stdlib.h>
#include <stdio.h>


My_FctnTable My_vmt = { 
    My_FctnInit, 
    My_Init, 
    My_Configure,
    My_PreProcessing,
    My_Collect, 
    My_Error 
};

My_Abstract_FctnTable My_abstract_vmt = {
    My_VTinit,
    My_init,
    My_reset,
    My_getType
};


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
    printf("My Pre\n");
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

void My_VTinit( MySensor* this)
{
    this->inherited.abstract.device_vt = &My_abstract_vmt;
}

int My_init( MySensor* this)
{
    printf("My Sensor Init\n");
    return 0;
}

int My_reset( MySensor* this)
{
    // virtual function
    return 0;
}

int My_getType(MySensor* this)
{
    return TYPE_SENSOR;
}


MySensor* New_My_Sensor( int num)
{
	MySensor *p = malloc(sizeof(MySensor));
    My_VTinit( p );
    My_FctnInit( p );
	p->inherited.test_num = num;
	return p;
}

