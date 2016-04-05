#ifndef _EVENT_H_
#define _EVENT_H_

struct _Event;
typedef struct _Event Event;
typedef struct _vmt
{
	void (*FctnInit)(Event*);
	void (*Init)(Event*);
	void (*MyPrint)(Event*);
} FctnTable;

struct _Event
{
	int test_num;
	FctnTable *vmt;
};


void Event_init(Event *this);
void E_update( Event *this);
void E_print( Event *this );
Event* Event_new( int num);

/* functions
 * Init : Sensor Init
 *
 */




#endif
