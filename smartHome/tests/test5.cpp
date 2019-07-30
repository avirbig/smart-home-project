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
 
 
#include  <dlfcn.h>

#include  "router.h"
#include  "sensors.h"
#include  "useful.h"
#include  "abscontroller.h"

using namespace smartHome;
using namespace advcpp;
typedef std::tr1::shared_ptr<AbsController> SharedController; 

int main(void)
{
	SharedChannel channel(new Channel<SharedEvent>);
	SharedDequeue dequeue = channel;
	SharedEnqueue enqueue = channel;
	
	SharedSubRegistry allSubs(new SubRegistry);
	SharedPublisher pub(new Publisher);
	
	SharedController (*makeAgent)(void);
	
	void* handle = dlopen("./libtempcontroller.so", RTLD_LAZY);
	if(!handle)
	{
		std::cout << "HANDLE IS NULL\n";
		return 1;
	}
	
	makeAgent = (SharedController (*)())dlsym(handle, "makeAgent");
	SharedController c1 = makeAgent();
	SharedController c2 = makeAgent();
	SharedController c3 = makeAgent();
	
	c1->init(Key("TEMPERATURE", Location(1,1,1)), allSubs);
	c1->init(Key("SMOKE", Location(1,1,2)), allSubs);
	c2->init(Key("TEMPERATURE", Location(1,1,1)), allSubs);
	
	Router r(dequeue, pub, allSubs);
	
	SensorSmoke ss(enqueue);
	SensorAccess sa(enqueue);
	SensorTemperature st(enqueue);
	
	return 0;
}

