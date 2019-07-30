 /**
 *
 * temperature.h
 *
 * 2019-04-15
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _TMPCNTRL_H_
#define _TMPCNTRL_H_

#include "ihandle.h"
#include "subRegistry.h"
#include "abscontroller.h"

namespace smartHome{

class TempController: public AbsController
{
public:
	virtual ~TempController();
	void handleEvent(std::tr1::shared_ptr<Event> _pevent);
};

}




#endif //_TMPCNTRL_H_
