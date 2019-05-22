#include <stdio.h>
#include <stdlib.h>


/* self-referential structure */
struct Node {	//now must store an array, not an item
	int data;
	//int item;
	struct Node *next;
};

struct List {
	struct Node *head;
	struct Node *tail;
	int capacity;
};


struct List SLL_new() {
	/* construct an empty list */
	struct List list;
	list.head = NULL;
	list.tail = NULL;
	return list;
}

int SLL_length(struct List *list) {
	/* return the number of items in the list */
	struct Node *p;

	int n = 0;
	for (p = list->head; p != NULL; p = p->next) {
		++n;
	}
	return n;
}

int SLL_empty(struct List *list) {	//only method that doesn't need to be changed.
	/* return true if the list contains no items */
	return list->head == NULL;
}

int SLL_pop(struct List *list) {
	/* remove and return the first item of the list */
	struct Node *node = list->head;
	int item = node->item;
	list->head = node->next;
	if (SLL_empty(list)) {
		list->tail = NULL;
	}
	free(node);
	return item;
}

void SLL_clear(struct List *list) {
	/* remove all the items from the list */
	while (!SLL_empty(list)) {
		SLL_pop(list);
	}
}

void SLL_push(struct List *list, int item) {	//always pushing one item at a time. maybe use a for-loop to iterate through the capacity the nodes take?
	/* insert the item at the front of the list */		//how many elements do i need to insert to get twice the speed? try with at least a million
	struct Node *node = malloc(sizeof(struct Node));
	node->item = item;
	node->next = list->head;
	if (SLL_empty(list)) {
		list->tail = node;
	}
	list->head = node;
}

void SLL_append(struct List *list, int item) {		//use circular array	and do not implement append
	/* append the item to the end of the list */
	if (SLL_empty(list)) {
		SLL_push(list, item);
	}
	else {
		struct Node *node = malloc(sizeof(struct Node));
		node->item = item;
		node->next = NULL;
		list->tail->next = node;
		list->tail = node;
	}
}


int main() {
	int i;

	struct List list = SLL_new();
	for (i = 0; i < 5; ++i) {
		SLL_push(&list, i);
		SLL_append(&list, i);
	}

	while (!SLL_empty(&list)) {
		printf("%d\n", SLL_pop(&list));
	}

	return 0;
}
