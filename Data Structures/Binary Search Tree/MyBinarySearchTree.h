#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

// Struct definitions
typedef struct {
	char word[MAX];
	int frequency;
} NodeData;

typedef struct treeNode {
	NodeData data;
	struct treeNode *left, *right;
} TreeNode, *TreeNodePtr;

typedef struct {
	TreeNodePtr root;
} BinaryTree;

// Function prototypes
TreeNodePtr makeTreeNode(NodeData data);
NodeData makeNodeData(char word[], int frequency);
void visitNode(TreeNodePtr node);
void preOrder(TreeNodePtr node);
void inOrder(TreeNodePtr node);
void postOrder(TreeNodePtr node);
TreeNodePtr buildTree(FILE *fp);
TreeNodePtr findOrInsert(BinaryTree binaryTree, NodeData data);
TreeNodePtr find(BinaryTree binaryTree, NodeData data);
TreeNodePtr find2(BinaryTree binaryTree, TreeNodePtr *parent, NodeData data);
void delete(BinaryTree binaryTree, NodeData data);
int getWord(FILE *fp, char word[]);
void reverse(TreeNodePtr node);
int numNodes(TreeNodePtr node);
int numLeaves(TreeNodePtr node);
int treeHeight(TreeNodePtr node);
int max(int a, int b);
