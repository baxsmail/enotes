#include "Sensor.h"
#include "My_Sensor.h"

int main()
{
	Sensor *t = New_Sensor( 1425 );
	Base_FctnInit(t);
	t->vmt->MyPrint(t);
	t->vmt->Init(t);
	t->vmt->MyPrint(t);

    MySensor *p = New_MySensor( 1023 );
    My_FctnInit(p);
    p->inherited.vmt->MyPrint(p);
    //p->inherited.vmt->Init(p);
    p->inherited.vmt->MyPrint(p);

    Sensor *new_p = (Sensor *) p;
    new_p->vmt->Init(new_p);
    new_p->vmt->MyPrint(new_p);
	return 0;
}
