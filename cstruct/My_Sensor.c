#include "Sensor.h"
#include "My_Sensor.h"
#include <stdlib.h>
#include <stdio.h>

My_FctnTable My_vmt = { My_FctnInit, My_Init, My_MyPrint };

void My_FctnInit( MySensor *this)
{
    this->inherited.vmt = & My_vmt;
}
void My_Init( MySensor *this)
{
    this->inherited.test_num = 7;
}
void My_MyPrint( MySensor *this )
{
	printf("My num = %d\n",this->inherited.test_num);
}
MySensor* New_MySensor( int num )
{
    MySensor *p = malloc( sizeof(MySensor) );
    p->inherited.test_num = num;
    return p;
}
