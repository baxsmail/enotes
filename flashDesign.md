More hints about Flash Disk Design --- Updated 08/18/2016
=======================

# Before you're doing any further coding imagine how should the file system work
## To help you to do so, try go through each function except the unit ones and ask yourself these questions
1. What information do I need to do this?
2. Where can I find such information? 
   * If it is static constant? We should decide it first and then use a variable or macro to define it.
   * If it is stored elsewhere in the flash disk we must need a way to fetch that information first before doing this. What is that way by claiming that we only have the functions we've went through?
   * If it is a data information, say the sensor's data, leave it as comment for now since these should be the last issue you should worry for the design.
3. By using this function, should we write some information elsewhere to help retrieve it later?
4. If needed, then where should we store it and through which method?

## During or after the asking procedure you should have some questions. Please summarize them and email them to me. It's important I make sure the system has no issues and you make sure you understand it in a right way before you made further codes.

# Right before you're doing further coding
## Please don't write codes right away in FlashStorage_Device.h/.c even though I noticed so for now.
## What you want to do is to create a new .h and .c somewhere you want and only focus on functions I provided for now.
## Or you can just eliminate all the copy & pastes codes in FlashStorage_Device.h/.c for now. When you do something you don't want to irrelevent codes bother your minds, do you?
## When you design codes you should always want to design it in the way that you can easily test it. Print anything in some good format so you can identify what's going on easily.
## Always test the functions before you need to use the functions in other functions.
## You should remove or comment most current codes out before launching a test. Since you want to test your function easily by including the .h and just calling them one by one. Current codes will print other stuff in the framework which can bother you debuging or thinking in various ways.
## Always think twice before coding, we can never make things very right if we think it in a wrong way. 
## Feel free to think more and ask bunches questions via emails.

Flash Disk Design
=====================

# Space Allocation

## Total Space : 128MB

### Allocation Info
* 8MB for managing description information
* 50MB for 1st bank to store pure sensor data
* 50MB for the other bank to store pure sensor data 
* 20MB reserved for swap space or other usage in future 

### Explanation
* Description information like the version of the flash software, size of data have been stored in either bank, current bank # for storing data, the storage format, and the data structure about the sensors' output.
* We want to have 2 banks to store data in turn
* since while transmitting data, sensors are still collecting, we can expect memory may get full and need somewhere to store data.
* Reserved space may cache some information in future case.


# Functions in details

## API function lists
* long writeByte( long location, unsigned char data );
* unsigned char readByte( long location );
* long writeInt( long location, int data );
* int readInt( long location );
* long writeLong( long location, long data );
* long readLong( long location );
* long writeFloat( long location, float data );
* float readFloat( long location );
* long getNumOfPeriodDataFromBank( int bankNumber );       
    * here # of data means number of collection periods, so if we collect 2 periods for 5 sensors, it should return 2 for 2 periods of collection periods
* long setNumOfPeriodDataFromBank( int bankNumber );       
* long getNumOfTotalSensorsWeHaveInDesign();
    * we want to know the max number of the sensors we support, so we can use this number to scan the sensor info and get if we have some sensors on this chip and what are those sensors' Info
* long setNumOfBytePerPeriodDataOccupy();
* unsigned char * getSensorInfo(int SensorNumber);
    * a fixed sized( size undetermined for now ) bytes array of data to descript :
        * do we have this sensor on this chip?
        * how many kinds of data do this sensor provide? ( maximum 5 maybe ) like BME280 provide humility/temperature/pressure 3 kinds of data
        * what the data structure of each data? int/int_32/float/double
* long setSensorInfo( unsigned char * SensorInfo);
* long writeNumOfPeriodData( long num, DataUnit * dataUnit, int bankNum );
* DataUnit * readNumOfPeriodData( long num, int bankNum );

## Simple Description

### Unit Functions
#### you should gurantee these 2 fundamental functions work correctly
* long writeByte( long location, unsigned char data );
    * return whether success or not, following write/set functions are similar
* unsigned char readByte( long location );
    * return the data you want, later read/get functions are similar

### Basic r/w functions
#### besides above 2, these functions can be easily constructed using Basic Functions
* long writeByte( long location, unsigned char data );
* unsigned char readByte( long location );
* long writeInt( long location, int data );
* int readInt( long location );
* long writeLong( long location, long data );
* long readLong( long location );
* long writeFloat( long location, float data );
* float readFloat( long location );

### File system functions for descrption information
#### these functions can be constructed using above Functions, and it should specify a specific location to read and write to perform get and set. 
#### following functions specify a location in description information part ( 8MB )
#### most functions are very easy and straight forward, we just need to specify a specific location in advance
* long getNumOfPeriodDataFromBank( int bankNumber );       
* long setNumOfPeriodDataFromBank( int bankNumber );       
* long getNumOfTotalSensorsWeHaveInDesign();
* long setNumOfBytePerPeriodDataOccupy();
* unsigned char * getSensorInfo(int SensorNumber);
* long setSensorInfo( unsigned char * SensorInfo);

### File system functions for pure data
#### these functions can be constructed via Basic r/w functions
#### and you also need functions for description information here to support
#### to know how many the sensors data we have in each period of collection
#### but basically, it just get some information and separate the tasks to be "I want to write/read this kind(int/float) information here and then this kind there and etc."
* long writeNumOfPeriodData( long num, DataUnit * dataUnit, int bankNum );
* DataUnit * readNumOfPeriodData( long num, int bankNum );
