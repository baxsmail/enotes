#include "Event.h"
#include <stdlib.h>
#include <stdio.h>

FctnTable E_vmt = { Event_init, E_update, E_print};

void Event_init(Event *this)
{
	this->vmt = &E_vmt;
}

void E_update( Event *this )
{
	this->test_num = 10;
}

void E_print( Event *this )
{
	printf("num = %d\n",this->test_num);
}


Event* Event_new( int num)
{
	Event *p = malloc(sizeof(Event));
	p->test_num = num;
	return p;
}

