#include "forwardlist.h"

void forwardList::check(const int &pos, const int &left, const int &right) {
	if (pos < left || pos > right) {
		cout << "位置越界";
	}
}

forwardList::forwardList(const initializer_list<int> &ls) {
	auto it = ls.begin();
	do {
		push_back(*it);
		it++;
	} while (it != ls.end());
}

forwardList::forwardList(forwardList& f) {
	begin = end = nullptr;
	for (int i = 0; i != f.size(); i++)
		push_back(f[i]);
}

forwardList &forwardList::operator=(forwardList &f) {
	//cout << "operator=" << endl;
	this->~forwardList();
	begin = end = nullptr;
	for (int i = 0; i != f.size(); i++)
		push_back(f[i]);
	return *this;
}

int forwardList::size() {
	int size = 0;
	Node *p = begin;
	while (p) {
		p = p->next;
		size++;
	}
	return size;
}

Node *forwardList::Begin() {
	return begin;
}

Node *forwardList::End() {
	return end;
}

int forwardList::front() {
	return Begin()->data;
}

int forwardList::back() {
	return End()->data;
}

void forwardList::push_back(const int &number) {

	Node *p = new Node;
	p->data = number;
	p->next = nullptr;
	if (end) {
		end->next = p;
		end = end->next;
	}
	else {
		begin = end = p;
	}
}

void forwardList::print() {
	cout << *this << endl;
}

Node* forwardList::find(const int &i) {
	Node *p = begin;
	while (p) {
		if (p->data == i)
			break;
		p = p->next;
	}
	return p;
}

void forwardList::erase(const int &i) {
	Node *p = find(i);
	Node *p_prev = p;

	if (p == begin)
	{
		begin = p->next;
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
	}
	else
		cout << "Sorry, not found!" << endl;

}

void forwardList::insert_before(const int &number, const int &pos) {
	Node *p = loc(pos);

	if (p) {

		if (p == begin) {
			Node *temp = new Node;
			temp->data = number;
			temp->next = begin;
			begin = temp;
		}
		else {
			Node *p_prev = begin;
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
	}
}

void forwardList::insert_after(const int &number, const int &pos) {
	auto p = loc(pos);
	if (p) {
		Node *temp = new Node;
		temp->data = number;
		temp->next = p->next;
		p->next = temp;
		if (temp->next == nullptr) {
			end = temp;
		}
	}
	else {
		cout << "Sorry, can't insert!" << endl;
	}
}

void forwardList::reverse() {
	Node *p_prev = nullptr;
	Node *p = begin->next;
	begin->next = nullptr;
	while (p != nullptr) {
		p_prev = p;
		p = p->next;
		p_prev->next = begin->next;
		begin->next = p_prev;
	}
}

bool forwardList::isSorted() {
	for (Node *p = Begin(); p != End(); p = p->next) {
		if (p->data > p->next->data)
			return false;
	}
	return true;
}

Node *forwardList::loc(const int &pos) {
	Node *p = begin;
	int j = 0;
	while (p && j < pos) {
		p = p->next;
		j++;
	}
	return p;
}

int forwardList::operator[](const int &pos) {
	auto p = loc(const_cast<int&>(pos));
	return p->data;
}

ostream &operator<<(ostream &os, const forwardList &f) {
	for (Node *p = f.begin; p; p = p->next) {
		os << p->data << ' ';
	}
	return os;
}

forwardList::~forwardList() {
	//cout << "~forwardList()" << endl;
	for (Node *p = begin; begin != nullptr; p = begin) {
		begin = p->next;
		delete p;
	}
	begin = end = nullptr;
}
