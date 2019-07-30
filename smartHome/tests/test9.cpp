 /**
 *
 * test8.cpp
 *
 * 17-04-2019
 * avishai cohen
 *
 * @brief: 
 * @description: implementation of builder
 *
 **/

#include  <dlfcn.h>

#include  "router.h"
#include  "builder.h"

using namespace smartHome;
using namespace advcpp;

int main(void)
{
	Builder builder;
	
	SharedSubRegistry allSubs = builder.getSubs();
	SharedPublisher pub = builder.getPub();
	SharedILog log = builder.getLog();
	
	builder.makeAgents();
	
	Router r(builder.getChannel(), pub, allSubs, log);

	return 0;
}

