/*
 * Offer66.h
 *
 *  Created on: 2017��2��13��
 *      Author: tla001
 */

#ifndef INC_OFFER66_H_
#define INC_OFFER66_H_
#include "Include.h"
class QO1 {
public:
	bool Find(vector<vector<int> > array, int target) {
		int row = array.size();
		int col = array[0].size();
		for (int i = row - 1, j = 0; i >= 0 && j < col;) {
			if (target == array[i][j]) {
				return true;
			} else if (target < array[i][j]) {
				i--;
			} else {
				j++;
			}
		}
	}
};
class QO2 {
public:
	void replaceSpace(char *str, int length) {
		int oldlength = 0;
		int newlength = 0;
		int spacenum = 0;
		int i = 0;
		while (str[i] != '\0') {
			oldlength++;
			if (str[i] == ' ')
				spacenum++;
			i++;
		}
		newlength = oldlength + 2 * spacenum;
		if (newlength > length)
			return;
		for (; oldlength >= 0; oldlength--) {
			if (str[oldlength] == ' ') {
				str[newlength--] = '0';
				str[newlength--] = '2';
				str[newlength--] = '%';
			} else {
				str[newlength--] = str[oldlength];
			}
		}
	}
};
class QO3 {
public:
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	vector<int> printListFromTailToHead(ListNode *head) {
		vector<int> vec;
		if (head == NULL)
			return vec;
		stack<int> stack;
		ListNode *temp = head;
		while (temp) {
			stack.push(temp->val);
			temp = temp->next;
		}
		while (!stack.empty()) {
			vec.push_back(stack.top());
			stack.pop();
		}
		return vec;
	}
};
class QO4 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {

		}
	};
	TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> in) {
		TreeNode *tree = new TreeNode(pre[0]);
		int index = 0;
		for (; index < pre.size(); index++) {
			if (in[index] == pre[0]) {
				break;
			}
		}
		vector<int> inL(in.begin(), in.begin() + index);
		vector<int> inR(in.begin() + index + 1, in.end());
		vector<int> preL(pre.begin() + 1, pre.begin() + index + 1);
		vector<int> preR(pre.begin() + index + 1, pre.end());

		if (index == 0)
			tree->left = NULL;
		else
			tree->left = reConstructBinaryTree(preL, inL);
		if (preR.size() == 0)
			tree->right = NULL;
		else
			tree->right = reConstructBinaryTree(preR, inR);
		return tree;
	}
};
class QO5 {
public:
	void push(int node) {
		stack1.push(node);
	}
	int pop() {
		if (stack1.empty())
			return NULL;
		int res;
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		res = stack2.top();
		stack2.pop();
		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return res;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};
class QO6 {
public:
	int minNumberInRotateAray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		return binaryfind(rotateArray, 0, rotateArray.size() - 1);
	}
	int binaryfind(vector<int> a, int low, int high) {
		if (low + 1 == high || low == high) {
			return a[high] < a[low] ? a[high] : a[low];
		}
		int mid = (low + high) / 2;
		if (a[mid] == a[low] && a[mid] == a[high]) {
			int find1 = binaryfind(a, low, mid);
			int find2 = binaryfind(a, mid + 1, high);
			return find1 > find2 ? find2 : find1;
		} else if (a[mid] >= a[low] && a[mid] > a[high]) {
			return binaryfind(a, mid, high);
		} else {
			return binaryfind(a, low, mid);
		}
	}
};
class QO7 {
public:
	int Fibonacci(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 1;
		if (n > 2) {
			int *a = new int[n];
			a[0] = 1;
			a[1] = 1;
			for (int i = 2; i < n; i++) {
				a[i] = a[i - 1] + a[i - 2];
			}
			int ret = a[n - 1];
			delete[] a;
			return ret;
		}
		return 0;
	}
};
class QO8 {
public:
	int jumpFloor(int number) {
		if (number == 1)
			return 1;
		else if (number == 2)
			return 2;
		else if (number > 2)
			return jumpFloor(number - 1) + jumpFloor(number - 2);
		else
			return 0;
	}
};
class QO9 {
	int jumpFloorII(int number) {
		if (number >= 1)
			return pow(2, number - 1);
		else
			return 0;
	}
};
class QO10 {
public:
	int rectCover(int number) {
		if (number == 1)
			return 1;
		else if (number == 2)
			return 2;
		else if (number > 2)
			return rectCover(number - 1) + rectCover(number - 2);
		else
			return 0;
	}
};
class QO11 {
	/*
	 * ��������1�ĸ���
	 */
public:
	int NumberOf1(int n) {
		int size = sizeof(n) * 8;
		int nums = 0;
		for (int i = 0; i < size; i++) {
			if ((n >> i) & 0x01)
				nums++;
		}
		return nums;
	}
};
class QO12 {
	/*
	 * ��ֵ�������η�
	 * ������,���Σ���������
	 */
public:
	double Power(double base, int exponent) {
		double res = 1.0;
		if (base == 0)
			return 0;
		if (exponent == 0)
			return res;
		int p = exponent < 0 ? (-exponent) : exponent;
		while (p) {
			if (p & 1 == 1)
				res *= base;
			base *= base;
			p = p >> 1;
		}
		return exponent < 0 ? 1 / res : res;
	}
};
class QO13 {
	/*
	 * ��������˳��ʹ����λ��ż��ǰ��
	 */
public:
	void reOrderArray(vector<int>&array) {
		for (int i = 0; i < array.size(); i++) {
			for (int j = array.size() - 1; j > i; j--) {
				if (array[j] % 2 == 1 && array[j - 1] % 2 == 0) {
					swap(array[j], array[j - 1]);
				}
			}

		}
	}
};
class QO14 {
	/*
	 * �����е�����k���ڵ�
	 */
public:
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
		if (k < 0 || pListHead == NULL)
			return NULL;
		ListNode *faster = pListHead;
		ListNode *chaser = pListHead;
		while (--k && faster->next) {
			faster = faster->next;
		}
		if (k > 0)
			return NULL;
		while (faster->next) {
			faster = faster->next;
			chaser = chaser->next;
		}
		return chaser;
	}
};
class QO15 {
	/*
	 * ��ת����
	 */
public:
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {

		}
	};
	ListNode *ReverseList(ListNode *pHead) {
		ListNode *prev = NULL;
		ListNode *next = NULL;
		while (pHead) {
			next = pHead->next;
			pHead->next = prev;
			prev = pHead;
			pHead = next;
		}
		return prev;
	}
};
class QO16 {
	/*
	 * �ϲ��������������
	 */
public:
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {

		}
	};
	ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
		ListNode *dummy = new ListNode(0);
		ListNode *head = dummy;

		while (pHead1 && pHead2) {
			if (pHead1->val <= pHead2->val) {
				head->next = pHead1;
				pHead1 = pHead1->next;
			} else {
				head->next = pHead2;
				pHead2 = pHead2->next;
			}
			head = head->next;
		}
		if (pHead1)
			head->next = pHead1;
		else
			head->next = pHead2;
		ListNode *newHead = dummy->next;
		delete dummy;
		return newHead;
	}
};
class QO17 {
	/*
	 * �������������ж��ӽṹ
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {

		}

		bool isSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
			if (pRoot2 == NULL)
				return true;
			if (pRoot1 == NULL)
				return false;
			if (pRoot1->val != pRoot2->val)
				return false;
			else
				return isSubtree(pRoot1->left, pRoot2->left)
						&& isSubtree(pRoot1->right, pRoot2->right);
		}
		bool HasSubtree(TreeNode *pRoot1, TreeNode* pRoot2) {
			if (!pRoot1 || !pRoot2)
				return false;
			return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2)
					|| HasSubtree(pRoot1->right, pRoot2);
		}
	};
};
class QO18 {
	/*
	 * ����������
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {

		}

		void Mirror(TreeNode *pRoot) {
			if (!pRoot)
				return;
			if (pRoot->left != NULL || pRoot->right != NULL) {
				TreeNode *node = pRoot->right;
				pRoot->right = pRoot->left;
				pRoot->left = node;
			}
			if (pRoot->left)
				Mirror(pRoot->left);
			if (pRoot->right)
				Mirror(pRoot->right);
		}
	};
};
class QO19 {
	/*
	 * ˳���ӡ����
	 */
public:
	void Print(vector<vector<int> > array) {
		vector<vector<int> >::iterator items;
		for (items = array.begin(); items < array.end(); items++) {
			for (vector<int>::iterator item = (*items).begin();
					item < (*items).end(); item++) {
				cout << *item << "\t";
			}
			cout << endl;
		}
	}
	vector<int> printMatrix(vector<vector<int>> matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> res;

		// ����Ķ�ά����Ƿ������ؿյ�����
		if (row == 0 || col == 0)
			return res;

		// �����ĸ��ؼ���������ʾ���Ϻ����µĴ�ӡ��Χ
		int left = 0, top = 0, right = col - 1, bottom = row - 1;
		while (left <= right && top <= bottom) {
			// left to right
			for (int i = left; i <= right; ++i)
				res.push_back(matrix[top][i]);
			// top to bottom
			for (int i = top + 1; i <= bottom; ++i)
				res.push_back(matrix[i][right]);
			// right to left
			if (top != bottom)
				for (int i = right - 1; i >= left; --i)
					res.push_back(matrix[bottom][i]);
			// bottom to top
			if (left != right)
				for (int i = bottom - 1; i > top; --i)
					res.push_back(matrix[i][left]);
			left++, top++, right--, bottom--;
		}
		return res;
	}
};
class QO20 {
	/*
	 * ����min������ջ
	 */
public:
	void push(int value) {
		valueStack.push(value);
		if (minStack.empty() || value <= minStack.top()) {
			minStack.push(value);
		}
	}
	void pop() {
		int res = valueStack.top();
		valueStack.pop();
		if (res == minStack.top())
			minStack.pop();
	}
	int top() {
		return valueStack.top();
	}
	int min() {
		return minStack.top();
	}
private:
	stack<int> valueStack;
	stack<int> minStack;
};
class QO21 {
	/*
	 * ջ��ѹ�롢��������
	 */
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0)
			return false;
		vector<int> stack;
		for (int i = 0, j = 0; i < pushV.size(); i++) {
			stack.push_back(pushV[i]);
			while (j < popV.size() && stack.back() == popV[j]) {
				stack.pop_back();
				j++;
			}
		}
		return stack.empty();
	}
};
class QO22 {
	/*
	 * �������������
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	vector<int> PrintFromTopToBottom(TreeNode *root) {
		vector<int> res;
		if (!root)
			return res;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			root = q.front();
			q.pop();
			res.push_back(root->val);
			if (root->left)
				q.push(root->left);
			if (root->right)
				q.push(root->right);
		}
		return res;
	}
};
class QO23 {
	/*
	 * �����������ĺ������
	 */
public:
	bool judge(vector<int> sequence, int start, int end) {
		if (start >= end)
			return true;
		int index = 0;
		for (index = start; index < end; index++) {
			if (sequence[index] > sequence[end])
				break;
		}
		for (int j = index; j < end; j++) {
			if (sequence[j] < sequence[end])
				return false;
		}
		return judge(sequence, start, index - 1)
				&& judge(sequence, index, end - 1);
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
			return false;
		return judge(sequence, 0, sequence.size() - 1);
	}
};
class QO24 {
	/*
	 * �������к�Ϊĳһֵ��·��
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;
		stack<TreeNode *> s;
		vector<int> routine;
		TreeNode *cur = root;
		TreeNode *last = NULL;
		s.push(root);
		int sum = 0;
		while (!s.empty()) {
			if (cur == NULL) {
				TreeNode *temp = s.top();
				if (temp->right != NULL && temp->right != last)
					cur = cur->right;
				else {
					last = temp;
					s.pop();
					routine.pop_back();
					sum -= temp->val;
				}
			} else {
				s.push(cur);
				sum += cur->val;
				routine.push_back(cur->val);
				if (cur->left == NULL && cur->right == NULL
						&& sum == expectNumber)
					res.push_back(routine);
				cur = cur->left;
			}
		}
		return res;
	}
};
class QO25 {
	/*
	 * ��������ĸ���
	 */
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
class QO26 {
	/*
	 * ����������-->˫������
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	TreeNode *Convert(TreeNode *pRootOfTree) {
		if (!pRootOfTree)
			return NULL;
		stack<TreeNode *> s;
		vector<TreeNode *> v;

		TreeNode *root = pRootOfTree;
		TreeNode *newRoot = NULL, *last = NULL;

		while (root || !s.empty()) {
			while (root) {
				s.push(root);
				root = root->left;
			}
			if (!s.empty()) {
				root = s.top();
				s.pop();
				v.push_back(root);
				root = root->right;
			}
		}
		newRoot = v.front();
		root = newRoot;
		for (int i = 1; i < v.size(); i++) {
			root->right = v[i];
			root->left = last;
			last = root;
			root = root->right;
		}
		newRoot->left = last;
		return newRoot;
	}
};
class QO27 {
	/*
	 * �ַ�������
	 */
public:
	void cal(vector<string>&v, int k, string str) {
		if (k == str.size() - 1)
			v.push_back(str);
		set<char> s;
		sort(str.begin() + k, str.end());
		for (int i = k; i < str.size(); i++) {
			if (s.find(str[i]) == s.end()) {
				s.insert(str[i]);
				swap(str[i], str[k]);
				cal(v, k + 1, str);
				swap(str[i], str[k]);
			}
		}
	}
	vector<string> Permutation(string str) {
		vector < string > v;
		cal(v, 0, str);
		return v;
	}
};
class QO28 {
	/*
	 * �����г��ֳ���һ�������
	 */
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		/*
		 * dp
		 */
//		int size = numbers.size();
//		if (size == 0)
//			return 0;
//		int num = numbers[0], count = 1;
//		for (int i = 1; i < size; i++) {
//			if (numbers[i] == num) {
//				count++;
//			} else {
//				count--;
//			}
//			if (count == 0) {
//				num = numbers[i];
//				count = 1;
//			}
//		}
//		count = 0;
//		for (int i = 0; i < size; i++) {
//			if (numbers[i] == num)
//				count++;
//		}
//		if (count * 2 > size)
//			return num;
//		return 0;
		/*
		 * map
		 */
		map<int, int> arr;
		for (int i = 0; i < numbers.size(); i++) {
			if (arr.find(numbers[i]) == arr.end())
				arr.insert(make_pair(numbers[i], 1));
			else
				arr[numbers[i]]++;
			if (arr[numbers[i]] * 2 > numbers.size())
				return numbers[i];
		}
		return 0;
	}
};
class QO29 {
	/*
	 * ��С��k����
	 */
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (k > input.size())
			return res;
		sort(input.begin(), input.end());
		for (int i = 0; i < k; i++) {
			res.push_back(input[i]);
		}
		return res;
	}
};
class QO30 {
	/*
	 * ����������������
	 */
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int curSum = 0;
		int maxSum = array[0];
		for (int i = 0; i < array.size(); i++) {
			curSum =
					(array[i] > curSum + array[i]) ?
							array[i] : curSum + array[i];
			maxSum = (curSum > maxSum) ? curSum : maxSum;
		}
		return maxSum;
	}
};
class QO31 {
	/*
	 * ������1���ֵĴ���
	 */
public:
	int NumberOf1Between1AndN_Solution(int n) {
		int count = 0;
		int lownum = 0;
		int curnum = 0;
		int highnum = 0;

		for (int m = 1; m <= n; m *= 10) {
			highnum = n / (m * 10);
			curnum = (n / m) % 10;
			lownum = n - (n / m) * m;
			if (curnum == 0) {
				//���Ϊ0������1�ĸ����ɸ�λ����
				count += highnum * m;
			} else if (curnum == 1) {
				//���Ϊ1������1�ĸ����ɸ�λ�͵�λ����
				count += highnum * m + lownum + 1;
			} else {
				//�������1������1�ĸ����ɸ�λ����
				count += (highnum + 1) * m;
			}
		}
		return count;
	}
};
class QO32 {
	/*
	 * �������ų���С����
	 */
public:
	static bool compare(const string &str1, const string &str2) {
		string s1 = str1 + str2;
		string s2 = str2 + str1;
		return s1 < s2;
	}
	string PrintMinNumber(vector<int> numbers) {
		string res;
		if (numbers.size() == 0)
			return res;
		vector < string > strnum;
		string s;
		stringstream ss;
		for (int i = 0; i < numbers.size(); i++) {
			ss.clear();
			ss << numbers[i];
			ss >> s;
			strnum.push_back(s);
		}
		sort(strnum.begin(), strnum.end(), compare);
		for (int i = 0; i < strnum.size(); i++)
			res.append(strnum[i]);
		return res;
	}
};
class QO33 {
	/*
	 * ����
	 */
public:
	int GetUglyNumber_Solution(int index) {
		if (index < 1)
			return 0;
		vector<int> k(index);
		k[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;
		for (int i = 1; i < index; i++) {
			k[i] = min(min(k[t2] * 2, k[t3] * 3), k[t5] * 5);
			if (k[i] == k[t2] * 2)
				t2++;
			if (k[i] == k[t3] * 3)
				t3++;
			if (k[i] == k[t5] * 5)
				t5++;
		}
		return k[index - 1];
	}
};
class QO34 {
	/*
	 * ��һ��ֻ����һ�ε��ַ�
	 */
public:
	int FirstNotRepeatingChar(string str) {
		if (str.empty())
			return -1;
		vector<int> v(256);
		for (int i = 0; i < str.length(); i++) {
			v[(int) str[i]]++;
		}
		for (int i = 0; i < str.length(); i++) {
			if (v[(int) str[i]] == 1)
				return i;
		}
		return -1;
	}
};
class QO35 {
	/*
	 * �����е������
	 */
public:
	int InversePairs(vector<int> data) {
		if (data.size() <= 1)
			return 0;
		vector<int> copy(data);
		return InversePairsCore(data, copy, 0, data.size() - 1);
	}
	int InversePairsCore(vector<int>&data, vector<int>&copy, int begin,
			int end) {
		if (begin == end) {
			copy[end] = data[end];
			return 0;
		} else {
			int mid = begin + (end - begin) / 2;
			int left = InversePairsCore(copy, data, begin, mid);
			int right = InversePairsCore(copy, data, mid + 1, end);
			int count = 0;
			int index = end;
			int pre = mid;
			int post = end;
			while (pre >= begin && post >= mid + 1) {
				if (data[pre] > data[post]) {
					count += post - mid;
					copy[index--] = data[pre--];
				} else {
					copy[index--] = data[post--];
				}
			}
			for (; pre >= begin; --pre)
				copy[index--] = data[pre];
			for (; post >= mid + 1; --post)
				copy[index--] = data[post];
			return left + right + count;
		}
	}
};
class QO36 {
	/*
	 * �������ĵ�һ�������ڵ�
	 */
public:
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
		int length1 = getListLength(pHead1);
		int length2 = getListLength(pHead2);
		int diff =
				length1 >= length2 ? (length1 - length2) : (length2 - length1);
		ListNode *longer = length1 >= length2 ? pHead1 : pHead2;
		ListNode *shorter = length2 > length1 ? pHead1 : pHead2;
		while (diff--) {
			longer = longer->next;
		}
		while ((longer != NULL) && (shorter != NULL) && (longer != shorter)) {
			longer = longer->next;
			shorter = shorter->next;
		}
		return longer;
	}
	int getListLength(ListNode *head) {
		int sum = 0;
		while (head) {
			head = head->next;
			sum++;
		}
		return sum;
	}
};
class QO37 {
	/*
	 * ���������������г��ֵĴ���
	 */
public:
	int getNumberOfR(vector<int> data, int k) {
		int low = 0;
		int high = data.size() - 1;
		int mid = 0;
		int nums = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (data[mid] > k) {
				high = mid - 1;
			} else if (data[mid] < k) {
				low = mid + 1;
			} else {
				int temp = mid;
				while (data[temp--] == k) {
					nums++;
				}
				while (data[++mid] == k) {
					nums++;
				}
				return nums;
			}
		}
		return nums;
	}
};
class QO38 {
	/*
	 * ���������
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	int TreeDepth(TreeNode *pRoot) {
		if (pRoot == NULL)
			return 0;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return max(left, right) + 1;
	}
};
class QO39 {
	/*
	 * �ж����Ƿ�Ϊƽ�������
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	int TreeDepth(TreeNode *pRoot) {
		if (pRoot == NULL)
			return 0;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return max(left, right) + 1;
	}
	bool IsBalanced_Solution(TreeNode *pRoot) {
		if (pRoot == NULL)
			return true;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		int diff = left - right;
		if (diff > 1 || diff < -1)
			return false;
		return IsBalanced_Solution(pRoot->left)
				&& IsBalanced_Solution(pRoot->right);
	}
};
class QO40 {
	/*
	 * ������ֻ����һ�ε�����
	 */
public:
	void FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
		int temp = 0;
		int index;
		for (int i = 0; i < data.size(); i++) {
			temp ^= data[i];

		}
		for (index = 0; index < sizeof(int) * 8; index++) {
			if (((temp >> index) & 1) == 1)
				break;
		}
		int nu1 = 0;
		int nu2 = 0;
		for (int i = 0; i < data.size(); i++) {
			if (((data[i] >> index) & 1) == 0) {
				nu1 ^= data[i];
			} else {
				nu2 ^= data[i];
			}
		}
		*num1 = nu1;
		*num2 = nu2;
	}
};
class QO41 {
	/*
	 * ��Ϊs��������������
	 */
public:
	vector<vector<int>> FindContinuousSwquence(int sum) {
		vector<vector<int>> res;
		int low = 1;
		int high = 2;

		while (low < high) {
			int cursum = (high + low) * (high - low + 1) / 2;
			if (cursum < sum) {
				high++;
			} else if (cursum == sum) {
				vector<int> tem;
				for (int i = low; i <= high; i++) {
					tem.push_back(i);
				}
				res.push_back(tem);
				low++;
			} else {
				low++;
			}
		}
		return res;
	}
};
class QO42 {
	/*
	 * ��Ϊs��������
	 */
public:
	static bool findsecond(vector<int> array, int low, int high, int k) {
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (array[mid] > k) {
				high = mid - 1;
			} else if (array[mid] < k) {
				low = mid + 1;
			} else {
				return true;
			}
		}
		return false;
	}
	static vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<vector<int>> arr;
		vector<int> res;
		if (array.size() < 2)
			return res;
		for (int i = 0; i < array.size(); i++) {
			res.clear();
			res.push_back(array[i]);
			int second = sum - array[i];
			if (findsecond(array, i, array.size() - 1, second)) {
				res.push_back(second);
				arr.push_back(res);
			} else {
				res.pop_back();
			}
		}
		if (arr.size() == 0) {
			res.clear();
			return res;
		}
//		cout << "arr size " << arr.size() << endl;
		int min = arr[0][0] * arr[0][1];
		int pos = 0;
		int mul = 0;
		int i = 0;
		for (vector<vector<int>>::iterator ite = arr.begin() + 1;
				ite != arr.end(); ite++) {
			mul = (*ite).at(0) * (*ite).at(1);
			if (mul < min) {
				pos = i;
				min = mul;
			}
			i++;
		}
		res = arr[pos];
//		res = *pos;
		return res;
	}
	vector<int> findNumbersWithSum(vector<int> array, int sum) {
		vector<int> res;
		int begin = 0;
		int end = array.size() - 1;

		while (begin < end) {
			long cursum = array[begin] + array[end];
			if (cursum == sum) {
				res.push_back(array[begin]);
				res.push_back(array[end]);
				return res;
			} else {
				if (cursum < sum)
					begin++;
				else
					end--;
			}
		}
		return res;
	}
	static void test() {
		vector<int> array = { 1, 2, 3, 4, 5, 6 };
		int sum = 7;
		vector<int> res;
		res = FindNumbersWithSum(array, sum);
		for (vector<int>::iterator ite = res.begin(); ite != res.end(); ite++) {
			cout << *ite << " ";
		}
		cout << endl;
	}
};
class QO43 {
	/*
	 * �����ַ���
	 */
public:
	static void reverseString(string &string, int begin, int end) {
		int mid = (begin + end) / 2;
//		cout << "begin= " << begin << " " << "mid= " << mid << " " << "end= "
//				<< end << endl;

		for (int i = begin; i <= mid; i++) {
//			cout << "i= " << i << endl;
			swap(string[i], string[end - i + begin]);
		}
	}
	static string LeftRotateString(string str, int n) {
		if (n == 0)
			return str;
		reverseString(str, 0, n - 1);
//		cout << str << endl;
		reverseString(str, n, str.size() - 1);
//		cout << str << endl;
		reverseString(str, 0, str.size() - 1);
		return str;
	}
	static void test() {
		string str = "abcXYZdef";
		int n = 3;
		cout << LeftRotateString(str, n) << endl;
	}
};
class QO44 {
	/*
	 * ��ת����˳����
	 */
public:
	static string ReverseSentence(string str) {
		vector < string > v;
		string res;
		if (str.length() < 1)
			return res;
		int start = 0;
		int pos = 0;
		while ((pos = str.find_first_of(' ', start)) != string::npos) {
//			cout << "pos= " << pos << endl;
			string tem = str.substr(start, pos - start);
//			cout << tem.size();
			start = pos + 1;
			v.push_back(tem);
		}
		if (str.size() - start > 0)
			v.push_back(str.substr(start, str.size() - start));
		for (int i = v.size() - 1; i >= 1; i--) {
			res += v[i];
			res += " ";
		}
		res += v[0];
		return res;
	}
	static void test() {
		string str = "student. a am I";
		cout << ReverseSentence(str) << endl;
	}
};
class QO45 {
	/*
	 * �˿���˳��
	 */
public:
	static bool IsContinuous(vector<int> numbers) {
		if (numbers.size() < 5)
			return false;
		sort(numbers.begin(), numbers.end());
		int zeros = 0;
		int index = 0;
		while (numbers[index++] == 0) {
			zeros++;
		}
		int pre = index - 1;
		int cur;
		int re = 0;
		cout << "zeros= " << zeros << " pre= " << pre << endl;
		for (int cur = index; cur < numbers.size(); cur++) {
			int diff = numbers[cur] - numbers[pre] - 1;
			if (diff < 0)
				re++;
			cout << "cur= " << cur << " diff=" << diff << endl;
			if (diff > zeros)
				return false;
			if (diff >= 0 && diff <= zeros && zeros >= 0) {
				zeros -= diff;
			}
			pre++;
		}
		if (numbers.size() - re > 4)
			return true;
		else
			return false;
	}
	static void test() {
		vector<int> numbers = { 1, 0, 0, 1, 0 };
		cout << IsContinuous(numbers);
	}
};
class QO46 {
	/*
	 * ԲȦ�����ʣ�µ���
	 */
public:
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	int LastRemaining_Solution(int n, int m) {
//		if (n == 0)
//			return -1;
//		if (n == 1)
//			return 0;
//		else
//			return (LastRemaining_Solution(n - 1, m) + m) % n;
		/*
		 * ����
		 */
//		bool *pos = new bool[n];
//		for (int i = 0; i < n; i++)
//			pos[i] = true;
//		int count = 0;
//		int last = 0;
//		for (int i = 0, j = 0;; i++) {
//			if (pos[i] == true) {
//				j++;
//				if (j == m) {
//					j = 0;
//					count++;
//					pos[i] = false;
//				}
//				if (count == n) {
//					last = i;
//					break;
//				}
//			}
//			if (i == n)
//				i = 0;
//		}
//		delete[] pos;
//		return last;
		/*
		 * ����
		 */
		if (n < 1 || m < 1)
			return -1;
		ListNode *pHead = new ListNode(0);
		ListNode *pCur = pHead;
		ListNode *pLast = NULL;
		for (int i = 1; i < n; i++) {
			pCur->next = new ListNode(i);
			pCur = pCur->next;
		}
		pCur->next = pHead;

		pLast = pCur;
		pCur = pHead;

		while (pCur->next != pCur) {
			for (int i = 0; i < m - 1; i++) {
				pLast = pCur;
				pCur = pCur->next;
			}
			pLast->next = pCur->next;
			delete pCur;
			pCur = pLast->next;
		}
		int res = pCur->val;
		delete pCur;
		return res;
	}
};
class QO47 {
	/*
	 * ��ͣ������ó��������
	 */
public:
	int Sum_Solution(int n) {
		int ans = n;
		ans && (ans += Sum_Solution(n - 1));
		return ans;
	}
};
class QO48 {
	/*
	 * ���üӼ��˳��ļӷ�
	 */
public:
	int Add(int num1, int num2) {
//		if (num2 == 0)
//			return num1;
//		int sum = num1 ^ num2;
//		int carry = (num1 & num2) << 1;
//		return Add(sum, carry);

		int sum, carry;
		do {
			sum = num1 ^ num2;
			carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		} while (num2 != 0);
		return num1;
	}
};
class QO49 {
public:
	/*
	 * ���ַ���ת��������
	 */
	static int StrToInt(string str) {
		if (str.empty())
			return 0;
		int space = 0;
		while (str[space] == ' ') {
			space++;
		}
		int flag = 1;
		str = str.substr(space, str.length() - space + 1);
		vector<int> v;
		for (int i = 0; i < str.length(); i++) {
			if (i == 0) {
				if (str[0] == '-') {
					flag = 0;
				} else if (str[0] == '+') {
					flag = 1;
				} else if (isdigit(str[0])) {
					flag = 1;
					v.push_back(str[0] - '0');
				} else {
					return 0;
				}
			} else {
				if (!isdigit(str[i]))
					return 0;
				else
					v.push_back(str[i] - '0');
			}
		}
		if (v.empty())
			return 0;
		long long num = v[0];
		for (int i = 1; i < v.size(); i++) {
			num = num * 10 + v[i];
		}
		if (flag == 0)
			num = -num;
		return num;
	}
	static void test() {
		string str = " -1147483647";
		cout << StrToInt(str);
	}
};
class QO50 {
public:
	/*
	 * �������ظ�����
	 */
	static bool duplicate(int numbers[], int length, int *duplication) {
		if (length < 2)
			return false;
		int *hash = new int[length];
		for (int i = 0; i < length; i++)
			hash[i] = 0;
		int count = 0;
		for (int i = 0; i < length; i++) {
			hash[numbers[i]]++;
			if (hash[numbers[i]] > 1) {
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
	static void test() {
		int numbers[] = { 2, 1, 3, 1, 4 };
		int length = 5;
		int *duplication = NULL;

	}
};
class QO51 {
	/*
	 * �����˻�����
	 */
public:
	vector<int> multiply(const vector<int>&A) {
		int n = A.size();
		vector<int> res(n);
		int tmp = 1;
		for (int i = 0; i < n; i++) {
			res[i] = tmp;
			tmp *= A[i];
		}
		tmp = 1;
		for (int i = n - 1; i >= 0; i--) {
			res[i] *= tmp;
			tmp *= A[i];
		}
		return res;
	}
};
class QO52 {
	/*
	 * ������ʽƥ��
	 */
public:
	bool match(char *str, char *pattern) {

	}
	bool matchCore(char *str, char *pattern) {
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*str != '\0' && *pattern == '\0')
			return false;
		if (*(pattern + 1) == '*') {
			if (*pattern == *str || (*pattern == '.' && *str != '\0'))
				return matchCore(str + 1, pattern)
						|| matchCore(str, pattern + 2);
			else
				return matchCore(str, pattern + 2);
		}
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
			return matchCore(str + 1, pattern + 1);
		return false;
	}
};
class QO53 {
public:
	/*
	 * ��ʾ��ֵ���ַ���
	 */
	bool isNumeric(char *str) {
		// ��Ƿ��š�С���㡢e�Ƿ���ֹ�
		bool sign = false, decimal = false, hasE = false;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == 'e' || str[i] == 'E') {
				if (i == strlen(str) - 1)
					return false; // e����һ��Ҫ������
				if (hasE)
					return false;  // ����ͬʱ��������e
				hasE = true;
			} else if (str[i] == '+' || str[i] == '-') {
				// �ڶ��γ���+-���ţ�����������e֮��
				if (sign && str[i - 1] != 'e' && str[i - 1] != 'E')
					return false;
				// ��һ�γ���+-���ţ��Ҳ������ַ�����ͷ����Ҳ���������e֮��
				if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E')
					return false;
				sign = true;
			} else if (str[i] == '.') {
				// e���治�ܽ�С���㣬С���㲻�ܳ�������
				if (hasE || decimal)
					return false;
				decimal = true;
			} else if (str[i] < '0' || str[i] > '9') // ���Ϸ��ַ�
				return false;
		}
		return true;
	}
};
class QO54 {
public:
	/*
	 * �ַ����е�һ�����ظ����ַ�
	 */
	vector<char> v;
	void Insert(char ch) {
		v.push_back(ch);
	}
	char FirstAppearingOnce() {
		char *hash = new char[256];
		for (int i = 0; i < v.size(); i++) {
			hash[i] = 0;
		}
		for (int i = 0; i < v.size(); i++) {
			hash[v[i]]++;
		}
		for (int i = 0; i < v.size(); i++) {
			if (hash[v[i]] == 1)
				return v[i];
		}
		return '#';
	}
};
class QO55 {
public:
	/*
	 * ��������ڽڵ�
	 */
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {

		}
	};
	ListNode *EntryNodeOfLoop(ListNode *pHead) {
		if (!pHead)
			return NULL;
		ListNode *faster = pHead;
		ListNode *chaser = pHead;
		while (faster->next && faster->next->next) {
			faster = faster->next->next;
			chaser = chaser->next;
			if (chaser == faster)
				break;
		}
		if (faster == NULL || faster->next == NULL)
			return false;
		chaser = pHead;
		while (chaser != faster) {
			chaser = chaser->next;
			faster = faster->next;
		}
		return chaser;
	}
};
class QO56 {
	/*
	 * ɾ���������ظ��Ľڵ�
	 */
public:
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	static ListNode *deleteDuplication(ListNode *pHead) {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode *dummy = new ListNode(0);
		dummy->next = pHead;
		ListNode *prev = dummy;
		ListNode *cur = pHead;
		ListNode *next = pHead->next;
		while (next) {
			if (cur->val == next->val) {
				while (cur->val == next->val && next != NULL) {
					cur->next = next->next;
					delete next;
					next = cur->next;
				}
				prev->next = cur->next;
				delete cur;
				cur = prev->next;
				if (next)
					next = next->next;
			} else {
				prev = prev->next;
				cur = cur->next;
				next = next->next;
			}
		}
		ListNode *newHead = dummy->next;
		delete dummy;
		return newHead;
	}
	static ListNode * create(vector<int> arr) {
		ListNode *head = new ListNode(arr[0]);
		ListNode *cur = head;
		for (int i = 1; i < arr.size(); i++) {
			ListNode *node = new ListNode(arr[i]);
			cur->next = node;
			cur = cur->next;
		}
		return head;
	}
	static void print(ListNode *pHead) {
		while (pHead) {
			cout << pHead->val << "->";
			pHead = pHead->next;
		}
		cout << endl;
	}
	static void test() {
		vector<int> a = { 1, 2, 3, 3, 4, 4, 5 };
		ListNode *pHead = create(a);
		print(pHead);
		pHead = deleteDuplication(pHead);
		print(pHead);
	}
};
class QO57 {
	/*
	 * ����������һ���ڵ�
	 */
public:

};
class QO58 {
	/*
	 * �Գƶ�����
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	bool isSymmetrical(TreeNode *pRoot) {
		return helper(pRoot, pRoot);
	}
	bool helper(TreeNode *pRoot1, TreeNode *pRoot2) {
		if (pRoot1 == NULL && pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return helper(pRoot1->left, pRoot2->right)
				&& helper(pRoot1->right, pRoot2->left);
	}
};
class QO59 {
	/*
	 * ��֮�ִ�ӡ������
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	vector<vector<int>> Print(TreeNode *pRoot) {
		vector<vector<int>> res;
		if (!pRoot)
			return res;
		stack<TreeNode *> stack1, stack2;
		TreeNode *node;
		stack1.push(pRoot);
		while (!stack1.empty() || !stack2.empty()) {
			vector<int> line;
			if (!stack1.empty()) {
				while (!stack1.empty()) {
					node = stack1.top();
					stack1.pop();
					line.push_back(node->val);
					if (node->left)
						stack2.push(node->left);
					if (node->right)
						stack2.push(node->right);
				}
				res.push_back(line);
			} else if (!stack2.empty()) {
				while (!stack2.empty()) {
					node = stack2.top();
					stack2.pop();
					line.push_back(node->val);
					if (node->right)
						stack1.push(node->right);
					if (node->left)
						stack1.push(node->left);
				}
				res.push_back(line);
			}
		}
		return res;
	}
};
class QO60 {
	/*
	 * �Ѷ�������ӡ�ɶ���
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	vector<vector<int>> Print(TreeNode*pRoot) {
		vector<vector<int>> res;
		if (pRoot == NULL)
			return res;
		TreeNode *node;
		queue<TreeNode *> q1, q2;
		q1.push(pRoot);
		while (!q1.empty() || !q2.empty()) {
			vector<int> line;
			if (!q1.empty()) {
				while (!q1.empty()) {
					node = q1.front();
					q1.pop();
					line.push_back(node->val);
					if (node->left)
						q2.push(node->left);
					if (node->right)
						q2.push(node->right);
				}
				res.push_back(line);
			} else if (!q2.empty()) {
				while (!q2.empty()) {
					node = q2.front();
					q2.pop();
					line.push_back(node->val);
					if (node->left)
						q1.push(node->left);
					if (node->right)
						q1.push(node->right);
				}
				res.push_back(line);
			}
		}
		return res;
	}
};
class QO61 {
	/*
	 * ���л�������
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	char *Serialize(TreeNode *root) {

	}
	TreeNode *Deserialize(char*str) {

	}
};
class QO62 {
	/*
	 * �������������ĵ�k���ڵ�
	 */
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	TreeNode *KthNode(TreeNode *pRoot, int k) {
		if (pRoot == NULL || k <= 0)
			return NULL;
		vector<TreeNode *> v;
		inOrder(pRoot, v);
		if (k > v.size())
			return NULL;
		return v[k - 1];
	}
	void inOrder(TreeNode *pRoot, vector<TreeNode *>&v) {
		if (pRoot == NULL)
			return;
		inOrder(pRoot->left, v);
		v.push_back(pRoot);
		inOrder(pRoot->right, v);
	}
};
class QO63 {
	/*
	 * ��εõ��������е���λ��
	 */
public:
	void Insert(int num) {
		v.push_back(num);
	}
	double GetMedian() {
		sort(v.begin(), v.end());
		int nums = v.size();
		double ave = 0.0;
		if (nums % 2 == 1) {
			ave = (double) v[(nums + 1) / 2 - 1];
		} else {
			int sum = v[nums / 2] + v[nums / 2 - 1];
			ave = (double) sum / 2;
		}
		return ave;
	}
private:
	vector<int> v;
};
class QO64 {
	/*
	 * �����������ֵ
	 */
public:
	static vector<int> maxInWindows(const vector<int>&num, unsigned int size) {
		vector<int> res;
		if (num.size() <= 0 || size <= 0 || size > num.size())
			return res;
		int max = num[0], pre = 0, next = 0;
		for (unsigned int i = 1; i < size; i++) {
			if (num[i] > max)
				max = num[i];
		}
		res.push_back(max);
		for (unsigned int i = size; i < num.size(); i++) {
			next = num[i];
			pre = num[i - size];
			if (pre == max) {
				max = num[i - size + 1];
				for (unsigned int j = 1; j < size; j++) {
					if (num[i - size + 1 + j] > max)
						max = num[i - size + 1 + j];
				}
			} else {
				if (next > pre) {
					if (next > max)
						max = next;
				}
			}
			res.push_back(max);
		}
		return res;
	}
	static void test() {
		vector<int> num = { 2, 3, 4, 2, 6, 2, 5, 1 };
		unsigned int size = 3;
		vector<int> res = maxInWindows(num, size);
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << "->";
		}
		cout << endl;
	}
};
class QO65 {
	/*
	 * �����е�·��
	 */
public:
	bool hasPath(char* matrix, int rows, int cols, char* str) {
		if (str == NULL || rows <= 0 || cols <= 0)
			return false;
		bool *isOk = new bool[rows * cols]();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				if (isHsaPath(matrix, rows, cols, str, isOk, i, j))
					return true;
		}
		return false;
	}
	bool isHsaPath(char *matrix, int rows, int cols, char *str, bool *isOk,
			int curx, int cury) {
		if (*str == '\0')
			return true;
		if (cury == cols) {
			curx++;
			cury = 0;
		}
		if (cury == -1) {
			curx--;
			cury = cols - 1;
		}
		if (curx < 0 || curx >= rows)
			return false;
		if (isOk[curx * cols + cury] || *str != matrix[curx * cols + cury])
			return false;
		isOk[curx * cols + cury] = true;
		bool sign = isHsaPath(matrix, rows, cols, str + 1, isOk, curx - 1, cury)
				|| isHsaPath(matrix, rows, cols, str + 1, isOk, curx + 1, cury)
				|| isHsaPath(matrix, rows, cols, str + 1, isOk, curx, cury - 1)
				|| isHsaPath(matrix, rows, cols, str + 1, isOk, curx, cury + 1);
		isOk[curx * cols + cury] = false;
		return sign;
	}
};
class QO66 {
	/*
	 * �������˶���Χ
	 */
	int movingCount(int threshold, int rows, int cols) {
		bool* flag = new bool[rows * cols];
		for (int i = 0; i < rows * cols; i++)
			flag[i] = false;
		int count = moving(threshold, rows, cols, 0, 0, flag); //�ӣ�0,0�����꿪ʼ����;
		delete[] flag;
		return count;
	}
	//��������ƶ�λ��
	int moving(int threshold, int rows, int cols, int i, int j, bool* flag) {
		int count = 0;
		if (check(threshold, rows, cols, i, j, flag)) {
			flag[i * cols + j] = true;
			//��Ƿ��ʹ��������־flag����Ҫ���ݣ���ΪֻҪ�����ʹ����ɡ�
			//��Ϊ����ܷ��ʣ����ʹ����1.���ܷ��ʣ�Ҳ�����·��ʹ���
			count = 1 + moving(threshold, rows, cols, i - 1, j, flag)
					+ moving(threshold, rows, cols, i, j - 1, flag)
					+ moving(threshold, rows, cols, i + 1, j, flag)
					+ moving(threshold, rows, cols, i, j + 1, flag);
		}
		return count;
	}
	//��鵱ǰλ���Ƿ���Է���
	bool check(int threshold, int rows, int cols, int i, int j, bool* flag) {
		if (i >= 0 && i < rows && j >= 0 && j < cols
				&& getSum(i) + getSum(j) <= threshold
				&& flag[i * cols + j] == false)
			return true;
		return false;
	}
	//����λ�õ���ֵ
	int getSum(int number) {
		int sum = 0;
		while (number > 0) {
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}
};
class someTest {
	// �������� X �� 1-n �г��ֵĴ�����
	int count(int n, int x) {
		int cnt = 0, k;
		for (int i = 1; k = n / i; i *= 10) {
			// ��λ�����֡�
			int high = k / 10;
			if (x == 0) {
				if (high) {
					high--;
				} else {
					break;
				}
			}
			cnt += high * i;
			// ��ǰλ�����֡�
			int cur = k % 10;
			if (cur > x) {
				cnt += i;
			} else if (cur == x) {
				// n - k * i Ϊ��λ�����֡�
				cnt += n - k * i + 1;
			}
		}
		return cnt;
	}
};
class outPut {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	/*
	 * ��������
	 */
	static void createList(ListNode *&head, vector<int> arr) {
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
	static void printList(ListNode *head) {
		ListNode *p = head;
		while (p) {
			cout << p->val << "\t";
			p = p->next;
		}
		cout << endl;
	}
	static ListNode *out(ListNode *list) {
		if (list == NULL)
			return list;
		deque<ListNode*> d;
		while (list) {
			d.push_back(list);
			list = list->next;
		}
		list = d.front();
		ListNode *p = list;
		d.pop_front();
		while (!d.empty()) {
			p->next = d.back();
			p = p->next;
			d.pop_back();
			if (!d.empty()) {
				p->next = d.front();
				p = p->next;
				d.pop_front();
			} else {
				break;
			}
		}
		p->next = NULL;
		return list;
	}
	static void test() {
		vector<int> arr = { 1, 2, 3, 4, 5, 6 };
		ListNode *head = NULL;
		createList(head, arr);
		printList(head);
		ListNode *ne = out(head);
		printList(ne);
	}
};
#endif /* INC_OFFER66_H_ */
