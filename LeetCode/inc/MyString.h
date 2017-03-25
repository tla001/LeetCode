/*
 * MyString.h
 *
 *  Created on: 2017年3月21日
 *      Author: tla001
 */

#ifndef INC_MYSTRING_H_
#define INC_MYSTRING_H_

#include "Include.h"
class MyString {
public:
	/*
	 * 字符串比较问题
	 * 对比两个字符串是否一致，可以使用哈希表，哈希之后，对比哈希表是否一致即可
	 */
	bool chkTransform(string A, int lena, string B, int lenb) {
		int *hash = new int[256];
		memset(hash, 0, sizeof(int) * 256);
		for (int i = 0; i < lenb; i++) {
			hash[A[i]]++;
		}
		for (int i = 0; i < lenb; i++) {
			if (hash[B[i]]-- == 0)
				return false;
		}
		return true;
	}
	/*
	 * 旋转词问题
	 * 如果B的元素可以全部在A中找到，则B是A的旋转词
	 * 解法：A+A穷举了A所有可能的旋转词，用B在A+A中做匹配即可
	 */
	bool chkRotation(string A, int lena, string B, int lenb) {
		if (A.empty() || B.empty() || lena != lenb)
			return false;
		string C = A + A;
		string D = B + B;
		if ((C.find(B.c_str(), 0, lenb) != string::npos)
				&& (D.find(A.c_str(), 0, lena) != string::npos))
			return true;
		return false;
	}
	/*
	 * 翻转句子，以空格为分隔符
	 */
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
		int begin = 0;
		int end = 0;
		for (int i = 0; i < n; i++) {
			if (res[i] == ' ') {
				end = i - 1;
				reverse(res, begin, end);
				begin = i + 1;
			}
		}
		reverse(res, begin, n - 1);
		return res;
	}
	/*
	 * 给出一些短字符串，拼接得到按字母表最小的字符串
	 */
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
	/*
	 * 循环移位
	 */
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
	/*
	 * 替换字符串中的空格
	 */
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
	/*
	 * 判断字符串中左右括号是否配对
	 */
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
	/*
	 * 给定一个字符串，求最大无重复字符子串的长度
	 */
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
	/*
	 * 将字符串转换成整数
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
	/*
	 * 判断回文
	 * 从两端到中间
	 */
	bool isPalindrome(char *str) {
		if (str == NULL)
			return false;
		int length = strlen(str);
		//cout << "length= " << length << endl;
		int head = 0;
		int tail = length - 1;
		while (head <= tail) {
			if (str[head] == str[tail]) {
				head++;
				tail--;
			} else {
				return false;
			}
		}
		return true;
	}
	/*
	 * 先从中间开始、然后向两边扩展查看字符是否相等
	 *
	 */
	bool isPalindrome2(char *str) {
		if (str == NULL)
			return false;
		int length = strlen(str);
		int mid;
		int tohead;
		int totail;
		if (length % 2 == 0) {
			mid = length / 2;
			tohead = mid - 1;
			totail = mid;
		} else {
			mid = (length - 1) / 2;
			tohead = mid - 1;
			totail = mid + 1;
		}
		while (tohead >= 0) {
			if (str[tohead--] != str[totail++])
				return false;
		}
		return true;
	}
	/*
	 * 最长回文子串
	 */
	int longestPalindrom(const char *str) {
		if (str == NULL)
			return 0;
		int length = strlen(str);
		int max = 0;
		int c = 0;
		for (int i = 0; i < length; i++) {
			for (int j = 0; (i - j >= 0) && (i + j) < length; j++) {
				if (str[i - j] != str[i + j])
					break;
				c = 2 * j + 1;
			}
			if (c > max)
				max = c;
			for (int j = 0; (i - j >= 0) && (i + j) < length; j++) {
				if (str[i - j] != str[i + j + 1])
					break;
				c = 2 * j + 2;
			}
			if (c > max)
				max = c;
		}
		return max;
	}
	/*
	 * 字符串全排列
	 */
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
	/*
	 * 数组中连续子序列和最大值
	 */
	int maxSubSequence(vector<int> arr) {
		int maxSum = arr[0];
		int curSum = 0;
		for (int i = 0; i < arr.size(); i++) {
			curSum = (arr[i] > curSum + arr[i]) ? arr[i] : curSum + arr[i];
			maxSum = (curSum > maxSum) ? curSum : maxSum;
		}
		return maxSum;
	}
	/*
	 * longest common prefix
	 */
	static string commonPrefix(vector<string>&strs) {
		string res;
		if (strs.size() < 1)
			return res;
		char prefix; //不要直接赋‘a’，因为你也不知道第一个是什么
		bool isprefix = true;
		for (int j = 0; j < strs[0].size(); j++) {
			prefix = strs[0][j];
			for (int i = 0; i < strs.size(); i++) {
				if (strs[i][j] != prefix) {
					isprefix = false;
					break;
				}
			}
			if (!isprefix)
				break;
			res += prefix;
		}
		return res;
	}
	static void test() {
		vector<string> strs= {"abcd","abcde","abcdef","abcf"};
		cout<<commonPrefix(strs)<<endl;
	}
};

#endif /* INC_MYSTRING_H_ */
