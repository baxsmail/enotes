#include "Base_Sensor.h"
#include "My_Sensor.h"
#include "Event.h"
#include <stdio.h>
#include "my_time.h"

enum MyEnum 
{
    CTY,
    Burning,
    ROTK
};

int main()
{
    init_timeoutq();

	BaseSensor *t = New_Base_Sensor( 1425 );

    MySensor *p = New_My_Sensor( 1023 );
    My_FctnInit(p);

    /*
    Sensor *new_p = (Sensor *) p;
    new_p->vmt->Init(new_p);
    new_p->vmt->MyPrint(new_p);
    */
    load_new_sensor( 1, 2, (BaseDevice *)p, 0 );
    handle_timeoutq_event();
    enum MyEnum vg ;
    vg = ROTK;
    printf("VG = %d\n",vg);

    tm my_tm;
    my_tm.unix_time =1462943387 ;
    calcDate( &my_tm );
	return 0;
}
