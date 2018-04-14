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
	~queuetp();		// 析构时，清空队列
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
		head = tail = nullptr;		// 若仅有一个元素，需要对队列尾进行处理
	}
	else {
		Node * second(head->next);	// 记录下一个节点
		item = head->item;
		delete head;
		head = second;				// 移动到下一节点
	}
	return true;
}

#endif