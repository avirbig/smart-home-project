 /**
 *
 * abscontroller.h
 *
 * 2019-04-14
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _ICONTROLLER_H_
#define _ICONTROLLER_H_

#include <tr1/memory>
#include "subRegistry.h"
#include "iagent.h"


namespace smartHome{

class AbsController: public std::tr1::enable_shared_from_this<AbsController>
					, public IHandleEvent
					, public IAgent
{
public:
	virtual ~AbsController();
	void connect(Key _key, SharedSubRegistry _sub, SharedEnqueue _q);
};

}
#endif //_ICONTROLLER_H_
