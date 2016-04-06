#ifndef _SENSOR_H_
#define _SENSOR_H_

struct _Sensor;
typedef struct _Sensor Sensor;
typedef struct _vmt
{
	void (*FctnInit)(Sensor*);
	void (*Init)(Sensor*);
	void (*MyPrint)(Sensor*);
} Base_FctnTable;

struct _Sensor
{
	int test_num;
	Base_FctnTable *vmt;
};


void Base_FctnInit(Sensor *this);
void Base_Init( Sensor *this);
void Base_MyPrint( Sensor *this );
Sensor* New_Sensor( int num );

/* functions
 * Init : Sensor Init
 *
 */




#endif
