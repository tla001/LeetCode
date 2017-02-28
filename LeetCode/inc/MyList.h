/*
 * MyList.h
 *
 *  Created on: 2017��1��10��
 *      Author: tla001
 */

#ifndef MYLIST_H_
#define MYLIST_H_
#include <iostream>

using namespace std;

class MyListH {
	/*
	 * ����ͷ���
	 * ��Ԫ�ذ�1��
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
	 * ��ӡ��Ϣ
	 */
	void printLog(string info, int status) {
		cout << info << endl;
		exit(status);
	}
	/*
	 * ��ʼ��ͷ���
	 */
	ListNode * initHead() {
		ListNode *head = new ListNode(0);
		return head;
	}
	/*
	 * ��������
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
	 * ��ӡ����
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
	 * ��posλ�ò���һ���ڵ�
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
	 * ɾ��posλ�õĽڵ㣬��������Ԫ��ֵ
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
	 * �ϲ����� ����
	 * Ҫ�������������������
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
	 * ������ͷ���
	 * ��Ԫ�ذ�1��
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
	 * ��ӡ��Ϣ
	 */
	void printLog(string info, int status) {
		cout << info << endl;
		exit(status);
	}
	/*
	 * ��������
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
	 * ��ӡ����
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
	 * ��posλ�ò���һ���ڵ�
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
	 * ɾ��posλ�õĽڵ㣬��������Ԫ��ֵ
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
	 * �ϲ����� ����
	 * Ҫ�������������������
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
	 * ��������
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
	 * ����һ�������һ��ֵx����дһ���������Ը��������������Ա�����С��x�Ľڵ�
	 * �������ڴ��ڻ����x�Ľڵ��ǰ��
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
	 * ����һ��������дһ�������������������м��
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
	 * �ҵ�һ�����������У��������һ��Ԫ��Ϊk���Ǹ�Ԫ�ء�
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
	 * ����һ�����ܰ�������������дһ�����������ػ���ʼ�Ľڵ㡣�����������������NULL
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
	 * ����һ������������ת����k��λ��
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
	 * ��������ת���ҷ����µ�����ͷ
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
	 * ����һ����������ÿ�������ڵĽڵ㲢����������ͷ
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
	 * �������������������дһ���������ϲ��������������ҷ���һ���µ���������
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
