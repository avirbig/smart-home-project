

#ifndef _SUBREG_H_
#define _SUBREG_H_


#include  "useful.h" //SubscribersGroup
#include  "id.h" //key

namespace smartHome{

class SubRegistry{
public:
	void add(Key _key, SharedIHandleEvent _h);
	SubscribersGroup& lookup(Key _key);
	//void remove();
private:
	std::map<Key, SubscribersGroup> m_subGroups;
};


}

#endif //_SUBREG_H_
