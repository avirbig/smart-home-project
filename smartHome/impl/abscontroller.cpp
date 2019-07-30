 /**
 *
 * abscontroller.cpp
 *
 * 2019-04-14
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#include "abscontroller.h"

namespace smartHome{

AbsController::~AbsController()
{
}

void AbsController::connect(Key _key, SharedSubRegistry _sub, SharedEnqueue _q)
{
	_sub->add(_key, shared_from_this());
}


}
