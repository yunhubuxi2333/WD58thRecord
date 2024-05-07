// BST.c
#include "BST.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

BST* bst_create(void) {
	return calloc(1, sizeof(BST));
}
void destroy(TreeNode* root) {
	// �߽�����
	if (root == NULL) {
		return;
	}
	// �ݹ鹫ʽ
	// ����������
	destroy(root->left);
	// ����������
	destroy(root->right);
	// ���������
	free(root);
}
void bst_destroy(BST* tree) {
	destroy(tree->root);
}

void bst_insert(BST* tree, K key) {
	// 1. �ҵ���ӵ�λ��
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
			// key �Ѵ���
			return;
		}
	}	// curr == NULL, cmp = key - parent->key
	// 2. ��ӽڵ�
	// a. �����ڵ㲢��ʼ��
	TreeNode* newnode = calloc(1, sizeof(TreeNode));
	newnode->key = key;
	// b. ����
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
	// 1. �ҵ�ɾ���Ľڵ�
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
	// 2. ɾ�� curr �ڵ�
	if (curr->left && curr->right) {
		// �˻��ɶ�Ϊ0���߶�Ϊ1�����
		TreeNode* minp = curr;
		TreeNode* min = curr->right;
		while (min->left) {
			minp = min;
			min = min->left;
		}
		// �˻�
		curr->key = min->key;
		curr = min;
		parent = minp;
	}

	// �ҵ�Ψһ�ĺ���
	TreeNode* child = curr->left ? curr->left : curr->right;

	if (parent == NULL) {
		tree->root = child;
	}
	else {
		// ��child���ӵ�parent����ȷλ��
		int cmp = curr->key - parent->key;	// Caution: �����±Ƚ�
		if (cmp < 0) {
			parent->left = child;
		}
		else if (cmp > 0) {
			parent->right = child;
		}
		else {
			// Caution: ����cmp == 0
			parent->right = child;
		}
	}
	free(curr);
}
//�������
void inorder(TreeNode* root) {
	// �߽�����
	if (root == NULL) {
		return;
	}
	// �ݹ鹫ʽ
	// ����������
	inorder(root->left);
	// ���������
	printf("%d ", root->key);
	// ����������
	inorder(root->right);
}
void bst_inorder(BST* tree) {
	inorder(tree->root);
	printf("\n");
}

//�ȸ�����
void preorder(TreeNode* root) {
	// �߽�����
	if (root == NULL) {
		return;
	}
	// �ݹ鹫ʽ
	// ���������
	printf("%d ", root->key);
	// ����������
	preorder(root->left);
	// ����������
	preorder(root->right);
}
void bst_preorder(BST* tree) {
	preorder(tree->root);
	printf("\n");
}

//�������
void postorder(TreeNode* root) {
	// �߽�����
	if (root == NULL) {
		return;
	}
	// �ݹ鹫ʽ
	// ����������
	postorder(root->left);
	// ����������
	postorder(root->right);
	// ���������
	printf("%d ", root->key);
}
void bst_postorder(BST* tree) {
	postorder(tree->root);
	printf("\n");
}

// ��α���
void bst_levelorder(BST* tree) {
	Queue* q = queue_create();
	// ������������
	queue_push(q, tree->root);
	// �ж϶����Ƿ�Ϊ��
	while (!queue_empty(q)) {
		// �����У���������ڵ�
		TreeNode* node = queue_pop(q);
		printf("%d ", node->key);
		// �ж��Ƿ�������
		if (node->left) {
			queue_push(q, node->left);
		}
		// �ж��Ƿ����Һ���
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
	//������������
	queue_push(q, tree->root);
	//�ж϶����Ƿ�Ϊ��
	while (!queue_empty(q)) {
		//�����У���������ڵ�
		TreeNode* node = queue_pop(q);
		printf("%d ", node->key);
		curLevelCount--;
		//�ж��Ƿ�������
		if (node->left) {
			queue_push(q, node->left);
			NextLevelCount++;
		}
		//�ж��Ƿ����Һ���
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