 /**
 *
 * controller.cpp
 *
 * 2019-04-10
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#include "controller.h"
#include "useful.h" // SharedEvent

namespace smartHome{

using namespace std;
using namespace advcpp;

Controller::~Controller()
{
}

void Controller::handleEvent(SharedEvent _pevent)
{
	cout << "EVENT: " << _pevent->getType() << " MSG: " << (*_pevent).getString() << "ADDRESS:" << this << "\n\n";
}

}
