/*
 * MyTree.h
 *
 *  Created on: 2017��1��3��
 *      Author: tla001
 */

#ifndef INC_MYTREE_H_
#define INC_MYTREE_H_
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
class MyBitTree {
public:
	typedef char Elemtype;
	struct TreeNode {
		Elemtype val;
		TreeNode *left;
		TreeNode *right;
		TreeNode() :
				val(0), left(NULL), right(NULL) {
		}
		TreeNode(Elemtype a) :
				val(a), left(NULL), right(NULL) {
		}
	};
	/*
	 * ��ӡ�������
	 */
	void printResult(vector<Elemtype> res) {
		for (vector<Elemtype>::iterator ite = res.begin(); ite != res.end();
				ite++) {
			cout << *ite << "\t";
		}
		cout << endl;
	}
	/*
	 * ����
	 */
	void visit(TreeNode *tree) {
		if (tree) {
			cout << tree->val << "\t";
		}
	}
	/*
	 * �������--�ݹ�
	 * recursive
	 */

	void preOrderR(TreeNode *tree) {
		if (tree) {
			visit(tree);
			preOrderR(tree->left);
			preOrderR(tree->right);
		}
	}

	void _preOrderR(TreeNode *tree, vector<Elemtype>&res) {
		if (tree) {
			res.push_back(tree->val);
			_preOrderR(tree->left, res);
			_preOrderR(tree->right, res);
		} else
			return;
	}
	vector<Elemtype> preOrderRV(TreeNode *tree) {
		vector<Elemtype> res;
		if (tree)
			_preOrderR(tree, res);
		return res;
	}
	/*
	 * �������--�ݹ�
	 * recursive
	 */
	void inOrderR(TreeNode *tree) {
		if (tree) {
			inOrderR(tree->left);
			visit(tree);
			inOrderR(tree->right);
		}
	}
	void _inOrderR(TreeNode *tree, vector<Elemtype>&res) {
		if (tree) {
			_inOrderR(tree->left, res);
			res.push_back(tree->val);
			_inOrderR(tree->right, res);
		} else
			return;
	}
	vector<Elemtype> inOrderRV(TreeNode *tree) {
		vector<Elemtype> res;
		if (tree)
			_inOrderR(tree, res);
		return res;
	}
	/*
	 * �������--�ݹ�
	 * recursive
	 */
	void postOrderR(TreeNode *tree) {
		if (tree) {
			postOrderR(tree->left);
			postOrderR(tree->right);
			visit(tree);
		}
	}
	void _postOrderR(TreeNode *tree, vector<Elemtype>&res) {
		if (tree) {
			_postOrderR(tree->left, res);
			_postOrderR(tree->right, res);
			res.push_back(tree->val);
		} else
			return;
	}
	vector<Elemtype> postOrderRV(TreeNode *tree) {
		vector<Elemtype> res;
		if (tree)
			_postOrderR(tree, res);
		return res;
	}
	/*
	 * �������--�ǵݹ�
	 */
	void preOrder(TreeNode *tree) {
		TreeNode *root;
		stack<TreeNode *> s;
		root = tree;
		while (root || !s.empty()) {
			if (root) {
				visit(root);
				s.push(root);
				root = root->left;
			} else {
				root = s.top();
				s.pop();
				root = root->right;
			}
		}
	}
//	vector<Elemtype> preOrderV(TreeNode *tree) {
//		TreeNode *root;
//		vector<Elemtype> res;
//		stack<TreeNode *> s;
//		root = tree;
//		while (root || !s.empty()) {
//			if (root) {
//				res.push_back(root->val);
//				s.push(root);
//				root = root->left;
//			} else {
//				root = s.top();
//				s.pop();
//				root = root->right;
//			}
//		}
//		return res;
//	}
	//����д��
	vector<Elemtype> preOrderV(TreeNode *root) {
		vector<Elemtype> res;
		stack<TreeNode *> s;
		if (root == NULL) {
			return res;
		}
		TreeNode *cur;
		s.push(root);
		while (!s.empty()) {
			cur = s.top();
			s.pop();
			res.push_back(cur->val);
			if (cur->right != NULL)
				s.push(cur->right);
			if (cur->left != NULL)
				s.push(cur->left);
		}
		return res;
	}
	/*
	 * �������--�ǵݹ�
	 */
	void inOrder(TreeNode *tree) {
		TreeNode *root;
		stack<TreeNode *> s;
		root = tree;
		while (root || !s.empty()) {
			while (root) {
				s.push(root);
				root = root->left;
			}
			if (!s.empty()) {
				root = s.top();
				s.pop();
				visit(root);
				root = root->right;
			}
		}
	}
	vector<Elemtype> inOrderV(TreeNode *root) {
		vector<Elemtype> res;
		stack<TreeNode *> s;
		while (root || !s.empty()) {
			while (root) {
				s.push(root);
				root = root->left;
			}
			if (!s.empty()) {
				root = s.top();
				s.pop();
				res.push_back(root->val);
				root = root->right;
			}
		}
		return res;
	}
	/*
	 * �������--�ǵݹ�
	 */
	void postOrder(TreeNode *root) {
		if (root == NULL)
			return;
		stack<TreeNode*> s;
		s.push(root);
		TreeNode *cur = NULL;
		while (!s.empty()) {
			cur = s.top();
			if (cur->left == NULL && cur->right == NULL) {
				visit(cur);
				s.pop();
			} else {
				if (cur->right) {
					s.push(cur->right);
					cur->right = NULL;
				}
				if (cur->left) {
					s.push(cur->left);
					cur->left = NULL;
				}
			}
		}
	}
	//��bug
//	void postOrder(TreeNode *tree) {
//		TreeNode *root;
//		stack<pair<TreeNode *, int>> s;
//		root = tree;
//		while (root || !s.empty()) {
//			while (root) {
//				s.push(pair<TreeNode *, int>(root, 0));
//				root = root->left;
//			}
//			if (s.top().second == 0) {
//				root = s.top().first;
//				s.top().second = 1;
//				root = root->right;
//			} else if (s.top().second == 1) {
//				while (s.top().second == 1) {
//					root = s.top().first;
//					s.pop();
//					visit(root);
//				}
//				root = NULL;
//			}
//		}
//	}
//	vector<Elemtype> postOrderV(TreeNode *tree) {
//		TreeNode *root;
//		vector<Elemtype> res;
//		stack<pair<TreeNode *, int>> s;
//		root = tree;
//		while (root || !s.empty()) {
//			while (root) {
//				s.push(pair<TreeNode *, int>(root, 0));
//				root = root->left;
//			}
//			if (s.top().second == 0) {
//				root = s.top().first;
//				s.top().second = 1;
//				root = root->right;
//			} else {
//				while (s.top().second == 1) {
//					root = s.top().first;
//					s.pop();
//					res.push_back(root->val);
//				}
//				root = NULL;
//			}
//		}
//		return res;
//	}
	//����д��
	vector<Elemtype> postOrderV(TreeNode *root) {
		vector<Elemtype> res;
		if (root == NULL)
			return res;
		stack<TreeNode*> s;
		s.push(root);
		TreeNode *cur = NULL;
		while (!s.empty()) {
			cur = s.top();
			if (cur->left == NULL && cur->right == NULL) {
				res.push_back(cur->val);
				s.pop();
			} else {
				if (cur->right) {
					s.push(cur->right);
					cur->right = NULL;
				}
				if (cur->left) {
					s.push(cur->left);
					cur->left = NULL;
				}
			}
		}
		return res;
	}
	/*
	 * �������--�ǵݹ�
	 */
	void levelOrder(TreeNode *tree) {
		TreeNode *root;
		queue<TreeNode *> q;
		root = tree;
		if (!root)
			return;
		q.push(root);
		while (!q.empty()) {
			root = q.front();
			q.pop();
			visit(root);
			if (root->left)
				q.push(root->left);
			if (root->right)
				q.push(root->right);
		}
	}
	vector<Elemtype> levelOrderV(TreeNode *tree) {
		TreeNode *root;
		vector<Elemtype> res;
		queue<TreeNode *> q;
		root = tree;
		if (!root)
			return res;
		q.push(root);
		while (!q.empty()) {
			root = q.front();
			q.pop();
			res.push_back(root->val);
			if (root->left)
				q.push(root->left);
			if (root->right)
				q.push(root->right);
		}
		return res;
	}
	/*
	 * �������
	 */
	int treeHeight(TreeNode *tree) {
		if (!tree)
			return 0;
		int left = treeHeight(tree->left);
		int right = treeHeight(tree->right);
		return (left > right ? left : right) + 1;
	}
	/*
	 * ����С���
	 */
	int treeMinHeight(TreeNode *root) {
		if (!root)
			return 0;
		int l = treeMinHeight(root->left);
		int r = treeMinHeight(root->right);
		if (l == 0 || r == 0)
			return 1 + r + l;
		return (l > r ? r : l) + 1;
	}
};
class OrdinaryBitTree: public MyBitTree {
public:

	/*
	 * ���뷽ʽ����������
	 */
	void createTree(TreeNode *& tree) {
		Elemtype data;
		cin >> data;
		if ('#' == data)
			tree = NULL;
		else {
			tree = new TreeNode(data);
			createTree(tree->left);
			createTree(tree->right);
		}
	}
	/*
	 * ���򴴽����Ƕ��з�ʽ
	 */
	void createTree1(TreeNode *&tree, vector<Elemtype> arr) {
		TreeNode *m;
		TreeNode *q;
		if (!tree)
			tree = new TreeNode(0);
		q = tree;
		int length = arr.size();
		if (length < 1 && length > 31)
			return;
		q->val = arr[0];
		for (int i = 2; i <= length; i++) {
			m = new TreeNode(arr[i - 1]);
			for (int j = 1; j < (int) floor(log10(i) / log10(2)); j++) {
				if (((int) floor(i / pow(2, (int) (log10(i) / log10(2)) - j)))
						% 2 == 0) { //0Ϊ����
					if (q->left == NULL) {
						cout << "�������,��" << i << "���ڵ��޸��ڵ�" << endl;
						delete m;
						return;
					}
					q = q->left;
				} else {
					if (q->right == NULL) {
						cout << "�������,��" << i << "���ڵ��޸��ڵ�" << endl;
						delete m;
						return;
					}
					q = q->right;
				}
			}
			if (i % 2 == 0) {
				q->left = m;
				cout << "�����: " << m->val << endl;
			} else {
				q->right = m;
				cout << "�Ҳ���: " << m->val << endl;
			}
			q = tree;
		}
	}
	/*
	 * ���򹹽������з�ʽ
	 */
	void createTree(TreeNode *&tree, vector<Elemtype> arr) {
		int length = arr.size();
		int i = 1;
		TreeNode *root, *temp;
		queue<TreeNode*> q;
		root = new TreeNode(arr[0]);
		q.push(root);
		tree = root;
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			if (i < length) {
				root = new TreeNode(arr[i]);
				q.push(root);
				temp->left = root;
			}
			i++;
			if (i < length) {
				root = new TreeNode(arr[i]);
				q.push(root);
				temp->right = root;
			}
			i++;
		}
	}
	/*
	 * �������ؽ�
	 * ��֪�������������
	 */
	TreeNode *reConstructBinaryTree1(vector<Elemtype> pre,
			vector<Elemtype> in) {
		TreeNode *tree = new TreeNode(pre[0]);
		int index = 0;
		for (; index < pre.size(); index++) {
			if (in[index] == pre[0]) {
				break;
			}
		}
		vector<Elemtype> inL(in.begin(), in.begin() + index);
		vector<Elemtype> inR(in.begin() + index + 1, in.end());

		vector<Elemtype> preL(pre.begin() + 1, pre.begin() + index + 1);
		vector<Elemtype> preR(pre.begin() + index + 1, pre.end());

		if (index == 0)
			tree->left = NULL;
		else
			tree->left = reConstructBinaryTree1(preL, inL);
		if (preR.size() == 0)
			tree->right = NULL;
		else
			tree->right = reConstructBinaryTree1(preR, inR);
		return tree;
	}
	/*
	 * �������ؽ�
	 * ��֪���򡢺���������
	 */
	TreeNode *reConstructBinaryTree2(vector<Elemtype> in,
			vector<Elemtype> post) {
		int length = post.size();
		TreeNode *tree = new TreeNode(post[length - 1]);
		int index = 0;
		for (; index < length; index++) {
			if (in[index] == post[length - 1]) {
				break;
			}
		}
		vector<Elemtype> inL(in.begin(), in.begin() + index);
		vector<Elemtype> inR(in.begin() + index + 1, in.end());

		vector<Elemtype> postL(post.begin(), post.begin() + index);
		vector<Elemtype> postR(post.begin() + index, post.end() - 1);

		if (index == 0)
			tree->left = NULL;
		else
			tree->left = reConstructBinaryTree2(inL, postL);
		if (postR.size() == 0)
			tree->right = NULL;
		else
			tree->right = reConstructBinaryTree2(inR, postR);
		return tree;
	}

	/*
	 * ����������--�ݹ�ʵ��
	 */
	void mirrorBinaryTreeR(TreeNode *&tree) {
		if (tree == NULL)
			return;
		if (tree->left != NULL || tree->right != NULL) {
			TreeNode *temp = tree->left;
			tree->left = tree->right;
			tree->right = temp;
		}
		if (tree->left)
			mirrorBinaryTreeR(tree->left);
		if (tree->right)
			mirrorBinaryTreeR(tree->right);
	}
	/*
	 * ����������--�ǵݹ�
	 */
	void mirrorBinaryTree(TreeNode *&tree) {
		if (tree == NULL)
			return;
		stack<TreeNode *> s;
		s.push(tree);
		while (!s.empty()) {
			TreeNode *root = s.top();
			s.pop();
			if (root->left != NULL || root->right != NULL) {
				TreeNode *temp = root->left;
				root->left = root->right;
				root->right = temp;
			}
			if (NULL != root->left)
				s.push(root->left);
			if (NULL != root->right)
				s.push(root->right);
		}
	}

	static void test1() {
		TreeNode * tree = NULL;
		OrdinaryBitTree treeFunc;
		char str[] = "ABCDEFGHIJKL";
		vector<Elemtype> arr(str, str + strlen(str));
		cout << "size " << arr.size() << endl;
		vector<Elemtype> res;
		treeFunc.printResult(arr);
		/*
		 * test1
		 */
		treeFunc.createTree1(tree, arr);
		//		treeFunc.preOrder(tree);
		//		cout << endl;
		//		treeFunc.inOrder(tree);
		//		cout << endl;
		treeFunc.postOrder(tree);
		cout << endl;
		treeFunc.levelOrder(tree);
		cout << endl;
		/*
		 * test2
		 */
		//		treeFunc.createTree(tree, arr);
		//		res = treeFunc.preOrderV(tree);
		//		treeFunc.printResult(res);
		//		res = treeFunc.inOrderV(tree);
		//		treeFunc.printResult(res);
		//		res = treeFunc.levelOrderV(tree);
		//		treeFunc.printResult(res);
		res = treeFunc.postOrderV(tree);
		treeFunc.printResult(res);
		/*
		 * test3
		 */
		//		treeFunc.createTree1(tree, arr);
		//		treeFunc.preOrderR(tree);
		//		cout << endl;
		//		treeFunc.inOrderR(tree);
		//		cout << endl;
		//		treeFunc.postOrderR(tree);
		//		cout << endl;
	}
	static void test2() {
		/*
		 * ��֪�������������
		 */
//		char apre[] = "abdeijcfg";
//		char ain[] = "dbiejafcg";
////		vector<Elemtype> pre = {1, 2, 4, 7, 3, 5, 6, 8};
////		vector<Elemtype> in = { 4, 7, 2, 1, 5, 3, 8, 6 };
//		vector<Elemtype> pre(apre, apre + strlen(apre));
//		vector<Elemtype> in(ain, ain + strlen(ain));
//		OrdinaryBitTree tt;
//		TreeNode *tree = tt.reConstructBinaryTree1(pre, in);
//		tt.preOrder(tree);
//		cout << endl;
//		tt.inOrder(tree);
//		cout << endl;
//		tt.postOrder(tree);
//		cout << endl;
		/*
		 * ��֪���򡢺���������
		 */
		char ain[] = "dbgeafc";
		char apost[] = "dgebfca";
		vector<Elemtype> in(ain, ain + strlen(ain));
		vector<Elemtype> post(apost, apost + strlen(apost));
		OrdinaryBitTree tt;
		TreeNode *tree = tt.reConstructBinaryTree2(in, post);
		tt.preOrder(tree);
		cout << endl;
		tt.inOrder(tree);
		cout << endl;
		tt.postOrder(tree);
		cout << endl;
	}
	static void test3() {
		char str[] = "ABCDEFGHIJKL";
		vector<Elemtype> arr(str, str + strlen(str));

		TreeNode *tree = NULL;
		OrdinaryBitTree tt;
		tt.createTree(tree, arr);
		tt.levelOrder(tree);
		cout << endl;
		tt.mirrorBinaryTreeR(tree);
		tt.levelOrder(tree);
		cout << endl;
		tt.mirrorBinaryTree(tree);
		tt.levelOrder(tree);
		cout << endl;
	}
	static void test() {
		//test1();
		//test2();
		test3();
	}
};
class BinarySearchTree: public MyBitTree {
public:
	/*
	 * ����Ԫ��
	 */
	TreeNode* BSTFind(TreeNode *tree, Elemtype e) {
		while (tree) {
			if (e > tree->val)
				tree = tree->right;
			else if (e < tree->val)
				tree = tree->left;
			else
				return tree;
		}
		return NULL;
	}
	/*
	 * �ݹ������С
	 */
	TreeNode *BSTFindMin(TreeNode *tree) {
		if (!tree)
			return NULL;
		else if (!tree->left)
			return tree;
		else
			return BSTFindMin(tree->left);
	}
	/*
	 * �����������
	 */
	TreeNode *BSTFindMax(TreeNode *tree) {
		if (tree) {
			while (tree->right)
				tree = tree->right;
			return tree;
		} else
			return NULL;
	}
	/*
	 * ����
	 */
	TreeNode *BSTInsert(TreeNode *&tree, Elemtype e) {
		if (!tree) {
			tree = new TreeNode(e);
		} else {
			if (e > tree->val)
				BSTInsert(tree->right, e);
			else if (e < tree->val)
				BSTInsert(tree->left, e);
			else
				;
		}
		return tree;
	}
	void BSTDelete(TreeNode *&tree, Elemtype e) {
		TreeNode *tem;
		if (!tree) {
			return;
		} else if (e < tree->val) {
			BSTDelete(tree->left, e);
		} else if (e > tree->val) {
			BSTDelete(tree->right, e);
		} else {
			if (tree->left && tree->right) {
				tem = BSTFindMin(tree->right);
				tree->val = tem->val;
//				if (!tem->left && !tem->right && tem)
//					delete tem;
				BSTDelete(tree->right, tree->val);
			} else {
				if (!tree->left && tree->right) {
					tree = tree->right;
				} else if (!tree->right && tree->left) {
					tree = tree->left;
				} else {
					tree = NULL;
				}
			}
		}
	}

	void BSTCreate(TreeNode *&tree, vector<Elemtype> arr) {
		for (int i = 0; i < arr.size(); i++) {
			BSTInsert(tree, arr[i]);
		}
	}

	static void test() {
		char str[] = "7264315";
		vector<Elemtype> arr(str, str + strlen(str));

		TreeNode *tree = NULL;
		BinarySearchTree bt;
		bt.BSTCreate(tree, arr);
		bt.levelOrder(tree);
		cout << endl;

		TreeNode *tem;
		tem = bt.BSTFindMax(tree);
		cout << "max " << tem->val << endl;

		tem = bt.BSTFindMin(tree);
		cout << "min " << tem->val << endl;

		bt.BSTDelete(tree, '4');
		bt.levelOrder(tree);
		cout << endl;
	}
};
class SomeSolutionOfTree: public OrdinaryBitTree {
public:
	/*
	 * �����������
	 */
	int treeDepth(TreeNode *tree) {
		if (!tree)
			return 0;
		int left = treeDepth(tree->left);
		int right = treeDepth(tree->right);
		return max(left, right) + 1;
	}
	/*
	 * �ж�һ���������Ƿ���ƽ����
	 */
	bool isBalancedBitTree(TreeNode *tree) {
		if (tree == NULL)
			return true;
		int left = treeDepth(tree->left);
		int right = treeDepth(tree->right);
		int diff = left - right;
		if (diff > 1 || diff < -1)
			return false;
		return isBalancedBitTree(tree->left) && isBalancedBitTree(tree->right);
	}
	/*
	 * ���һ�����Ƿ��Ƕ���������
	 */
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
	bool isValidBST(TreeNode *tree) {
		/*
		 * ���������ʽ
		 */
//		return _isValidBST_inoder(tree);
		/*
		 * ���巽ʽ
		 */
		return _isValidBST_define(tree, INT_MIN, INT_MAX);
	}
	bool _isValidBST_inoder(TreeNode *tree) {
		if (tree == NULL)
			return true;
		stack<TreeNode *> s;
		vector<int> v;
		while (tree || !s.empty()) {
			while (tree) {
				s.push(tree);
				tree = tree->left;
			}
			if (!s.empty()) {
				tree = s.top();
				s.pop();
				v.push_back(tree->val);
				tree = tree->right;
			}
		}
		if (v.size() == 1)
			return true;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] <= v[i - 1])
				return false;
		}
		return true;
	}
	bool _isValidBST_define(TreeNode *tree, int min, int max) {
		if (!tree)
			return true;
		if ((tree->val < max || (tree->val == INT_MAX && tree->right == NULL))
				&& (tree->val > min
						|| (tree->val == INT_MIN && tree->left == NULL))
				&& _isValidBST_define(tree->left, min, tree->val)
				&& _isValidBST_define(tree->right, tree->val, max))
			return true;
		return false;
	}
	/*
	 * �ж���B�Ƿ�Ϊ��A������
	 */
	bool isSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
		if (pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		else
			return isSubtree(pRoot1->left, pRoot2->left)
					&& isSubtree(pRoot1->right, pRoot2->right);
	}
	bool HasSubtree(TreeNode *pRoot1, TreeNode* pRoot2) {
		if (!pRoot1 || !pRoot2)
			return false;
		return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2)
				|| HasSubtree(pRoot1->right, pRoot2);
	}

	/*
	 * ��ȡ������������·�������ǴӸ���ʼ��·��ֽ��Ӧ�õ���һ������ֵ
	 */
	vector<vector<int>> pathSum1(TreeNode *root, int sum) {
		vector<int> path;
		vector<vector<int>> result;
		pathSumHelper1(path, result, root, sum);
		return result;
	}
	void pathSumHelper1(vector<int> path, vector<vector<int>>&result,
			TreeNode *root, int sum) {
		if (!root)
			return;
		path.push_back(root->val);
		if (root->val == sum)
			result.push_back(path);
		pathSumHelper1(path, result, root->left, sum - root->val);
		pathSumHelper1(path, result, root->right, sum - root->val);
	}
	/*
	 * ��ȡ������������·�������ǴӸ���ʼ����Ҷĩ�˽�����·��ֽ��Ӧ�õ���һ������ֵ
	 */
	vector<vector<int>> pathSum2(TreeNode *root, int sum) {
		vector<int> path;
		vector<vector<int>> result;
		pathSumHelper2(path, result, root, sum);
		return result;
	}
	void pathSumHelper2(vector<int> path, vector<vector<int>>&result,
			TreeNode *root, int sum) {
		if (!root)
			return;
		path.push_back(root->val);
		if (root->val == sum && root->left == NULL && root->right == NULL)
			result.push_back(path);
		pathSumHelper2(path, result, root->left, sum - root->val);
		pathSumHelper2(path, result, root->right, sum - root->val);
		result.pop_back();
	}
	/*
	 * ��������ת��Ϊһ��������Ҫ����Ŀռ�
	 */
	TreeNode *convertToList(TreeNode *root) {
		if (!root)
			return NULL;
		TreeNode *leftTail = convertToList(root->left);
		TreeNode *rightTail = convertToList(root->right);

		if (leftTail)
			leftTail->right = root->right;
		if (root->left)
			root->right = root->left;
		root->left = NULL;
		if (rightTail)
			return rightTail;
		else if (leftTail)
			return leftTail;
		else
			return root;
	}
	/*
	 * ��һ�����������ת��Ϊһ��ƽ��BST
	 */
	TreeNode *helper(vector<int> num, int first, int last) {
		if (first > last)
			return NULL;
		if (first == last) {
			TreeNode *parent = new TreeNode(num[first]);
			return parent;
		}
		int mid = (first + last) / 2;
		TreeNode *leftchild = helper(num, first, mid - 1);
		TreeNode *rightchild = helper(num, mid + 1, last);
		TreeNode *parent = new TreeNode(num[mid]);
		parent->left = leftchild;
		parent->right = rightchild;
		return parent;
	}
	TreeNode *sortArrayToBST(vector<int>&num) {
		if (num.size() == 0)
			return NULL;
		if (num.size() == 1) {
			TreeNode *parent = new TreeNode(num[0]);
			return parent;
		}
		int first = 0;
		int last = (int) num.size() - 1;
		return helper(num, first, last);
	}
	/*
	 * ����������и����ӵĶ��������ҵ������ڵ����һ���ڵ�
	 */
	TreeNode *leftMostNode(TreeNode *node) {
		if (!node)
			return NULL;
		while (node->left) {
			node = node->left;
		}
		return node;
	}
	bool isLeftChild(TreeNode *node, TreeNode *parent) {
		return parent->left = node;
	}
	TreeNode *inOrderSuccessor(TreeNode *node) {
		if (!node) {
			return NULL;
		}
		if (node->right)
			return leftMostNode(node->right);
		TreeNode *parent = node;		//node->parent
		while (parent && !isLeftChild(node, parent)) {
			node = parent;
			parent = node;		//node->parent
		}
		return parent;
	}
	/*
	 * BST����������������ӵĶ��������ҵ������ڵ����һ���ڵ�
	 */
	TreeNode *inOrderSuccessor(TreeNode *node, TreeNode *root) {
		if (!node)
			return NULL;
		if (node->left)
			return leftMostNode(node->left);
		TreeNode *successor = NULL;
		while (root) {
			if (root->val > node->val) {
				successor = root;
				root = root->left;
			} else {
				root = root->right;
			}
		}
		return successor;
	}
};
#endif /* INC_MYTREE_H_ */
