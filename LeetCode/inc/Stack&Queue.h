/*
 * Stack&Queue.h
 *
 *  Created on: 2017��2��16��
 *      Author: tla001
 */

#ifndef INC_STACK_QUEUE_H_
#define INC_STACK_QUEUE_H_
#include "Include.h"
/*
 * ���һ��ջ������pop push max ʱ�临�Ӷ�ΪO(1)
 */
class stackWithMax {
private:
	stack<int> valueStack;
	stack<int> maxStack;
public:
	void push(int x) {
		valueStack.push(x);
		if (maxStack.empty() || maxStack.top() <= x) {
			maxStack.push(x);
		}
	}
	int pop() {
		int value = valueStack.top();
		valueStack.pop();
		if (value == maxStack.top())
			maxStack.pop();
		return value;
	}
	int max() {
		return maxStack.top();
	}
};
/*
 * ����һ��ջ�ṹ��ʵ��һ������
 */
class stackQueue {
private:
	stack<int> inStack;
	stack<int> outStack;
public:
	void enqueue(int x) {
		inStack.push(x);
	}
	int dequeue() {
		int value;
		if (!outStack.empty()) {
			value = outStack.top();
			outStack.pop();
			return value;
		}
		while (!inStack.empty()) {
			outStack.push(inStack.top());
			inStack.pop();
		}
		value = outStack.top();
		outStack.pop();
		return value;
	}
};
/*
 * �����������һ��ջ
 */
stack<int> sortStack(stack<int>&input) {
	stack<int> output;
	while (!input.empty()) {
		int value = input.top();
		while (!output.empty() && value <= output.top()) {
			input.push(output.top());
			output.pop();
		}
		output.push(value);
	}
	return output;
}
/*
 * ����һ���ַ������ж����ŵ�ƥ�����
 */
class IsPair {
public:
	bool isLeftParentheses(char input) {
		return input == '(' || input == '[' || input == '{';
	}
	bool isMatchParentheses(char left, char right) {
		switch (left) {
		case '(':
			return right == ')';
		case '[':
			return right == ']';
		case '{':
			return right == '}';
		}
		return false;
	}
	bool isValidParenteses(string input) {
		stack<char> stack;
		for (int i = 0; i < input.size(); i++) {
			if (isLeftParentheses(input[i])) {
				stack.push(input[i]);
			} else {
				if (stack.empty() || !isMatchParentheses(stack.top(), input[i]))
					return false;
				stack.pop();
			}
		}
		return stack.empty();
	}
};
/*
 * ջʵ���������
 */
class treeInoder {
public:
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
				val(x), left(NULL), right(NULL) {
		}
	};
	void visit(TreeNode *) {

	}
	void inOrderTraversal(TreeNode *root) {
		if (root == NULL)
			return;
		stack<TreeNode *> st;
		while (root || !st.empty()) {
			if (root) {
				st.push(root);
				root = root->left;
			} else {
				root = st.top();
				st.pop();
				visit(root);
				root = root->right;
			}
		}
	}
};

#endif /* INC_STACK_QUEUE_H_ */
