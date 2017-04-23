/*
 * MyBits.h
 *
 *  Created on: 2017年2月28日
 *      Author: tla001
 */

#ifndef INC_MYBITS_H_
#define INC_MYBITS_H_

#include "Include.h"
class SomeQuetionOfBits {
public:
	/*
	 * 比较两个数字bit位不同的个数
	 */
	int numberOfDifferentBits(int A, int B) {
		int diff = A ^ B;
		int count = 0;
		while (diff > 0) {
			count += diff & 0x1;
			diff = diff >> 1;
		}
		return count;
	}
	/*
	 * 给定数组中每个元素都出现两次，只有一个元素例外。找出那个元素
	 */
	int singleValue(vector<int> array) {
		int value = 0;
		for (int i = 0; i < array.size(); i++) {
			value ^= array[i];
		}
		return value;
	}
	/*
	 * 将N的i到j位设为和M中相同位的值
	 */
#define INT_BIT_LENGTH 32
	void setBits(unsigned int &N, unsigned int &M, int i, int j) {
		unsigned int max = ~0;
		unsigned int bitMask = (max << INT_BIT_LENGTH - i) | (max >> j);
		N = (M & (~bitMask)) | (N & bitMask);
	}
	/*
	 * 将一个整数中相邻的奇数位和偶数位互换
	 */
	int swapBits(int input) {
		return ((0xaaaaaaaa & input) >> 1) | ((0x55555555 & input) << 1);
	}
	/*
	 * 交换两个数组
	 */
	vector<int> getSwap(vector<int> num) {
		num[0] = num[0] ^ num[1];
		num[1] = num[0] ^ num[1];
		num[0] = num[0] ^ num[1];
		return num;
	}
};

#endif /* INC_MYBITS_H_ */
