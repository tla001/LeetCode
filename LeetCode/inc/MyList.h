/*
 * MyList.h
 *
 *  Created on: 2017年1月10日
 *      Author: tla001
 */

#ifndef MYLIST_H_
#define MYLIST_H_
#include <iostream>

using namespace std;

class MyListH {
	/*
	 * 存在头结点
	 * 首元素按1计
	 */
public:
	typedef int Elemtype;
	struct ListNode {
		Elemtype val;
		ListNode *next;
		ListNode(Elemtype x) :
				val(x), next(NULL) {
		}
	};
	/*
	 * 打印信息
	 */
	void printLog(string info, int status) {
		cout << info << endl;
		exit(status);
	}
	/*
	 * 初始化头结点
	 */
	ListNode * initHead() {
		ListNode *head = new ListNode(0);
		return head;
	}
	/*
	 * 创建链表
	 */
	void createList(ListNode *&head, vector<Elemtype> arr) {
		if (head == NULL)
			head = initHead();
		ListNode *p1 = head;
		ListNode *p2;
		for (int i = 0; i < arr.size(); i++) {
			p2 = new ListNode(arr[i]);
			p1->next = p2;
			p1 = p1->next;
		}
	}
	/*
	 * 打印链表
	 */
	void printList(ListNode *head) {
		ListNode *p = head->next;
		while (p) {
			cout << p->val << "\t";
			p = p->next;
		}
		cout << endl;
	}
	/*
	 * 在pos位置插入一个节点
	 */
	void insertList(ListNode *&head, Elemtype e, int pos) {
		if (head == NULL)
			return;
		ListNode *p1, *p2 = head;
		int i = 0;
		while (p2 && i < pos - 1) {
			i++;
			p2 = p2->next;
		}
		if (!p2->next || i > pos - 1)
			printLog("pos error", -1);
		p1 = new ListNode(e);
		p1->next = p2->next;
		p2->next = p1;
	}
	/*
	 * 删除pos位置的节点，并返回其元素值
	 */
	Elemtype deleteList(ListNode *&head, int pos) {
		if (head == NULL)
			return NULL;
		ListNode *p1, *p2 = head;
		int i = 0;
		while (p2 && i < pos - 1) {
			i++;
			p2 = p2->next;
		}
		if (!p2 || i > pos - 1)
			printLog("pos error", -1);
		p1 = p2->next;
		p2->next = p1->next;
		Elemtype res = p1->val;
		delete p1;
		return res;
	}
	/*
	 * 合并排序 升序
	 * 要求：输入的两个序列有序
	 */
	void mergeSort(ListNode *&head1, ListNode*&head2, ListNode *&res) {
		if (head1 == NULL && head2 == NULL)
			return;
		ListNode *p1 = head1->next, *p2 = head2->next, *p3;
		if (res == NULL)
			res = initHead();
		p3 = res;
		while (p1 && p2) {
			if (p1->val < p2->val) {
				p3->next = p1;
				p3 = p3->next;
				p1 = p1->next;
			} else {
				p3->next = p2;
				p3 = p3->next;
				p2 = p2->next;
			}
		}
		while (p1) {
			p3->next = p1;
			p3 = p3->next;
			p1 = p1->next;
		}
		while (p2) {
			p3->next = p2;
			p3 = p3->next;
			p2 = p2->next;
		}
		delete head1;
		delete head2;
	}
	void reverseList(ListNode *head) {
		if (!head)
			return;
		ListNode *p1 = head->next, *p2 = NULL;
		head->next = NULL;
		while (p1) {
			p2 = p1->next;
			p1->next = head->next;
			head->next = p1;
			p1 = p2;
		}
	}
	static void test() {
		MyListH t;
		ListNode *head = NULL;
		vector<Elemtype> arr = { 5, 6, 8, 7, 4, 2 };

		t.createList(head, arr);
		t.printList(head);
		t.insertList(head, 9, 2);
		t.printList(head);
		t.deleteList(head, 1);
		t.printList(head);
		t.reverseList(head);
		t.printList(head);

//		ListNode *head1 = NULL;
//		ListNode *head2 = NULL;
//		ListNode *head3 = NULL;
//		vector<Elemtype> arr1 = { 5, 6, 8, 7, 4, 2 };
//		vector<Elemtype> arr2 = { 6, 8, 7, 4, 2 };
//		t.createList(head1, arr1);
//		t.createList(head2, arr2);
//		t.mergeSort(head1, head2, head3);
//		t.printList(head3);
	}
};
class MyList {
	/*
	 * 不存在头结点
	 * 首元素按1计
	 */
public:
	typedef int Elemtype;
	struct ListNode {
		Elemtype val;
		ListNode *next;
		ListNode(Elemtype x) :
				val(x), next(NULL) {
		}
	};
	/*
	 * 打印信息
	 */
	void printLog(string info, int status) {
		cout << info << endl;
		exit(status);
	}
	/*
	 * 创建链表
	 */
	void createList(ListNode *&head, vector<Elemtype> arr) {
		if (head == NULL)
			head = new ListNode(arr[0]);
		ListNode *p1 = head;
		ListNode *p2;
		for (int i = 1; i < arr.size(); i++) {
			p2 = new ListNode(arr[i]);
			p1->next = p2;
			p1 = p1->next;
		}
	}
	/*
	 * 打印链表
	 */
	void printList(ListNode *head) {
		ListNode *p = head;
		while (p) {
			cout << p->val << "\t";
			p = p->next;
		}
		cout << endl;
	}
	/*
	 * 在pos位置插入一个节点
	 */
	void insertList(ListNode *&head, Elemtype e, int pos) {
		if (head == NULL)
			return;
		if (pos == 1) {
			ListNode *p = new ListNode(e);
			p->next = head;
			head = p;
		} else {
			ListNode *p1, *p2 = head;
			int i = 1;
			while (p2 && i < pos - 1) {
				i++;
				p2 = p2->next;
			}
			if (!p2->next || i > pos - 1)
				printLog("pos error", -1);
			p1 = new ListNode(e);
			p1->next = p2->next;
			p2->next = p1;
		}

	}
	/*
	 * 删除pos位置的节点，并返回其元素值
	 */
	Elemtype deleteList(ListNode *&head, int pos) {
		if (head == NULL)
			return NULL;
		if (pos == 1) {
			ListNode *p = head;
			head = p->next;
			Elemtype res = p->val;
			delete p;
			return res;
		} else {
			ListNode *p1, *p2 = head;
			int i = 1;
			while (p2 && i < pos - 1) {
				i++;
				p2 = p2->next;
			}
			if (!p2 || i > pos - 1)
				printLog("pos error", -1);
			p1 = p2->next;
			p2->next = p1->next;
			Elemtype res = p1->val;
			delete p1;
			return res;
		}

	}
	/*
	 * 合并排序 升序
	 * 要求：输入的两个序列有序
	 */
	void mergeSort(ListNode *&head1, ListNode*&head2, ListNode *&res) {
		if (head1 == NULL && head2 == NULL)
			return;
		ListNode *p1 = head1, *p2 = head2, *p3;
		if (res == NULL)
			res = new ListNode(0);
		p3 = res;
		while (p1 && p2) {
			if (p1->val < p2->val) {
				p3->next = p1;
				p3 = p3->next;
				p1 = p1->next;
			} else {
				p3->next = p2;
				p3 = p3->next;
				p2 = p2->next;
			}
		}
		while (p1) {
			p3->next = p1;
			p3 = p3->next;
			p1 = p1->next;
		}
		while (p2) {
			p3->next = p2;
			p3 = p3->next;
			p2 = p2->next;
		}
		p1 = res;
		res = res->next;
		delete p1;
	}
	void reverseList(ListNode *&head) {
		if (!head)
			return;
		ListNode *p1 = head->next, *p2 = NULL;
		head->next = NULL;
		while (p1) {
			p2 = p1->next;
			p1->next = head;
			head = p1;
			p1 = p2;
		}
	}
	/*
	 * 插入排序
	 */
	ListNode *insertSort(ListNode *head) {
		if (!head || !head->next)
			return head;
		ListNode *cur = head;
		ListNode *nhead = new ListNode(0);
		ListNode *ncur = nhead->next;
		ListNode *pre = NULL, *temp = NULL;
		while (cur != NULL) {
			temp = cur;
			for (ncur = nhead->next; ncur != NULL; ncur = ncur->next)
				cur = cur->next;
		}
	}
	static void test() {
		MyList t;
		ListNode *head = NULL;
		vector<Elemtype> arr = { 5, 6, 8, 7, 4, 2 };

		t.createList(head, arr);
		t.printList(head);
		t.insertList(head, 9, 2);
		t.printList(head);
		t.deleteList(head, 1);
		t.printList(head);
		t.reverseList(head);
		t.printList(head);

//		ListNode *head1 = NULL;
//		ListNode *head2 = NULL;
//		ListNode *head3 = NULL;
//		vector<Elemtype> arr1 = { 5, 6, 8, 7, 4, 2 };
//		vector<Elemtype> arr2 = { 6, 8, 7, 4, 2 };
//		t.createList(head1, arr1);
//		t.createList(head2, arr2);
//		t.mergeSort(head1, head2, head3);
//		t.printList(head3);
	}
};
class ListProblems: public MyList {
public:
	/*
	 * 给定一个链表和一个值x，编写一个函数，对该链表重新排序，以便所有小于x的节点
	 * 都出现在大于或等于x的节点的前面
	 */
	ListNode *reorderList(ListNode *head, int x) {
		ListNode *newHead = NULL;
		ListNode *aDummy = new ListNode(0);
		ListNode *aCurr = aDummy;
		ListNode *bDummy = new ListNode(0);
		ListNode *bCurr = bDummy;

		while (head) {
			ListNode *next = head->next;
			head->next = NULL;
			if (head->val < x) {
				aCurr->next = head;
				aCurr = head;
			} else {
				bCurr->next = head;
				bCurr = head;
			}
			head = next;
			aCurr->next = bDummy->next;
			newHead = aDummy->next;
			delete aDummy;
			delete bDummy;

			return newHead;
		}
	}

	/*
	 * 给定一个链表，编写一个函数返回这个链表的中间点
	 */
	ListNode *midpoint(ListNode *head) {
		ListNode *chaser = head, *runner = head;
		if (head == NULL)
			return NULL;
		while (runner->next && runner->next->next) {
			runner = runner->next->next;
			chaser = chaser->next;
		}
		return chaser;
	}

	/*
	 * 找到一个单项链表中，距离最后一个元素为k的那个元素。
	 */
	ListNode *findkthtoLast(ListNode *head, int k) {
		ListNode *runner = head;
		ListNode *chaser = head;

		if (head == NULL || k < 0)
			return NULL;
		for (int i = 0; i < k; i++)
			runner = runner->next;
		if (runner == NULL)
			return NULL;
		while (runner->next) {
			runner = runner->next;
			chaser = chaser->next;
		}
		return chaser;
	}

	/*
	 * 给定一个可能包含环的链表，编写一个函数来返回环开始的节点。如果不包含环，返回NULL
	 */
	ListNode *findLoop(ListNode *head) {
		if (head == NULL)
			return NULL;
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				break;
		}
		if (fast == NULL || fast->next == NULL)
			return NULL;
		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}

	/*
	 * 给定一个链表，向右旋转链表k个位置
	 */
	ListNode *rotateRight(ListNode *head, int k) {
		int len = 1;
		ListNode *cur = head;
		if (head == NULL)
			return NULL;
		while (cur->next) {
			len++;
			cur = cur->next;
		}
		k = k % len;
		if (k == 0)
			return head;
		cur->next = head;
		cur = head;
		for (int i = 0; i < len - k - 1; i++) {
			cur = cur->next;
		}
		ListNode * const newTail = cur;
		ListNode * const newHead = cur->next;
		newTail->next = NULL;
		return newHead;
	}

	/*
	 * 将链表逆转并且返回新的链表头
	 */
	ListNode *reserseLinkedList(ListNode *head) {
		ListNode *prev = NULL;
		ListNode *next = NULL;
		while (head) {
			next = head->next;
			head->next = prev;

			prev = head;
			head = next;
		}
		return prev;
	}

	/*
	 * 给定一个链表，交换每两个相邻的节点并返回其链表头
	 */
	ListNode *swapPairs(ListNode *head) {
		if (head == NULL)
			return head;
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *prev = dummy;
		ListNode *node1 = head, *node2 = head->next;
		ListNode *newHead = NULL;

		while (node1 && node1->next) {
			node2 = node1->next;
			prev->next = node2;
			node1->next = node2->next;
			node2->next = node1;

			prev = node1;
			node1 = prev->next;
		}

		newHead = dummy->next;
		delete dummy;
		return newHead;
	}

	/*
	 * 给定两个有序的链表，编写一个函数来合并这两个链表，并且返回一个新的有序链表
	 */
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *dummy = new ListNode(0);
		ListNode *cur = dummy;
		ListNode *newHead = NULL;

		while (l1 && l2) {
			if (l1->val <= l2->val) {
				cur->next = l1;
				l1 = l1->next;
			} else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if (l1)
			cur->next = l1;
		else
			cur->next = l2;
		newHead = dummy->next;
		delete dummy;
		return newHead;
	}

	/*
	 * given input(7->1->6)+(5->9->2),output 2->1->9
	 */
	ListNode *addList(ListNode *l1, ListNode *l2) {
		int carry = 0;
		ListNode *dummy = new ListNode(0);
		ListNode *curr = dummy;
		ListNode *newHead = NULL;

		while (l1 && l2) {
			int sum = l1->val + l2->val + carry;
			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode *rest = l1 ? l1 : l2;
		while (rest) {
			int sum = rest->val + carry;
			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
			rest = rest->next;
		}
		if (carry)
			curr->next = new ListNode(carry);
		newHead = dummy->next;
		delete dummy;
		return newHead;
	}
};
#endif /* MYLIST_H_ */
