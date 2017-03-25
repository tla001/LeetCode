/*
 * Program2016.h
 *
 *  Created on: 2017年3月1日
 *      Author: tla001
 */

#ifndef INC_PROGRAM2016_H_
#define INC_PROGRAM2016_H_

#include "Include.h"
#include <limits>
class NetEasy {
public:
	static void timesToPali() {
		int n;
		while (cin >> n) {
			vector<int> v;
			int a;
			int times = 0;
			for (int i = 0; i < n; i++) {
				cin >> a;
				v.push_back(a);
			}
			int start = 0;
			int end = n - 1;
			while (start <= end) {
				if (v[start] == v[end]) {
					start++;
					end--;
				} else if (v[start] < v[end]) {
					times++;
					v[start + 1] += v[start];
					start++;
				} else {
					times++;
					v[end - 1] += v[end];
					end--;
				}
			}
			cout << times << endl;
		}
	}

	static void getBetterPoints() {
		int r;
		while (cin >> r) {
			int end = sqrt(r);
			int start = 0;
			int dtimes = 0;
			int stimes = 0;
			while (start <= end) {
				int sum = start * start + end * end;
				if (sum == r) {
					cout << "sum= " << sum << " start= " << start << " end="
							<< end << endl;
					if (start == end || start == 0)
						stimes++;
					else
						dtimes++;
					start++;
				} else if (sum < r)
					start++;
				else
					end--;
			}
			cout << dtimes * 8 + 4 * stimes << endl;
		}
	}
	static void getFactors(int n, vector<int> &factors) {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				factors.push_back(i);
				if (n / i != i)
					factors.push_back(n / i);
			}
		}
	}
	/*
	 * 跳石板
	 */
	static void getMinSteps() {
		int n, m;
		while (cin >> n >> m) {
			vector<int> steps(m + 1, 0);
			steps[n] = 1;
			for (int i = n; i <= m; i++) {
				if (steps[i] == 0)
					continue;
				vector<int> factors;
				getFactors(i, factors);
				for (int j = 0; j < factors.size(); j++) {
					if (factors[j] + i <= m) {
						if (steps[factors[j] + i] == 0)
							steps[factors[j] + i] = steps[i] + 1;
						else
							steps[factors[j] + i] =
									(steps[i] + 1) < steps[factors[j] + i] ?
											(steps[i] + 1) :
											steps[factors[j] + i];
					}
				}
			}
			if (steps[m] == 0)
				cout << -1 << endl;
			else
				cout << steps[m] - 1 << endl;
		}
	}
	/*
	 * 暗黑的字符串
	 */
	static void getBlackNums() {
		int n;
		while (cin >> n) {
			if (n == 1)
				cout << 3 << endl;
			if (n == 2)
				cout << 9 << endl;
			long long dp[2];
			dp[0] = 3;
			dp[1] = 6;
			for (int i = 2; i < n; i++) {
				long long temp0 = dp[0];
				long long temp1 = dp[1];
				dp[0] = temp0 + temp1;
				dp[1] = 2 * temp0 + temp1;
			}
			cout << dp[0] + dp[1] << endl;
		}
	}
	/*
	 * 数字翻转
	 */
	static int turnNum(int num) {
		if (num < 10)
			return num;
		int res = 0;
		vector<int> v;
		while (num > 0) {
			if (num % 10 != 0 || !v.empty())
				v.push_back(num % 10);
			num /= 10;
		}
		for (int i = 0; i < v.size(); i++) {
			res = res * 10 + v[i];
		}
		return res;
	}
	static void turnNums() {
		int x, y;
		while (cin >> x >> y) {
			int a = turnNum(x);
			int b = turnNum(y);
			cout << turnNum(a + b) << endl;
		}
	}
	static int getMinFactor(int num) {
		while (num % 2 == 0) {
			num /= 2;
		}
		return num;
	}
	static void calF() {
		int n;
		while (cin >> n) {
			long long sum = 0;
//			for (int i = 1; i <= n; i++) {
//				sum += getMinFactor(i);
//			}
			for (long i = n; i > 0; i = i / 2) {
				long temp = (i + 1) / 2;
				sum += temp * temp;
			}
			cout << sum << endl;
		}
	}
	/*
	 * 买苹果
	 */
	static void buyApple() {
		int n;

		while (cin >> n) {
			vector<int> table(n + 1, (numeric_limits<int>::max)());
			table[0] = 0;
			vector<int> vec = { 6, 8 };
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < vec.size(); j++) {
					if (i >= vec[j] && table[i] > table[i - vec[j]])
						table[i] = table[i - vec[j]] + 1;
				}
			}
			if (table[n] == (numeric_limits<int>::max)())
				cout << -1 << endl;
			else
				cout << table[n] << endl;
		}
	}
	/*
	 * 计算abc
	 */
	static void calABC() {
		int h1, h2, h3, h4;
		while (cin >> h1 >> h2 >> h3 >> h4) {
			int A = (h1 + h3) / 2;
			int B = (h2 + h4) / 2;
			int C = h4 - B;
			if ((A - B == h1) && (B - C == h2) && (A + B == h3)
					&& (B + C == h4))
				cout << A << " " << B << " " << C << endl;
			else
				cout << "No" << endl;
		}
	}

	/*
	 * 洗牌
	 */
	static void reverse(vector<int>&v, int n) {
		for (int i = 0; i < n / 2; i++) {
			swap(v[n + i], v[2 * n - i - 1]);
		}
	}
	static void refreshCards() {
		int t;
//		vector<int> a = { 1, 2, 3, 4, 5, 6 };
//		reverse(a, 3);
//		for (int i = 0; i < a.size(); i++)
//			cout << a[i] << " ";
		while (cin >> t) {
			for (int x = 0; x < t; x++) {
				int n, k;
				cin >> n >> k;
				int a;
				vector<int> v(2 * n, 0);
				for (int i = 0; i < 2 * n; i++) {
					cin >> a;
					v[i] = a;
				}
				for (int i = 0; i < k; i++) {
					reverse(v, n);
					vector<int> tmp;
					for (int j = 0; j < n; j++) {
						tmp.push_back(v[j]);
						tmp.push_back(v[2 * n - j - 1]);
					}
					v = tmp;
				}
				for (int i = 0; i < v.size() - 1; i++)
					cout << v[i] << " ";
				cout << v[v.size() - 1] << endl;
			}
		}
	}
};

#endif /* INC_PROGRAM2016_H_ */
