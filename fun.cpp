#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "linkedList.h"
#include "fun.h"

using namespace std;

int printMenu1(){
  bool valid = false;
  int selection;
  cout <<"\n\nWELCOME TO RESERACH HOSPITAL" << endl;
  cout << "1: Heart Clinic" << endl;
  cout << "2: Lung Clinic" << endl;
  cout << "3: Plastic Surgery" << endl;
  cout << "4: Quit" << endl;
  while (valid == false) {
  cout << "Please enter the clinic: " << endl;
  cin >> selection;
    //isdigit was forcing it into an infinite loop
    //WILL FIX LATER - AL
    if((selection < 5) && (selection > 0))
      valid = true;
      return selection;
    }
  return selection;
}

int printMenu2(int s, string &clinic){
  switch (s){
    case 1:
      clinic = "Heart Clinic";
      break;
    case 2:
      clinic = "Lung Clinic";
      break;
    case 3:
    clinic = "Plastic Surgery";
    break;
    default:
      //error handling
    break;
    }
  
  int choice;   
  cout << "\n\nWelcome to the " << clinic << endl;
  cout << "1: - Add Patient" << endl;
  cout << "2: - Add Critical Patient" << endl;
  cout << "3: - Operate Patient and remove from queue" << endl;
  cout << "4: - Cancel Patient" << endl;
  cout << "5: - List Patients in Queue" << endl;
  cout << "6: - Change Department or Exit" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  
  while(choice <0 || choice >6){
    cout << "Sorry, not a valid input. Please select again:";
    cin >> choice;
      }
  
  return choice;
  }

//READ FILE FUNCTION, -JULIO
void readFile(string fileName, vector<Patient>& patients){
    string currentLine;
    ifstream inFile;
    string currentWord;
    inFile.open(fileName);

    if (!inFile.good()) {
        cout << "Could not open In File" << endl;
    } // CHECKS IF FILE IS OPEN
    while (getline(inFile, currentLine)) { // READS LINE
        if (currentLine[0] == 'Q') // END OF FILE DO NOTHING
            break;
        
        stringstream line(currentLine);
        Patient newPatient;
        newPatient.type = 'P';
        for(int i = 0; getline(line, currentWord,',');i++){
            // cout << "Hello world" << endl;
            switch(i){
                case(0):
                    newPatient.clinic = currentWord;
                    // cout << "Hello" << endl;
                    // cout << currentWord << endl;
                    break;
                case(1):
                    newPatient.fName = currentWord;
                    break;
                case(2):
                    newPatient.lName = currentWord;
                    break;
                default:
                    int ssn = stoi(currentWord);
                    newPatient.ssn = ssn;
                    break;
            }
        }
        patients.push_back(newPatient);
        cout << patients.back().clinic << " " 
        << patients.back().fName << " "
        << patients.back().lName << " "
        << patients.back().ssn << endl;
    }
}
