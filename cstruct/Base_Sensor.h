#ifndef _Base_SENSOR_H_
#define _Base_SENSOR_H_

#include "Base_Device.h"

struct _Base_Sensor;
typedef struct _Base_Sensor BaseSensor;
typedef struct _Base_vmt
{
	void (*FctnInit)(BaseSensor*);
	void (*Init)(BaseSensor*);
	void (*Configure)(BaseSensor*);
	void (*PreProcessing)(BaseSensor*);
	void (*Collect)(BaseSensor*);
	void (*Error)(BaseSensor*);
} Base_FctnTable;

typedef struct _Abstract_vmt
{
    void (*VTinit)( BaseSensor* );
    int (*init)( BaseSensor* );
    int (*reset)( BaseSensor* );
    int (*getType)( BaseSensor* );
} Abstract_FctnTable;

struct _Base_Sensor
{
    BaseDevice abstract;
	int test_num;
	Base_FctnTable *vmt;
    int (*getNum)( BaseSensor* );
};


void Base_FctnInit( BaseSensor *this);
void Base_Init( BaseSensor *this);
void Base_Configure( BaseSensor *this );
void Base_PreProcessing( BaseSensor *this );
void Base_Collect( BaseSensor *this );
void Base_Error( BaseSensor *this );

void Base_VTinit( BaseSensor* );
int Base_init( BaseSensor* );
int Base_reset( BaseSensor* );
int Base_getType( BaseSensor* );

BaseSensor* New_Base_Sensor( int num );
int Base_getNum( BaseSensor * );



#endif
