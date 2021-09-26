#include "forwardlist.h"

void forwardList::check(const int &pos, const int &left, const int &right) {
	if (pos < left || pos > right) {
		cout << "位置越界";
	}
}

// 找到返回前驱的 next, 未找到返回 nullptr
Node *forwardList::get(const int &pos) const{
	Node *p = head;
	int j = 0;
	while (p && j < pos) {
		p = p->next;
		j++;
	}
	return p;
}


forwardList::forwardList(Node *p) :head(p), tail(p) { ; }

forwardList::forwardList(const initializer_list<int> &ls) {
	auto it = ls.begin();
	do {
		push_back(*it);
		it++;
	} while (it != ls.end());
}

forwardList::forwardList(forwardList& f) {
	head = tail = nullptr;
	for (int i = 0; i != f.size(); i++)
		push_back(f[i]);
}

forwardList::forwardList(forwardList &f, const int &left, const int &right) {
	for (Node *p = f.get(left); p != f.get(right); p = p->Next()) {
		push_back(p->Data());
	}
}

forwardList &forwardList::operator=(forwardList &f) {
	if (*this == f)
		;
	else {
		clear();
		for (int i = 0; i != f.size(); i++)
			push_back(f[i]);
	}
	return *this;
}

int forwardList::size() const{
	int size = 0;
	Node *p = head;
	while (p) {
		p = p->next;
		size++;
	}
	return size;
}

Node *forwardList::begin() const{
	return head;
}

Node *forwardList::end() const{
	return tail;
}

int forwardList::front() const{
	return begin()->data;
}

int forwardList::back() const{
	return end()->data;
}

void forwardList::clear() {
	for (Node *p = head; head != nullptr; p = head) {
		head = p->next;
		delete p;
	}
	head = tail = nullptr;
}

void forwardList::push_back(const int &number) {

	Node *p = new Node;
	p->data = number;
	p->next = nullptr;
	if (tail) {
		tail->next = p;
		tail = tail->next;
	}
	else {
		head = tail = p;
	}
}

void forwardList::print() {
	cout << *this << endl;
}

Node* forwardList::find(const int &number) const{
	Node *p = head;
	while (p) {
		if (p->data == number)
			break;
		p = p->next;
	}
	return p;
}

void forwardList::erase(const int &number) {
	Node *p = find(number);
	Node *p_prev = head;

	if (p == head)
	{
		head = p->next;
		delete p; // 释放节点
	}
	else if (p != nullptr)
	{
		while (p_prev->next != p) {
			p_prev = p_prev->next; // 找到p前驱
		}
		p_prev->next = p->next; // p_prev的后继指向p的后继
		delete p; // 释放节点                               
		p = nullptr;
		// 调整尾指针
		if (p_prev->next == nullptr) {
			tail = p_prev;
		}
	}
	else {
		cout << "Sorry, not found!" << endl;
		clear();
		exit(0);
	}

}

void forwardList::insert_before(const int &number, const int &pos) {
	Node *p = get(pos);

	if (p) {

		if (p == head) {
			Node *temp = new Node;
			temp->data = number;
			temp->next = head;
			head = temp;
		}
		else {
			Node *p_prev = head;
			while (p_prev->next != p) {
				p_prev = p_prev->next;
			}
			Node *temp = new Node;
			temp->data = number;
			temp->next = p_prev->next;
			p_prev->next = temp;
		}
	}
	else {
		cout << "Sorry, can't insert!" << endl;
		clear();
		exit(0);
	}
}

void forwardList::insert_after(const int &number, const int &pos) {
	auto p = get(pos);
	if (p) {
		Node *temp = new Node;
		temp->data = number;
		temp->next = p->next;
		p->next = temp;
		if (temp->next == nullptr) {
			tail = temp;
		}
	}
	else {
		cout << "Sorry, can't insert!" << endl;
		clear();
		exit(0);
	}
}

void forwardList::reverse() {
	Node *p_prev = head;
	Node *p = p_prev->next;
	head->next = nullptr;
	tail = head;
	while (p) {
		p_prev = p;
		p = p->next;
		p_prev->next = head;
		head = p_prev;
	}
}

bool forwardList::isEmpty() {
	if (head == nullptr && tail == nullptr)
		return true;
	else
		return false;
}

bool forwardList::isSorted() {
	for (Node *p = head; p != end(); p = p->next) {
		if (p->data > p->next->data)
			return false;
	}
	return true;
}

void forwardList::sort() {
	;
}

void forwardList::Delete(const int &left, const int &right) {
	Node *p = head;
	Node *prev = head;
	while (p) {
		if (p->data < right && p->data >= left) {
			if (p == head) {
				head = p->next;
				prev = head;
				delete p;
				p = head;
			}
			else {
				prev->next = p->next;
				delete p;
				p = prev->next;
			}
		}
		else {
			prev = p;
			p = p->next;
		}
	}
	tail = prev;
}

int forwardList::operator[](const int &pos) {
	auto p = get(const_cast<int&>(pos));
	if (p)
		return p->data;
	else {
		cout << "下标越界!" << endl;
		clear();
		exit(0);
	}
}

ostream &operator<<(ostream &os, const forwardList &f) {
	for (Node *p = f.head; p; p = p->Next()) {
		os << p->Data() << ' ';
	}
	return os;
}

bool forwardList::operator==(forwardList &f) {
	if (size() != f.size())
		return false;
	Node *p = begin();
	Node *q = f.begin();
	while (q) {
		if (p->data != q->data)
			return false;
		p = p->next;
		q = q->Next();
	}
	return true;
}

forwardList::~forwardList() {
	clear();
}


void forwardList::MergeSort(forwardList &f1, forwardList &f2) {
	Node *i = f1.begin();
	Node *j = f2.begin();
	while (i && j) {
		if (i->data >= j->data) {
			push_back(j->data);
			j = j->next;
		}
		else {
			push_back(i->data);
			i = i->next;
		}
	}
	while (i) {
		push_back(i->data);
		i = i->next;
	}
	while (j) {
		push_back(j->data);
		j = j->next;
	}
}