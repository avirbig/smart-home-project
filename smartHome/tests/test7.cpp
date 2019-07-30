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
typedef std::tr1::shared_ptr<AbsSensor> SharedSensorSmoke; 
typedef std::tr1::shared_ptr<AbsSensor> SharedSensorAccess; 
typedef std::tr1::shared_ptr<AbsSensor> SharedSensorTemperature; 
typedef std::tr1::shared_ptr<ILog> SharedILog; 

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
	
	c1->connect(Key("TEMPERATURE", Location(1,1,1)), allSubs, enqueue);
	c1->connect(Key("SMOKE", Location(1,1,2)), allSubs, enqueue);
	c2->connect(Key("TEMPERATURE", Location(1,1,1)), allSubs, enqueue);
	
	SharedILog (*makeLog)(void);
	
	void* logHandle = dlopen("./liblogstdout.so", RTLD_LAZY);
	if(!logHandle)
	{
		std::cout << "LOG HANDLE IS NULL\n";
		return 1;
	}
	
	makeLog = (SharedILog (*)())dlsym(logHandle, "makeLog");
	SharedILog log = makeLog();
	
	Router r(dequeue, pub, allSubs, log);
	
	Key dummyKey("DUMMY", Location(0,0,0));
	SharedSubRegistry dummySub;
	
	SharedSensorSmoke ss(new SensorSmoke);
	SharedSensorAccess sa(new SensorAccess);
	SharedSensorTemperature st(new SensorTemperature);
	
	ss->connect(dummyKey, dummySub, enqueue);
	sa->connect(dummyKey, dummySub, enqueue);
	st->connect(dummyKey, dummySub, enqueue);
	
	//ss->start();
	//sa->start();
	//st->start();

	return 0;
}

