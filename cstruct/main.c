#include "Event.h"

int main()
{
	Event *t = Event_new( 1425 );
	Event_init(t);
	t->vmt->MyPrint(t);
	t->vmt->Update(t);
	t->vmt->MyPrint(t);
	return 0;
}
