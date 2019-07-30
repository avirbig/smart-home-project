 /**
 *
 * ilog.h
 *
 * 2019-04-16
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _ILOG_H_
#define _ILOG_H_

#include "useful.h"

namespace smartHome{

class ILog{
public:
	virtual ~ILog();
	virtual void insert(SharedEvent) = 0;
};

}

#endif //_ILOG_H_
