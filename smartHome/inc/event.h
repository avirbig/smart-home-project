 /**
 *
 * event.h
 *
 * 07-04-2019
 * avishai cohen
 *
 * @brief:
 * @description:
 *
 **/
 
 #ifndef _EVENT_H_
 #define _EVENT_H_
 

#include <string>
#include  "nonCopyable.h"
#include  "id.h"			//Location

namespace smartHome{

class Event : public advcpp::NonCopyable{
public:
	Event(Event_Type _et, Building _b, Floor _f, Room _r, std::string _desc);
	
	Event_Type getType() const;
	Location const& getLocation() const;
	Key const& getKey() const;
	std::string getString() const;
	
private:
	Event_Type m_type;
	Location m_loc;
	Key m_key;
	std::string m_eventDesc;
};

inline Event_Type Event::getType() const
{
	return m_type;
}
	 
inline std::string Event::getString() const
{
	return m_eventDesc;
}

inline Location const& Event::getLocation() const
{
	return m_loc;
}

inline Key const& Event::getKey() const
{
	return m_key;
}

}

#endif //_EVENT_H_
