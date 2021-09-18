#include <iostream>
#include "Node.h"
using namespace std;

class forwardList {
private:
	Node *begin, *end;
	// 检查 pos 是否在范围 [front, back](左闭右闭)中
	void check(const int &pos, const int &left, const int &right);
	Node* loc(const int &pos); // 定位
public:
	forwardList(Node *p = nullptr) :begin(p), end(p) { ; }
	forwardList(const initializer_list<int> &ls); // 序列初始化
	forwardList(forwardList& f);
	forwardList &operator = (forwardList &f);
	int size();
	Node *Begin(); // 头指针
	Node *End(); // 尾指针
	int front(); // 头值
	int back(); // 尾值
	void push_back(const int &number); // 尾后添加元素
	void print(); // 打印链表
	Node* find(const int &i); // 查找
	void erase(const int &i); // 删除
	void insert_before(const int &i, const int &pos); // 将元素插入 pos 位置之前
	void insert_after(const int &i, const int &pos); // 将元素插入 pos 位置之后
	void reverse();
	bool isSorted();
	int operator [] (const int &pos); // 随机访问
	friend ostream & operator<<(ostream &os, const forwardList &f); // 打印链表
	~forwardList();
};
