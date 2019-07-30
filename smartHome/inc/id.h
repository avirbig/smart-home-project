 /**
 *
 * id.h
 *
 * 2019-04-10
 * avishai
 *
 * @brief: id parameters of subscription groups
 * @description: 	these id's are useful in order to create subscription groups
 * 					in order to store them in designated container
 *
 **/
 
#ifndef _ID_H_
#define _ID_H_

#include <string>

namespace smartHome{

typedef std::string Event_Type;

typedef int Room;
typedef int Floor;
typedef int Building;

class Location{
public:
	Location(Building _b, Floor _f, Room _r);
	bool operator < (const Location& _other) const;
	bool operator == (const Location& _other) const;
	bool operator != (const Location& _other) const;
	
private:
	Room m_room;
	Floor m_floor;
	Building m_building;
};

struct Key{
public:
	Key(Event_Type _et, Location _loc);
	bool operator < (const Key& _other) const;
private:
	Event_Type m_et;
	Location m_loc;
};

}
#endif //_ID_H_
