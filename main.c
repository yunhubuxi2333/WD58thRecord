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

	//先序遍历
	bst_preorder(tree);
	//中序遍历
	bst_inorder(tree);
	//后序遍历
	bst_postorder(tree);

	//层次遍历
	bst_levelorder(tree);
	//层次遍历2
	bst_levelorder2(tree);

	bst_destroy(tree);

	return 0;
}