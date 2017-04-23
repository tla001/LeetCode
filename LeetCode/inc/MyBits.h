/*
 * MyBits.h
 *
 *  Created on: 2017��2��28��
 *      Author: tla001
 */

#ifndef INC_MYBITS_H_
#define INC_MYBITS_H_

#include "Include.h"
class SomeQuetionOfBits {
public:
	/*
	 * �Ƚ���������bitλ��ͬ�ĸ���
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
	 * ����������ÿ��Ԫ�ض��������Σ�ֻ��һ��Ԫ�����⡣�ҳ��Ǹ�Ԫ��
	 */
	int singleValue(vector<int> array) {
		int value = 0;
		for (int i = 0; i < array.size(); i++) {
			value ^= array[i];
		}
		return value;
	}
	/*
	 * ��N��i��jλ��Ϊ��M����ͬλ��ֵ
	 */
#define INT_BIT_LENGTH 32
	void setBits(unsigned int &N, unsigned int &M, int i, int j) {
		unsigned int max = ~0;
		unsigned int bitMask = (max << INT_BIT_LENGTH - i) | (max >> j);
		N = (M & (~bitMask)) | (N & bitMask);
	}
	/*
	 * ��һ�����������ڵ�����λ��ż��λ����
	 */
	int swapBits(int input) {
		return ((0xaaaaaaaa & input) >> 1) | ((0x55555555 & input) << 1);
	}
	/*
	 * ������������
	 */
	vector<int> getSwap(vector<int> num) {
		num[0] = num[0] ^ num[1];
		num[1] = num[0] ^ num[1];
		num[0] = num[0] ^ num[1];
		return num;
	}
};

#endif /* INC_MYBITS_H_ */
