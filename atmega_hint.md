ATMEGA SKELECTON
===========

## REFERENCE PROGRAM

### AVR130 
* interrupt config
* ISR

### timer as an external int.

## PROGRAM SKETCH


### BMP280
* XMIT : TWI / I2C
* current mode
	1. init & configure oversample rate
	2. start measurement ( return time should be waited )
	3. wait & read the value
* handlers' types
	* error handlers
		* TWI_COMM_ERR
		* INVALID_RESLT
	* callback on success handlers
* future mode
	1. init & configure oversample rate
	2. start measurement in some timer interrupt and set timer accordingly ( could be a round robin mechanism )
	3. in corresponding timer interrupt read and call-back
	4. if somewhat failed call corresponding error handlers

### K30
* XMIT : TWI / I2C
* current mode
	1. init & configure sample frequency
	2. start measurement 
	3. delay some fixed time and read the value
* handlers' types
	* error handlers
		* TWI_SENT_ERR
		* TWI_SLAR_ERR
		* TWI_RECV_ERR
		* CHCK_SUM_ERR
	* callback on success handlers
* future mode
	1. init & configure sample frequency
	2. start measurement
	3. in corresponding timer interrupt read and call-back
	4. if somewhat failed call corresponding error handlers

### Si7020
* XMIT : TWI / I2C
* current mode
	1. init & configure sample frequency
	2. start measurement 
	3. read and return
* handlers' types
	* error handlers
		* TWI_SENT_ERR
		* TWI_SLAR_ERR
		* TWI_RECV_ERR
		* CRC_CHCK_ERR
	* callback on success handlers
* future mode
	1. init & configure sample frequency
	2. start measurement
	3. read and return ( or add a delay like other sensors )
	4. if somewhat failed call corresponding error handlers

### TGS2600
* XMIT : TWI / I2C
* current mode
	1. init & turn on SPI stuff
	2. read adc and return
* handlers' types
	* error handlers
		* currently nop
	* callback on success handlers
* future mode
	1. init & turn on SPI stuff
	2. read adc and return


