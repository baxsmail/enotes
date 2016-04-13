#include "Base_Sensor.h"
#include "My_Sensor.h"

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
    t->abstract->device_vt->init(t);

    MySensor *p = New_My_Sensor( 1023 );
    My_FctnInit(p);
    p->inherited.vmt->Init(p);

    /*
    Sensor *new_p = (Sensor *) p;
    new_p->vmt->Init(new_p);
    new_p->vmt->MyPrint(new_p);
    */
    load_new_sensor( 1, 2, (BaseSensor *)t, 0 );
    handle_timeoutq_event();
    enum MyEnum vg ;
    vg = ROTK;
    printf("VG = %d\n",vg);
	return 0;
}
