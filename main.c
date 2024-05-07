#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BST.h"
int main() {
	BST* tree = bst_create();

	bst_insert(tree, 4);
	bst_insert(tree, 2);
	bst_insert(tree, 6);
	bst_insert(tree, 1);
	bst_insert(tree, 3);
	bst_insert(tree, 5);
	bst_insert(tree, 7);

	//�������
	bst_preorder(tree);
	//�������
	bst_inorder(tree);
	//�������
	bst_postorder(tree);

	//��α���
	bst_levelorder(tree);
	//��α���2
	bst_levelorder2(tree);

	bst_destroy(tree);

	return 0;
}