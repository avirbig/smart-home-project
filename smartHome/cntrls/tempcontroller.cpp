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

#include "tempcontroller.h"

namespace smartHome{

using namespace std;
using namespace advcpp;

TempController::~TempController()
{
}

void TempController::handleEvent(SharedEvent _pevent)
{
	cout << "EVENT: " << _pevent->getType() << " MSG: " << _pevent->getString() << "ADDRESS:" << this << "\n\n";
}

extern "C" std::tr1::shared_ptr<TempController> makeAgent()
{
	return std::tr1::shared_ptr<TempController>(new TempController);
}

}

