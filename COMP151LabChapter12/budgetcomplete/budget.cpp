
// This program reads in from the keyboard a record of financial information
// consisting of a person's name, income, rent, food cost, utilities and 
// miscellaneous expenses.  It then determines the net money
// (income minus all expenses)and places that information in a record
// which is then written to an output file.

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Pedro J. Navarrete
// V1.00

const int NAMESIZE = 15;
struct  budget  //declare a structure to hold name and financial information
{
	char name[NAMESIZE + 1];
	float income;       // person's monthly income
	float rent;         // person's monthly rent
	float food;         // person's monthly food bill
	float utilities;    // person's monthly utility bill
	float miscell;      // person's other bills
	float net;          // person's net money after bills are paid

};

//void getBudget(vector<budget> &);

int main()

{
	fstream indata;
	ofstream outdata;                                   // output file of
														// student.
	indata.open("income.dat", ios::out | ios::binary);  // open file as binary
														// output.
	outdata.open("student.out");                        // output file that 
														// we will write student
														// information to. 
	outdata << left << fixed << setprecision(2);        // left indicates left
														// justified for fields

	budget person;   //defines person to be a record
	//vector<budget> persons;

	cout << "Enter the following information" << endl;
	cout << "Person's name: ";
	cin.getline(person.name, NAMESIZE);
	cout << "Income :";
	cin >> person.income;


	// FILL IN CODE TO READ IN THE REST OF THE FIELDS:
	// rent, food, utilities AND miscell TO THE person RECORD
	cout << "Rent: ";
	cin >> person.rent;
	cout << "Food: ";
	cin >> person.food;
	cout << "Utilities: ";
	cin >> person.utilities;
	cout << "Miscellaneous: ";
	cin >> person.miscell;

	// find the net field
	// FILL IN CODE TO DETERMINE NET INCOME (income - expenses)
	float expenses = person.rent + person.food + person.utilities + person.miscell;
	person.net = person.income - expenses;

	// write this record to the file
	// Fill IN CODE TO WRITE THE RECORD TO THE FILE indata (one instruction)
	indata.write((const char *)&person, sizeof person);

	indata.close();

	// FILL IN THE CODE TO REOPEN THE indata FILE, NOW AS AN INPUT FILE.
	indata.open("income.dat", ios::in | ios::binary);

	// FILL IN THE CODE TO READ THE RECORD FROM indata AND PLACE IT IN THE 
	// person RECORD (one instruction)
	indata.read((char *)&person, sizeof person);

	// write information to output file
	outdata << setw(20) << "Name" << setw(10) << "Income" << setw(10) << "Rent"
		<< setw(10) << "Food" << setw(15) << "Utilities" << setw(15)
		<< "Miscellaneous" << setw(10) << "Net Money" << endl << endl;

	// FILL IN CODE TO WRITE INDIVIDUAL FIELD INFORMATION OF THE RECORD TO 
	// THE outdata FILE.(several instructions)
	outdata
		<< setw(20) << person.name
		<< setw(10) << person.income
		<< setw(10) << person.rent
		<< setw(10) << person.food
		<< setw(10) << person.utilities
		<< "          "
		<< setw(10) << person.miscell
		<< setw(10) << person.net
		<< endl;

	outdata.close();
	indata.close();

	return 0;
}

//void getBudget(vector<budget> &persons) {
//	int n = persons.size();
//	persons.push_back(budget());
//
//	cout << "Enter the following information" << endl;
//	cout << "Person's name: ";
//	cin.getline(persons[n].name, NAMESIZE);
//	cout << "Income: ";
//	cin >> persons[n].income;
//	cout << "Rent: ";
//	cin >> persons[n].rent;
//	cout << "Food: ";
//	cin >> persons[n].food;
//	cout << "Utilities: ";
//	cin >> persons[n].utilities;
//	cout << "Miscellaneous: ";
//	cin >> persons[n].miscell;
//}