// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 4
// Description: Main file which holds the threads for Publisher-Subscriber.

//---------------//
// Include Files //
//---------------//
#include "sem.h"

//--------------------//
// Global Definitions //
//--------------------//
#define SHELF_SIZE 5

//---------------------//
// Global Declarations //
//---------------------//
int in = 0;
int out = 0;
int global = 0;
int shelf[SHELF_SIZE];
struct semaphore *sem;
struct semaphore *empty;
struct semaphore *full;

//----------------------------//
// Method Forward Declaration //
//----------------------------//

//--------------------//
// Threaded Functions //
//--------------------//
void publisher();
void subscriber();

//------------------//
// publisher Method //
//------------------//
void publisher() {
	return;
}

//-------------------//
// subscriber Method //
//-------------------//
void subscriber() {
	return;
}

//-------------//
// main Method //
//-------------//
int main() {
	// Allocate memory for the two Semaphores
	empty = (struct semaphore*) malloc(sizeof(struct semaphore));
	full = (struct semaphore*) malloc(sizeof(struct semaphore));

	// Allocate memory for the Run Queue to hold the threaded processes
	runQ = (struct queue*) malloc(sizeof(struct queue));

	// Create the Queue
	initQueue(runQ);

	// Initialize the 2 Semaphores. Make empty = N and full = 0
	initSem(empty, SHELF_SIZE);
	initSem(full, 0);

	// Prepare the shelf
	initShelf();

	// Add processes to threads
	startThread(consumer1);
	startThread(consumer2);
	startThread(producer1);
	startThread(producer2);

	// Begin execution of threads
	run();

	return 0;
}
