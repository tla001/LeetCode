/*
 * MyBack.h
 *
 *  Created on: 2017年3月24日
 *      Author: tla001
 */

#ifndef INC_MYBACK_H_
#define INC_MYBACK_H_

#include "Include.h"

class MyBack {
public:
	/*
	 * 生成括号所有合法组合
	 */
	static void parenthesesCombination(int left, int right, string &path,
			vector<string>&paths) {
//		cout << "left=" << left << " right=" << right << endl;
		if (left < 0 || right < 0)
			return;
		if (left > 0) {
			path.push_back('(');
			parenthesesCombination(left - 1, right, path, paths);
			path.pop_back();
		}
		if (left < right) {
			path.push_back(')');
			right--;
			if (right == 0) {
				paths.push_back(path);
//				cout << path << endl;
			}
			parenthesesCombination(left, right, path, paths);
			path.pop_back();
		}
	}
	static vector<string> generateParenthesis(int n) {
		vector < string > res;
		if (n <= 0)
			return res;
		string path;
		parenthesesCombination(n, n, path, res);
		return res;
	}
	/*
	 * n皇后问题
	 */
	static bool checkValid(int k, vector<int> line) {
		for (int i = 1; i < k; i++) {
			if (line[i] == line[k] || abs(i - k) == abs(line[i] - line[k]))
				return false;
		}
		return true;
	}
	static int placeQ(int n, vector<vector<int>>&res) {
		vector<int> line(n + 1, 0);
		int sum = 0;
		int k = 1;
		while (k > 0) {
			line[k] += 1; //当前列加1的位置开始搜索
			while (line[k] <= n && !checkValid(k, line))
				line[k] += 1; //当前列位置是否满足条件,不满足条件，继续搜索下一个位置
			if (line[k] <= n) { //存在满足条件的列
				if (k == n) { //是最后一个皇后，完成搜索
					vector<int> tmp;
					for (int i = 1; i <= n; i++)
						tmp.push_back(line[i]);
					res.push_back(tmp);
					sum++;
				} else { //不是，则处理下一个皇后
					k++;
					line[k] = 0;
				}
			} else { //回溯
				k--;
			}
		}
		return sum;
	}
	/*
	 * 给定一个集合，其中包含重复值，返回其所有可能的子集
	 */
	static void subsetsWithDup(int index, const vector<int>&s, vector<int>&path,
			vector<vector<int>> paths) {
		if (index == s.size())
			return;
		for (int i = index; i < s.size(); i++) {
			if (i != index && s[i] == s[i - 1])
				continue;
			path.push_back(s[i]);
			paths.push_back(path);
			subsetsWithDup(i + 1, s, path, paths);
			path.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>&s) {
		vector<vector<int>> paths;
		vector<int> path;
		paths.push_back(path);
		sort(s.begin(), s.end());
		subsetsWithDup(0, s, path, paths);
		return paths;
	}
	static void test() {
//		vector < string > res = generateParenthesis(2);
//		for (int i = 0; i < res.size(); i++)
//			cout << res[i] << endl;
//		vector<vector<int>> res;
//		int sum = placeQ(10, res);
//		cout << "sum " << sum << endl;
//		for (int i = 0; i < res.size(); i++) {
//			for (int j = 0; j < res[i].size(); j++) {
//				cout << res[i][j];
//			}
//			cout << endl;
//		}
	}
};

#endif /* INC_MYBACK_H_ */
