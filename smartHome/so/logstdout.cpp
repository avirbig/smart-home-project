 /**
 *
 * logstdout.cpp
 *
 * 2019-04-16
 * avishai
 *
 * @brief:
 * @description:
 *
 **/
 
#include "logstdout.h"

namespace smartHome{

using namespace std;
using namespace advcpp;

void LogStdout::insert(SharedEvent _pevent)
{
	cout << " LOG === " << "EVENT: " << _pevent->getType() << " MSG: " << _pevent->getString() << "ADDRESS:" << this << "\n\n";
}

extern "C" std::tr1::shared_ptr<LogStdout> makeLog()
{
	return std::tr1::shared_ptr<LogStdout>(new LogStdout);
}

}

