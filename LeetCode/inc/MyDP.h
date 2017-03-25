/*
 * MyDP.h
 *
 *  Created on: 2017��3��22��
 *      Author: tla001
 */

#ifndef INC_MYDP_H_
#define INC_MYDP_H_

#include "Include.h"
#include <limits>
class MyDP {
public:
	/*
	 * ��̨������
	 */
	int climbStairs(int n) {
		if (n <= 1)
			return 1;
		if (n == 2)
			return 2;
		int p = 1, q = 2, curr;
		for (int i = 3; i <= n; i++) {
			curr = p + q;
			p = q;
			q = curr;
		}
		return curr;
	}
	/*
	 * �����n������
	 * ��ǰ�����ܱ�֮ǰ����������
	 */
	int getNthPrime(int n) {
		list<int> primes(1, 2); //��ʼ������Ϊ1��ֵΪ2
		int number = 3;
		while (primes.size() != n) {
			bool isPrime = true;
			for (list<int>::const_iterator ite = primes.begin();
					ite != primes.end() && (*ite) * (*ite) != number; ite++) {
				if (number % (*ite) == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				primes.push_back(number);
			}
			number += 2;
		}
		return *(primes.rbegin());
	}
	/*
	 * ����һ���ַ����Ͱ���һЩ���ʵ��ֵ䣬�ж��ַ����Ƿ� �����ɼ����������
	 */
	bool wordBreak(string s, unordered_set<string> &dict) {
		int begin = 0, end = 0;
		string word;
		bool words[s.size() + 1] = { 0 };
		words[0] = true;
		for (int i = 1; i <= s.size(); i++) {
			words[i] = false;
		}
		for (end = 0; end < s.size(); end++) {
			for (begin = 0; begin <= end; begin++) {
				if (words[begin]
						&& dict.find(s.substr(begin, end - begin + 1))
								!= dict.end()) {
					words[end + 1] = true;
					break;
				}
			}
		}
		return words[s.size()];
	}
	/*
	 * ����һ���ַ����������иʹ�и���ÿһ�ζ���һ�����ģ����ػ��ķָ��������С�ָ����
	 */
	int getMin(string s) {
		if (s.empty())
			return 0;
		vector<vector<bool>> palin(s.size(), vector<bool>(s.size(), false));
		vector<int> mincut(s.size() + 1, 0);
		for (int i = 0; i <= s.size(); i++) {
			mincut[i] = s.size() - i - 1;
		}
		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = i; j < s.size(); j++) {
				if (s[i] == s[j] && (j - i <= 1 || palin[i + 1][j - 1])) {
					palin[i][j] = true;
					mincut[i] = min(mincut[j + 1] + 1, mincut[i]);
				}
			}
		}
		return mincut[0];
	}
	/*
	 * �����˴ӣ�0,0���ƶ�����x��y���ж�����·��
	 */
	static int uniquePaths(int m, int n) {
		int **dp = new int*[m];
		for (int i = 0; i < m; i++) {
			dp[i] = new int[n];
			dp[i][0] = 1;
		}
		for (int i = 0; i < n; i++) {
			dp[0][i] = 1;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		int res = dp[m - 1][n - 1];
		for (int i = 0; i < m; i++) {
			delete[] dp[i];
		}
		delete[] dp;
		return res;
	}
	static int uniquePaths1(int m, int n) {
		int ways[n] = { 0 };
		ways[n - 1] = 1;
		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 2; j >= 0; --j)
				ways[j] += ways[j + 1];
		}
		return ways[0];
	}
	/*
	 * ��Ӳ������
	 */
	/*
	 * change coins
	 * ���з���
	 */
	int countWaysToChange(vector<int> s, int n) {
		vector<int> table(n + 1, 0);
		table[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 0; i < s.size(); j++)
				table[i] += (i - s[j] >= 0) ? table[i - s[j]] : 0;
		return table[n];
	}
	/*
	 * �����ΪN�������ٵ�Ӳ����Ŀ
	 */
	int minNumOfCoins(vector<int> s, int n) {
		vector<int> table(n + 1, (numeric_limits<int>::max)());
		table[0] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < s.size(); j++) {
				if (i >= s[i] && table[i] > table[i - s[j]])
					table[i] = table[i - s[j]] + 1;
			}
		return table[n];
	}
	/*
	 * �����������
	 */
	/*
	 * ��һ�����������У��ҵ���ĵ���������
	 * LIS longest increasing sequence
	 */
	static int longestIncreaseSubsequence(int arr[], int n) {
		vector<int> maxLength(n, 1);
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j] && maxLength[j] + 1 > maxLength[i]) {
					maxLength[i] = maxLength[j] + 1;
					if (max < maxLength[i])
						max = maxLength[i];
				}
			}
		}
		return max;
	}
	/*
	 * ��һ���������ҵ�һ�������������飬ʹ�����
	 */
	static int getMaxSubSeq(vector<int> arr) {
		int maxSum = 0;
		int curSum = 0;
		for (int i = 0; i < arr.size(); i++) {
			curSum = max(curSum + arr[i], arr[i]);
			if (curSum > maxSum)
				maxSum = curSum;
		}
		return maxSum;
	}
	/*
	 * gas station
	 */
	static int canCompleteCircuit(vector<int>&gas, vector<int> &cost) {
		if (gas.size() != cost.size() || gas.size() == 0)
			return -1;
		int total = 0;
		int sum = 0;
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
	/*
	 * ������Ӵ�����
	 * LCS longest common sequence
	 */
	static int lcs(string str1, string str2) {
		vector<vector<int>> length(str1.size() + 1,
				vector<int>(str2.size() + 1));
		for (int i = 0; i < str1.size(); i++) {
			for (int j = 0; j < str2.size(); j++) {
				if (i == 0 || j == 0)
					length[i][j] = 0;
				else if (str1[i] == str2[j])
					length[i][j] = length[i - 1][j - 1] + 1;
				else
					length[i][j] = max(length[i - 1][j], length[i][j - 1]);
			}
		}
		return length[str1.size()][str2.size()];
	}
	/*
	 * ��Ʊ�������
	 */
	static int maxProfit(vector<int> prices) {
		vector<int> profit(prices.size(), 0);
		int minPrice = prices[0];
		int maxProfit = 0;
		for (int i = 1; i < prices.size(); i++) {
			profit[i] = max(profit[i - 1], prices[i] - minPrice);
			minPrice = min(minPrice, prices[i]);
			maxProfit = max(maxProfit, profit[i]);
		}
		return maxProfit;
	}
	/*
	 * ��ǰԪ������������Ԫ�س˻��滻
	 */
	static void replaceWithProducts(vector<int>&elements) {
		int size = elements.size();
		int product = 1;
		vector<int> table(size, 0);
		for (int i = 0; i < size; i++) {
			table[i] = product;
			product *= elements[i];
		}
		product = 1;
		for (int i = size - 1; i >= 0; i--) {
			int temp = elements[i];
			elements[i] = table[i] * product;
			product *= temp;
		}
	}
	/*
	 * ��ˮ������
	 */
	static int maxTrap(vector<int> arr) {
		vector<int> table(arr.size() - 2, 0);
		int maxvalue = 0;
		for (int i = 1; i < arr.size() - 1; i++) {
			table[i] = max(max(arr[i - 1], arr[i + 1]) - arr[i], 0);
			maxvalue = max(table[i], maxvalue);
		}
		return maxvalue;
	}
	static void test() {
//		cout << uniquePaths1(3, 4) << endl;
//		int arr[] = { 1, 3, 2, 4 };
//		cout << longestIncreaseSubsequence(arr, 4) << endl;
		vector<int> arr = { 1, 2, 3, 4, 5 };
		replaceWithProducts(arr);
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

#endif /* INC_MYDP_H_ */
