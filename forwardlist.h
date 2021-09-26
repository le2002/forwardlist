#pragma once
#include <iostream>
#include "Node.h"
#include "forwardlist.h"
using namespace std;

class forwardList {
private:
	Node *head, *tail;
	// 检查 pos 是否在范围 [front, back](左闭右闭)中
	void check(const int &pos, const int &left, const int &right);
	Node* get(const int &pos) const; // 定位
public:
	forwardList(Node *p = nullptr);
	forwardList(const initializer_list<int> &ls); // 序列初始化
	forwardList(forwardList& f); // 拷贝构造
	// 用链表下标在 [left, right) （左闭右开）之间的值创建链表
	forwardList(forwardList &f, const int &left, const int &right);
	forwardList &operator = (forwardList &f); // 赋值
	int size() const; // 链表长度
	Node *begin() const; // 头指针
	Node *end() const; // 尾指针
	int front() const; // 头值
	int back() const; // 尾值
	void clear(); // 链表清空
	void push_back(const int &number); // 尾后添加元素
	void print(); // 打印链表
	Node* find(const int &number) const; // 查找
	void erase(const int &number); // 删除
	void insert_before(const int &number, const int &pos); // 将元素插入 pos 位置之前
	void insert_after(const int &number, const int &pos); // 将元素插入 pos 位置之后
	void reverse(); // 链表逆转
	bool isSorted(); // 判断是否排序
	bool isEmpty();
	void sort();
	// 删除大于等于 left, 小于 right 的值: [left, right)
	void Delete(const int &left, const int &right);
	int operator [] (const int &pos); // 随机访问
	friend ostream &operator<<(ostream &os, const forwardList &f); // 打印链表
	bool operator==(forwardList &f);
	void MergeSort(forwardList &f1, forwardList &f2); // 归并排序
	~forwardList();
};
