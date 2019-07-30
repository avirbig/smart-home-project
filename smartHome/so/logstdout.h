 /**
 *
 * logstdout.h
 *
 * 2019-04-16
 * avishai
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _LOGSTDOUT_H_
#define _LOGSTDOUT_H_

#include "ilog.h"

namespace smartHome{

class LogStdout: public ILog
{
public:
	void insert(SharedEvent _e);
};

}

#endif //_LOGSTDOUT_H_
