#ifndef _MY_SENSOR_H_
#define _MY_SENSOR_H_

struct _My_Sensor;
typedef struct _My_Sensor MySensor;
typedef struct _My_vmt
{
    void (*FctnInit)(MySensor*);
    void (*Init)(MySensor*);
    void (*MyPrint)(MySensor*);
} My_FctnTable;

struct _My_Sensor
{
    Sensor inherited;
};

void My_FctnInit( MySensor *this);
void My_Init( MySensor *this);
void My_MyPrint( MySensor *this );
MySensor* New_MySensor( int num );
#endif
