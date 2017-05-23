/*
 * JingDong.h
 *
 *  Created on: 2017年4月7日
 *      Author: tla001
 */

#ifndef INC_ONLINETEST_H_
#define INC_ONLINETEST_H_

#include "Include.h"
#include "limits"

class JingDong47 {
public:
	static void calSeqs() {
		int m, n;
		while (cin >> n >> m) {
			double sum = n;
			double pre = n;
			for (int i = 0; i < m - 1; i++) {
				pre = sqrt(pre);
				sum += pre;
			}
			cout << setiosflags(ios::fixed) << setprecision(2);
			cout << sum << endl;
		}
	}
	static void three() {
		while (1) {
			char a[3][3]; //二维数组存储棋盘数据
			int xCount = 0, oCount = 0; //X和0的个数
			for (int i = 0; i < 3; ++i) {
				string s = "";
				getline(cin, s);
				if (s.size() == 0)
					return; //终止条件
				for (int j = 0; j < 3; ++j) {
					a[i][j] = s[j]; //赋值
					// 计数
					if (s[j] == 'X')
						++xCount;
					else if (s[j] == '0')
						++oCount;
				}
			}

			// 计算差值和基本判断
			int diff = xCount - oCount;
			if (diff != 0 && diff != 1) {
				cout << "x" << endl;
				continue;
			}

			int wx = 0, wo = 0; //X赢和0赢的标志
			// 判断行
			for (int i = 0; i < 3; ++i) {
				if (a[i][1] != '.' && a[i][0] == a[i][1]
						&& a[i][2] == a[i][1]) {
					if (a[i][1] == 'X')
						wx = 1;
					else
						wo = 1;
				}
			}
			// 判断列
			for (int i = 0; i < 3; ++i) {
				if (a[1][i] != '.' && a[0][i] == a[1][i]
						&& a[2][i] == a[1][i]) {
					if (a[1][i] == 'X')
						wx = 1;
					else
						wo = 1;
				}
			}
			// 判断对角
			if (a[1][1] != '.'
					&& ((a[0][0] == a[1][1] && a[2][2] == a[1][1])
							|| (a[0][2] == a[1][1] && a[2][0] == a[1][1]))) {
				if (a[1][1] == 'X')
					wx = 1;
				else
					wo = 1;
			}

			// 判断输出
			if (wx && wo || wx && !diff || wo && diff)
				cout << "x" << endl; //X与0不能同时赢；X赢时diff不能为0；0赢时diff不能为1
			else if (wx)
				cout << "1 won" << endl;
			else if (wo)
				cout << "2 won" << endl;
			else if (xCount + oCount == 9)
				cout << "draw" << endl;
			else if (diff)
				cout << "2" << endl;
			else if (diff == 0)
				cout << "1" << endl;
		}
	}

	static void route() {
		char s[3], t[3];
		while (scanf("%s%s", s, t) != EOF) {
			vector < string > ans;
			int dc = t[0] - s[0], dr = t[1] - s[1];
			if (dr < 0) {
				if (dc > 0) {
					while (dr != 0 && dc != 0) {
						ans.push_back("RD");
						dc--, dr++;
					}
				} else if (dc < 0) {
					while (dr != 0 && dc != 0) {
						ans.push_back("LD");
						dc++, dr++;
					}
				}
			} else if (dr > 0) {
				if (dc > 0) {
					while (dr != 0 && dc != 0) {
						ans.push_back("RU");
						dc--, dr--;
					}
				} else if (dc < 0) {
					while (dr != 0 && dc != 0) {
						ans.push_back("LU");
						dc++, dr--;
					}
				}
			}
			if (dr != 0) {
				if (dr > 0) {
					while (dr-- > 0)
						ans.push_back("U");
				} else {
					while (dr++ < 0)
						ans.push_back("D");
				}
			}
			if (dc != 0) {
				if (dc > 0) {
					while (dc-- > 0)
						ans.push_back("R");
				} else {
					while (dc++ < 0)
						ans.push_back("L");
				}
			}
			cout << ans.size() << endl;
			for_each(ans.begin(), ans.end(),
					[](string& a) {cout << a << endl;});
		}
	}
	static void orro() {
		int n;
		while (cin >> n) {
			string a, b;
			cin >> a >> b;
			int res = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] == b[i]) {

				} else {
					res += pow(2, n - i - 1);
				}
			}
			cout << res << endl;
		}
	}
	static void calP() {
		int n;
		while (cin >> n) {
			vector<float> table(n, 0.0);
			int a;
			for (int i = 0; i < n; i++) {
				cin >> a;
				table[i] = (float) ((float) a / 100);
			}
			unsigned char okNum = ceil(0.6 * n);
//			cout << ceil(0.4 * n) << " " << floor(0.4 * n) << endl;
			float res = 0.0;
			vector<pair<unsigned char, float>> tree[n];
			tree[0].push_back(
					make_pair<unsigned char, float>(0, (float) (1 - table[0])));
			tree[0].push_back(
					make_pair<unsigned char, float>(1, (float) table[0]));
			for (unsigned char i = 1; i < n; i++) {
				for (unsigned char j = 0; j < tree[i - 1].size(); j++) {
					tree[i].push_back(
							make_pair<unsigned char, float>(
									(unsigned char) tree[i - 1][j].first,
									(float) tree[i - 1][j].second
											* (1 - table[i])));
					tree[i].push_back(
							make_pair<unsigned char, float>(
									(unsigned char) tree[i - 1][j].first + 1,
									(float) tree[i - 1][j].second * table[i]));
				}
			}
			for (unsigned char i = 0; i < tree[n - 1].size(); i++) {
				if (tree[n - 1][i].first >= okNum) {
					res += (float) tree[n - 1][i].second;
				}
			}
			cout << setiosflags(ios::fixed) << setprecision(5);
			cout << res << endl;
		}
	}
};
class Net325 {
public:
	static void test() {
		cout << "hello" << endl;
	}
	static void calstring() {
		string str;
		while (cin >> str) {
			vector<int> nums;
			vector<char> sign;
			for (int i = 0; i < str.length(); i++) {
				if (isdigit(str[i])) {
					nums.push_back(str[i] - '0');
				} else {
					sign.push_back(str[i]);
				}
			}
			int value = nums[0];
			for (int i = 1; i < nums.size(); i++) {
				if (sign[i - 1] == '+') {
					value += nums[i];
				} else if (sign[i - 1] == '-') {
					value -= nums[i];
				} else if (sign[i - 1] == '*') {
					value *= nums[i];
				}
			}
			cout << value << endl;
		}
	}
	static void getSets() {
		int w, x, y, z;
		while (cin >> w >> x >> y >> z) {
			set<double> s;
			for (int p = w; p <= x; p++) {
				for (int q = y; q <= z; q++) {
					double t = (double) ((double) p / (double) q);
//					cout << t << endl;
					s.insert(t);
				}
			}
			cout << s.size() << endl;
		}
	}
	static void calmintime() {
		int n;
		while (cin >> n) {
			int a;
			vector<int> v;
			for (int i = 0; i < n; i++) {
				cin >> a;
				v.push_back(a);
			}
			sort(v.begin(), v.end());
			long long suma = 0;
			long long sumb = 0;
			long long diff = 0;
			long long minv = 0;
			suma = v[0] + v[v.size() - 1];
			for (int i = 1; i < v.size() - 1; i++)
				sumb += v[i];
			diff = abs(suma - sumb);
			minv = max(suma, sumb);
			if (abs(suma - v[0] - (sumb + v[0])) < diff) {
				minv = max(suma - v[0], (sumb + v[0]));
			} else {
				for (int i = 1; i < v.size() - 1; i++) {
					suma += v[i];
					sumb -= v[i];
					if (abs(suma - sumb) < diff) {
						minv = max(suma, sumb);
					}
				}
			}
			cout << minv << endl;
//			for (int i = 1; i < v.size(); i++) {
//				sumb += v[i];
//			}
//			diff = abs(suma - sumb);
//			min = diff;
//			for (int i = 1; i < v.size() - 1; i++) {
//				for (int x = 0; x < i; x++) {
//					suma += v[x];
//				}
//				for (int x = i; x < v.size(); x++) {
//					sumb += v[x];
//				}
//				for (int j = 0; j < i; j++) {
//					for (int k = 0; k < v.size(); k++) {
//						suma
//					}
//				}
//			}
		}
	}
	static int getNums(vector<int> arr, int a) {
		int res = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] >= a)
				res++;
		}
		return res;
	}
	static void getnums() {
		int n, q;
		while (cin >> n >> q) {
			vector<int> A, B;
			int a;
			for (int i = 0; i < n; i++) {
				cin >> a;
				A.push_back(a);
			}
			for (int i = 0; i < n; i++) {
				cin >> a;
				B.push_back(a);
			}
			sort(A.begin(), A.end());
			sort(B.begin(), B.end());
			int x, y;
			int nums_x = 0, nums_y = 0;
			for (int i = 0; i < q; i++) {
				cin >> x >> y;
				nums_x = getNums(A, x);
				nums_y = getNums(B, y);
				int res = (nums_x < nums_y) ? nums_x : nums_y;
				cout << res << endl;

			}
		}
	}
	static set<string> breakSentence(string str) {
		set < string > res;
		transform(str.begin(), str.end(), str.begin(), ::toupper);
		int pos = 0;
		int pre = 0;

		while ((pos = str.find_first_of(' ', pre)) != string::npos) {
			string s = str.substr(pre, pos - pre);
			pre = pos + 1;
			res.insert(s);
		}
		if (str.size() - pre > 0)
			res.insert(str.substr(pre, str.size() - pre));
		return res;
	}
	static int comToEqual(set<string> a, set<string> b) {
		int res = 0;
		for (set<string>::iterator ite = a.begin(); ite != a.end(); ite++) {
			if (b.find(*ite) != b.end())
				res++;
		}
		return res;
	}
	static void findBsetSentence() {
		int n, m;
		string str;
		while (cin >> n >> m) {
			vector < set < string >> v;
			vector < string > strs;
			getline(cin, str);
			for (int i = 0; i < n; i++) {
				getline(cin, str);
				strs.push_back(str);
				v.push_back(breakSentence(str));
			}
			set < string > mset;
			cout << "v size " << v.size() << endl;
			for (int i = 0; i < m; i++) {
				int index = 0;
				int nums = 0;
				int max = 0;
				getline(cin, str);
				mset = breakSentence(str);
				for (int j = 0; j < v.size(); j++) {
					nums = comToEqual(mset, v[j]);
					if (nums > max) {
						max = nums;
						index = j;
					}
				}
				cout << strs[index] << endl;
			}
		}

//		string str;
//		while (1) {
//			getline(cin, str);
//			set < string > res = breakSentence(str);
//			for (set<string>::iterator ite = res.begin(); ite != res.end();
//					ite++) {
//				cout << *ite << endl;
//			}
//		}

	}
};

#endif /* INC_ONLINETEST_H_ */
