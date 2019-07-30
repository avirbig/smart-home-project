 /**
 *
 * router.cpp
 *
 * 2019-04-10
 * avishai
 *
 * @brief:
 * @description:
 *
 **/
 
#include  "router.h"

namespace smartHome{


using namespace advcpp;
using namespace std;

Router::Router(SharedDequeue _q, SharedPublisher _pub, SharedSubRegistry _sub, SharedILog _log)
: m_q(_q)
, m_publisher(_pub)
, m_subs(_sub)
, m_log(_log)
, m_thread(this)
{
}

Router::~Router()
{
	m_thread.join();
}	

void Router::run()
{
	while(true)
	{
		SharedEvent p;
		m_q->dequeue(p);
		m_log->insert(p);
		//Qrouter-pub.enqueue(p)
		m_publisher->notify(m_subs->lookup(p->getKey()) ,p); //Qrouter-pub.dequeue(p)
	}
}

}
