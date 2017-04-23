/*
 * NiuKeVideo.h
 *
 *  Created on: 2017年3月8日
 *      Author: tla001
 */

#ifndef INC_NIUKEVIDEO_H_
#define INC_NIUKEVIDEO_H_

#include "Include.h"
class AboutString {
public:
	static void reverse(string &A, int begin, int end) {
		int mid = (begin + end) / 2;
		for (int i = begin; i <= mid; i++) {
			swap(A[i], A[end - i + begin]);
		}
	}
	static string reverseSentence(string A, int n) {
		if (n <= 1)
			return A;
		string res(A);
		reverse(res, 0, n - 1);
//		cout << "res " << res << endl;
		int begin = 0;
		int end = 0;
		for (int i = 0; i < n; i++) {
			if (res[i] == ' ') {
//				cout << "i " << i << " begin " << begin;
				end = i - 1;
//				cout << " end " << end << " ";
				reverse(res, begin, end);
				begin = i + 1;
//				cout << res << endl;
			}
		}
		reverse(res, begin, n - 1);
		return res;
	}
	static bool compare(string a, string b) {
		string ab = a + b;
		string ba = b + a;
		return ab < ba ? true : false;
	}
	string findSmallest(vector<string> strs, int n) {
		string res;
		if (n == 0)
			return res;
		if (n == 1)
			return strs[0];
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (compare(strs[j], strs[i])) {
					swap(strs[i], strs[j]);
				}
			}
			res += strs[i];
		}
		return res;
	}
	static string stringTranslation(string A, int n, int len) {
		if (n <= 1)
			return A;
		string res(A);
		int l = len % n;
		reverse(res, 0, l - 1);
		reverse(res, l, n - 1);
		reverse(res, 0, n - 1);
		return res;
	}
	string replaceSpace(string iniString, int length) {
		if (length < 1)
			return iniString;
		int count = 0;
		for (int i = 0; i < length; i++) {
			if (iniString[i] == ' ')
				count++;
		}
		int newLength = 2 * count + length;
		int pos = newLength - 1;
		iniString.append(2 * count, ' ');
		for (int i = length - 1; i >= 0; i--) {
			if (iniString[i] == ' ') {
				iniString[pos--] = '0';
				iniString[pos--] = '2';
				iniString[pos--] = '%';
			} else {
				iniString[pos--] = iniString[i];
			}
		}
		return iniString;
	}
	bool chkParenthesis(string A, int n) {
		if (A.empty() || n == 0)
			return false;
		int num = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] != '(' && A[i] != ')') {
				return false;
			}
			if (A[i] == ')') {
				num--;
				if (num < 0)
					return false;
			}
			if (A[i] == '(') {
				num++;
			}
		}
		return num == 0;
	}
	int longestSubstring(string A, int n) {
		int last[256];
		for (int i = 0; i < 256; ++i)
			last[i] = -1;

		last[A[0]] = 0;
		int pre = 1;
		int max = 1;

		for (int i = 1; i < n; ++i) {
			if (last[A[i]] < i - pre) {
				++pre;
			} else {
				pre = i - last[A[i]];
			}
			last[A[i]] = i;
			if (max < pre)
				max = pre;
		}
		return max;
	}
	static void test() {
		string A = "abc def gh";
//		reverse(A, 4, 6);
//		cout << A << endl;
		cout << reverseSentence(A, A.size()) << endl;
	}
};
class AboutSort {
public:
	static void print(int *A, int n) {
		for (int i = 0; i < n; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}
	static int *bubbleSort(int *A, int n) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (A[j] > A[j + 1]) {
					int tem = A[j];
					A[j] = A[j + 1];
					A[j + 1] = tem;
				}
			}
		}
		return A;
	}
	static int *selectSort(int *A, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (A[i] > A[j]) {
					int tem = A[j];
					A[j] = A[i];
					A[i] = tem;
				}
			}
		}
		return A;
	}
	static int *insertSort(int *A, int n) {
		for (int i = 1; i < n; i++) {
			if (A[i] < A[i - 1]) {
				int j = i - 1;
				int pivot = A[i];
				while (pivot < A[j] && j >= 0) {
					A[j + 1] = A[j];
					j--;
				}
				A[j + 1] = pivot;
			}
		}
		return A;
	}
	static void mergeHelper(int *A, int *helper, int left, int right) {
		if (left >= right)
			return;
		int mid = (left + right) / 2;
		mergeHelper(A, helper, left, mid);
		mergeHelper(A, helper, mid + 1, right);

		int helperLeft = left;
		int helperRight = mid + 1;

		for (int i = left; i <= right; i++) {
			helper[i] = A[i];
		}
		int cur = left;
		while (helperLeft <= mid && helperRight <= right) {
			if (helper[helperLeft] <= helper[helperRight])
				A[cur++] = helper[helperLeft++];
			else
				A[cur++] = helper[helperRight++];
		}
		while (helperLeft <= mid)
			A[cur++] = helper[helperLeft++];
	}
	static int *mergeSort(int*A, int n) {
		int *helper = new int[n];
		mergeHelper(A, helper, 0, n - 1);
		delete[] helper;
		return A;
	}
	static void quickHelper(int *A, int left, int right) {
		if (left >= right)
			return;
		int pivot = A[left];
		int i = left;
		int j = right;
		while (i < j) {
			while (A[j] >= pivot && j > i)
				j--;
			while (A[i] <= pivot && i < j)
				i++;
			if (i < j) {
				int tem = A[j];
				A[j] = A[i];
				A[i] = tem;
			}
		}
		A[left] = A[i];
		A[i] = pivot;
		quickHelper(A, left, i - 1);
		quickHelper(A, i + 1, right);
	}
	static int *quickSort(int *A, int n) {
		quickHelper(A, 0, n - 1);
		return A;
	}
	static int *heapSort(int *A, int n) {

	}
	static int *shellSort(int *A, int n) {
		int gap = n / 2;
		while (gap >= 1) {
			for (int i = gap; i < n; i++) {
				if (A[i] < A[i - gap]) {
					int j = i - gap;
					int x = A[i];
					while (x < A[j] && j >= 0) {
						A[j + gap] = A[j];
						j -= gap;
					}
					A[j + gap] = x;
				}
			}
			gap /= 2;
		}
		return A;
	}
	static int *countingSort(int *A, int n) {
		const int maxsize = 10000;
		int *bucket = new int[maxsize];
		memset(bucket, 0, maxsize * sizeof(int));
		for (int i = 0; i < n; i++) {
			bucket[A[i]]++;
		}
		int count = 0;
		for (int i = 0; i < maxsize; i++) {
			if (bucket[i] != 0) {
				for (int j = 0; j < bucket[i]; j++) {
					A[count++] = i;
				}
			}
		}
		return A;
	}
	static int *radixSort(int *A, int n) {

		return A;
	}
	/*
	 * 荷兰其问题
	 */
	vector<int> sortThreeColor(vector<int> A, int n) {
		int begin = 0;
		int end = A.size() - 1;
		int cur = 0;

		while (cur <= end) {
			if (A[cur] == 0) {
				swap(A[cur], A[begin]);
				cur++;
				begin++;
			} else if (A[cur] == 1) {
				cur++;
			} else {
				swap(A[cur], A[end]);
				end--;
			}
		}
		return A;
	}
	/*
	 * 找出已经排序的方阵中是否含有某个数
	 */
	bool findX(vector<vector<int>> mat, int x) {
		int row = mat.size();
		int col = mat[0].size();
		int i = col - 1;
		int j = 0;
		while (i >= 0 && j < row) {
			if (mat[j][i] > x)
				i--;
			else if (mat[j][i] < x)
				j++;
			else
				return true;
		}
		return false;
	}
	/*
	 * 需要排序的最短子数组长度
	 */
	static int shortestSubsequence(vector<int> A, int n) {
		int max = A[0];
		int posmax = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] >= max) {
				max = A[i];
			} else {
				posmax = i;
			}
		}
		cout << "max " << max << " pos " << posmax << endl;
		int min = A[n - 1];
		int posmin = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (A[i] <= min) {
				min = A[i];
			} else {
				posmin = i;
			}
		}
		cout << "min " << min << " pos " << posmin << endl;
		if (posmax == 0 && posmin == 0)
			return 0;
		return posmax - posmin + 1;
	}
	/*
	 * 排序数组中相邻元素的最大差值
	 */
	int maxGap(vector<int> A, int n) {
		int max = A[0];
		int min = A[0];
		for (int i = 0; i < n; i++) {
			if (A[i] > max)
				max = A[i];
			if (A[i] < min)
				min = A[i];
		}
		int size = max - min + 1;
		int *bucket = new int[size];
		memset(bucket, 0, size * sizeof(int));
		for (int i = 0; i < n; i++) {
			bucket[A[i] - min] = 1;
		}
		int count = 0;
		int res = 0;
		for (int i = 0; i < size; i++) {
			if (bucket[i] == 0)
				count++;
			else
				count = 0;
			if (res < count)
				res = count;
		}
		delete[] bucket;
		if (res == 0)
			return 0;
		return res + 1;
	}
	bool isOddNumber(int data) {
		return (data & 1) == 1;
	}
	void OddWvenSort(vector<int> arr) {
		if (arr.empty())
			return;
		int head = 0;
		int tail = arr.size() - 1;
		while (head < tail) {
			if (isOddNumber(arr[head])) {
				head++;
			} else if (!isOddNumber(arr[tail])) {
				tail--;
			} else {
				swap(arr[head], arr[tail]);
			}
		}
	}
	static void test() {
		int A[] = { 1, 2, 10, 1, 8, 9 };
		int n = sizeof(A) / sizeof(A[0]);
		vector<int> aa(A, A + n);
//		bubbleSort(A, n);
//		selectSort(A, n);
//		insertSort(A, n);
//		mergeSort(A, n);
//		quickSort(A, n);
//		shellSort(A, n);
//		countingSort(A, n);
		cout << shortestSubsequence(aa, n) << endl;
		print(A, n);
	}
};
class AboutStack {
public:
	static vector<int> reverseStack(vector<int> A, int n) {
		if (n == 0)
			return A;
		else {
			int cur = getStackBottom(A, n);
			n--;
			reverseStack(A, n);
			A[n] = cur;
			return A;
		}
	}
	static int getStackBottom(vector<int> A, int n) {
		int res = A[n - 1];
		n--;
		if (n == 0) {
			return res;
		} else {
			int cur = getStackBottom(A, n);
			A[n - 1] = res;
			return cur;
		}
	}
	static vector<int> twoStacksSort(vector<int> numbers) {
		// write code here
		stack<int> helper;
		int index = 0;
		int n = numbers.size();
		int tem = numbers[index];
		while (index < n) {
			if (helper.empty() || tem <= helper.top()) {
				helper.push(tem);
				if (index < n - 1)
					tem = numbers[++index];
				else
					break;
			} else {
				numbers[index] = helper.top();
				helper.pop();
				index--;
			}
		}
		while (index >= 0) {
			numbers[index] = helper.top();
			helper.pop();
			index--;
		}
		return numbers;
	}
	static vector<int> slide(vector<int> arr, int n, int w) {
		vector<int> res;
		if (n < w)
			return res;
		int pre = 0;
		int next = 0;
		int max = arr[0];
		for (int next = 1; next < w; next++) {
			if (arr[next] > max)
				max = arr[next];
		}
		res.push_back(max);
		for (int next = w; next < n; next++) {
			if (arr[pre] < max) {
				if (arr[next] >= max)
					max = arr[next];
			} else {
				max = arr[pre + 1];
				for (int i = pre + 2; i <= next; i++) {
					if (arr[i] > max)
						max = arr[i];
				}
			}
			pre++;
			res.push_back(max);
		}
		return res;
	}
	static void test() {
		vector<int> A = { 1, 2, 3, 4, 6, 5, 4 };
		vector<int> B = twoStacksSort(A);
		for (int i = 0; i < B.size(); i++) {
			cout << B[i] << " ";
		}
		cout << endl;
	}
};
class AboutList {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) :
				val(x), next(NULL) {
		}
	};
	static ListNode *create(vector<int> a) {
		ListNode *dummy = new ListNode(0);
		ListNode *cur = dummy;
		for (int i = 0; i < a.size(); i++) {
			ListNode *node = new ListNode(a[i]);
			cur->next = node;
			cur = cur->next;
		}
		ListNode *head = dummy->next;
		delete dummy;
		return head;
	}
	static ListNode *listDivide(ListNode *head, int val) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *low = NULL, *p1 = NULL;
		ListNode *high = NULL, *p2 = NULL;
		while (head != NULL) {
			ListNode *next = head->next;
			head->next = NULL;
			if (head->val <= val) {
				if (low == NULL) {
					low = head;
					p1 = low;
				} else {
					low->next = head;
					low = low->next;
				}
			} else {
				if (high == NULL) {
					high = head;
					p2 = high;
				} else {
					high->next = head;
					high = high->next;
				}
			}
			head = next;
		}
		head = NULL;
//		print(p1);
//		print(p2);
//		print(p3);
		if (p1 != NULL && p2 == NULL) {
			head = p1;
		} else if (p2 != NULL && p1 == NULL) {
			head = p2;
		} else if (p1 != NULL && p2 != NULL) {
			head = p1;
			low->next = p2;
		} else {
			head = NULL;
		}

		return head;
	}
	static vector<int> findCommonParts(ListNode *headA, ListNode *headB) {
		vector<int> res;
		if (!headA || !headB)
			return res;
		while (headA != NULL && headB != NULL) {
			if (headA->val < headB->val) {
				headA = headA->next;
			} else if (headA->val == headB->val) {
				res.push_back(headA->val);
				headA = headA->next;
				headB = headB->next;
			} else {
				headB = headB->next;
			}
		}
		return res;
	}
	ListNode* inverse(ListNode* head, int k) {
		if (head == NULL || k <= 0)
			return head;

		stack<int> help;
		int i = 0;
		ListNode * currNode = head;
		ListNode * newHead = head;
		while (currNode) {
			help.push(currNode->val);
			++i;

			if (i == k) {
				while (!help.empty()) {
					newHead->val = help.top();
					help.pop();
					newHead = newHead->next;
				}
				i = 0;
			}
			currNode = currNode->next;
		}
		return head;
	}
	ListNode *clear(ListNode *head, int val) {
		if (!head)
			return head;
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *pre = dummy;
		ListNode *cur = head;

		while (cur != NULL) {
			if (cur->val == val) {
				pre->next = cur->next;
				delete cur;
				cur = pre->next;
			} else {
				pre = pre->next;
				cur = pre->next;
			}
		}
		ListNode *newHead = dummy->next;
		delete dummy;
		return newHead;
	}
	static bool isPalindrome(ListNode *pHead) {
		if (!pHead)
			return false;
		if (!pHead->next)
			return true;
		ListNode *faster = pHead;
		ListNode *chaser = pHead;
		stack<ListNode *> s;
		int size = 0;
		while (chaser) {
			chaser = chaser->next;
			size++;
		}
		chaser = pHead;
		while (faster && faster->next) {
			s.push(chaser);
			chaser = chaser->next;
			faster = faster->next->next;
		}
		if (size % 2 == 1) {
			chaser = chaser->next;
		}
		while (chaser) {
			if (chaser->val != s.top()->val)
				return false;
			s.pop();
			chaser = chaser->next;
		}
		if (!s.empty())
			return false;
		return true;
	}
	static void print(ListNode *head) {
		while (head) {
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}
	static void test() {
		vector<int> a = { 1, 3, 4, 4, 2, 1 };
		ListNode *list = create(a);
		print(list);
//		ListNode *res = listDivide(list, 4);
//		print(res);
		cout << isPalindrome(list) << endl;
	}
};
class AboutSearch {
public:
	/*
	 * 寻找局部最小值
	 */
	int getLessIndex(vector<int> arr) {
		int n = arr.size();
		if (n == 0)
			return -1;
		if (n == 1)
			return 0;
		int low = 0;
		int high = n - 1;
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (arr[low] < arr[low + 1])
				return low;
			if (arr[high] < arr[high - 1])
				return high;
			if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
				return mid;
			else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
				high = mid - 1;
			} else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1]) {
				low = mid + 1;
			} else {
				low = mid + 1;
			}
		}
		return -1;
	}
	/*
	 * 找到最靠左的元素的位置
	 */
	int findPos(vector<int> arr, int n, int num) {
		int low = 0;
		int high = n - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] < num) {
				low = mid + 1;
			} else if (arr[mid] > num) {
				high = mid - 1;
			} else {
				while (arr[mid] == num) {
					mid--;
				}
				return mid + 1;
			}
		}
		return -1;
	}
	/*
	 * 寻找循环移位后序列的最小值：4123
	 */
	static int getMin(vector<int> arr, int n) {
		if (n <= 0)
			return -1;
		if (n == 1)
			return arr[0];
		int low = 0;
		int high = n - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[(mid + n - 1) % n] > arr[mid]
					&& arr[mid] <= arr[(mid + n + 1) % n])
				return arr[mid];
			if (arr[low] > arr[high]) {
				if (arr[mid] > arr[high]) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			} else {
				high = mid - 1;
			}
			cout << "mid= " << arr[mid] << endl;
		}
		return -1;
	}

	static int findPos(vector<int> arr, int n) {
		if (n == 0)
			return -1;
		int low = 0;
		int high = n - 1;
		int res = -1;
		while (low <= high) {
			if (arr[low] > low || arr[high] < high) {
				break;
			}
			int mid = low + (high - low) / 2;
			if (arr[mid] < mid) {
				low = mid + 1;
			} else if (arr[mid] > mid) {
				high = mid - 1;
			} else {
				res = mid;
				high = mid - 1;
			}
		}
		return res;
	}
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	static int count(TreeNode *root) {
		if (!root)
			return 0;
		return 1 + count(root->left) + count(root->right);
	}
	long long num = 1000000007;
	int getPower(int k, int N) {
		// write code here
		if (N == 0)
			return 0;
		if (N == 1)
			return k;
		long long tmp = getPower(k, N >> 1) % num;
		tmp = (tmp * tmp) % num;
		if (N & 1)
			tmp = tmp * (long long) k % num;
		return (int) tmp;
	}
	static void test() {
		vector<int> a = { 443, 449, 454, 456, 457, 458, 459, 459, 459, 467, 467,
				470, 474, 476, 478, 480, 481, 482, 490, 490, 491, 495, 496, 500,
				500, 501, 502, 503, 505, 507, 509, 510, 512, 515, 516, 520, 520,
				521, 522, 525, 526, 528, 528, 529, 543, 545, 548, 548, 550, 552,
				552, 555, 562, 563, 564, 574, 576, 576, 577, 580, 580, 584, 586,
				589, 590, 593, 600, 602, 602, 603, 603, 610, 612, 616, 618, 618,
				622, 625, 1, 1, 2, 4, 4, 5, 5, 6, 7, 18, 18, 23, 29, 30, 33, 34,
				44, 47, 48, 48, 52, 62, 71, 72, 73, 73, 73, 76, 78, 82, 84, 84,
				86, 87, 88, 88, 91, 91, 92, 93, 98, 99, 102, 103, 105, 106, 107,
				110, 110, 114, 115, 122, 122, 124, 127, 130, 131, 134, 134, 134,
				138, 138, 143, 144, 146, 147, 148, 155, 156, 158, 159, 161, 161,
				164, 168, 170, 173, 175, 193, 193, 199, 200, 201, 202, 203, 206,
				210, 213, 215, 215, 216, 216, 217, 220, 221, 222, 223, 226, 227,
				229, 231, 236, 241, 242, 242, 243, 244, 245, 245, 246, 252, 253,
				254, 258, 259, 259, 260, 260, 264, 265, 266, 269, 270, 274, 275,
				277, 279, 280, 282, 293, 294, 297, 302, 309, 311, 312, 314, 315,
				317, 318, 318, 322, 328, 331, 331, 337, 337, 337, 338, 339, 343,
				344, 345, 345, 347, 351, 360, 363, 367, 368, 369, 372, 376, 379,
				381, 389, 395, 403, 403, 406, 406, 407, 407, 407, 415, 419, 419,
				421, 422, 425, 428, 429, 429, 430, 434, 437, 437 };
		cout << getMin(a, a.size()) << endl;
	}
};
class AboutBits {
public:
	vector<int> getSwap(vector<int> num) {
		num[0] = num[0] ^ num[1];
		num[1] = num[0] ^ num[1];
		num[0] = num[0] ^ num[1];
		return num;
	}
	/*
	 * 判断两数大小
	 */
	int getMax(int a, int b) {
		// write code here
		int c = a - b;
		int sa = sign(a);
		int sb = sign(b);
		int sc = sign(c);

		int diff = sa ^ sb;
		int same = filp(diff);

		int returnA = diff * sa + same * sc;
		return returnA * a + filp(returnA) * b;
	}
	int filp(int v) {
		return v ^ 1;
	}
	int sign(int v) {
		return filp((v >> 31) & 1);
	}
	int findOdd(vector<int> A, int n) {
		// write code here
		int res = 0;
		for (int i = 0; i < n; i++) {
			res ^= A[i];
		}
		return res;
	}
	vector<int> findOdds(vector<int> arr, int n) {
		int e0 = 0;
		for (int i = 0; i < n; i++)
			e0 ^= arr[i];
		int flag = 1;
		while ((e0 & flag) != flag) {
			flag = flag << 1;
		}
		int e1 = 0;
		for (int i = 0; i < n; i++) {
			if ((arr[i] & flag) == flag)
				e1 ^= arr[i];
		}
		vector<int> res;
		int a = e1;
		int b = e0 ^ e1;
		if (a > b) {
			res.push_back(b);
			res.push_back(a);
		} else {
			res.push_back(a);
			res.push_back(b);
		}
		return res;
	}
};
class AboutDP {
public:
	int countWays(int n) {
		int *dp = new int[n];
		dp[0] = 1;
		dp[1] = 2;
		for (int i = 2; i < n; i++) {
			dp[i] = (dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007)
					% 1000000007;
		}
		int res = dp[n - 1];
		delete[] dp;
		return res;
	}

	int getMin(vector<vector<int>> map, int n, int m) {
		vector<vector<int>> dp(n);
		for (int i = 0; i < dp.size(); i++) {
			dp[i].resize(m);
		}
		dp[0][0] = map[0][0];
		for (int i = 1; i < n; i++) {
			dp[i][0] += dp[i - 1][0] + map[i][0];
		}
		for (int i = 1; i < m; i++) {
			dp[0][i] += dp[0][i - 1] + map[0][i];
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (dp[i][j - 1] < dp[i - 1][j]) {
					dp[i][j] += dp[i][j - 1] + map[i][j];
				} else {
					dp[i][j] += dp[i - 1][j] + map[i][j];
				}
			}
		}
		return dp[n - 1][m - 1];
	}
	int getLIS(vector<int> A, int n) {
		if (0 == n)
			return 0;
		vector<int> res(n);
		int lis = 1;
		res[0] = 1;
		for (int i = 1; i < n; ++i) {
			int max = 0;
			for (int j = 0; j < i; ++j) {
				if (A[j] < A[i] && res[j] > max)
					max = res[j];
			}
			res[i] = max + 1;
			lis = res[i] > lis ? res[i] : lis;
		}
		return lis;
	}
};
#endif /* INC_NIUKEVIDEO_H_ */
