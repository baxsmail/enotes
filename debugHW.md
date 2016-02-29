### ATMOS Hardward Debug

* pi027 board
	* never changed
	* 3V VRef
	* figaro good
	* CO : +- 600 mV
	* OZone :

* pi026 board
	* changed capacitor - C3, C9 both from 10uF to 1uF
	* 3V VRef
	* figaro not work after changing capacitor
	* CO : +- 20 mV
	* OZone : +- 20mV

* convex board
	* R12 is 3 * 27K in series ( might have fake connection )
	* 5V VRef ( which is supposed to be right )
	* figaro good
	* CO : working channnel no out put 
		* cause there is no input to that channel on the adc
	* OZone : left untested
