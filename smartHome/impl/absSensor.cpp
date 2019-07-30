 /**
 *
 * absSensor.cpp
 *
 * 2019-04-08
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#include "absSensor.h"

namespace smartHome{

using namespace advcpp;

AbsSensor::AbsSensor()
: m_thrd(0)
{
}

AbsSensor::~AbsSensor()
{
	//if(m_thrd)
	//{
		//m_thrd->join();
		//delete m_thrd;
	//}
}

void AbsSensor::connect(Key _key, SharedSubRegistry _sub, SharedEnqueue _q)
{
	m_q = _q;
	m_thrd = new Thread(this);
}


}
