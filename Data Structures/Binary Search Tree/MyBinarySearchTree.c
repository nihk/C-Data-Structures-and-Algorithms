#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MyBinarySearchTree.h"

// Function definitions
TreeNodePtr makeTreeNode(NodeData data) {
	TreeNodePtr node = malloc(sizeof *node);
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

NodeData makeNodeData(char word[], int frequency) {
	NodeData data;
	strcpy(data.word, word);
	data.frequency = frequency;

	return data;
}

void visitNode(TreeNodePtr node) {
	printf("%15s : %d\n", node->data.word, node->data.frequency);
}

// NLR
void preOrder(TreeNodePtr node) {
	if (node != NULL) {
		visitNode(node);
		preOrder(node->left);
		preOrder(node->right);
	}
}

// LNR
// An in order traversal of a BST will print in alphabetical order
void inOrder(TreeNodePtr node) {
	if (node != NULL) {
		inOrder(node->left);
		visitNode(node);
		inOrder(node->right);
	}
}

// LRN
void postOrder(TreeNodePtr node) {
	if (node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		visitNode(node);
	}
}

// From a file which specifically defines the tree, e.g. A B @ @ C @ @
// Note: this function can potentially create a regular binary tree (i.e. not a BST)
TreeNodePtr buildTree(FILE *fp) {
	char word[MAX + 1];
	fscanf(fp, "%s", word);
	
	if (strcmp(word, "@") == 0) {
		return NULL;
	}

	NodeData data = makeNodeData(word, 1);
	TreeNodePtr node = makeTreeNode(data);

	node->left = buildTree(fp);
	node->right = buildTree(fp);

	return node;
}

// Searches for a word in a binary search tree. If not found, inserts it in the ordered spot
TreeNodePtr findOrInsert(BinaryTree binaryTree, NodeData data) {
	if (binaryTree.root == NULL) {
		return makeTreeNode(data);
	}

	TreeNodePtr curr = binaryTree.root;
	int comparison;

	while ((comparison = strcmp(data.word, curr->data.word)) != 0) {
		if (comparison < 0) {
			if (curr->left == NULL) {
				return curr->left = makeTreeNode(data);
			} 
			
			curr = curr->left;
		} else {
			if (curr->right == NULL) {
				return curr->right = makeTreeNode(data);
			}

			curr = curr->right;
		}
	}

	return curr;
}

// Returns NULL if the data wasn't found
TreeNodePtr find(BinaryTree binaryTree, NodeData data) {
	TreeNodePtr curr = binaryTree.root;
	int comparison;

	while (curr != NULL && (comparison = strcmp(data.word, curr->data.word)) != 0) {
		if (comparison < 0) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}

	return curr;
}

// Returns the found node and also captures its parent; used for node deletion
TreeNodePtr find2(BinaryTree binaryTree, TreeNodePtr *parent, NodeData data) {
	TreeNodePtr curr = binaryTree.root;
	int comparison;

	while (curr != NULL && (comparison = strcmp(data.word, curr->data.word)) != 0) {
		if (comparison < 0) {
			*parent = curr;
			curr = curr->left;
		} else {
			*parent = curr;
			curr = curr->right;
		}
	}

	return curr;
}

void delete(BinaryTree binaryTree, NodeData data) {
	TreeNodePtr parent, x;
	parent = NULL;
	x = find2(binaryTree, &parent, data);

	if (x == NULL) return;
	
	// x has two children, so replace its data with its in-order successor.
	// That latter node is then deleted thru one of the subsequent three
	// 'if' statement blocks. Therefore, if x had two children, its
	// in-order successor will always have <= 1 child.
	if (x->left != NULL && x->right != NULL) {
		parent = x;
		TreeNodePtr xSuccessor = x->right;
		while (xSuccessor->left != NULL) {
			parent = xSuccessor;
			xSuccessor = xSuccessor->left;
		}
		// Replace x's data with its in-order successor's data then assign
		// the in-order successor node to x for it to be deleted further on in
		// this function
		x->data = xSuccessor->data;
		x = xSuccessor;
	}

	// x has no children
	if (x->left == NULL && x->right == NULL) {
		if (parent == NULL) {printf("parent null\n"); return;}
		if (parent->right == x) {
			parent->right = NULL;
		} else {
			parent->left = NULL;
		}
		free(x);
		return;
	}

	// x has no left child
	if (x->left == NULL && x->right != NULL) {
		if (parent->left == x) {
			parent->left = x->right;
		} else {
			parent->right = x->right;
		}
		free(x);
		return;
	}

	// x has no right child
	if (x->left != NULL && x->right == NULL) {
		if (parent->left == x) {
			parent->left = x->left;
		} else {
			parent->right = x->left;
		}
		free(x);
		return;
	}
}

// Helper function to read an individual word from a file into the char word[] argument
int getWord(FILE *fp, char word[]) {
	char ch;
	int index = 0;

	while (!isalpha(ch = getc(fp)) && ch != EOF);
	
	if (ch == EOF) {
		return 0;
	}

	word[index] = tolower(ch);
	index++;

	while (isalpha(ch = getc(fp)) && ch != EOF) {
		if (index < MAX) {
			word[index] = tolower(ch);
			index++;
		}
	}

	word[index] = '\0';
	
	return 1;
}

int numNodes(TreeNodePtr node) {
	if (node == NULL) {
		return 0;
	}

	return 1 + numNodes(node->left) + numNodes(node->right);
}
