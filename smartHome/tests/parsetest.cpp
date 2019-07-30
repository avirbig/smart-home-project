 /**
 *
 * test0.cpp
 *
 * 07-04-2019
 * avishai cohen
 *
 * @brief:
 * @description:
 *
 **/
 
#include  "fileInput.h"

//using namespace smartHome;
//using namespace advcpp;

int main(void)
{
	FileInput f;
	
	f.read("config.txt");
	f.print();
	
	return 0;
}
