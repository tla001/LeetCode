/*
 * Page2.h
 *
 *  Created on: 2017Äê5ÔÂ22ÈÕ
 *      Author: tla001
 */

#ifndef INC_PAGE2_H_
#define INC_PAGE2_H_

#include "Include.h"
namespace LeetCode {

class Q21 {
public:
	void solve(vector<vector<char>> &board) {
		if (board.size() <= 0 || board[0].size() <= 0)
			return;
		int rowNum = board.size();
		int colNum = board[0].size();
		for (int i = 0; i < colNum; i++) {
			dfs(board, 0, i);
			dfs(board, rowNum - 1, i);
		}
		for (int i = 0; i < rowNum; i++) {
			dfs(board, i, 0);
			dfs(board, i, colNum - 1);
		}
		for (int i = 0; i < rowNum; i++) {
			for (int j = 0; j < colNum; j++) {
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
		for (int i = 0; i < rowNum; i++) {
			for (int j = 0; j < colNum; j++) {
				if (board[i][j] == '*') {
					board[i][j] = 'O';
				}
			}
		}
	}
	void dfs(vector<vector<char>> &board, int row, int col) {
		if (board[row][col] == 'O') {
			board[row][col] = '*';
			if (row > 1) {
				dfs(board, row - 1, col);
			}
			if (col > 1) {
				dfs(board, row, col - 1);
			}
			if (row < board.size() - 1) {
				dfs(board, row + 1, col);
			}
			if (col < board[0].size() - 1) {
				dfs(board, row, col + 1);
			}
		} else
			return;
	}
};

class Q22 {
public:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	static void cal(vector<vector<int>> &res, vector<int>&path,
			TreeNode *root) {
		if (!root)
			return;
		path.push_back(root->val);
		if (root->left == NULL && root->right == NULL)
			res.push_back(path);
		cal(res, path, root->left);
		cal(res, path, root->right);
		path.pop_back();
	}
	static int sumNumbers(TreeNode *root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return root->val;
		vector<vector<int>> res;
		vector<int> path;
		cal(res, path, root);
		int sum = 0;
		for (int i = 0; i < res.size(); i++) {
			int tmp = 0;
			for (int j = 0; j < res[i].size(); j++) {
				tmp = res[i][j] + 10 * tmp;
				cout << res[i][j];
			}
			cout << endl;
			sum += tmp;
		}
		return sum;
	}
	static void createTree(TreeNode *&tree, vector<int> arr) {
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
	static void test() {
		vector<int> arr = { 1, 0 };
		TreeNode *tree;
		createTree(tree, arr);
		cout << sumNumbers(tree) << endl;
	}
};
}

#endif /* INC_PAGE2_H_ */
