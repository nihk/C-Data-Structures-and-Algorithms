#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "MyLinkedList.h"

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

	deleteNthNodeFromEnd(&revrev, 3);
	deleteMiddle(revrev->next);

	printLL(revrev);
	return 0;
}
