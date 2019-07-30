 /**
 *
 * publisher.h
 *
 * 2019-04-10
 * avishai
 *
 * @brief:
 * @description:
 *
 **/


#ifndef _PUBLISH_H_
#define _PUBLISH_H_

#include "useful.h"

namespace smartHome{

class Publisher{
public:
	void notify(SubscribersGroup& _subsGroup, SharedEvent _e);
};

}

#endif //_PUBLISH_H_
