#include "Sensor.h"
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

	Sensor *t = New_Sensor( 1425 );
	Base_FctnInit(t);

    MySensor *p = New_MySensor( 1023 );
    My_FctnInit(p);
    p->inherited.vmt->Init(p);

    /*
    Sensor *new_p = (Sensor *) p;
    new_p->vmt->Init(new_p);
    new_p->vmt->MyPrint(new_p);
    */
    printf("load begin\n");
    load_new_sensor( 1, 1, (Sensor *)p, 0 );
    printf("load ready\n");
    handle_timeoutq_event();
    enum MyEnum vg ;
    vg = ROTK;
    printf("VG = %d\n",vg);
	return 0;
}
