#include "CurrentSensor.h"
#include "Arduino.h"

CurrentSensor::CurrentSensor(int pin) {
	_pin=pin;
	_offset=2.5;
}
double CurrentSensor::getVolts() {
	int i=500; // Average over i readings to reduce noise
	double sum=0;
	double sensorValue;
	while(i>0){
		sensorValue = analogRead(_pin);
		// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
		sum += sensorValue * (5.0 / 1023.0);
		i--;
	}
	sensorValue=sum/500;
	return sensorValue;
}
double CurrentSensor::getAmps() {// Convert Volts to amps
	double volts=getVolts();
	volts-=_offset;
	volts/=.185;
	return volts;
}
void CurrentSensor::calibrate() { //Should be called only when there is no current being detected
	_offset=getVolts();
}
