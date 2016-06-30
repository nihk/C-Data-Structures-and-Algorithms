#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct {
	char word[20];
} NodeData;

typedef struct node {
	NodeData data;
	struct node *next;
} Node, *NodePtr;

NodePtr makeNode(NodeData data) {
	NodePtr node = malloc(sizeof *node);
	node->data = data;
	node->next = NULL;

	return node;
}

NodeData makeNodeData(char word[]) {
	NodeData data;
	strcpy(data.word, word);

	return data;
}

// Reverses in place
void reverse(NodePtr *head) {
	NodePtr prev = NULL;
	NodePtr curr = *head;
	NodePtr next;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}

	*head = prev;
}

int length(NodePtr head) {
	NodePtr curr = head;
	int counter = 0;

	while (curr != NULL) {
		curr = curr->next;
		counter++;
	}

	return counter;
}

void addLast(NodePtr head, NodeData data) {
	NodePtr curr = head;

	while (curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = makeNode(data);
}

void addFirst(NodePtr *head, NodeData data) {
	NodePtr node = makeNode(data);
	node->next = *head;
	*head = node;
}

// Returns a reversed, new linked list based on the given param
NodePtr getReverse(NodePtr head) {
	NodePtr revHead = NULL;
	NodePtr curr = head;

	while (curr != NULL) {
		addFirst(&revHead, curr->data);
		curr = curr->next;
	}

	return revHead;
}

void insert(NodePtr *head, int index, NodeData data) {
	if (index == 0) {
		addFirst(head, data);
		return;
	}

	NodePtr prev = NULL;
	NodePtr curr = *head;
	int counter = 0;

	while (curr->next != NULL && counter != index) {
		prev = curr;
		curr = curr->next;
		counter++;
	}

	if (counter != index) {
		exit(0);
	}

	NodePtr node = makeNode(data);
	prev->next = node;
	node->next = curr;
}

void delete(NodePtr *head, int index) {
	NodePtr prev = NULL;
	NodePtr curr = *head;
	int counter = 0;

	if (index == 0) {
		prev = curr;
		*head = curr->next;
		free(prev);
		return;
	}

	while (curr->next != NULL && counter != index) {
		prev = curr;
		curr = curr->next;
		counter++;
	}

	if (counter != index) {
		exit(0);
	}

	prev->next = curr->next;
	free(curr);
}

NodePtr search(NodePtr head, NodeData data) {
	NodePtr curr = head;

	while (curr != NULL && curr->data.word != data.word) {
		curr = curr->next;
	}

	return curr;
}

void printLL(NodePtr head) {
	NodePtr curr = head;

	while (curr != NULL) {
		printf("%s ", curr->data.word);
		curr = curr->next;
	}
	printf("\n");
}

void printReverseLL(NodePtr curr) {
	if (curr != NULL) {
		printReverseLL(curr->next);
		printf("%s ", curr->data.word);
	}
}

int main(void) {
	// Basic demonstration of using a Linked List
	NodePtr head = makeNode(makeNodeData("A"));
	addLast(head, makeNodeData("B"));
	addLast(head, makeNodeData("C"));
	addLast(head, makeNodeData("D"));

	delete(&head, 2);
	insert(&head, 2, makeNodeData("_"));
	reverse(&head);

	NodePtr revrev = getReverse(head);

	printLL(revrev);
	return 0;
}
