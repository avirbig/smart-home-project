 /**
 *
 * test8.cpp
 *
 * 17-04-2019
 * avishai cohen
 *
 * @brief: 
 * @description: implementation of builder
 *
 **/

#include  <dlfcn.h>

#include  "router.h"
#include  "sensors.h"
#include  "useful.h"
#include  "abscontroller.h"
#include  "builder.h"

using namespace smartHome;
using namespace advcpp;
typedef std::tr1::shared_ptr<AbsController> SharedController; 
typedef std::tr1::shared_ptr<AbsSensor> SharedSensorSmoke; 
typedef std::tr1::shared_ptr<AbsSensor> SharedSensorAccess; 
typedef std::tr1::shared_ptr<AbsSensor> SharedSensorTemperature; 

int main(void)
{
	Builder builder;
	SharedDequeue dequeue = builder.getChannel();
	SharedEnqueue enqueue = builder.getChannel();
	
	SharedSubRegistry allSubs = builder.getSubs();
	SharedPublisher pub = builder.getPub();
	
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
	
	c1->connect(Key("TEMPERATURE", Location(1,1,1)), allSubs, enqueue);
	c1->connect(Key("SMOKE", Location(1,1,2)), allSubs, enqueue);
	c2->connect(Key("TEMPERATURE", Location(1,1,1)), allSubs, enqueue);
	
	SharedILog log = builder.getLog();
	
	Router r(dequeue, pub, allSubs, log);
	
	Key dummyKey("DUMMY", Location(0,0,0));
	SharedSubRegistry dummySub;
	
	SharedSensorSmoke ss(new SensorSmoke);
	SharedSensorAccess sa(new SensorAccess);
	SharedSensorTemperature st(new SensorTemperature);
	
	ss->connect(dummyKey, dummySub, enqueue);
	sa->connect(dummyKey, dummySub, enqueue);
	st->connect(dummyKey, dummySub, enqueue);
	
	return 0;
}

