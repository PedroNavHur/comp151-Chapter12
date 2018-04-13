
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
struct  budget {

	// Stuff
	char name[NAMESIZE + 1];
	float income;       // person's monthly income
	float rent;         // person's monthly rent
	float food;         // person's monthly food bill
	float utilities;    // person's monthly utility bill
	float miscell;      // person's other bills
	float net;          // person's net money after bills are paid

	//Populates a budget
	void getBudget(void) {
		cout << "Enter the following information" << endl;
		cout << "Person's name: ";
		cin.getline(name, NAMESIZE);
		cout << "Income: ";
		cin >> income;
		cout << "Rent: ";
		cin >> rent;
		cout << "Food: ";
		cin >> food;
		cout << "Utilities: ";
		cin >> utilities;
		cout << "Miscellaneous: ";
		cin >> miscell;

		float expenses = rent + food + utilities + miscell;
		net = income - expenses;
	}

	//Sends the budget to the stream sent
	void sendBudget(ostream &outdata) {
		outdata
			<< setw(20) << name
			<< setw(10) << income
			<< setw(10) << rent
			<< setw(10) << food
			<< setw(10) << utilities
			<< "          "
			<< setw(10) << miscell
			<< setw(10) << net
			<< endl;
	}

};

void getUserData(vector<budget> &);
void outData(vector<budget> &, ostream &);
void saveData(vector<budget> &, fstream &);
void loadData(vector<budget> &, fstream &);


int main() {
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

	// vector of person budgets
	vector<budget> persons;

	// Gets the Data from the user
	getUserData(persons);

	// Writes records to the file
	saveData(persons, indata);
	indata.close();

	// Opening data file
	indata.open("income.dat", ios::in | ios::binary);

	// Reads records to the file
	loadData(persons, indata);

	// Sends the data to outdata
	outData(persons, outdata);
	outdata.close();

	indata.close();

	return 0;
}

void getUserData(vector<budget> &persons) {
	int x = 0;
	persons.push_back(budget());
	persons[x].getBudget();

	char getMore;
	cout << "Enter a Y if you would like to input more data" << endl;
	cin >> getMore;

	while (getMore == 'Y') {

		cin.ignore();
		x++;
		persons.push_back(budget());
		persons[x].getBudget();

		cout << "Enter a Y if you would like to input more data" << endl;
		cin >> getMore;
	}
}

void outData(vector<budget> &persons, ostream &outdata) {

	outdata
		<< setw(20) << "Name"
		<< setw(10) << "Income"
		<< setw(10) << "Rent"
		<< setw(10) << "Food"
		<< setw(15) << "Utilities"
		<< setw(15) << "Miscellaneous"
		<< setw(10) << "Net Money"
		<< endl << endl;

	int n = persons.size();
	for (size_t i = 0; i < n; i++) {
		persons[i].sendBudget(outdata);
	}
}

void saveData(vector<budget> &persons, fstream &indata) {
	int n = persons.size();
	for (int i = 0; i < n; i++) {
		indata.write((const char *)&persons[i], sizeof persons[i]);
	}
}

void loadData(vector<budget> &persons, fstream &indata) {
	int i = 0;
	int n = persons.size();
	while ((i < n) && indata.read((char *)&persons[i], sizeof persons[i])){
		i++;
	}
}