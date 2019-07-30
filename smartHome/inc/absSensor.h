 /**
 *
 * AbsSensor.h
 *
 * 2019-04-08
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _ABSTRACT_SENSOR_H_
#define _ABSTRACT_SENSOR_H_

#include  "useful.h"
#include  "iagent.h"

namespace smartHome{

class AbsSensor: public advcpp::IRun
				, public IAgent
{

public:
	AbsSensor();
	virtual ~AbsSensor();
	virtual void run() = 0;
	virtual void connect(Key _key, SharedSubRegistry _sub, SharedEnqueue _q);
protected:
	SharedEnqueue m_q;
	advcpp::Thread* m_thrd;
};

}

#endif //_ABSTRACT_SENSOR_H_
