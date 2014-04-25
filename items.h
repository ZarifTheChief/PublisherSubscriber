// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 4
// Description: Stores the Published Items in a Linked List.
//		Allows Publishers to add items and Subscribers to read them.

#ifndef ITEMS_H
#define ITEMS_H

//---------------//
// Include Files //
//---------------//
#include <stdlib.h>

//----------------------------//
// Data Structure Declaration //
//----------------------------//
typedef struct item {
	int volume;
	int value;
	struct item *next;
} item;

//---------------------//
// Global Declarations //
//---------------------//
int volume = 0;
struct item *head;
struct item *curr;

//----------------------------//
// Method Forward Declaration //
//----------------------------//
struct item* createList(int);
struct item* addItem(int);
void printList();

struct item* createList(int value) {
	struct item *ptr = (struct item*) malloc(sizeof(struct item));

	if (NULL == ptr) {
		return NULL;
	}

	volume++;
	ptr->volume = volume;
	ptr->value = value;
	ptr->next = NULL;

	head = ptr;
	curr = ptr;

	return ptr;
}

struct item* addItem(int value) {
	if (NULL == head) {
		return createList(value);
	}

	struct item *ptr = (struct item*) malloc(sizeof(struct item));

	if (NULL == ptr) {
		return NULL;
	}

	volume++;
	ptr->volume = volume;
	ptr->value = value;	
	ptr->next = NULL;

	// Add Item to end of List
	curr->next = ptr;
	curr = ptr;

	// Increment the Linked List Counter
	volume++;

	return ptr;
}

void printList() {
	struct item *ptr = head;

	printf("----------PRINTING VOLUMES----------\n");
	printf("\n");

	// Iterate over the Linked List of Items
	while (NULL != ptr) {
		printf("VOLUME(%d):\t%d\n", ptr->volume, ptr->value); // Display the Volume Item Information	
		ptr = ptr->next; // Iterate to next node
	}

	printf("\n");
	printf("----------DONE PRINTING----------\n");
	printf("\n");
	printf("\n");
	
	return;
}

#endif
