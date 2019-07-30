 /**
 *
 * channel.h
 *
 * 2019-04-11
 * avishai
 *
 * @brief:
 * @description:
 *
 **/
 
#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include <tr1/memory>

#include "idequeue.h"
#include "ienqueue.h"
#include "waitQueue.h"

namespace smartHome{

template <typename T>
class Channel: 	public IEnqueue<T>,
				public IDequeue<T>{
public:
	Channel();
	void enqueue(T const& _var);
	void dequeue(T& _var);
private:
	advcpp::WaitableQueue<T> m_q;
};

template <typename T>
Channel<T>::Channel()
{
}

template <typename T>
void Channel<T>::enqueue(T const& _var)
{
	m_q.enqueue(_var);
}

template <typename T>
void Channel<T>::dequeue(T& _var)
{
	m_q.dequeue(_var);
}

}

#endif //_CHANNEL_H_
