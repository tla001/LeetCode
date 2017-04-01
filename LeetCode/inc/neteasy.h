/*
 * neteasy.h
 *
 *  Created on: 2017Äê3ÔÂ25ÈÕ
 *      Author: tla001
 */

#ifndef INC_NETEASY_H_
#define INC_NETEASY_H_

#include "Include.h"
#include "limits"

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

#endif /* INC_NETEASY_H_ */
