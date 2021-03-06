/*
 * Code30.h
 *
 *  Created on: 2016年12月23日
 *      Author: tla001
 */

#ifndef INC_PAGE1_H_
#define INC_PAGE1_H_
#include "Include.h"

namespace LeetCode {
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
class nini {
public:
	static void merge(vector<int>&nums1, int m, vector<int>&nums2, int n) {
		int index1 = 0;
		int index2 = 0;
		int index = 0;
		while (index1 < n && index2 < n) {
			if (nums1[index] <= nums2[index2]) {
				index1++;
				index++;
			} else {
				nums1.insert(nums1.begin() + index, nums2[index2++]);
				index++;
			}
		}
		while (index2 < n) {
			nums1.insert(nums1.begin() + index - 1, nums2[index2++]);
			index++;
		}
	}
	static void test() {
		int m = 3;
		int n = 4;
		vector<int> nums1(m + n + 1, 0);
		vector<int> nums2(n, 0);
		for (int i = 0; i < m; i++) {
			nums1[i] = i + 1;
		}
		for (int i = 0; i < m; i++) {
			cout << nums1[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			nums2[i] = i + 2;
		}
		for (int i = 0; i < n; i++) {
			cout << nums2[i] << " ";
		}
		cout << endl;
		merge(nums1, m, nums2, n);
		for (int i = 0; i < m + n; i++) {
			cout << nums1[i] << " ";
		}
		cout << endl;
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
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	static ListNode * createList(vector<int> arr) {
		ListNode *head = new ListNode(arr[0]);
		ListNode *p = head;
		for (int i = 1; i < arr.size(); i++) {
			ListNode *node = new ListNode(arr[i]);
			p->next = node;
			p = p->next;
		}
		return head;
	}
	static void printList(ListNode *list) {
		while (list) {
			cout << list->val << " ";
			list = list->next;
		}
		cout << endl;
	}
	static ListNode *insertSort(ListNode *head) {
		if (!head || !head->next)
			return head;
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *cur = head->next;
		ListNode *pre = NULL;
		ListNode *next = NULL;
		head->next = NULL;
		while (cur) {
			pre = dummy;
			next = cur->next;
			while (pre->next && pre->next->val < cur->val) {
				pre = pre->next;
			}
			cur->next = pre->next;
			pre->next = cur;
			cur = next;
		}
		head = dummy->next;
		delete dummy;
		return head;

	}
	static void test() {
		vector<int> arr = { 12, 2, 3, 20, 5, 6, 4 };
		ListNode *list = createList(arr);
		printList(list);
		ListNode *list1 = insertSort(list);
		printList(list1);
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
	static void reorderList1(ListNode *head) {
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
	static void reorderList2(ListNode *head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return;
		queue<ListNode *> q;
		ListNode *slower = head;
		q.push(slower);
		ListNode *faster = head;
		while (faster->next && faster->next->next) {
			slower = slower->next;
			faster = faster->next->next;
			q.push(slower);
		}
		slower = slower->next;
		stack<ListNode *> s;
		while (slower) {
			s.push(slower);
			slower = slower->next;
		}
//		while (!q.empty()) {
//			cout << q.front()->val << " ";
//			q.pop();
//		}
//		cout << endl;
//		while (!s.empty()) {
//			cout << s.top()->val << " ";
//			s.pop();
//		}
//		cout << endl;
////		return;
		head = q.front();
		q.pop();
		ListNode *p = head;
		while (!s.empty()) {
			p->next = s.top();
			s.pop();
			p = p->next;
//			if (!q.empty()) {
//				p->next = q.front();
//				q.pop();
//				p = p->next;
//			} else {
//				break;
//			}
		}

//		while (!q.empty()) {
//			p->next = q.front();
//			q.pop();
//			p = p->next;
//		}
	}
	static void test() {
		vector<Elemtype> arr = { 1, 2, 3, 4, 5, 6 };
		ListNode *head = NULL;
		createList(head, arr);
		//printList(head);
		reorderList(head);
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

	static void reorderList(ListNode *head) {
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
class Q13 {
public:
	struct RandomListNode {
		int label;
		struct RandomListNode*next, *random;
		RandomListNode(int x) :
				label(x), next(NULL), random(NULL) {
		}
	};
	RandomListNode *Clone(RandomListNode *pHead) {
		if (pHead == NULL)
			return NULL;
		RandomListNode *cur = pHead;
		while (cur) {
			RandomListNode *temp = new RandomListNode(cur->label);
			temp->next = cur->next;
			cur->next = temp;
			cur = temp->next;
		}
		cur = pHead;
		while (cur) {
			if (cur->random != NULL)
				cur->next->random = cur->random->next;
			cur = cur->next->next;
		}

		RandomListNode *node = NULL;
		cur = pHead;
		RandomListNode *newHead = pHead->next;
		while (cur->next) {
			node = cur->next;
			cur->next = cur->next->next;
			cur = node;
		}
		return newHead;
	}
};
class Q14 {
public:
	static void test() {
		int A[] = { 2, 2, 3, 4, 5, 2, 4, 3, 3, 4 };
		int n = 10;
		cout << singleNumber(A, n) << endl;
	}
	static int singleNumber1(int A[], int n) {
		stable_sort(A, A + n);
		for (int i = 0; i < n - 3; i += 3) {
			if (A[i] != A[i + 1]) {
				return A[i];
			}
		}
		return A[n - 1];
	}
	static int singleNumber(int A[], int n) {
		int ones = 0;
		int twos = 0;
		int threes;
		for (int i = 0; i < n; i++) {
			int t = A[i];
			twos |= ones & t; //要在更新one之前更新two
			ones ^= t;
			threes = ones & twos;
			ones &= ~threes;
			twos &= ~threes;
		}
		return ones;
	}
};
class Q15 {
public:
	static void test() {
		int A[] = { 2, 5, 3, 4, 4, 5, 2 };
		int n = 7;
		cout << "res= ";
		cout << singleNumber(A, n) << endl;
	}
	static int singleNumber1(int A[], int n) {
		stable_sort(A, A + n);
		for (int i = 0; i < n - 2; i += 2) {
			if (A[i] != A[i + 1]) {
				return A[i];
			}
		}
		return A[n - 1];
	}
	static int singleNumber(int A[], int n) {
		int res = A[0];
		for (int i = 1; i < n; i++) {
			res ^= A[i];
		}
		return res;
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
class Q17 {
	/*
	 * gas-station
	 */
public:
	static int canCompleteCircuit(vector<int>&gas, vector<int>&cost) {
		if (gas.size() != cost.size() || gas.size() == 0 || cost.size() == 0)
			return -1;
//		vector<int> diff;
//		int total = 0;
//		for (int i = 0; i < gas.size(); i++) {
//			int di = gas[i] - cost[i];
//			total += di;
//			diff.push_back(di);
//		}
//		if (total < 0)
//			return -1;
//		int index = 0;
//		int cur = 0;
//		while (diff[cur] < 0) {
//			cur++;
//		}
//		index = cur;
//		total = 0;
//		while (cur % gas.size() != index) {
//			total += diff[cur];
//			if (total < 0) {
//				total -= diff[index];
//				index++;
//				while (index < cur && diff[index] < 0 || total < 0) {
//					total -= diff[index];
//					index++;
//				}
//			}
//			cur++;
//		}
//		return index;
		int total = 0, sum = 0;
		int index = -1;
		for (int i = 0; i < gas.size(); i++) {
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0) {
				sum = 0;
				index = i;
			}
		}
		return total >= 0 ? index + 1 : -1;
	}
	static void test() {

	}
};
class Q18 {
public:
	struct UndirectedGraphNode {
		int label;
		vector<UndirectedGraphNode*> neigthbors;
		UndirectedGraphNode(int x) :
				label(x) {
		}
	};
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node)
			return node;
		if (hash.find(node) == hash.end()) {
			hash[node] = new UndirectedGraphNode(node->label);
			for (auto x : node->neigthbors) {
				(hash[node]->neigthbors).push_back(cloneGraph(x));
			}
		}
		return hash[node];
	}
};
class Q19 {
public:
	bool isPalindrome(string s, int left, int right) {
		int i, j;
		for (i = left, j = right; i < j; i++, j--) {
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
	int minCut(string s) {
		int len = s.size();
		if (len < 2)
			return 0;
		vector<int> dp(len, 0);
		for (int i = 1; i < len; i++) {
			if (isPalindrome(s, 0, i)) {
				dp[i] = 0;
			} else {
				dp[i] = i;
			}
		}
		for (int i = 1; i < len; i++) {
			for (int j = 1; j < i; j++) {
				if (isPalindrome(s, j, i)) {
					dp[i] = min(dp[i], dp[j - 1] + 1);
				} else {
					dp[i] = min(dp[i], dp[i - 1] + 1);
				}
			}
		}

		return dp[len - 1];
	}
};
class Q20 {
public:
	vector<vector<string>> res;
	vector<string> tmp;
	bool isPalindrome(string s) {
		bool flag = true;
		int left = 0;
		int right = s.size() - 1;
		while (left <= right) {
			if (s[left] != s[right]) {
				flag = false;
				break;
			}
			left++;
			right--;
		}
		return flag;
	}
	void dfs(string s, int pos) {
		if (pos >= s.size()) {
			res.push_back(tmp);
		}
		for (int i = 1; i <= s.size() - pos; i++) {
			string sub = s.substr(pos, i);
			if (isPalindrome(sub)) {
				tmp.push_back(sub);
				dfs(s, pos + i);
				tmp.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		dfs(s, 0);
		return res;
	}
};
class GetLongest {
public:
	static int testTwoSides(string &s, int low, int up) {
		int n = s.length();
		int max = 0;
		if (low == up) {
			low--;
			up++;
			max = 1;
		}
		while (low >= 0 && up < n && s[low] == s[up]) {
			max += 2;
			low--;
			up++;
		}
		return max;
	}
	static string longestPalindrome(string s) {
		int n = s.length();
		int subStartPoint = 0;
		int maxLength = 1;
		int temp = 0;
		for (int i = 0; i < n; i++) {
			temp = testTwoSides(s, i, i);
			if (temp > maxLength) {
				subStartPoint = i - temp / 2;
				maxLength = temp;
			}
		}
		for (int i = 1; i < n; i++) {
			temp = testTwoSides(s, i - 1, i);
			if (temp > maxLength) {
				subStartPoint = i - temp / 2;
				maxLength = temp;
			}
		}
		return s.substr(subStartPoint, maxLength);
	}
};
}
#endif /* INC_PAGE1_H_ */
