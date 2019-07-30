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
#include  "useful.h"
#include  "controller.h"


using namespace smartHome;
using namespace advcpp;
typedef std::tr1::shared_ptr<Controller> SharedController; 

int main(void)
{
	SharedChannel channel(new Channel<SharedEvent>);
	SharedDequeue dequeue = channel;
	SharedEnqueue enqueue = channel;
	
	SharedSubRegistry allSubs(new SubRegistry);
	SharedPublisher pub(new Publisher);
	
	SharedController c1(new Controller);
	SharedController c2(new Controller);
	SharedController c3(new Controller);
	
	c1->init(Key("TEMPERATURE", Location(1,1,1)), allSubs);
	c1->init(Key("SMOKE", Location(1,1,2)), allSubs);
	c2->init(Key("TEMPERATURE", Location(1,1,1)), allSubs);
	
	Router r(dequeue, pub, allSubs);
	
	SensorSmoke ss(enqueue);
	SensorAccess sa(enqueue);
	SensorTemperature st(enqueue);
	
	return 0;


}

