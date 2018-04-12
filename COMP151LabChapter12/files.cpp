


// This program uses hours, pay rate, state tax and fed tax to determine gross
// and net pay.

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Pedro J. Navarrete
// V1.00

int main()
{
	// Fill in the code to define payfile as an input file
	ifstream payfile;
	ofstream outPayfile("pay.out", ios::out);
	float gross;
	float net;
	float hours;
	float payRate;
    float stateTax;
	float fedTax;

	outPayfile << fixed << setprecision(2) << showpoint;
	// FILL IN THE CODE TO OPEN payfile AND ATTACH IT TO THE PHYSICAL FILE
    // NAMED payroll.dat
	payfile.open("payroll.txt");

	// FILL IN CODE TO WRITE A CONDITIONAL STATEMENT TO CHECK IF payfile 
	// DOES NOT EXIST.
	if(!payfile)
	{
		outPayfile << "Error opening file. \n";
		outPayfile << "It may not exist where indicated" << endl;
		return 1;
	}

	outPayfile << "Payrate      Hours    Gross Pay       Net Pay" << endl   << endl;      
    
	while(payfile >> hours){
	   payfile >> payRate >> stateTax >> fedTax;
	   gross = payRate * hours;
	   net = gross - (gross * stateTax) - (gross * fedTax);
	   outPayfile << payRate << setw(15) << hours << setw(12) << gross
              << setw(12)  << net << endl;

	}
      payfile.close();
      return 0;
}