/*
 * MySort.h
 *
 *  Created on: 2017年3月3日
 *      Author: tla001
 */

#ifndef INC_MYSORT_H_
#define INC_MYSORT_H_

#include "Include.h"
class SomeSortMethods {
public:
	/*
	 * 二路归并排序
	 * 思路：利用分治思想，对原数组进行二分分段，使元素在每一小段内有序，然后逐渐合并
	 * 如，最小分段是2，先2内有序，合并为4,4内有序。。。。
	 *
	 * 时间复杂度：O(nlogn)
	 * 空间复杂度：O(n)需要一个额外的数组作为临时存储
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
	 * 快速排序
	 * 思路：先选择一个哨兵元素，然后后往前遍历，遇到比哨兵小的元素停止，从前往后进行遍历，
	 * 遇到比哨兵元素大的元素停止，交换两个元素，继续，直到前后相遇，此时交换相遇点的元素
	 * 和哨兵元素，一趟排序下来，可以确保哨兵元素左边的元素比哨兵小，右边的元素比哨兵大（升序排序）；
	 * 然后分区间再继续上述过程
	 * 注意：通常选取左边界作为哨兵元素，此时，必定先进行从后往前的移动，否则不对称缺项会出错
	 *
	 * 时间复杂度：平均O(nlogn) 最差O(n^2)
	 * 空间复杂度：O(logn)交换时需要一个额外的空间，一共交换logn次
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
	 * 堆排序
	 */
	//调整堆，larger=true大顶堆，否则为小顶堆
	static void adjustHeap(int array[], int parent, int length, bool large) {
		int pivot = array[parent]; //保存当前父节点
		int child = 2 * parent + 1; //获取左孩子
		while (child < length) {
			if (large) {
				//大顶堆
				//如果有右孩子，且右孩子大于左孩子，选取有孩子节点
				if (child + 1 < length && array[child] < array[child + 1])
					child++;
				// 如果父节点的值已经大于孩子节点的值，则直接结束
				if (array[parent] > array[child])
					break;
			} else {
				//如果有右孩子，且右孩子小于左孩子，选取右孩子节点
				if (child + 1 < length && array[child] > array[child + 1])
					child++;
				//如果父节点的值已经小于孩子节点的值，则直接结束
				if (array[parent] < array[child])
					break;
			}
			//把孩子节点的值赋给父节点
			array[parent] = array[child];
			//选取孩子节点的左孩子节点，继续向下筛选
			parent = child;
			child = child * 2 + 1;
			array[parent] = pivot;
		}
	}
	/*
	 * 初始化堆
	 * 调整之后，第一个元素为序列的极值
	 */
	static void buildHeap(int array[], int length, bool large) {
		for (int i = (length - 1) / 2; i >= 0; --i)
			adjustHeap(array, i, length, large);
	}
	/*
	 * 初次建堆时间复杂度O(n)
	 * 调整一次的时间为O(logn),一共调整n次
	 * 时间复杂度为O(nlogn)
	 * 空间复杂度O(1)
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
		//将极值逐渐放到队尾，剩下元素重新调整
		for (int i = length - 1; i > 0; i--) {
			int temp = array[i];
			array[i] = array[0];
			array[0] = temp;
			adjustHeap(array, 0, i, large);
			print(array, length);
		}
	}
	/*
	 * 直接插入排序
	 * 思路：由第二个元素开始，从前向后遍历，如若当前元素比前一个元素小，则将
	 * 当前元素设为哨兵元素，保存当前元素，从当前位置向前扫描，寻找哨兵元素应该插入的位置，
	 * 前面的元素依次后移，找到直接插入。然后继续上述过程
	 * 时间复杂度：O(n^2)
	 * 空间复杂度：O(1)
	 */
	static void directInsertSort(int array[], int length) {
		//升序版本
		for (int i = 1; i < length; i++) {
			if (array[i] < array[i - 1]) {				//找到小数
				int j = i - 1;
				int pivot = array[i];				//复制小数为哨兵元素
//				array[i] = array[i - 1];				//先进行一次后移
				while (pivot < array[j] && j >= 0) {				//寻找小数插入位置
					array[j + 1] = array[j];
					j--;
				}
				array[j + 1] = pivot;
			}
		}
	}
	/*
	 * 二分插入排序
	 * 是直接插入排序的改进，主要体现在寻找哨兵元素插入位置时，使用了二分查找
	 * 因为哨兵之前的元素一定是已经排序的，所以可以使用二分查找
	 */
	static void binaryInsertSort(int array[], int length) {
		for (int i = 1; i < length; i++) {
			if (array[i] < array[i - 1]) {				//找到小数
				int pivot = array[i];				//复制小数为哨兵元素
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
				//low位置就是要插入的位置,所以low到i之间的元素都需要往后移动一个位置
				while (j > low) {				//寻找小数插入位置
					array[j] = array[j - 1];
					j--;
				}
				array[low] = pivot;
			}
		}
	}
	/*
	 *	二路插入排序
	 *	思路：创建一个辅助数组，将此数组当成一个环，环头存最小元素，环尾存最大元素
	 *	如果待插入元素比当前最小的元素小，则插入最小元素之前，更新head
	 *	如果待插入元素比当前最大的元素大，则插入最大元素之后，更新tail
	 *	如果在最大最小之间，需要由后向前遍历，并依次向后移动，寻找插入点，插入
	 *	最后，将环顺序复制并转化为正常顺序
	 */
	static void twoInsertSort(int array[], int length) {
		//升序版本
		int head = 0;				//头指针 小元素
		int tail = 0;				//尾指针 大元素
		int cur = 0;
		int *helper = new int[length];
		helper[0] = array[0];
		for (int i = 1; i < length; i++) {
			if (array[i] < helper[head]) {				//待插入的元素比最小的元素小
				head = (head - 1 + length) % length;
				helper[head] = array[i];
			} else if (array[i] > helper[tail]) {				//待插入的元素比最大的大
				tail = (tail + 1 + length) % length;
				helper[tail] = array[i];
			} else {				//待插入的元素比最小的大，比最大的小
				cur = (tail + 1 + length) % length;
				//由后向前遍历，寻找当前元素插入点
				while (helper[(cur - 1 + length) % length] > array[i]) {
					helper[(cur + length) % length] = helper[(cur - 1 + length)
							% length];
					cur = (cur - 1 + length) % length;
				}
				//插入元素
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
	 * shell排序（缩小增量排序）
	 * 思路：以一定间隔对数组进行分组，在组上进行直接插入排序，使之有序，之后缩小间隔，
	 * 重复上述过程
	 * 时间复杂度：O(n^1.5)
	 * 空间复杂度：O(1)
	 */
	static void shellSort(int array[], int length) {
		int gap = length / 2;
		while (gap >= 1) {
			//距离间隔gap为一组，遍历所有组
			for (int i = gap; i < length; i++) {
				if (array[i] < array[i - gap]) {
					int j = i - gap;
					int x = array[i];
//					array[i] = array[j];
					//寻找x在当前序列上的插入点
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
	 * 直接选择排序
	 * 思路：(1)从待排序序列中，找到关键字最小的元素；
	 * (2)如果最小元素不是待排序序列的第一个元素，将其和第一个元素互换；
	 * (3)从余下的 N - 1 个元素中，找出关键字最小的元素，重复(1)、(2)步，直到排序结束。
	 * 时间复杂度：O(n^2)
	 * 空间复杂度：O(1)
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
	 * 两路选择排序
	 * 思路：外循环确定当前元素位置（头和尾），内循环遍历剩下元素并记录最大值和最小值的位置
	 * 最后交换最值与当前元素
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
	 * 冒泡排序
	 * 思路：每次内循环使相邻元素有序，单次循环后最大值沉底（升序时）
	 * 之后缩短内循环范围，继续上述操作，但是 有个问题，太冗杂
	 * 时间复杂度：O(N^2)
	 * 空间复杂度：O(1)
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
	 * 改进冒泡1
	 * 思路：设置一标志性变量pos,用于记录每趟排序中最后一次进行交换的位置。
	 * 由于pos位置之后的记录均已交换到位,故在进行下一趟排序时只要扫描到pos位置即可
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
	 * 改进冒泡2
	 * 思路：进行两个方向的冒泡，以升序为例，正方向上下沉最大值，逆方向上上浮最小值
	 * 范围是在不断缩小的
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
	 * 桶排序
	 * 思路：
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
	 * 基数排序
	 * 思路：由低位到高位，分别用桶排序使之有序
	 */
	//得到最大数的位数
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
	//得到某位上的数字，最大支持5位
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
		//从低位到高位排序
		for (int d = 1; d <= digits; d++) {
			for (i = 0; i < radix; i++) {
				count[i] = 0;
			}
			//统计各个桶要装入数据的个数
			for (i = 0; i < n; i++) {
				j = getDigit(a[i], d);
				count[j]++;
			}
			// count[i]表示第i个桶的右边界索引,将桶映射到数组
			// 表明当前界限之前有多少个元素要入桶，累加的意图就是为前面小元素空位
			// count[j]-count[j-1]就代表 j桶中元素的个数
			//--|---|----|-----|
			for (i = 1; i < radix; i++) {
				count[i] = count[i] + count[i - 1];
			}
			// 将数据依次装入桶中
			// 这里要从右向左扫描，保证排序稳定性
			for (i = n - 1; i >= 0; i--) {
				j = getDigit(a[i], d);
				bucket[count[j] - 1] = a[i];			//根据索引，得到桶对应数组的位置，从后向前
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
//		bucketSort(array, size, 8);//max 需要大于数组里最大值
//		radixSort(array, size, 10);
//		OutSortTest();
		print(array, size);
	}

	/*
	 * 外排序
	 * 思路：首先对大文件分割，并排序存到小文件中。
	 * 打开所有小文件，每个文件打开时读入第一个数，数来自哪个文件也要记录，填满buf（buf大小和文件个数一致），
	 * 对buf建立最小堆，将堆顶数据写入输出文件，并从堆顶元素来自的文件补充一个元素，重新建堆，重复上述。
	 * 直到写出的数据个数和总个数相等时，结束
	 */
#include <stdio.h>
#include <time.h>
#include <math.h>
	//在文件中随机产生m个数据，每个一行
	static void OutSortGenData(char *fileName, int m) {
		FILE *fp = fopen(fileName, "w");
		if (fp == NULL) {
			printf("open file failed \n");
			exit(-1);
		}
		srand(time(0));
		for (int i = 0; i < m; i++) {
			int temp = (rand() << 15) | rand();	//rand一般产生15位随机数(32767)，扩展成30位
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
		OPair temp = a[parent]; //保存当前父节点
		int child = 2 * parent + 1; //获取左孩子
		while (child < length) {
			/*****小顶堆********/
			//如果有有孩子，且右孩子小于做孩子，选取右孩子节点
			if (child + 1 < length && a[child].num > a[child + 1].num) {
				child++;
			}
			// 如果父结点的值已经小于孩子结点的值，则直接结束
			if (a[parent].num < a[child].num) {
				break;
			}
			// 把孩子结点的值赋给父结点
			a[parent] = a[child];
			// 选取孩子结点的左孩子结点,继续向下筛选
			parent = child;
			child = 2 * child + 1;
		}
		a[parent] = temp;
		//PrintHeapSort(a, length);
	}
	/**
	 * 初始堆进行调整
	 * 将H[0..length-1]建成堆
	 * 调整完之后第一个元素是序列的最小的元素
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
