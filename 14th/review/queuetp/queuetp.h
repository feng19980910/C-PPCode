#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class t1>
class queuetp {
	private:
		struct Node { t1 item; Node * next; };
		queuetp<t1> * head;
		queuetp<t1> * tail;

		// forbid copy
		queuetp(const queuetp & qt) = delete;
		queuetp & operator=(const queuetp & qt) = delete;
	public:
		queuetp();
		bool enqueue(const t1 &it);
		bool dequeue(t1 & it);
};

#endif
