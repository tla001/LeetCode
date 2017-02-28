/*
 * MyQueue.h
 *
 *  Created on: 2017Äê2ÔÂ20ÈÕ
 *      Author: tla001
 */

#ifndef INC_MYQUEUE_H_
#define INC_MYQUEUE_H_
#include "Include.h"

class BaseQueue {
public:
	typedef int Elemtype;
	virtual Elemtype front()=0;
	virtual void push(Elemtype)=0;
	virtual void pop()=0;
	virtual int size()=0;
	virtual bool empty()=0;
};
class ArrQueue: public BaseQueue {
public:
	ArrQueue() {
		maxSize = 5;
		curnums = 0;
		elems = new Elemtype[maxSize];
		frontIndex = tailIndex = 0;
	}
	~ArrQueue() {
		delete[] elems;
	}
	Elemtype front() {
		if (empty())
			return -1;
		return elems[frontIndex % maxSize];
	}
	void push(Elemtype e) {
		if (frontIndex == (tailIndex + 1) % maxSize)
			return;
		elems[tailIndex] = e;
		tailIndex = (tailIndex + 1) % maxSize;
		curnums++;
	}
	void pop() {
		if (empty())
			return;
		frontIndex = (frontIndex + 1) % maxSize;
		curnums--;
	}
	int size() {
		return curnums;
	}
	bool empty() {
		if (frontIndex == tailIndex)
			return true;
		else
			return false;
	}
private:
	Elemtype *elems;
	int maxSize;
	int curnums;
	int frontIndex;
	int tailIndex;
public:
	static void test() {
		ArrQueue a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.push(4);
		cout << "size: " << a.size() << endl;
		while (!a.empty()) {
			cout << a.front() << " ";
			a.pop();
		}
		cout << endl;
		cout << "size: " << a.size() << endl;
	}
};
class ListQueue: public BaseQueue {
public:
	struct ListNode {
		Elemtype val;
		ListNode *next;
		ListNode(Elemtype e) :
				val(e), next(NULL) {
		}
	};
	ListQueue() {
		head = NULL;
		tail = NULL;
		curnums = 0;
	}
	~ListQueue() {
		while (head) {
			ListNode *node = head;
			head = head->next;
			delete node;
		}
	}
	Elemtype front() {
		if (head == NULL)
			return -1;
		return head->val;
	}
	void push(Elemtype e) {
		ListNode *node = new ListNode(e);
		if (head == NULL) {
			head = node;
			tail = head;
		} else {
			tail->next = node;
			tail = tail->next;
		}
		curnums++;
	}
	void pop() {
		if (head == NULL)
			return;
		ListNode *node = head;
		head = head->next;
		delete node;
		curnums--;
	}
	int size() {
		return curnums;
	}
	bool empty() {
		if (head == NULL)
			return true;
		else
			return false;
	}
private:
	ListNode *head;
	ListNode *tail;
	int curnums;

public:
	static void test() {
		ListQueue a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.push(4);
		cout << "size: " << a.size() << endl;
		while (!a.empty()) {
			cout << a.front() << " ";
			a.pop();
		}
		cout << endl;
		a.push(4);
		cout << "size: " << a.size() << endl;
	}
};
#endif /* INC_MYQUEUE_H_ */
