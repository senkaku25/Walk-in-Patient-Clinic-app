#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "List.h"
#include "Patient.h"



using namespace std;
/*
private members to work with:
static const int MAX_ELEMENTS = 3;
Patient elements[MAX_ELEMENTS];
int elementCount;
int capacity;

*/

// Default constructor
List::List() : elementCount(0), capacity(MAX_ELEMENTS) {
}


int  List::getElementCount() const {
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement) {// TO BE CONT.
	bool dup = false; //if there is a duplicate patient, we don't add it in
	int i;
	int pos;

	if (elementCount == capacity)	return false;

	for (i = 1; i < elementCount+1; i++) {//finding a duplicate
		if (elements[i] == newElement) dup = true;
	}

	if (dup == true) return false; //theres a duplicate so we cannot add another
	if (dup == false) {
		//if (MAX_ELEMENTS < elementCount) MAX_ELEMENTS++;
		elementCount++;
		i = 1;
		while ((i<elementCount) && (newElement.getCareCard() > elements[i].getCareCard())) {  
			i++;																				 
		}

		pos = i;
		//elements[pos] = newElement;
		for (i=pos; i <= elementCount-1; i++) {elements[i+1] = elements[i];}
		elements[pos] = newElement;
	}
	return true;
}

// Description: Remove an element.
// Precondition: no duplicated patients
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove(const Patient& toBeRemoved) {
	int i;
	bool isthere=false; //is the patient even on the list?

	for (i = 1; i < elementCount+1; i++) {
		if (isthere) {
			elements[i - 1] = elements[i]; //shifting the elements back if we found the element
		}
		if (elements[i] == toBeRemoved) {//is the current patient the to be removed one?
			isthere = true;
		}
	}

	if (isthere == false) {
		cout << "Patient not in our system" << endl;
		return false;
	}
	else {
		elementCount--;
		/*
		if (i == elementCount) {
			elements[i-1] = Patient(); //COMMENTING OUT FOR NOWWWWWWWWWWWWWWWWW
		}
		*/
		return true;
	} //decreasing element count by 1
}

// Description: Remove all elements.
// TO BE CHECKED =========================>
void List::removeAll() {
	memset(elements, 0, sizeof(elements)); //setting all elements to 0 before removing them
	elementCount = 0; //unstable remove
}



// Description: Search for target element via carecard
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target) {
	int i;
	for (i = 1; i < elementCount+1; i++) {
		if (elements[i].getCareCard() == target.getCareCard()) return &elements[i]; //returns the address of the element which is the target
	}
	return NULL;
}

// Description: Prints all elements stored in List.
void List::printList() {
	int i;
	for (i = 1; i < elementCount+1; i++) {elements[i].printPatient();}//patients get added from 1 onwards
}
