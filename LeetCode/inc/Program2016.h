/*
 * Program2016.h
 *
 *  Created on: 2017Äê3ÔÂ1ÈÕ
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
	 * ÌøÊ¯°å
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
	 * °µºÚµÄ×Ö·û´®
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
	 * Êý×Ö·­×ª
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
	 * ÂòÆ»¹û
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
	 * ¼ÆËãabc
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
	 * Ï´ÅÆ
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

class JingDong {
public:
	static int countWays(int n) {
		if (n == 1)
			return 0;
		if (n == 2)
			return 2;
		if (n == 3)
			return 2;
		int *table = new int[n + 1];
		table[1] = 0;
		table[2] = 1;
		table[3] = 2;
		for (int i = 4; i <= n; i++) {
			table[i] = (table[i - 1] % 1000000007 + table[i - 2] % 1000000007)
					% 1000000007;
		}
		int res = table[n] % 1000000007;
		delete[] table;
		return res;
	}
	static int calcDistance(int A, int B, int C, int D) {
		// write code here
		return (int) distance(A) + distance(B) + distance(C) + distance(D);
	}

	static double distance(double dis) {
		if (dis == 0)
			return 0;
		else
			return dis / 2 * 3 + distance(dis / 2);
	}
	static int getMost(vector<vector<int>> board) {
		vector<vector<int>> table(board);
		for (int i = 1; i < table.size(); i++) {
			table[0][i] = table[0][i - 1] + table[0][i];
			table[i][0] = table[i - 1][0] + table[i][0];
		}
		for (int i = 1; i < table.size(); i++) {
			for (int j = 1; j < table[i].size(); j++) {
				table[i][j] = max(table[i - 1][j], table[i][j - 1])
						+ table[i][j];
			}
		}
		return table[table.size() - 1][table.size() - 1];
	}
	static void test() {
		int n = 88;
//		cout << countWays(n) << endl;
		cout << calcDistance(100, 90, 80, 70) << endl;
	}
};
class Tencent {
public:
	static void printDelNums() {
		string str;
		while (cin >> str) {
			int pos = 0;
			int nums = 0;
			vector<int> table(str.size(), 0);
			for (int i = 0; i < str.size(); i++) {
				if (table[i] == 0) {
					if ((pos = str.find_first_of(str[i], i + 1))
							!= string::npos) {
//						cout << str[i] << endl;
						table[i] = 1;
						table[pos] = 1;
					} else {
						table[i] = 1;
						nums++;
					}
				}
			}
			cout << nums << endl;
		}
	}
	static void moveABC() {
		string str;
		while (cin >> str) {
			int index = str.size() - 1;
			for (int i = str.size() - 1; i >= 0; i--) {
				if (str[i] >= 'A' && str[i] <= 'Z') {
					char tem = str[i];
					for (int j = i; j <= index - 1; j++) {
						str[j] = str[j + 1];
					}
					str[index--] = tem;
//					cout << str << endl;
				}
			}
			cout << str << endl;
		}
	}
	static void getMaxMinDiff() {
		int n;
		while (cin >> n) {
			vector<int> table(n, 0);
			int a;
			for (int i = 0; i < n; i++) {
				cin >> a;
				table[i] = a;
			}
			int maxValue = 0;
			int maxNums = 0;
			int minValue = 0;
			int minNums = 0;

			int tailnum = 1;
			int headnum = 1;
			sort(table.begin(), table.end());
			int maxpoint = table[n - 1];
			int minpoint = table[0];
			for (int i = n - 2; i >= 0; i--) {
				if (maxpoint == table[i])
					tailnum++;
				else
					break;
			}
			for (int i = 1; i < n && minpoint < maxpoint; i++) {
				if (minpoint == table[i])
					headnum++;
				else
					break;
			}
			maxNums = tailnum * headnum;
			for (int i = 0; i < n - 1; i++) {
				int value = abs(table[i] - table[i + 1]);
				if (value == minValue) {
					minNums++;
				}
				if (value < minValue) {
					minValue = value;
					minNums = 1;
				}
			}
//			for (int i = 0; i < n; i++) {
//				for (int j = i + 1; j < n; j++) {
//					int value = abs(table[i] - table[j]);
//					if (value == maxValue) {
//						maxNums++;
//					}
//					if (value > maxValue) {
//						maxValue = value;
//						maxNums = 1;
//					}
//					if (value == minValue) {
//						minNums++;
//					}
//					if (value < minValue) {
//						minValue = value;
//						minNums = 1;
//					}
//				}
//			}
			cout << minNums << " " << maxNums << endl;
		}
	}

	static vector<string> getGray(int n) {
		vector < string > res;
		if (n == 1) {
			res.push_back("0");
			res.push_back("1");
			return res;
		}
		vector < string > v = getGray(n - 1);
		int len = pow(2, n - 1);
		for (int i = 0; i < len; i++) {
			res.push_back("0" + v[i]);
		}
		for (int i = len - 1; i >= 0; i--) {
			res.push_back("1" + v[i]);
		}
		return res;
	}
	static int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		int pre, cur;
		pre = cur = gifts[0];
		int sum = 1;
		for (int i = 1; i < gifts.size(); i++) {
			cur = gifts[i];
			if (pre != cur) {
				sum = 0;
			}
			sum++;
			if (sum > n / 2)
				return cur;
			if ((n - i + sum) < (n / 2 + 1))
				break;
			pre = cur;
		}
		return 0;
	}
};
class BaiDu {
public:
	static void transCrimer() {
		int n, t, c;
		while (cin >> n >> t >> c) {
			vector<int> v(n, 0);
			int a;
			for (int i = 0; i < n; i++) {
				cin >> a;
				v[i] = a;
			}
			int pre = v[0];
			int sum = 0;
			int nums = 0;
			for (int i = 0; i < c; i++) {
				sum += v[i];
			}
			if (sum <= t)
				nums++;
			for (int i = c; i < n; i++) {
				sum -= pre;
				sum += v[i];
				pre = v[i - c + 1];
				if (sum <= t)
					nums++;
			}
			cout << nums << endl;
		}
	}
	static void getArea() {
		int n;
		while (cin >> n) {
			int maxdiff_x = 0;
			int curdiff_x = 0;
			int maxvalue_x = 0;
			int minvalue_x = 0;
			int maxdiff_y = 0;
			int curdiff_y = 0;
			int maxvalue_y = 0;
			int minvalue_y = 0;
			int x, y;
			cin >> x >> y;
			maxvalue_x = x;
			minvalue_x = x;
			maxvalue_y = y;
			minvalue_y = y;
			for (int i = 1; i < n; i++) {
				cin >> x >> y;
				curdiff_x = max(max(abs(x - maxvalue_x), abs(x - minvalue_x)),
						curdiff_x);
				if (curdiff_x > maxdiff_x)
					maxdiff_x = curdiff_x;
				if (x > maxvalue_x)
					maxvalue_x = x;
				if (x < minvalue_x)
					minvalue_x = x;
				curdiff_y = max(max(abs(y - maxvalue_y), abs(y - minvalue_y)),
						curdiff_y);
				if (curdiff_y > maxdiff_y)
					maxdiff_y = curdiff_y;
				if (y > maxvalue_y)
					maxvalue_y = y;
				if (y < minvalue_y)
					minvalue_y = y;
			}
			int maxvalue = max(maxdiff_x, maxdiff_y);
			cout << maxvalue * maxvalue << endl;
		}
	}

	static void goFish() {
		int n, m, x, y, t;
		while (cin >> n >> m >> x >> y >> t) {
			vector<vector<double>> table(n, vector<double>(m, 0.0));
			double avp = 0.0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cin >> table[i][j];
					avp += table[i][j];
				}
			}
			avp /= m * n;
			double pcc = 1 - pow(1 - table[x - 1][y - 1], t);
			double pss = 1 - pow(1 - avp, t);
			cout << setiosflags(ios::fixed) << setprecision(2);
			if (pcc > pss) {
				cout << "cc" << endl;
				cout << pcc << endl;
			} else if (pcc < pss) {
				cout << "ss" << endl;
				cout << pss << endl;
			} else {
				cout << "equal" << endl;
				cout << pcc << endl;
			}

		}
	}

	static void findway() {

		int n, m, k;
		while (cin >> n >> m >> k) {
			vector < vector<double> > p((n + 1), vector<double>(m + 1));
			int x, y;
			for (int i = 0; i < k; i++) {
				cin >> x >> y;
				p[x][y] = -1.0;
			}
			p[1][1] = 1.0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (!(i == 1 && j == 1)) {
						if (p[i][j] == -1.0) {
							p[i][j] = 0;
						} else {
							p[i][j] = p[i - 1][j] * (j == m ? 1 : 0.5)
									+ p[i][j - 1] * (i == n ? 1 : 0.5);
						}
					}
				}
			}
			cout << setiosflags(ios::fixed) << setprecision(2);
			cout << p[n][m] << endl;
		}

	}
};

class DidiTest {
public:
	static void continueSum() {
		int n;
		while (cin >> n) {
			int a = 0;
			cin >> a;
			int sum = a;
			int cursum = a;
			for (int i = 1; i < n; i++) {
				cin >> a;
				cursum = max(cursum + a, a);
				sum = max(cursum, sum);
			}
			cout << sum << endl;
		}
	}
	static void cosume() {
		int n, m;
		while (cin >> n >> m) {
		}
	}
	static void zeronums() {
		int n = 0;
		while (cin >> n) {
//			unsigned long long sum = 1;
//			for (int i = 1; i <= n; i++) {
//				sum *= i;
//			}
//			int num = 0;
//			while (sum % 10 == 0) {
//				num++;
//				sum /= 10;
//			}
			int num = 0;
			for (int i = 1; i <= n; i++) {
				int j = i;
				while (j % 5 == 0) {
					num++;
					j /= 5;
				}
			}
			cout << num << endl;
		}
	}

	static void tran() {
		int m, n;
		vector<char> chars = { 'A', 'B', 'C', 'D', 'E', 'F' };
		while (cin >> m >> n) {
			int flag = 0;
			if (m < 0) {
				flag = 1;
				m = 0 - m;
			}
			vector<int> arr;
			while (m) {
				int num = m % n;
				m /= n;
				arr.push_back(num);
			}
			if (flag)
				cout << "-";
			for (int i = arr.size() - 1; i >= 0; i--) {
				if (arr[i] > 9) {
					cout << chars[arr[i] - 10];
				} else {
					cout << arr[i];
				}
			}
			cout << endl;
		}
	}

	static void sumnum() {
		int n, sum;
		while (cin >> n >> sum) {
			vector<int> arr(n, 0);
			for (int i = 0; i < n; i++) {
				cin >> arr[i];
			}

		}
	}

};
namespace didi {
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<vector<int> > &input, int i, int j, int n, int m) {
	if (i < 0 || j < 0 || i >= n || j >= m || (0 == input[i][j]))
		return;
	input[i][j] = 0;
	dfs(input, i + 1, j, n, m);
	dfs(input, i, j + 1, n, m);
	dfs(input, i - 1, j, n, m);
	dfs(input, i, j - 1, n, m);
}

int test() {
	int n, m;
	cin >> n >> m;
	vector < vector<int> > input;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			int tmp = str[j] - '0';
			v.push_back(tmp);
		}
		input.push_back(v);
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (1 == input[i][j]) {
				dfs(input, i, j, n, m);
				++count;
			}
		}
	}
	cout << count;

	return 0;
}

static void t9() {
	string word;
	map<int, string> m;
	m.insert(make_pair(2, "abc"));
	m.insert(make_pair(3, "def"));
	m.insert(make_pair(4, "ghi"));
	m.insert(make_pair(5, "jkl"));
	m.insert(make_pair(6, "mno"));
	m.insert(make_pair(7, "pqrs"));
	m.insert(make_pair(8, "tuv"));
	m.insert(make_pair(9, "wxyz"));
	/*
	 Produces a printable string representation of a dictory
	 784
	 */

	while (getline(cin, word)) {
		istringstream iss(word);
		string s;
		vector < string > words;
		while (iss >> s) {
//			cout << s << endl;
			words.push_back(s);
		}
		string nums;
		cin >> nums;
		vector < string > ready(words);
		for (int i = 0; i < nums.size(); i++) {
			string chars = m[nums[i] - '0'];
//			cout << chars << endl;

			for (int k = 0; k < ready.size(); k++) {
				vector < string > tmp;
				for (int j = 0; j < chars.size(); j++) {
//					cout << "ready " << k << " chars " << j << endl;
					if (ready[k].size() > i) {
						if (ready[k][i] == chars[j]
								|| ready[k][i] == toupper(chars[j])) {
							tmp.push_back(ready[k]);
//							break;
						}
					}
				}
				ready.clear();
				for (int a = 0; a < tmp.size(); a++) {
					cout << tmp[a] << endl;
					ready.push_back(tmp[a]);
				}
			}
		}
	}
}
}
#endif /* INC_PROGRAM2016_H_ */
