#include <iostream>
#include <vector>
#include "fun.h"
#include "linkedList.h"

using namespace std;

int main() {

int clinic, action;
string department;
LinkedList list;
Patient temp;

bool access = true;
bool clinical = true;

vector<Patient> patients; // JULIO
/*
readFile("patient.csv", patients);
*/
  
while (access){
  clinic = printMenu1(); //Select specific clinic
  if (clinic == 4){
    cout << "Thank you for visiting Research Hospital." << endl;
    access = false;
    break;
  }
  
  action = printMenu2(clinic, department); //Clinic selection automatically prompts specific clinic's choices

  while (action == 6){   //User opts to change department or quit
    clinic = printMenu1();
    if (clinic == 4){
      cout << "Thank you for visiting Research Hospital." << endl;
      access = false;
      break;
    }
    else
      action = printMenu2(clinic, department);  //Change department
    }

  switch (action) {
    case 1:
      //Add patient
      cout << "Enter patient's first name:" << endl;
      cin >> temp.fName;
      cout << "Enter patient's last name:" << endl;
      cin >> temp.lName;
      cout << "Enter patient's social security number:" << endl;
      cin >> temp.ssn;
      temp.type = 'R';
      temp.clinic = department;
      list.addPatient(temp);
      break;
    case 2:
      //Add Crit Patient
      cout << "Enter patient's first name:" << endl;
      cin >> temp.fName;
      cout << "Enter patient's last name:" << endl;
      cin >> temp.lName;
      cout << "Enter patient's social security number:" << endl;
      cin >> temp.ssn;
      temp.type = 'C';
      temp.clinic = department;
      list.CriticalPatient(temp);
      break;
    case 3:
      //Operate
      list.operPatient(department);
      break;
    case 4:
      //Cancel Patient
      cout << "Enter patient's social security number:" << endl;
      cin >> temp.ssn;
      list.cancelPatient(temp);
      break;
    case 5:
      //ListPatients
      cout << endl << "Listing Patients in " << department << endl;
      list.printList(department);
      break;

  }
  
}


}