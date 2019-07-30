 /**
 *
 * test0.cpp
 *
 * 07-04-2019
 * avishai cohen
 *
 * @brief:
 * @description:
 *
 **/
 
#include  "router.h"
#include  "sensors.h"

using namespace smartHome;
using namespace advcpp;

int main(void)
{
	WaitableQueueOfSharedEvents q(new WaitableQueue<SharedEvent>);
	
	Controller c;
	Router r(q, c);
	SensorSmoke ss(q);
	SensorAccess sa(q);
	SensorTemperature st(q);
	
	return 0;
}
