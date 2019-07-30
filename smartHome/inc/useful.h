 /**
 *
 * useful.h
 *
 * 2019-04-10
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _USEFUL_H_
#define _USEFUL_H_

#include <tr1/memory>
#include <set>
#include <map>

#include "thread.h"
#include "channel.h"

// SHARED POINTERS
#include "event.h"
#include "ihandle.h"

namespace smartHome{

class ILog; //forward decl
typedef std::tr1::shared_ptr<ILog> SharedILog; 

class IAgent; //forward decl
typedef std::tr1::shared_ptr<IAgent> SharedIAgent; 

typedef std::tr1::shared_ptr<Event> SharedEvent; 
typedef std::tr1::shared_ptr<IHandleEvent> SharedIHandleEvent; 
typedef std::tr1::shared_ptr<advcpp::WaitableQueue<SharedEvent> > WaitableQueueOfSharedEvents; 
typedef std::tr1::shared_ptr<Channel<SharedEvent> >  SharedChannel;
typedef std::tr1::shared_ptr<IDequeue<SharedEvent> >  SharedDequeue;
typedef std::tr1::shared_ptr<IEnqueue<SharedEvent> >  SharedEnqueue;

typedef std::set<SharedIHandleEvent> SubscribersGroup;

}

#endif //_USEFUL_H_
