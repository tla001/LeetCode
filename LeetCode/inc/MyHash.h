/*
 * MyHash.h
 *
 *  Created on: 2017��3��1��
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
	 * ��ϣ��ɢ�м��㺯��
	 * �����ϣ���λ��
	 */
	HashPosType hashFunc(HashPosType id) {
		HashPosType pos = 0;
		pos = id % HASHTABLEMAX;
		return pos;
	}
	/*
	 * ��ʼ��hash head����Ϊ�ǽڵ�
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
	 * ���ҵ�ǰhashTable���Ƿ������Ԫ��
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
	 * ����Ԫ��
	 * ȥ���ظ�Ԫ�أ����ظ�ʱ��ֱ�ӷ���false
	 * �������
	 */
	bool insert(HashDataType data) {
		if (NULL != find(data))
			return false;
//		cout << "insert data " << data << endl;
		HashPosType pos = hashFunc(data);
		HashHead *head = hashTable[pos];
		HashNode * node = hashTable[pos]->next;
		HashNode *tem = new HashNode(data);
		//�����
		if (node == NULL) {
			head->next = tem;
			return true;
		}
		//�����һ����Ч���
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
	 * ɾ��Ԫ��
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
	 * �õ���Ԫ�ظ���
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
	 * ��ӡ
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
