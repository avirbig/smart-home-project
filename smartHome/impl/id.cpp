 /**
 *
 * id.cpp
 *
 * 2019-04-10
 * avishai
 *
 * @brief:
 * @description:
 *
 **/
 
#include "id.h"

namespace smartHome{

Location::Location(Building _b, Floor _f, Room _r)
: m_room(_r)
, m_floor(_f)
, m_building(_b)
{
}

bool Location::operator == (const Location& _other) const
{
	return 		(m_building == _other.m_building)
			&&	(m_floor == _other.m_floor)
			&&	(m_room == _other.m_room);
}

bool Location::operator != (const Location& _other) const
{
	return 		!(*this == _other);
}

bool Location::operator < (const Location& _other) const
{
	if (m_building != _other.m_building )
	return m_building < _other.m_building;

	else if ( m_floor != _other.m_floor)
	   return m_floor < _other.m_floor;

	else if (m_room != _other.m_room)
	   return  m_room < _other.m_room;

	return false;
}

Key::Key(Event_Type _et, Location _loc)
: m_et(_et)
, m_loc(_loc)
{
}

bool Key::operator < (const Key& _other) const
{
	if (m_loc != _other.m_loc )
		return m_loc < _other.m_loc;

	else if ( m_et != _other.m_et)
		return m_et < _other.m_et;

	return false;
}
	
}
