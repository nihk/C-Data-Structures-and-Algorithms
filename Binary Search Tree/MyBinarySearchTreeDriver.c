#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MyBinarySearchTree.h"

int main(void) {
	// Read from a file and build a binary tree
	FILE *fp = fopen("tree.txt", "r");
	BinaryTree binaryTree;
	binaryTree.root = buildTree(fp);
	fclose(fp);

	// The three means of traversing a binary tree
	preOrder(binaryTree.root);
	printf("\n");
	//inOrder(binaryTree.root);
	//printf("\n");
	//postOrder(binaryTree.root);
	//printf("\n");

	NodeData data = makeNodeData("Z", 666);
	findOrInsert(binaryTree, data);

	preOrder(binaryTree.root);
	printf("\n");

	printf("\tNumber of nodes: %d\n\n", numNodes(binaryTree.root));

	// Demonstration of creating a binary search tree consisting of a paragraph's
	// word and word frequency
	binaryTree.root = NULL;
	char word[MAX + 1];
	fp = fopen("gatsby.txt", "r");

	while (getWord(fp, word) != 0) {
		if (binaryTree.root == NULL) {
			NodeData data = makeNodeData(word, 1);
			binaryTree.root = makeTreeNode(data);
		} else {
			NodeData data = makeNodeData(word, 0);
			TreeNodePtr node = findOrInsert(binaryTree, data);
			node->data.frequency++;
		}
	}

	fclose(fp);
	inOrder(binaryTree.root);
	printf("\tNumber of nodes: %d\n\n", numNodes(binaryTree.root));

	NodeData data1 = makeNodeData("zebra", 1);
	NodeData data2 = makeNodeData("younger", 1);
	TreeNodePtr node;

	// Search for words (without insertion)
	printf("Attempting to find \"%s\":\n", data1.word);

	if ((node = find(binaryTree, data1)) != NULL) {
		printf("Found %s!\n", node->data.word);
	} else {
		printf("Didn't find it.\n");
	}

	printf("Attempting to find \"%s\":\n", data2.word);

	if ((node = find(binaryTree, data2)) != NULL) {
		printf("Found \"%s\"!\n", node->data.word);
	} else {
		printf("Didn't find it.\n");
	}

	return 0;
}
