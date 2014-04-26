// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 4
// Description: Main file which holds the threads for Publisher-Subscriber.

//---------------//
// Include Files //
//---------------//
#include "sem.h"
#include "items.h"

//--------------------//
// Global Definitions //
//--------------------//
#define SUB_LIMIT 5

//---------------------//
// Global Declarations //
//---------------------//
int subCount = 0;
struct semaphore *sem;

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
	// Initialize a new Linked List to Store the Items Published
	createList(rand()); // Use a random number for Item

	while (1) {
		P(sem);
		// Critical Section
		addItem(rand());
		// End Critical Section
		V(sem);
	}

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
	// Define the Random Number Generator
	srand(time(NULL));

	// Allocate memory for the Semaphores
	sem = (struct semaphore*) malloc(sizeof(struct semaphore));

	// Allocate memory for the Run Queue to hold the threaded processes
	runQ = (struct queue*) malloc(sizeof(struct queue));

	// Create the Queue
	initQueue(runQ);

	// Add processes to threads
	startThread(publisher);
	startThread(subscriber);

	// Begin execution of threads
	run();

	return 0;
}
