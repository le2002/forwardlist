#pragma once
#include "forwardlist.h"

class Node {
	friend class forwardList;
private:
	int data;
	class Node *next;
public:
	int Data() const {
		return data;
	}
	Node *Next() const {
		return next;
	}
};
