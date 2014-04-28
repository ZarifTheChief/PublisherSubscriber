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
#include <time.h>

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
void createList(int);
void addItem(int);
void readItem(struct item*);
void printList();

void createList(int value) {
	struct item *ptr = (struct item*) malloc(sizeof(struct item));

	if (NULL == ptr) {
		printf("ERROR: Could not allocate memory\n");
		return;
	}

	if (DEBUG) printf("----------CREATING LIST----------\n");

	volume++;
	ptr->volume = volume;
	ptr->value = value;
	ptr->next = NULL;

	head = ptr;
	curr = ptr;

	printf("PUBLISHING: VOLUME(%d)\t%d\n\n", ptr->volume, ptr->value);

	return;
}

void addItem(int value) {
	if (NULL == head) {
		createList(value);
		return;
	}

	struct item *ptr = (struct item*) malloc(sizeof(struct item));

	if (NULL == ptr) {
		printf("ERROR: Could not allocate memory\n");
		return;
	}

	volume++;
	ptr->volume = volume;
	ptr->value = value;	
	ptr->next = NULL;

	// Add Item to end of List
	curr->next = ptr;
	curr = ptr;

	printf("PUBLISHING: VOLUME(%d)\t%d\n\n", ptr->volume, ptr->value);

	return;
}

void readItem(struct item *ptr) {
	if (NULL == ptr) {
		printf("ERROR: INVALID POINTER (READING)\n");
		return;
	}

	printf("READING VOLUME(%d)\t%d\n", ptr->volume, ptr->value);	

	return;
}

void printList() {
	struct item *ptr = head;

	printf("----------PRINTING VOLUMES----------\n");

	// Iterate over the Linked List of Items
	while (NULL != ptr) {
		printf("VOLUME(%d):\t%d\n", ptr->volume, ptr->value); // Display the Volume Item Information	
		ptr = ptr->next; // Iterate to next node
	}

	printf("----------DONE PRINTING----------\n");
	printf("\n");
	printf("\n");

	sleep(1);
	
	return;
}

#endif
