/*
 * MyStack.h
 *
 *  Created on: 2017Äê2ÔÂ15ÈÕ
 *      Author: tla001
 */

#ifndef INC_MYSTACK_H_
#define INC_MYSTACK_H_
#include "Include.h"
class StackBase {
public:
	typedef int Elemtype;
	virtual Elemtype top()=0;
	virtual void push(Elemtype)=0;
	virtual void pop()=0;
	virtual int size()=0;
	virtual bool empty()=0;
};
class ArrStack: public StackBase {
public:
	ArrStack() {
		maxSize = 3;
		increment = 2;
		curnums = 0;
		baseE = new Elemtype[maxSize];
		topE = baseE;
	}
	~ArrStack() {
		delete[] baseE;
	}
	Elemtype top() {
		if (baseE == topE)
			return -1;
		return *(topE - 1);
	}
	int size() {
		return curnums;
	}
	void push(Elemtype e) {
		if (curnums >= maxSize) {
			Elemtype *temp = new Elemtype[maxSize + increment];
			memcpy(temp, baseE, curnums * sizeof(Elemtype));
			delete[] baseE;
			baseE = temp;
//			for (int i = 0; i < curnums; i++)
//				cout << baseE[i] << " ";
//			cout << endl;
			topE = baseE + curnums;
			maxSize += increment;
		}
		*topE++ = e;
		curnums++;
	}
	void pop() {
		if (baseE == topE)
			return;
		topE--;
		curnums--;
	}
	bool empty() {
		if (curnums == 0)
			return true;
		else if (curnums > 0)
			return false;
		return false;
	}
private:
	int maxSize;
	int curnums;
	int increment;
	Elemtype *baseE;
	Elemtype *topE;

public:
	static void test() {
		ArrStack a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.push(4);
		cout << "size: " << a.size() << endl;
		while (!a.empty()) {
			cout << a.top() << " ";
			a.pop();
		}
		cout << endl;
		cout << "size: " << a.size() << endl;
	}
};
class ListStack: public StackBase {
public:
	struct ListNode {
		Elemtype val;
		ListNode *next;
		ListNode(Elemtype e) :
				val(e), next(NULL) {
		}
	};
	ListStack() {
		topE = NULL;
		curnums = 0;
	}
	~ListStack() {

	}
	Elemtype top() {
		if (topE == NULL)
			return -1;
		return topE->val;
	}
	void push(Elemtype e) {
		ListNode *tem = new ListNode(e);
		tem->next = topE;
		topE = tem;
		curnums++;
	}
	void pop() {
		if (curnums == 0)
			return;
		ListNode *tem = topE;
		topE = topE->next;
		delete tem;
		curnums--;
	}
	int size() {
		return curnums;
	}
	bool empty() {
		if (curnums == 0)
			return true;
		else if (curnums > 0)
			return false;
		return false;
	}
private:
	int curnums;
	ListNode *topE;
public:
	static void test() {
		ListStack a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.push(4);
		cout << "size: " << a.size() << endl;
		while (!a.empty()) {
			cout << a.top() << " ";
			a.pop();
		}
		cout << endl;
		cout << "size: " << a.size() << endl;
	}
};
#endif /* INC_MYSTACK_H_ */
