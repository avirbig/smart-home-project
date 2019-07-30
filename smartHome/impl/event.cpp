 /**
 *
 * event.cpp
 *
 * 07-04-2019
 * avishai cohen
 *
 * @brief:
 * @description:
 *
 **/

#include "event.h"

namespace smartHome{

Event::Event(Event_Type _et, Building _b, Floor _f, Room _r, std::string _desc)
: m_type(_et)
, m_loc(_b, _f, _r)
, m_key(m_type, m_loc)
, m_eventDesc(_desc)
{
}

}
