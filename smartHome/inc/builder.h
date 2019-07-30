 /**
 *
 * builder.h
 *
 * 2019-04-16
 * avishai
 *
 * @brief:
 * @description:
 *
 **/
 
 
#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "builder.h"
#include "ilog.h" //contain useful.h
#include "publisher.h"
#include "subRegistry.h"

namespace smartHome{

typedef std::tr1::shared_ptr<Publisher> SharedPublisher; 
typedef std::tr1::shared_ptr<SubRegistry> SharedSubRegistry; 

class Builder : advcpp::NonCopyable{
public:
	Builder();
	
	SharedILog getLog() const;
	SharedPublisher getPub() const;
	SharedChannel getChannel() const;
	SharedSubRegistry getSubs() const;
	
	void makeAgents();
	
private:
	SharedILog m_log;
	SharedPublisher m_pub;
	SharedChannel m_channel;
	SharedSubRegistry m_subs;
	std::set<SharedIAgent> m_agents;
};


inline SharedILog Builder::getLog() const
{
	return m_log;
}

inline SharedPublisher Builder::getPub() const
{
	return m_pub;
}

inline SharedChannel Builder::getChannel() const
{
	return m_channel;
}

inline SharedSubRegistry Builder::getSubs() const
{
	return m_subs;
}

}
#endif //_BUILDER_H_

