 /**
 *
 * subRegistry.cpp
 *
 * 2019-04-10
 * avishai
 *
 * @brief:
 * @description:
 *
 **/
 
#include "subRegistry.h"

namespace smartHome{

using namespace std;
using namespace advcpp;

void SubRegistry::add(Key _key, SharedIHandleEvent _h)
{
	m_subGroups[_key].insert(_h);
}

SubscribersGroup& SubRegistry::lookup(Key _key)
{
	return m_subGroups[_key];
}

}
