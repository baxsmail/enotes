#ifndef _My_SENSOR_H_
#define _My_SENSOR_H_

#include "common.h"
#include "Base_Sensor.h"

struct _My_Sensor;
typedef struct _My_Sensor MySensor;
typedef struct _My_vmt
{
	void (*FctnInit)(MySensor*);
	void (*Init)(MySensor*);
	void (*Configure)(MySensor*);
	void (*PreProcessing)(MySensor*);
	void (*Collect)(MySensor*);
	void (*Error)(MySensor*);
} My_FctnTable;

typedef struct _My_Abstract_vmt
{
    void (*VTinit)( MySensor* );
    int (*init)( MySensor* );
    int (*reset)( MySensor* );
    int (*getType)( MySensor* );
} My_Abstract_FctnTable;


struct _My_Sensor
{
    BaseSensor inherited;
};


void My_FctnInit( MySensor *this);
void My_Init( MySensor *this);
void My_Configure( MySensor *this );
void My_PreProcessing( MySensor *this );
void My_Collect( MySensor *this );
void My_Error( MySensor *this );

void My_VTinit( MySensor* );
int My_init( MySensor* );
int My_reset( MySensor* );
int My_getType( MySensor* );

MySensor* New_My_Sensor( int num );



#endif
