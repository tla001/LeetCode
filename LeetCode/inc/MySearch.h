/*
 * MySearch.h
 *
 *  Created on: 2017年3月20日
 *      Author: tla001
 */

#ifndef INC_MYSEARCH_H_
#define INC_MYSEARCH_H_
#include "Include.h"
class MySearch {
public:
	/*
	 * 快速选择算法
	 * 在平均时间O(n)时间内从一个无序的数组中返回第k大的数
	 */
	int partition(int arr[], int left, int right) {
		int pivot = arr[right];
		while (left != right) {
			while (arr[left] < pivot && left < right) {
				left++;
			}
			if (left < right) {
				swap(arr[left], arr[right - 1]);
			}
			while (arr[right] > pivot && left < right) {
				right--;
			}
			if (left < right) {
				swap(arr[left++], arr[right]);
			}
		}
		return left;
	}

	int quickSelect(int arr[], int left, int right, int k) {
		if (left >= right)
			return arr[left];
		int index = partition(arr, left, right);
		int size = index - left + 1;
		if (size == k)
			return arr[left + k - 1];
		else if (size > k)
			return quickSelect(arr, left, index - 1, k);
		else
			return quickSelect(arr, index + 1, right, k - size);
	}
	/*
	 * 二分查找
	 */
	int binarySearch(vector<int> arr, int value) {
		int low = 0;
		int high = arr.size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] < value) {
				low = mid + 1;
			} else if (arr[mid] > value) {
				high = mid - 1;
			} else {
				return mid;
			}
		}
		return -1;
	}
	/*
	 * 有序二维数组查找问题
	 *  1234
	 *  5678
	 *
	 */
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
		return false;
	}
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
	 * 查找指定元素出现最靠前的位置，存在重复
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
	 * 找到有序循环数组中的最小值
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

};

#endif /* INC_MYSEARCH_H_ */
