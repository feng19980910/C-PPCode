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

template <class t1>
queuetp<t1>::queuetp() {
	head = tail = nullptr;
}

template <class t1>
bool queuetp<t1>::enqueue(const t1 & it) {
	if (head == nullptr && tail == nullptr) {
		head = tail = new Node;
		tail->item = it, tail->next = nullptr;
	}
	else {
		tail->next = new Node;
		tail->tiem = it, tail->next = nullptr;
	}
	return true;
}

template <class t1>
bool queuetp<t1>::dequeue(t1 & it) {
	if (head == nullptr && tail == nullptr)
		return false;
	if (head == tail) {
		it = *head;
		delete head;
		head = tail = nullptr;
	}
	else {
		it = *head;
		auto tempptr = head;
		head = ->next;
		delete tempptr;
	}
	return true;
}
#endif
