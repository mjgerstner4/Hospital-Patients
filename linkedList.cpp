#include "linkedList.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

LinkedList::LinkedList() {
	header = nullptr;
	listCounter = 0;
}

LinkedList::~LinkedList() {

}
void LinkedList::addPatient(Patient p) {
	if (listCounter >= 10) {
		cout << "Too many entries" << endl;
		return;
	}

	Node* newNode = new Node;
	newNode->data.fName = p.fName;
	newNode->data.lName = p.lName;
	newNode->data.ssn = p.ssn;
	newNode->data.type = p.type;
  newNode->data.clinic=p.clinic;
	newNode->nextPtr = nullptr;

	// add element to begining

	if (header == nullptr) {
		//cout << "Add to empty list" << endl;
		header = newNode;
		listCounter++;
	}
	else {
		// add to end 
		//cout << "Add to end of list" << endl;
		Node* tempPtr = header;
		while (tempPtr->nextPtr != nullptr) {
			tempPtr = tempPtr->nextPtr;
		}
		tempPtr->nextPtr = newNode;
		listCounter++;
	}

  cout << newNode-> data.fName << " " << newNode-> data.lName << ", SSN: " << newNode-> data.ssn << endl;
}

void LinkedList::CriticalPatient(Patient p) {
	if (listCounter >= 10) {
		cout << "Error: Too many entries" << endl;
		return;
	}

	Node* newNode = new Node;
	newNode->data.fName = p.fName;
	newNode->data.lName = p.lName;
	newNode->data.ssn = p.ssn;
	newNode->data.type = p.type;
	newNode->nextPtr = nullptr;

	//add to empty list
	if (header == nullptr) {
		header = newNode;
		listCounter++;
	}

	else {
		//does this patient go first?
		if (header->data.type != 'C') {
			newNode->nextPtr = header;
			header = newNode;
			listCounter++;
		}
		else {
			Node* tempPtr = header;
			while (tempPtr->nextPtr != nullptr && tempPtr->data.type == 'C') {
				tempPtr = tempPtr->nextPtr;

			}
			newNode->nextPtr = tempPtr->nextPtr;
			tempPtr->nextPtr = newNode;
		}
	}
    cout << newNode-> data.fName << " " << newNode-> data.lName << ", SSN: " << newNode-> data.ssn << endl;
}

void LinkedList::operPatient(string clinic) {
  Node* tempPtr = header;
  
	if (header == nullptr) {
		cout << "Error: No patients" << endl;
		return;
	}
  while (tempPtr != nullptr) {
    if (tempPtr->data.clinic == clinic){
      cout << "Patient: " << header->data.fName << " " << header->data.lName << " taken for operation." << endl;
      header = header->nextPtr;
      delete tempPtr;
      tempPtr = nullptr;
      listCounter--;
    }
    else {
      tempPtr = tempPtr->nextPtr;
    }
  }
  }


bool LinkedList::cancelPatient (Patient p){
  //CANCEL FUCTION!!!
  if (header == nullptr) {
    cout << "List is empty." << endl;
		return false;
	}
	if (header->data.ssn == p.ssn) {
		Node* tempPtr = header;
		header = header->nextPtr;
		delete tempPtr;
		tempPtr = nullptr;
    cout << "Patient: " << header->data.fName << " " << header->data.lName << " has been deleted from the list." << endl;
		return true;
	}
	else {
		Node* tempPtr = header;
		while (tempPtr != nullptr) {
			if (tempPtr->nextPtr != nullptr && tempPtr->data.ssn == p.ssn) {
				//delete node
				Node* holdPtr = tempPtr->nextPtr;
				tempPtr->nextPtr = holdPtr->nextPtr;
				delete holdPtr;
				holdPtr = nullptr;
        cout << "Patient: " << header->data.fName << " " << header->data.lName << " has been deleted from the list." << endl;
				return true;
			}
			tempPtr = tempPtr->nextPtr;
		}
	}
cout << "Patient does not exist." << endl;
}

void LinkedList::printList(string clinic) {
	Node* tempPtr = header;
  
  if (header == nullptr) {
    cout << "List is empty." << endl;
	}
  else{
    cout << setw(15) << left << "First Name";
    cout << setw(15) << left << "Last Name";
    cout << setw(5) << left << "SSN";
    cout << setw(4) << left << "Status" << endl;
	  while (tempPtr != nullptr) {
      if (tempPtr->data.clinic == clinic){
        cout << setw(15) << left << tempPtr->data.fName;
        cout << setw(15) << left << tempPtr->data.lName;
        cout << setw(5) << left << tempPtr->data.ssn;
        cout << setw(4) << left << tempPtr->data.type << endl; 
      }
      tempPtr = tempPtr->nextPtr;
	  }
  }
}
