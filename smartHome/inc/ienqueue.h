 /**
 *
 * ienqueue.h
 *
 * 10-04-2019
 * avishai cohen
 *
 * @brief: 	interface with enqueue() function to insert objects to
 * 			a container with implemented enqueue function
 * @description:
 *
 **/
 
#ifndef _IENQ_H_
#define _IENQ_H_

namespace smartHome{

template <typename T>
class IEnqueue{
public:
	virtual ~IEnqueue();
	virtual void enqueue(T const& _var) = 0;
};

template <typename T>
inline IEnqueue<T>::~IEnqueue()
{
}

}

#endif //_IENQ_H_
