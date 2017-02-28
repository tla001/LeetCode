/*
 * Code30.h
 *
 *  Created on: 2016年12月23日
 *      Author: tla001
 */

#ifndef INC_CODE30_H_
#define INC_CODE30_H_
#include "Include.h"

/*
 *树最小深度
 */
class Q1 {
public:
	struct TreeNode {
		TreeNode *left;
		TreeNode *right;
	};
	static void test() {
//		string str("uihsi");
//		string aa = to_string(1);
//		cout << aa << endl;
	}
	int run(TreeNode *root) {
		if (!root)
			return 0;
		int l = run(root->left);
		int r = run(root->right);
		if (l == 0 || r == 0)
			return 1 + r + l;
		return (l > r ? r : l) + 1;
	}
};
/*
 *逆波兰数计算
 */
class Q2 {
public:
	static void test() {
		vector<string> tokens= {"2", "1", "+", "3", "*"};
		cout<<evalRPN(tokens)<<endl;
	}
	static int evalRPN(vector<string> &tokens) {
		int res = 0;
		int size = tokens.size();
		stack<int> opnum;
		for (int i = 0; i < size; i++) {
			if (tokens[i] == "*") {
				int rop = opnum.top();
				opnum.pop();
				int lop = opnum.top();
				opnum.pop();
				res = lop * rop;
				opnum.push(res);
			} else if (tokens[i] == "/") {
				int rop = opnum.top();
				opnum.pop();
				int lop = opnum.top();
				opnum.pop();
				res = lop / rop;
				opnum.push(res);
			} else if (tokens[i] == "+") {
				int rop = opnum.top();
				opnum.pop();
				int lop = opnum.top();
				opnum.pop();
				res = lop + rop;
				opnum.push(res);
			} else if (tokens[i] == "-") {
				int rop = opnum.top();
				opnum.pop();
				int lop = opnum.top();
				opnum.pop();
				res = lop - rop;
				opnum.push(res);
			} else {
				opnum.push(atoi(tokens[i].c_str()));
			}
		}
		return opnum.top();
	}
};
class Q3 {
	/*
	 * 直线上点个数的最大值
	 */
public:
	struct Point {
		int x;
		int y;
		Point() :
				x(0), y(0) {
		}
		Point(int a, int b) :
				x(a), y(b) {
		}
	};
	static void test() {

	}
	static int maxPoints(vector<Point>&points) {
//		if (points.size() < 3)
//			return points.size();
//		double k = 0.0;
//		double a = 0.0;
//		//to_string(1);
//		map<pair<double, double>, int> hm;
//		int dup = 0;
//		for (int i = 0; i < points.size(); i++) {
//			for (int j = 0; j < i; j++) {
//				if (points[j].x != points[i].x) {
//					k = (double) (points[j].y - points[i].y)
//							/ (points[j].x - points[i].x);
//					a = (double) (points[i].y
//							- (points[j].y - points[i].y)
//									/ (points[j].x - points[i].x));
//				} else {
//					if (points[j].y == points[i].y) {
//						dup++;
//					} else {
//						k = 65535.0;
//						a = 0.0;
//					}
//
//				}
//
//				if (hm.find(pair<double, double>(k, a)) == hm.end()) {
//					hm.insert(make_pair(pair<double, double>(k, a), 1));
//				} else {
//					hm[pair<double, double>(k, a)]++;
//				}
//			}
//		}
//		int max = 0;
//		for (map<pair<double, double>, int>::iterator ite = hm.begin();
//				ite != hm.end(); ite++) {
//			if (ite->second > max)
//				max = ite->second;
//		}
//		return max + dup + 1;
		int size = points.size();
		if (size < 3)
			return size;

		int ret = 0;
		for (int i = 0; i < size; i++) {

			int curmax = 1;
			map<double, int> mp;
			int vcnt = 1; //垂直点
			int dup = 0; //重复点
			for (int j = i + 1; j < size; j++) {
				double x1 = points[i].x - points[j].x;
				double y1 = points[i].y - points[j].y;
				if (x1 == 0 && y1 == 0) {   //重复
					dup++;
				} else if (x1 == 0) {      //垂直
					vcnt++;
					curmax = max(vcnt, curmax);
				} else {
					double k = y1 / x1;          //斜率
					if (mp[k] == 0)
						mp[k] = 2;
					else
						mp[k]++;
					curmax = max(mp[k], curmax);
				}
			}
			ret = max(ret, curmax + dup);
		}
		return ret;
	}
};

class Q4 {
	/*
	 * 单链表排序
	 */
	/*
	 考点：
	 1. 快慢指针；2. 归并排序。
	 此题经典，需要消化吸收。
	 复杂度分析:
	 //	             T(n)            拆分 n/2, 归并 n/2 ，一共是n/2 + n/2 = n
	 //	            /    \           以下依此类推：
	 //	          T(n/2) T(n/2)      一共是 n/2*2 = n
	 //	         /    \  /     \
//	        T(n/4) ...........   一共是 n/4*4 = n

	 一共有logn层，故复杂度是 O(nlogn)
	 */
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	ListNode *sortList(ListNode *head) {
		if (!head || !head->next)
			return head;

		ListNode* p = head, *q = head->next;
		while (q && q->next) {
			p = p->next;
			q = q->next->next;
		}

		ListNode* left = sortList(p->next);
		p->next = NULL;
		ListNode* right = sortList(head);

		return merge(left, right);
	}

	ListNode *merge(ListNode *left, ListNode *right) {
		ListNode dummy(0);
		ListNode *p = &dummy;
		while (left && right) {
			if (left->val < right->val) {
				p->next = left;
				left = left->next;
			} else {
				p->next = right;
				right = right->next;
			}
			p = p->next;
		}
		if (left)
			p->next = left;
		if (right)
			p->next = right;
		return dummy.next;
	}
};

class Q5 {
public:
	static void test() {

	}
};
class Q6 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	static void test() {

	}
	void postorder(TreeNode *root, vector<int> &res) {
		if (root) {
			postorder(root->left, res);
			postorder(root->right, res);
			res.push_back(root->val);
		} else {
			return;
		}
	}
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		if (root)
			postorder(root, res);
		return res;
	}
};
class Q7 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	static void test() {

	}
	void preorder(TreeNode *root, vector<int> &res) {
		if (root) {
			res.push_back(root->val);
			preorder(root->left, res);
			preorder(root->right, res);
		} else {
			return;
		}
	}
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		if (root)
			preorder(root, res);
		return res;
	}
};
class Q8 {
public:
	typedef int Elemtype;
	struct ListNode {
		Elemtype val;
		ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	static void createList(ListNode *&head, vector<Elemtype> arr) {
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
	static void printList(ListNode *head) {
		ListNode *p = head;
		while (p) {
			cout << p->val << "\t";
			p = p->next;
		}
		cout << endl;
	}
	static void reorderList(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return;
		ListNode *p = head;
		int num = 0;
		while (p) {
			num++;
			p = p->next;
		}
		//cout << num << endl;
		int mid = (num % 2 == 1) ? ((num - 1) / 2 + 1) : (num / 2);
		p = head;
		num = 0;
		while (num++ < mid - 1) {
			p = p->next;
		}

		ListNode *shead = p->next;
		p->next = NULL;
		//printList(shead);
		p = shead->next;
		shead->next = NULL;
		while (p) {
			ListNode*tt = p->next;
			p->next = shead;
			shead = p;
			p = tt;
		}
//		printList(head);
//		cout << endl;
//		printList(shead);
//		cout << endl;
		p = head;
		//p = p->next;
		while (p && shead) {
			ListNode *tt = p->next;
			p->next = shead;
			shead = shead->next;
			p = p->next;
			p->next = tt;
			p = p->next;
		}
		p = NULL;
		//printList(head);
	}
	static void test() {
		vector<Elemtype> arr = { 1, 2, 3, 4, 5, 6 };
		ListNode *head = NULL;
		createList(head, arr);
		//printList(head);
		reorderList1(head);
		printList(head);
	}
	static void reverseList(ListNode* & head) {
		if (head == NULL)
			return;
		ListNode* p = head->next;
		ListNode* temp = NULL;
		head->next = NULL;
		while (p != NULL) {
			temp = p->next;
			p->next = head;
			head = p;
			p = temp;
		}
	}

	static void reorderList1(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return;
		ListNode *fast = head, *slow = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		//将链表从中间断开，前半段长度大于等于后半段
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		reverseList(slow);   //后半段反转
		printList(slow);
		ListNode *p1 = head, *p2 = slow, *temp = NULL;
		while (p2 != NULL) {
			temp = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p2 = temp;
			p1 = p1->next->next;
		}
	}
};
class Q9 {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL) {
			return NULL;
		}
		ListNode *p1 = head;
		ListNode *p2 = head;
		while (p2 != NULL && p2->next != NULL) {
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2) {
				break;
			}
		}
		if (p2 == NULL || p2->next == NULL)
			return NULL;
		p1 = head;
		while (p1 != p2) {
			p1 = p1->next;
			p2 = p2->next;
		}
		return p2;
	}
};
class Q10 {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	bool hasCycle(ListNode *head) {
		if (head == NULL) {
			return false;
		}
		ListNode *p1 = head;
		ListNode *p2 = head;
		while (p2 != NULL && p2->next != NULL) {
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2) {
				return true;
			}
		}
		return false;
	}
};
class Q11 {
public:
	static void test() {

	}
};
class Q12 {

	static void test() {

	}
	static bool wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> wordB(s.length() + 1, false);
		wordB[0] = true;
		for (int i = 1; i < s.length() + 1; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (wordB[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					wordB[i] = true;
					break; //只要找到一种切分方式就说明长度为i的单词可以成功切分，因此可以跳出内层循环。  
				}
			}
		}
		return wordB[s.length()];
	}
};
class Q14 {
public:
	static void test() {
		int A[] = { 2, 2, 3, 4, 5, 2, 4, 3, 3, 4 };
		int n = 10;
		cout << singleNumber(A, n) << endl;
	}
	static int singleNumber(int A[], int n) {
		stable_sort(A, A + n);
		for (int i = 0; i < n - 3; i += 3) {
			if (A[i] != A[i + 1]) {
				return A[i];
			}
		}
		return A[n - 1];
	}
};
class Q15 {
public:
	static void test() {
		int A[] = { 2, 5, 3, 4, 4, 5, 2 };
		int n = 10;
		cout << singleNumber(A, n) << endl;
	}
	static int singleNumber(int A[], int n) {
		stable_sort(A, A + n);
		for (int i = 0; i < n - 2; i += 2) {
			if (A[i] != A[i + 1]) {
				return A[i];
			}
		}
		return A[n - 1];
	}
};
class Q16 {
public:
	static void test() {

	}
	static int candy(vector<int> &ratings) {
		int n = ratings.size();
		vector<int> candy(n, 1);
		for (int i = 1; i < n; i++) {
			if (ratings[i] > ratings[i - 1]) {
				candy[i] = candy[i - 1] + 1;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]) {
				candy[i] =
						candy[i] > (candy[i + 1] + 1) ?
								candy[i] : (candy[i + 1] + 1);
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
			res += candy[i];
		return res;
	}
};
#endif /* INC_CODE30_H_ */
