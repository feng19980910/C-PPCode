#include "queuetp.h"

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
		head = head->next;
		delete tempptr;
	}
	return true;
}
