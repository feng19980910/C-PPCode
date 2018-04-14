#ifndef QUEUETP
#define QUEUETP

template <class type>
class queuetp {
private:
	struct Node;	// structor used
	Node * head;
	Node * tail;
public:
	queuetp();
	~queuetp();		// ����ʱ����ն���
	bool enqueue(const type & item);
	bool dequeue(type & item);
};

template <class type>
struct queuetp<type>::Node {
	type item;
	Node * next;
};

template <class type>
queuetp<type>::queuetp() {
	head = tail = nullptr;
}

template <class type>
queuetp<type>::~queuetp() {
	Node * temp;
	while (head != nullptr) {
		temp = head->next;
		delete head;
		head = temp;
	}
}

template <class type>
bool queuetp<type>::enqueue(const type & item) {
	if (head == nullptr) {
		head = tail = new Node;
		tail->item = item;
		tail->next = nullptr;
	}
	else {
		tail->next = new Node;
		tail = tail->next;
		tail->item = item;
		tail->next = nullptr;
	}
	return true;
}

template <class type>
bool queuetp<type>::dequeue(type & item) {
	if (head == nullptr)
		return false;
	if (head == tail) {
		item = head->item;
		delete head;
		head = tail = nullptr;		// ������һ��Ԫ�أ���Ҫ�Զ���β���д���
	}
	else {
		Node * second(head->next);	// ��¼��һ���ڵ�
		item = head->item;
		delete head;
		head = second;				// �ƶ�����һ�ڵ�
	}
	return true;
}

#endif