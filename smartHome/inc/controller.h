 /**
 *
 * controller.h
 *
 * 2019-04-10
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "ihandle.h"
#include "subRegistry.h"
#include "abscontroller.h"

namespace smartHome{

class Controller: public AbsController
{
public:
	virtual ~Controller();
	void handleEvent(std::tr1::shared_ptr<Event> _pevent);
};

}

#endif //_CONTROLLER_H_
