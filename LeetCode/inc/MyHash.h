/*
 * MyHash.h
 *
 *  Created on: 2017年3月1日
 *      Author: tla001
 */

#ifndef INC_MYHASH_H_
#define INC_MYHASH_H_
#include <iostream>
using namespace std;
class MyHashTable {
public:
#define HASHTABLEMAX 20
	typedef int HashDataType;
	typedef int HashPosType;
	typedef struct LinkNode {
		HashDataType data;
		struct LinkNode *next;
		LinkNode(HashDataType _data) :
				data(_data), next(NULL) {
		}
	} HashNode;
	struct HashHead {
		struct LinkNode *next;
		HashHead() :
				next(NULL) {
		}
	};

	MyHashTable() {
		initHashTable();
	}
	~MyHashTable() {
		dropHashTable();
	}
	/*
	 * 哈希表散列计算函数
	 * 计算哈希表的位置
	 */
	HashPosType hashFunc(HashPosType id) {
		HashPosType pos = 0;
		pos = id % HASHTABLEMAX;
		return pos;
	}
	/*
	 * 初始化hash head，作为亚节点
	 */
	void initHashTable() {
		for (int i = 0; i < HASHTABLEMAX; i++) {
			hashTable[i] = new HashHead();
		}
	}
	void dropHashTable() {
		HashNode *node;
		HashHead *head;
		for (int i = 0; i < HASHTABLEMAX; i++) {
			head = hashTable[i];
			node = hashTable[i]->next;
			while (node) {
				head->next = node->next;
				delete node;
				node = head->next;
			}
			delete head;
		}
	}
	/*
	 * 查找当前hashTable中是否包含此元素
	 */
	HashNode *find(HashDataType data) {
		HashPosType pos = hashFunc(data);
		HashNode * node = hashTable[pos]->next;
		if (node == NULL)
			return NULL;
		while (node) {
			if (node->data == data)
				return node;
			node = node->next;
		}
		return NULL;
	}
	/*
	 * 插入元素
	 * 去除重复元素，有重复时，直接返回false
	 * 升序插入
	 */
	bool insert(HashDataType data) {
		if (NULL != find(data))
			return false;
//		cout << "insert data " << data << endl;
		HashPosType pos = hashFunc(data);
		HashHead *head = hashTable[pos];
		HashNode * node = hashTable[pos]->next;
		HashNode *tem = new HashNode(data);
		//处理空
		if (node == NULL) {
			head->next = tem;
			return true;
		}
		//处理第一个有效结点
		if (node->data > tem->data) {
			tem->next = node;
			head->next = tem;
			return true;
		}
		HashNode *prev = node;
		node = node->next;
		while (node) {
			if (node->data < tem->data) {
				prev = prev->next;
				node = node->next;
			} else {
				tem->next = node;
				prev->next = tem;
				return true;
			}
		}
		prev->next = tem;
		return true;
	}
	/*
	 * 删除元素
	 */
	bool remove(HashDataType data) {
		HashPosType pos = hashFunc(data);
		HashHead *head = hashTable[pos];
		HashNode *prev;
		HashNode * node = hashTable[pos]->next;
		if (node->data == data) {
			head->next = node->next;
			delete node;
			return true;
		}
		prev = node;
		node = node->next;
		while (node) {
			if (node->data == data) {
				prev->next = node->next;
				delete node;
				return true;
			}
			prev = prev->next;
			node = node->next;
		}
		return false;
	}
	/*
	 * 得到总元素个数
	 */
	int size() {
		HashNode *node;
		int num = 0;
		for (int i = 0; i < HASHTABLEMAX; i++) {
			node = hashTable[i]->next;
			while (node) {
				num++;
				node = node->next;
			}
		}
		return num;
	}
	/*
	 * 打印
	 */
	void print() {
		HashNode *node;
		cout << "******************hash table**************" << endl;
		for (int i = 0; i < HASHTABLEMAX; i++) {
			node = hashTable[i]->next;
			if (node) {
				cout << "id " << i << " : ";
				while (node) {
					cout << node->data << " -> ";
					node = node->next;
				}
				cout << endl;
			}
		}
	}
private:
	HashHead *hashTable[HASHTABLEMAX];
public:
	static void test() {
		MyHashTable *hashTable = new MyHashTable();
		for (int i = 1; i < 5; i++) {
			hashTable->insert(i);
		}
		hashTable->print();
		hashTable->remove(3);
		hashTable->print();
		for (int i = 1; i < 5; i++) {
			hashTable->insert(i + HASHTABLEMAX * 2);
		}
		hashTable->print();
		cout << hashTable->size() << endl;
		for (int i = 1; i < 5; i++) {
			hashTable->insert(i + HASHTABLEMAX);
		}
		hashTable->print();
	}
};

#endif /* INC_MYHASH_H_ */
