#ifndef _MY_SENSOR_H_
#define _MY_SENSOR_H_

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

struct _My_Sensor
{
    Sensor inherited;
};

void My_FctnInit(MySensor *this);
void My_Init( MySensor *this);
void My_Configure(MySensor *this );
void My_PreProcessing(MySensor *this );
void My_Collect(MySensor *this );
void My_Error(MySensor *this );
MySensor* New_MySensor( int num );
#endif
