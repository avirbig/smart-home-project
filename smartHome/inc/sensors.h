 /**
 *
 * sensors.h
 *
 * 2019-04-08
 * avishai
 *
 * @brief:		Different sensors, all inheritting from sensor Abstract
 * @description: in current implementation each sensor is operating in his own thread
 *
 **/

#ifndef _SENSORS_H_
#define _SENSORS_H_

#include  "absSensor.h"

namespace smartHome{

class SensorTemperature: public AbsSensor
{
public:
	//SensorTemperature();
	~SensorTemperature();
	//void start();
	void run();
};

class SensorSmoke: public AbsSensor
{
public:
	//SensorSmoke();
	~SensorSmoke();
	//void start();
	void run();
};

class SensorAccess: public AbsSensor
{
public:
	//SensorAccess();
	~SensorAccess();
	//void start();
	void run();
};

}

#endif //_SENSORS_H_
