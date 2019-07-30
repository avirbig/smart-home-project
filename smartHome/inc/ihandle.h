 /**
 *
 * ihandle.h
 *
 * 2019-04-14
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _IHANDLE_H_
#define _IHANDLE_H_

#include <tr1/memory>
#include "event.h"
namespace smartHome{

typedef std::tr1::shared_ptr<Event> SharedEvent; 

class IHandleEvent{
public:
	virtual ~IHandleEvent();
	virtual void handleEvent(SharedEvent _pevent) = 0;
};

}

#endif //_IHANDLE_H_
