#ifndef CURRENT_SENSOR_H
#define CURRENT_SENSOR_H

#include "Arduino.h"
class CurrentSensor
{
	private:
		int _pin;		//Analog pin to which the sensor output is connected
		double _offset;	// variable to save the voltage output when there is no current passing through the sensor
	public:
		CurrentSensor(int pin);	//Constructor
		double getVolts();		//Analog output voltage is returned
		double getAmps();		//returns output voltage converted to amps
		void calibrate();		//If called when there is no current passing through the current sensor, sets the offset to the output voltage
};

#endif
