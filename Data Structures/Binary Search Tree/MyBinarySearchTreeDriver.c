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
	printf("Pre-order\n");
	preOrder(binaryTree.root);
	printf("\nIn-order\n");
	inOrder(binaryTree.root);
	printf("\nPost-order\n");
	postOrder(binaryTree.root);
	printf("\n\n");
	
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

	// Making a balanced BST
	NodeData a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s;
	a = makeNodeData("A", 1);
	b = makeNodeData("B", 1);
	c = makeNodeData("C", 1);
	d = makeNodeData("D", 1);
	e = makeNodeData("E", 1); 
	f = makeNodeData("F", 1);
	g = makeNodeData("G", 1);
	h = makeNodeData("H", 1);
	i = makeNodeData("I", 1);
	j = makeNodeData("J", 1);
	k = makeNodeData("K", 1);
	l = makeNodeData("L", 1);
	m = makeNodeData("M", 1);
	n = makeNodeData("N", 1);
	o = makeNodeData("O", 1);
	p = makeNodeData("P", 1);
	q = makeNodeData("Q", 1);
	r = makeNodeData("R", 1);
	s = makeNodeData("S", 1);

	binaryTree.root = makeTreeNode(i);
	findOrInsert(binaryTree, d);
	findOrInsert(binaryTree, b);
	findOrInsert(binaryTree, a);
	findOrInsert(binaryTree, c);
	findOrInsert(binaryTree, f);
	findOrInsert(binaryTree, e);
	findOrInsert(binaryTree, h);
	findOrInsert(binaryTree, g);
	findOrInsert(binaryTree, n);
	findOrInsert(binaryTree, k);
	findOrInsert(binaryTree, j);
	findOrInsert(binaryTree, l);
	findOrInsert(binaryTree, m);
	findOrInsert(binaryTree, q);
	findOrInsert(binaryTree, p);
	findOrInsert(binaryTree, o);
	findOrInsert(binaryTree, s);
	findOrInsert(binaryTree, r);

	printf("\n\nPre-order:\n");
	preOrder(binaryTree.root);
	delete(binaryTree, i);
	printf("\nNew Pre-order:\n");
	preOrder(binaryTree.root);

	return 0;
}
