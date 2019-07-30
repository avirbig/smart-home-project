 /**
 *
 * iagent.h
 *
 * 2019-04-15
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _IAGENT_H_
#define _IAGENT_H_

#include <tr1/memory>
#include "useful.h"
#include "subRegistry.h"



namespace smartHome{
typedef std::tr1::shared_ptr<SubRegistry> SharedSubRegistry; 

class IAgent{
public:
	virtual ~IAgent();
	virtual void connect(Key _key, SharedSubRegistry _sub, SharedEnqueue _q) = 0;
};

}

#endif //_IAGENT_H_
