 /**
 *
 * publisher.cpp
 *
 * 2019-04-10
 * avishai
 *
 * @brief:
 * @description:
 *
 **/
 
#include "publisher.h"
#include <algorithm>

namespace smartHome{
using namespace std;
using namespace advcpp;
	
class SendEvent{
	SharedEvent m_e;
public:
	SendEvent(SharedEvent _e): m_e(_e) {}
	bool operator () (SharedIHandleEvent _h)
	{
		_h->handleEvent(m_e);
		
		return true;
	}
};

void Publisher::notify(SubscribersGroup& _subsGroup, SharedEvent _e)
{
	for_each(_subsGroup.begin(), _subsGroup.end(), SendEvent(_e));
}

}
