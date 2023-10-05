#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Patient {
	string fName;
  string lName;
  string clinic;
	int ssn;
	char type;
};

struct Node {
	Patient data;
	Node* nextPtr;
};

class LinkedList{
private:
	Node* header;
	int listCounter;
public:
	LinkedList();
	~LinkedList();
	void addPatient(Patient p);
	void CriticalPatient(Patient p);
	void operPatient(string);
  bool cancelPatient (Patient p);
	void printList(string);
};