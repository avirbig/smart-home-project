 /**
 *
 * sensors.cpp
 *
 * 2019-04-08
 * avishai
 *
 * @brief:
 * @description:
 *
 **/
 
#include <unistd.h>
#include "sensors.h"

namespace smartHome{

using namespace advcpp;

const int SLEEP_TIME_MILISEC = 500000;

//SensorTemperature::SensorTemperature()
//{
//}

//void SensorTemperature::start()
//{
//m_thrd = new Thread(this);
//}

SensorTemperature::~SensorTemperature()
{
	if(m_thrd)
	{
		m_thrd->join();
		delete m_thrd;
	}
}

void SensorTemperature::run()
{
	while(true)
	{
		SharedEvent p (new Event("TEMPERATURE", 1, 1, 1, "this is a Temperature Event"));
		m_q->enqueue(p);
		usleep(SLEEP_TIME_MILISEC);
	}
}

//SensorSmoke::SensorSmoke()
//{
//}

//void SensorSmoke::start()
//{
//m_thrd = new Thread(this);
//}

SensorSmoke::~SensorSmoke()
{
	if(m_thrd)
	{
		m_thrd->join();
		delete m_thrd;
	}
}

void SensorSmoke::run()
{
	while(true)
	{
		SharedEvent p (new Event("SMOKE", 1, 1, 2, "this is a Smoke Event"));
		m_q->enqueue(p);
		usleep(SLEEP_TIME_MILISEC);
	}
}

//SensorAccess::SensorAccess()
//{
//}

//void SensorAccess::start()
//{
//m_thrd = new Thread(this);
//}

SensorAccess::~SensorAccess()
{
	if(m_thrd)
	{
		m_thrd->join();
		delete m_thrd;
	}
}

void SensorAccess::run()
{
	while(true)
	{
		SharedEvent p (new Event("ACCESS", 1, 1, 1, "this is a Access Event"));
		m_q->enqueue(p);
		usleep(SLEEP_TIME_MILISEC);
	}
}

}
