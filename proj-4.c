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
int subCount = 1;
struct semaphore *sub;
struct semaphore *pub;

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
	while (1) {
		P(sub);
		// Critical Section
		addItem(rand());
		printList();
		// End Critical Section
		V(sub);
		V(pub);
	}

	return;
}

//-------------------//
// subscriber Method //
//-------------------//
void subscriber() {
	// Grab the Subscriber ID from the Counter
	int subID = subCount;

	// Declare the Pointer to the Linked List of Items
	struct item *volume = head;

	while (1) {
		P(pub);
		// Critical Section
		if (DEBUG) printf("SUBSCRIBER(%d): CHECKING FOR ITEMS\n", subID);

		// Checking for Published Items
		if (NULL == volume) {
			printf("SUBSCRIBER(%d): ERROR CHECKED TOO EARLY\n", subID);
		}

		// Iterate over all Published Items
		while (NULL != volume) {
			// Print Subscriber Tag
			printf("SUBSCRIBER(%d): ", subID);

			// Read One Volume of Work 
			readItem(volume);

			volume = volume->next; // Iterate to next Item
		}

		if (DEBUG) printf("SUBSCRIBER(%d): CHECKING SUB COUNT (%d)\n", subID, subCount);

		if (subCount < SUB_LIMIT) {
			// Call your buddy and add a new subscriber
			subCount++;
			startThread(subscriber);

			if (DEBUG) printf("SUBSCRIBER(%d): ADDED NEW SUBSCRIBER\n", subID);
		}

		// End Critical Section
		V(pub);

		printf("\n");

		P(sub);
		// Critical Section
		if (DEBUG) printf("SUBSCRIBER(%d): GRABBING CURRENT VOLUME\n", subID);
		volume = curr;
		// End Critical Section
		V(sub);
	}

	return;
}

//-------------//
// main Method //
//-------------//
int main() {
	// Define the Random Number Generator
	srand(time(NULL));

	// Allocate memory for the Semaphores
	sub = (struct semaphore*) malloc(sizeof(struct semaphore));
	pub = (struct semaphore*) malloc(sizeof(struct semaphore));

	// Allocate memory for the Run Queue to hold the threaded processes
	runQ = (struct queue*) malloc(sizeof(struct queue));

	// Create the Queue
	initQueue(runQ);

	// Initialize the Semaphore
	initSem(sub, 1);
	initSem(pub, 0);

	// Add processes to threads
	startThread(publisher);
	startThread(subscriber);

	// Begin execution of threads
	run();

	return 0;
}
