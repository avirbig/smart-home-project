 /**
 *
 * idequeue.h
 *
 * 10-04-2019
 * avishai cohen
 *
 * @brief: 	interface with dequeue() function to insert objects to
 * 			a container with implemented dequeue function
 * @description:
 *
 **/
 
#ifndef _IDEQ_H_
#define _IDEQ_H_

namespace smartHome{

template <typename T>
class IDequeue{
public:
	virtual ~IDequeue();
	virtual void dequeue(T& _var) = 0;
};

template <typename T>
inline IDequeue<T>::~IDequeue()
{
}

}

#endif //_IDEQ_H_
