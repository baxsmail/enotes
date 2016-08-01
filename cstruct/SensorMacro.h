

enum SensorList
{
    SensorListStart,
    BMP280,
    Si7020,
    SensorListEnd
};


void InitAllDevices()
{
    for( int i = SensorList; i < SensorListEnd; ++i )
    {
    }
}
