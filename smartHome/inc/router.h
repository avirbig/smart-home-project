 /**
 *
 * router.h
 *
 * 07-04-2019
 * avishai cohen
 *
 * @brief:			this module extracts events and routes them to publisher for
 * 					further treatment
 * @description:
 *
 **/
 
 #ifndef _ROUTER_H_
 #define _ROUTER_H_


#include "ilog.h" //contain useful.h
#include "publisher.h"
#include "subRegistry.h"

namespace smartHome{

typedef std::tr1::shared_ptr<Publisher> SharedPublisher; 
typedef std::tr1::shared_ptr<SubRegistry> SharedSubRegistry; 

class Router: public advcpp::IRun {
public:
	Router(SharedDequeue _q, SharedPublisher _pub, SharedSubRegistry _sub, SharedILog _log);
	~Router();

	void run();

private:
	void publish(SharedEvent _p);

private:
	SharedDequeue m_q;
	SharedPublisher m_publisher;
	SharedSubRegistry m_subs;
	SharedILog m_log;
	advcpp::Thread m_thread;
};


}

 #endif //_ROUTER_H_
