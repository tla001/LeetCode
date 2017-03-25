/*
 * MySort.h
 *
 *  Created on: 2017��3��3��
 *      Author: tla001
 */

#ifndef INC_MYSORT_H_
#define INC_MYSORT_H_

#include "Include.h"
class SomeSortMethods {
public:
	/*
	 * ��·�鲢����
	 * ˼·�����÷���˼�룬��ԭ������ж��ֶַΣ�ʹԪ����ÿһС��������Ȼ���𽥺ϲ�
	 * �磬��С�ֶ���2����2�����򣬺ϲ�Ϊ4,4�����򡣡�����
	 *
	 * ʱ�临�Ӷȣ�O(nlogn)
	 * �ռ临�Ӷȣ�O(n)��Ҫһ�������������Ϊ��ʱ�洢
	 */
	static void mergeSort(int array[], int helper[], int left, int right) {
		if (left >= right)
			return;
		int mid = (left + right) / 2;
		mergeSort(array, helper, left, mid);
		mergeSort(array, helper, mid + 1, right);

		int helperLeft = left;
		int helperRight = mid + 1;
		int cur = left;
		for (int i = left; i <= right; i++) {
			helper[i] = array[i];
		}
		while (helperLeft <= mid && helperRight <= right) {
			if (helper[helperLeft] <= helper[helperRight])
				array[cur++] = helper[helperLeft++];
			else
				array[cur++] = helper[helperRight++];
		}
		while (helperLeft <= mid)
			array[cur++] = helper[helperLeft++];
	}
	/*
	 * ��������
	 * ˼·����ѡ��һ���ڱ�Ԫ�أ�Ȼ�����ǰ�������������ڱ�С��Ԫ��ֹͣ����ǰ������б�����
	 * �������ڱ�Ԫ�ش��Ԫ��ֹͣ����������Ԫ�أ�������ֱ��ǰ����������ʱ�����������Ԫ��
	 * ���ڱ�Ԫ�أ�һ����������������ȷ���ڱ�Ԫ����ߵ�Ԫ�ر��ڱ�С���ұߵ�Ԫ�ر��ڱ����������򣩣�
	 * Ȼ��������ټ�����������
	 * ע�⣺ͨ��ѡȡ��߽���Ϊ�ڱ�Ԫ�أ���ʱ���ض��Ƚ��дӺ���ǰ���ƶ������򲻶Գ�ȱ������
	 *
	 * ʱ�临�Ӷȣ�ƽ��O(nlogn) ���O(n^2)
	 * �ռ临�Ӷȣ�O(logn)����ʱ��Ҫһ������Ŀռ䣬һ������logn��
	 */
	static void quickSort(int array[], int left, int right) {
		if (left >= right)
			return;
		int pivot = array[left];
		int i = left;
		int j = right;
		while (i != j) {
			while (array[j] >= pivot && j > i)
				j--;
			while (array[i] <= pivot && i < j)
				i++;
			if (i < j) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		array[left] = array[i];
		array[i] = pivot;

		quickSort(array, left, i - 1);
		quickSort(array, i + 1, right);
	}
	/*
	 * ������
	 */
	//�����ѣ�larger=true�󶥶ѣ�����ΪС����
	static void adjustHeap(int array[], int parent, int length, bool large) {
		int pivot = array[parent]; //���浱ǰ���ڵ�
		int child = 2 * parent + 1; //��ȡ����
		while (child < length) {
			if (large) {
				//�󶥶�
				//������Һ��ӣ����Һ��Ӵ������ӣ�ѡȡ�к��ӽڵ�
				if (child + 1 < length && array[child] < array[child + 1])
					child++;
				// ������ڵ��ֵ�Ѿ����ں��ӽڵ��ֵ����ֱ�ӽ���
				if (array[parent] > array[child])
					break;
			} else {
				//������Һ��ӣ����Һ���С�����ӣ�ѡȡ�Һ��ӽڵ�
				if (child + 1 < length && array[child] > array[child + 1])
					child++;
				//������ڵ��ֵ�Ѿ�С�ں��ӽڵ��ֵ����ֱ�ӽ���
				if (array[parent] < array[child])
					break;
			}
			//�Ѻ��ӽڵ��ֵ�������ڵ�
			array[parent] = array[child];
			//ѡȡ���ӽڵ�����ӽڵ㣬��������ɸѡ
			parent = child;
			child = child * 2 + 1;
			array[parent] = pivot;
		}
	}
	/*
	 * ��ʼ����
	 * ����֮�󣬵�һ��Ԫ��Ϊ���еļ�ֵ
	 */
	static void buildHeap(int array[], int length, bool large) {
		for (int i = (length - 1) / 2; i >= 0; --i)
			adjustHeap(array, i, length, large);
	}
	/*
	 * ���ν���ʱ�临�Ӷ�O(n)
	 * ����һ�ε�ʱ��ΪO(logn),һ������n��
	 * ʱ�临�Ӷ�ΪO(nlogn)
	 * �ռ临�Ӷ�O(1)
	 */
	static void heapSort(int array[], int length, bool increase) {
		bool large;
		if (increase) {
			large = true;
		} else {
			large = false;
		}
		buildHeap(array, length, large);
		print(array, length);
		//����ֵ�𽥷ŵ���β��ʣ��Ԫ�����µ���
		for (int i = length - 1; i > 0; i--) {
			int temp = array[i];
			array[i] = array[0];
			array[0] = temp;
			adjustHeap(array, 0, i, large);
			print(array, length);
		}
	}
	/*
	 * ֱ�Ӳ�������
	 * ˼·���ɵڶ���Ԫ�ؿ�ʼ����ǰ��������������ǰԪ�ر�ǰһ��Ԫ��С����
	 * ��ǰԪ����Ϊ�ڱ�Ԫ�أ����浱ǰԪ�أ��ӵ�ǰλ����ǰɨ�裬Ѱ���ڱ�Ԫ��Ӧ�ò����λ�ã�
	 * ǰ���Ԫ�����κ��ƣ��ҵ�ֱ�Ӳ��롣Ȼ�������������
	 * ʱ�临�Ӷȣ�O(n^2)
	 * �ռ临�Ӷȣ�O(1)
	 */
	static void directInsertSort(int array[], int length) {
		//����汾
		for (int i = 1; i < length; i++) {
			if (array[i] < array[i - 1]) {				//�ҵ�С��
				int j = i - 1;
				int pivot = array[i];				//����С��Ϊ�ڱ�Ԫ��
//				array[i] = array[i - 1];				//�Ƚ���һ�κ���
				while (pivot < array[j] && j >= 0) {				//Ѱ��С������λ��
					array[j + 1] = array[j];
					j--;
				}
				array[j + 1] = pivot;
			}
		}
	}
	/*
	 * ���ֲ�������
	 * ��ֱ�Ӳ�������ĸĽ�����Ҫ������Ѱ���ڱ�Ԫ�ز���λ��ʱ��ʹ���˶��ֲ���
	 * ��Ϊ�ڱ�֮ǰ��Ԫ��һ�����Ѿ�����ģ����Կ���ʹ�ö��ֲ���
	 */
	static void binaryInsertSort(int array[], int length) {
		for (int i = 1; i < length; i++) {
			if (array[i] < array[i - 1]) {				//�ҵ�С��
				int pivot = array[i];				//����С��Ϊ�ڱ�Ԫ��
				int low = 0;
				int high = i - 1;
				int mid = 0;

				while (low <= high) {
					mid = (low + high) / 2;
					if (pivot >= array[mid]) {
						low = mid + 1;
					} else {
						high = mid - 1;
					}
				}
				int j = i;
				//lowλ�þ���Ҫ�����λ��,����low��i֮���Ԫ�ض���Ҫ�����ƶ�һ��λ��
				while (j > low) {				//Ѱ��С������λ��
					array[j] = array[j - 1];
					j--;
				}
				array[low] = pivot;
			}
		}
	}
	/*
	 *	��·��������
	 *	˼·������һ���������飬�������鵱��һ��������ͷ����СԪ�أ���β�����Ԫ��
	 *	���������Ԫ�رȵ�ǰ��С��Ԫ��С���������СԪ��֮ǰ������head
	 *	���������Ԫ�رȵ�ǰ����Ԫ�ش���������Ԫ��֮�󣬸���tail
	 *	����������С֮�䣬��Ҫ�ɺ���ǰ����������������ƶ���Ѱ�Ҳ���㣬����
	 *	��󣬽���˳���Ʋ�ת��Ϊ����˳��
	 */
	static void twoInsertSort(int array[], int length) {
		//����汾
		int head = 0;				//ͷָ�� СԪ��
		int tail = 0;				//βָ�� ��Ԫ��
		int cur = 0;
		int *helper = new int[length];
		helper[0] = array[0];
		for (int i = 1; i < length; i++) {
			if (array[i] < helper[head]) {				//�������Ԫ�ر���С��Ԫ��С
				head = (head - 1 + length) % length;
				helper[head] = array[i];
			} else if (array[i] > helper[tail]) {				//�������Ԫ�ر����Ĵ�
				tail = (tail + 1 + length) % length;
				helper[tail] = array[i];
			} else {				//�������Ԫ�ر���С�Ĵ󣬱�����С
				cur = (tail + 1 + length) % length;
				//�ɺ���ǰ������Ѱ�ҵ�ǰԪ�ز����
				while (helper[(cur - 1 + length) % length] > array[i]) {
					helper[(cur + length) % length] = helper[(cur - 1 + length)
							% length];
					cur = (cur - 1 + length) % length;
				}
				//����Ԫ��
				helper[(cur + length) % length] = array[i];
				tail = (tail + 1 + length) % length;
			}
		}
		for (cur = 0; cur < length; cur++) {
			array[cur] = helper[(head + cur) % length];
		}
		delete[] helper;
	}
	/*
	 * shell������С��������
	 * ˼·����һ�������������з��飬�����Ͻ���ֱ�Ӳ�������ʹ֮����֮����С�����
	 * �ظ���������
	 * ʱ�临�Ӷȣ�O(n^1.5)
	 * �ռ临�Ӷȣ�O(1)
	 */
	static void shellSort(int array[], int length) {
		int gap = length / 2;
		while (gap >= 1) {
			//������gapΪһ�飬����������
			for (int i = gap; i < length; i++) {
				if (array[i] < array[i - gap]) {
					int j = i - gap;
					int x = array[i];
//					array[i] = array[j];
					//Ѱ��x�ڵ�ǰ�����ϵĲ����
					while (x < array[j] && j >= 0) {
						array[j + gap] = array[j];
						j -= gap;
					}
					array[j + gap] = x;
				}
			}
			print(array, length);
			gap /= 2;
		}
	}
	/*
	 * ֱ��ѡ������
	 * ˼·��(1)�Ӵ����������У��ҵ��ؼ�����С��Ԫ�أ�
	 * (2)�����СԪ�ز��Ǵ��������еĵ�һ��Ԫ�أ�����͵�һ��Ԫ�ػ�����
	 * (3)�����µ� N - 1 ��Ԫ���У��ҳ��ؼ�����С��Ԫ�أ��ظ�(1)��(2)����ֱ�����������
	 * ʱ�临�Ӷȣ�O(n^2)
	 * �ռ临�Ӷȣ�O(1)
	 */
	static void selectSort(int array[], int length) {
		for (int i = 0; i < length; i++) {
			for (int j = i + 1; j < length; j++) {
				if (array[i] > array[j]) {
					int temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}
	}
	/*
	 * ��·ѡ������
	 * ˼·����ѭ��ȷ����ǰԪ��λ�ã�ͷ��β������ѭ������ʣ��Ԫ�ز���¼���ֵ����Сֵ��λ��
	 * ��󽻻���ֵ�뵱ǰԪ��
	 */
	static void selectTwoSort(int array[], int length) {
		for (int i = 0; i <= length / 2; i++) {
			int min = i, max = i;
			for (int j = i + 1; j < length - i; j++) {
				if (array[j] >= array[max]) {
					max = j;
					continue;
				}
				if (array[j] < array[min]) {
					min = j;
				}
			}
			int temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			temp = array[length - i - 1];
			array[length - i - 1] = array[max];
			array[max] = temp;
		}
	}
	/*
	 * ð������
	 * ˼·��ÿ����ѭ��ʹ����Ԫ�����򣬵���ѭ�������ֵ���ף�����ʱ��
	 * ֮��������ѭ����Χ�������������������� �и����⣬̫����
	 * ʱ�临�Ӷȣ�O(N^2)
	 * �ռ临�Ӷȣ�O(1)
	 */
	static void bubbleSort(int array[], int length) {
		for (int i = 0; i < length - 1; i++) {
			for (int j = 0; j < length - i - 1; j++) {
				if (array[j] > array[j + 1]) {
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
			print(array, length);
		}
	}
	/*
	 * �Ľ�ð��1
	 * ˼·������һ��־�Ա���pos,���ڼ�¼ÿ�����������һ�ν��н�����λ�á�
	 * ����posλ��֮��ļ�¼���ѽ�����λ,���ڽ�����һ������ʱֻҪɨ�赽posλ�ü���
	 */
	static void bubbleSort1(int array[], int length) {
		int i = length - 1;
		while (i > 0) {
			int pos = 0;
			for (int j = 0; j < i; j++) {
				if (array[j] > array[j + 1]) {
					pos = j;
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
			i = pos;
			print(array, length);
		}
	}
	/*
	 * �Ľ�ð��2
	 * ˼·���������������ð�ݣ�������Ϊ�������������³����ֵ���淽�����ϸ���Сֵ
	 * ��Χ���ڲ�����С��
	 */
	static void bubbleSort2(int array[], int length) {
		int low = 0;
		int high = length - 1;
		int j, temp;
		int pos = 0;
		while (low < high) {
			for (j = low; j < high; j++) {
				if (array[j] > array[j + 1]) {
					pos = j;
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
			high = pos;
			for (j = high; j > low; --j) {
				if (array[j] < array[j - 1]) {
					pos = j;
					temp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = temp;
				}
			}
			low = pos;
			print(array, length);
		}
	}
	/*
	 * Ͱ����
	 * ˼·��
	 */
	static void bucketSort(int array[], int length, int max) {
		int *tempArray = new int[length];
		int i;
		for (i = 0; i < length; i++)
			tempArray[i] = array[i];
		int *count = new int[max];
		memset(count, 0, max * sizeof(int));

		for (i = 0; i < length; i++) {
			count[array[i]]++;
		}
		for (i = 1; i < max; i++)
			count[i] = count[i - 1] + count[i];
		for (i = length - 1; i >= 0; i--) {
			array[--count[tempArray[i]]] = tempArray[i];
		}
	}
	/*
	 * ��������
	 * ˼·���ɵ�λ����λ���ֱ���Ͱ����ʹ֮����
	 */
	//�õ��������λ��
	static int getMaxNums(int a[], int n) {
		int max = ~0;
		for (int i = 0; i < n; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
		int j = 1;
		while (max >= 10) {
			j++;
			max /= 10;
		}
		return j;
	}
	//�õ�ĳλ�ϵ����֣����֧��5λ
	static int getDigit(int x, int d) {
		int temp[] = { 1, 10, 100, 1000, 10000 };
		return ((x / temp[d - 1]) % 10);
	}
	//radix always equal 10, as 10 radix
	static void radixSort(int a[], int n, int radix) {
		int *count = new int[radix];
		int *bucket = new int[n];
		int digits = getMaxNums(a, n);

		int i = 0, j = 0;
		//�ӵ�λ����λ����
		for (int d = 1; d <= digits; d++) {
			for (i = 0; i < radix; i++) {
				count[i] = 0;
			}
			//ͳ�Ƹ���ͰҪװ�����ݵĸ���
			for (i = 0; i < n; i++) {
				j = getDigit(a[i], d);
				count[j]++;
			}
			// count[i]��ʾ��i��Ͱ���ұ߽�����,��Ͱӳ�䵽����
			// ������ǰ����֮ǰ�ж��ٸ�Ԫ��Ҫ��Ͱ���ۼӵ���ͼ����Ϊǰ��СԪ�ؿ�λ
			// count[j]-count[j-1]�ʹ��� jͰ��Ԫ�صĸ���
			//--|---|----|-----|
			for (i = 1; i < radix; i++) {
				count[i] = count[i] + count[i - 1];
			}
			// ����������װ��Ͱ��
			// ����Ҫ��������ɨ�裬��֤�����ȶ���
			for (i = n - 1; i >= 0; i--) {
				j = getDigit(a[i], d);
				bucket[count[j] - 1] = a[i];			//�����������õ�Ͱ��Ӧ�����λ�ã��Ӻ���ǰ
				count[j]--;
			}
			for (i = 0; i < n; i++) {
				a[i] = bucket[i];
			}
			print(a, n);
		}
		delete[] count;
		delete[] bucket;
	}
	static void print(int array[], int size) {
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
	static void test() {
		int array[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
		int size = sizeof(array) / sizeof(array[0]);
		int *helper = new int[size];
//		mergeSort(array, helper, 0, size - 1);
//		quickSort(array, 0, size - 1);
		heapSort(array, size, true);
//		directInsertSort(array, size);
//		binaryInsertSort(array, size);
//		twoInsertSort(array, size);
//		shellSort(array, size);
//		selectSort(array, size);
//		selectTwoSort(array, size);
//		bubbleSort(array, size);
//		bubbleSort1(array, size);
//		bubbleSort2(array, size);
//		bucketSort(array, size, 8);//max ��Ҫ�������������ֵ
//		radixSort(array, size, 10);
//		OutSortTest();
		print(array, size);
	}

	/*
	 * ������
	 * ˼·�����ȶԴ��ļ��ָ������浽С�ļ��С�
	 * ������С�ļ���ÿ���ļ���ʱ�����һ�������������ĸ��ļ�ҲҪ��¼������buf��buf��С���ļ�����һ�£���
	 * ��buf������С�ѣ����Ѷ�����д������ļ������ӶѶ�Ԫ�����Ե��ļ�����һ��Ԫ�أ����½��ѣ��ظ�������
	 * ֱ��д�������ݸ������ܸ������ʱ������
	 */
#include <stdio.h>
#include <time.h>
#include <math.h>
	//���ļ����������m�����ݣ�ÿ��һ��
	static void OutSortGenData(char *fileName, int m) {
		FILE *fp = fopen(fileName, "w");
		if (fp == NULL) {
			printf("open file failed \n");
			exit(-1);
		}
		srand(time(0));
		for (int i = 0; i < m; i++) {
			int temp = (rand() << 15) | rand();	//randһ�����15λ�����(32767)����չ��30λ
			fprintf(fp, "%d\n", temp);
		}
		fclose(fp);
	}
	static void OutSortSplit(char *fileName, int m, int n) {
		FILE *in = fopen(fileName, "r");
		int *buf = (int *) malloc(sizeof(int) * n);
		int k = ceil(double(m) / n);
		for (int i = 0, j; i < k; i++) {
			for (j = 0; j < n; j++) {
				if (fscanf(in, "%d", buf + j) != 1)
					break;
			}
			int num = j;
			quickSort(buf, 0, num - 1);
			char tempfile[20];
			sprintf(tempfile, "./res/tempfile_%d.txt", i);
			FILE *out = fopen(tempfile, "w");
			for (j = 0; j < num; j++) {
				fprintf(out, "%d\n", buf[j]);
			}
			fclose(out);
		}
		free(buf);
	}
	typedef struct ospair {
		int num;
		int pos;
	} OPair;
	static void OutSortAdjust(OPair a[], int parent, int length) {
		OPair temp = a[parent]; //���浱ǰ���ڵ�
		int child = 2 * parent + 1; //��ȡ����
		while (child < length) {
			/*****С����********/
			//������к��ӣ����Һ���С�������ӣ�ѡȡ�Һ��ӽڵ�
			if (child + 1 < length && a[child].num > a[child + 1].num) {
				child++;
			}
			// ���������ֵ�Ѿ�С�ں��ӽ���ֵ����ֱ�ӽ���
			if (a[parent].num < a[child].num) {
				break;
			}
			// �Ѻ��ӽ���ֵ���������
			a[parent] = a[child];
			// ѡȡ���ӽ������ӽ��,��������ɸѡ
			parent = child;
			child = 2 * child + 1;
		}
		a[parent] = temp;
		//PrintHeapSort(a, length);
	}
	/**
	 * ��ʼ�ѽ��е���
	 * ��H[0..length-1]���ɶ�
	 * ������֮���һ��Ԫ�������е���С��Ԫ��
	 */
	static void OutSortBuildHeap(OPair a[], int length) {
		for (int i = (length - 1) / 2; i >= 0; --i) {
			OutSortAdjust(a, i, length);
		}
	}
	static void OutSortMerge(char *outfile, int m, int n) {
		FILE *out = fopen(outfile, "w");
		int k = ceil((double) m / n);
		OPair *buf = (OPair *) malloc(sizeof(OPair) * k);
		FILE **fp = (FILE **) malloc(sizeof(FILE*) * k);
		for (int i = 0; i < k; i++) {
			*(fp + i) = (FILE*) malloc(sizeof(FILE));
			char tempfile[20];
			sprintf(tempfile, "./res/tempfile_%d.txt", i);
			fp[i] = fopen(tempfile, "r");
			int tem;
			fscanf(fp[i], "%d", &tem);
			buf[i].num = tem;
			buf[i].pos = i;
		}
		OutSortBuildHeap(buf, k);
		int nums = 0;
		while (1) {
			int minNum = buf[0].num;
			int minPos = buf[0].pos;
			if (nums == m)
				break;
			fprintf(out, "%d\n", minNum);
			int tem;
			fscanf(fp[minPos], "%d", &tem);
			buf[0].num = tem;
			OutSortBuildHeap(buf, k);
			nums++;
		}
		for (int i = 0; i < k; i++) {
			fclose(fp[i]);
			free(fp[i]);
		}
		free(*fp);
		free(buf);
		fclose(out);
	}
	static void OutSortTest() {
		char src[] = "./res/data.txt";
		char result[] = "./res/out.txt";
		int m = 200, n = 20;
		OutSortGenData(src, m);
		OutSortSplit(src, m, n);
		OutSortMerge(result, m, n);
	}
};
#endif /* INC_MYSORT_H_ */
