#ifndef _Base_SENSOR_H_
#define _Base_SENSOR_H_

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

struct _Base_Sensor
{
	int test_num;
	Base_FctnTable *vmt;
};


void Base_FctnInit( BaseSensor *this);
void Base_Init( BaseSensor *this);
void Base_Configure( BaseSensor *this );
void Base_PreProcessing( BaseSensor *this );
void Base_Collect( BaseSensor *this );
void Base_Error( BaseSensor *this );
BaseSensor* New_Base_Sensor( int num );



#endif
