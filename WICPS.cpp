#include <iostream>
#include <string>
#include <cctype>
#include "List.h"
#include "Patient.h"
using namespace std;


void join(List * patients) {
	string cCard = "";
	string name = "";
	string address = "";
	string phone = "";
	string email = "";
	//int position = -1;

	// Create a new member profile
	cout << "Please, enter your carecard number: ";
	getline(cin >> ws, cCard);
	Patient newpatient(cCard);

	cout << "Please, enter your name: ";
	getline(cin >> ws, name);
	newpatient.setName(name);

	cout << "Please, enter your address: ";
	getline(cin >> ws, address);
	newpatient.setAddress(address);

	cout << "Please, enter your phone: ";
	getline(cin >> ws, phone);
	newpatient.setPhone(phone);

	cout << "Please, enter your email: ";
	getline(cin >> ws, email);
	newpatient.setEmail(email);



	if (patients->search(newpatient)!=NULL) cout << newpatient.getName() << " has already been entered into the system using " << newpatient.getCareCard() << " carecard number." << endl;
	else{
		patients->insert(newpatient);
		cout << "Patient: " << newpatient.getName() << " has successfully been entered into the walk in patient system." << endl;
	}
	return;
}

void leave(List * patients) {
	string cCard = "";
	cout << "Please, enter your carecard number " << endl;
	getline(cin >> ws, cCard);
	Patient target(cCard);


if (patients->getElementCount() != 0) {

	if (patients->search(target)!=NULL){
		cout << "patient found" << endl;
			if (patients->remove(*patients->search(target)) ) {//searches patient then removes them
				cout << "Patient has left the system." << endl;
			}

	}
	else
		cout << "Patient was either not found" << endl;
	}
else cout << "There are no patients in the system yet." << endl;

	return;
}

void modify(List * patients){
	char choice = ' ';
	string cCard = "";
	string name = "";
	string address = "";
	string phone = "";
	string email = "";

	cout << "Walk in patient clinic information editing system" << endl;
	cout << "Please, enter your carecard number " << endl;
	getline(cin >> ws, cCard);
	Patient target(cCard);
	
	if (patients->search(target)!=NULL){
	cout << "What function would you like to edit? (Enter the function number)" << endl;
	cout << "1. Name" << endl;
	cout << "2. Address" << endl;
	cout << "3. Phone" << endl;
	cout << "4. Email" << endl;
	cout << "5. Leave editing system" << endl;
	cin >> choice;
	
	
      switch(choice) {

      case '1': cout << "Enter name: "<<  endl; 
	getline(cin >> ws, name);
	(*patients->search(target)).setName(name);
	break;

      case '2': 	
	cout << "Please, enter your address: ";
	getline(cin >> ws, address);
	(*patients->search(target)).setAddress(address);
	break;

      case '3': 	
	cout << "Please, enter your phone: ";
	getline(cin >> ws, phone);
	(*patients->search(target)).setPhone(phone);
	break;

      case '4': 
	cout << "Please, enter your email: ";
	getline(cin >> ws, email);
	(*patients->search(target)).setEmail(email);
	break;

      case '5':
	cout << "leaving editing system" << endl;
	break;

      default: cout << "Not sure what you mean! Please, try again!" << endl;
   	 }
	cout << "Changes have been made... *PRINTING INFORMATION*" << endl;
	(*patients->search(target)).printPatient();
	
	}
	
	else cout << "Carecard number " << cCard << " has not been entered yet." << endl;
	return;


}


int main() {

	List* patients = new List();
	bool finished = false;
	char choice;


	while (!finished) {
		cout << "Welcome to the walk in patient system!" << endl;
		cout << "What function would you like to do? (Enter the function number)" << endl;
		cout << "1. Enter a new patient." << endl;
		cout << "2. Remove a patient from the system." << endl;
		cout << "3. Search for a patient." << endl;
		cout << "4. modify a patient's record." << endl;
		cout << "5. print all patients by ascending order of care card numbers." << endl;
		cout << "6. Leave system." << endl;

		cin >> choice;
		/*
		while (choice != '1' && choice != '2'&& choice != '3'&& choice != '4'&& choice != '5' && choice != '6') {
			cout << "Invalid option, please enter another number option." << endl;
			cin >> choice;
		} */
		switch (choice) {
		case '1': {
			join(patients);
			cout << "New list of patients: " << endl;
			patients->printList();
			break;
			}
		case '2': {
			leave(patients);
			cout << "New list of patients: " << endl;
			patients->printList();
			break;
		}
		case '3': {
			string cCard = "";
			cout << "Please, enter your carecard number " << endl;
			getline(cin >> ws, cCard);
			Patient target(cCard);

			 if (patients->search(target)!=NULL){
		 		cout << "Patient is in the system... *PRINTING INFORMATION*" << endl;
				(*patients->search(target)).printPatient(); }
			 else cout << "Patient has not been found. Carecard has not been entered yet." << endl;
		 	 break; }
		case '4' : {
		 	modify(patients);
		 	break;}
		case '5' : {
				cout << "Printing list of all patients..." << endl;
				patients->printList();
				break; }
		case '6' : {
			cout << "Thank you for using the walk in patient clinic!" << endl;
			finished = true;
			break;}

		default: cout << "Not sure what you mean! Please, try again!" << endl;

	}
	}
	return 0;
}
