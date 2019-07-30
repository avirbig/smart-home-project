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
#include  "channel.h"

using namespace smartHome;
using namespace advcpp;

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
	
	allSubs->add(Key("TEMPERATURE", Location(1,1,1)), c1);
	allSubs->add(Key("SMOKE", Location(1,1,2)), c1);
	allSubs->add(Key("TEMPERATURE", Location(1,1,1)), c2);
	
	Router r(dequeue, pub, allSubs);
	
	SensorSmoke ss(enqueue);
	SensorAccess sa(enqueue);
	SensorTemperature st(enqueue);
	
	return 0;
}
