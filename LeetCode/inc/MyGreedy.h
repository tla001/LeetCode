/*
 * MyGreedy.h
 *
 *  Created on: 2017年3月29日
 *      Author: tla001
 */

#ifndef INC_MYGREEDY_H_
#define INC_MYGREEDY_H_
#include "Include.h"

class MyGreedy {
public:
	/*
	 * 货箱装载问题
	 */
	static void containLoading(vector<int> &container, int capacity, int n,
			vector<int>&res) {
		stable_sort(container.begin(), container.end());
		for (int i = 0; i < n && container[i] <= capacity; i++) {
			capacity -= container[i];
			res.push_back(container[i]);
		}
	}
	static void test() {
		vector<int> container = { 100, 200, 50, 90, 150, 50, 20, 80 };
		int c = 400;
		int n = 10;
		vector<int> res;

		containLoading(container, c, n, res);
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
};

#endif /* INC_MYGREEDY_H_ */
