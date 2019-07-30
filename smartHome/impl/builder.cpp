 /**
 *
 * builder.cpp
 *
 * 2019-04-16
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#include  <dlfcn.h>

#include  "sensors.h"
#include  "abscontroller.h"
#include "builder.h"

namespace smartHome{
	
Builder::Builder()
: m_pub(new Publisher)
, m_channel(new Channel<SharedEvent>)
, m_subs(new SubRegistry)
{
	SharedILog (*makeLog)(void);
	
	void* logHandle = dlopen("./liblogstdout.so", RTLD_LAZY);
	if(!logHandle)
	{
		std::cout << "LOG HANDLE IS NULL\n";
	}
	
	makeLog = (SharedILog (*)())dlsym(logHandle, "makeLog");
	m_log = makeLog();
}
	
	
void Builder::makeAgents()
{
	//todo - parsing config and generate agents according to requirements
	typedef std::tr1::shared_ptr<AbsController> SharedController; 
	typedef std::tr1::shared_ptr<AbsSensor> SharedSensorSmoke; 
	typedef std::tr1::shared_ptr<AbsSensor> SharedSensorAccess; 
	typedef std::tr1::shared_ptr<AbsSensor> SharedSensorTemperature; 
	
	SharedController (*makeAgent)(void);
	void* handle = dlopen("./libtempcontroller.so", RTLD_LAZY);
	if(!handle)
	{
		std::cout << "HANDLE IS NULL\n";
		return;
	}
	
	makeAgent = (SharedController (*)())dlsym(handle, "makeAgent");
	SharedController c1 = makeAgent();
	SharedController c2 = makeAgent();
	SharedController c3 = makeAgent();
	
	c1->connect(Key("TEMPERATURE", Location(1,1,1)), m_subs, m_channel);
	c1->connect(Key("SMOKE", Location(1,1,2)), m_subs, m_channel);
	c2->connect(Key("TEMPERATURE", Location(1,1,1)), m_subs, m_channel);
	
	m_agents.insert(c1);
	m_agents.insert(c2);
	
	Key dummyKey("DUMMY", Location(0,0,0));
	
	SharedSensorSmoke ss(new SensorSmoke);
	SharedSensorAccess sa(new SensorAccess);
	SharedSensorTemperature st(new SensorTemperature);
	
	ss->connect(dummyKey, m_subs, m_channel);
	sa->connect(dummyKey, m_subs, m_channel);
	st->connect(dummyKey, m_subs, m_channel);
	
	m_agents.insert(ss);
	m_agents.insert(sa);
	m_agents.insert(st);
}

	
}
