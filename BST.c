// BST.c
#include "BST.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

BST* bst_create(void) {
	return calloc(1, sizeof(BST));
}
void destroy(TreeNode* root) {
	// 边界条件
	if (root == NULL) {
		return;
	}
	// 递归公式
	// 遍历左子树
	destroy(root->left);
	// 遍历右子树
	destroy(root->right);
	// 遍历根结点
	free(root);
}
void bst_destroy(BST* tree) {
	destroy(tree->root);
}

void bst_insert(BST* tree, K key) {
	// 1. 找到添加的位置
	TreeNode* parent = NULL;
	TreeNode* curr = tree->root;

	int cmp;
	while (curr) {
		cmp = key - curr->key;
		if (cmp < 0) {
			parent = curr;
			curr = curr->left;
		}
		else if (cmp > 0) {
			parent = curr;
			curr = curr->right;
		}
		else {
			// key 已存在
			return;
		}
	}	// curr == NULL, cmp = key - parent->key
	// 2. 添加节点
	// a. 创建节点并初始化
	TreeNode* newnode = calloc(1, sizeof(TreeNode));
	newnode->key = key;
	// b. 链接
	if (parent == NULL) {
		tree->root = newnode;
	}
	else if (cmp < 0) {
		parent->left = newnode;
	}
	else {
		parent->right = newnode;
	}
}

TreeNode* bst_search(BST* tree, K key) {
	TreeNode* curr = tree->root;
	while (curr) {
		int cmp = key - curr->key;
		if (cmp < 0) {
			curr = curr->left;
		}
		else if (cmp > 0) {
			curr = curr->right;
		}
		else {
			return curr;
		}
	} // curr == NULL
	return NULL;
}

void bst_delete(BST* tree, K key) {
	// 1. 找到删除的节点
	TreeNode* parent = NULL;
	TreeNode* curr = tree->root;
	while (curr) {
		int cmp = key - curr->key;
		if (cmp < 0) {
			parent = curr;
			curr = curr->left;
		}
		else if (cmp > 0) {
			parent = curr;
			curr = curr->right;
		}
		else {
			break;
		}
	} // curr == NULL || curr != NULL
	if (curr == NULL) return;
	// 2. 删除 curr 节点
	if (curr->left && curr->right) {
		// 退化成度为0或者度为1的情况
		TreeNode* minp = curr;
		TreeNode* min = curr->right;
		while (min->left) {
			minp = min;
			min = min->left;
		}
		// 退化
		curr->key = min->key;
		curr = min;
		parent = minp;
	}

	// 找到唯一的孩子
	TreeNode* child = curr->left ? curr->left : curr->right;

	if (parent == NULL) {
		tree->root = child;
	}
	else {
		// 将child链接到parent的正确位置
		int cmp = curr->key - parent->key;	// Caution: 得重新比较
		if (cmp < 0) {
			parent->left = child;
		}
		else if (cmp > 0) {
			parent->right = child;
		}
		else {
			// Caution: 可能cmp == 0
			parent->right = child;
		}
	}
	free(curr);
}
//中序遍历
void inorder(TreeNode* root) {
	// 边界条件
	if (root == NULL) {
		return;
	}
	// 递归公式
	// 遍历左子树
	inorder(root->left);
	// 遍历根结点
	printf("%d ", root->key);
	// 遍历右子树
	inorder(root->right);
}
void bst_inorder(BST* tree) {
	inorder(tree->root);
	printf("\n");
}

//先根遍历
void preorder(TreeNode* root) {
	// 边界条件
	if (root == NULL) {
		return;
	}
	// 递归公式
	// 遍历根结点
	printf("%d ", root->key);
	// 遍历左子树
	preorder(root->left);
	// 遍历右子树
	preorder(root->right);
}
void bst_preorder(BST* tree) {
	preorder(tree->root);
	printf("\n");
}

//后根遍历
void postorder(TreeNode* root) {
	// 边界条件
	if (root == NULL) {
		return;
	}
	// 递归公式
	// 遍历左子树
	postorder(root->left);
	// 遍历右子树
	postorder(root->right);
	// 遍历根结点
	printf("%d ", root->key);
}
void bst_postorder(BST* tree) {
	postorder(tree->root);
	printf("\n");
}

// 层次遍历
void bst_levelorder(BST* tree) {
	Queue* q = queue_create();
	// 将根结点入队列
	queue_push(q, tree->root);
	// 判断队列是否为空
	while (!queue_empty(q)) {
		// 出队列，遍历这个节点
		TreeNode* node = queue_pop(q);
		printf("%d ", node->key);
		// 判断是否有左孩子
		if (node->left) {
			queue_push(q, node->left);
		}
		// 判断是否有右孩子
		if (node->right) {
			queue_push(q, node->right);
		}
	} // queue_empty(q)
	printf("\n");
}
void bst_levelorder2(BST* tree) {
	int curLevelCount = 1;
	int NextLevelCount = 0;
	Queue* q = queue_create();
	//将根结点入队列
	queue_push(q, tree->root);
	//判断队列是否为空
	while (!queue_empty(q)) {
		//出队列，遍历这个节点
		TreeNode* node = queue_pop(q);
		printf("%d ", node->key);
		curLevelCount--;
		//判断是否有左孩子
		if (node->left) {
			queue_push(q, node->left);
			NextLevelCount++;
		}
		//判断是否有右孩子
		if (node->right) {
			queue_push(q, node->right);
			NextLevelCount++;
		}
		if (curLevelCount == 0) {
			printf("\n");
			curLevelCount = NextLevelCount;
			NextLevelCount = 0;
		}
	}
	printf("\n");
}