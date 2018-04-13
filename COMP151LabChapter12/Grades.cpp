
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;


// This program reads records from a file.  The file contains the
// following: student's name, two test grades and final exam grade. 
// It then prints this information to the screen.

// Pedro J. Navarrete
// V1.00

const int NAMESIZE = 15;
const int MAXRECORDS = 50;
struct Grades                             // declares a structure
{
	char name[NAMESIZE + 1];
	int test1;
	int test2;
	int final;
	char letter;

};

typedef Grades gradeType[MAXRECORDS];
// This makes gradeType a data type
// that holds MAXRECORDS
// Grades structures.


void readIt(ifstream &, gradeType&, int &);
// FIll IN THE CODE FOR THE PROTOTYPE OF THE FUNCTION ReadIt
// WHERE THE FIRST ARGUMENT IS AN INPUT FILE, THE SECOND IS THE
// ARRAY OF RECORDS, AND THE THIRD WILL HOLD THE NUMBER OF RECORDS
// CURRENTLY IN THE ARRAY.

char getLetter(int, int, int);

int main()

{
	ifstream indata;
	indata.open("graderoll.txt");
	int numRecord;                // number of records read in
	gradeType studentRecord;

	if (!indata)
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

	// FILL IN THE CODE TO CALL THE FUNCTION ReadIt.
	readIt(indata, studentRecord, numRecord);

	// output the information 
	for (int count = 0; count < numRecord; count++)
	{
		cout << studentRecord[count].name
			<< setw(10) << studentRecord[count].test1
			<< setw(10) << studentRecord[count].test2
			<< setw(10) << studentRecord[count].final
			<< setw(10) << studentRecord[count].letter << endl;
	}

	return 0;
}

//**************************************************************
//					readIt
//
//  task:	  This procedure reads records into an array of 
//            records from an input file and keeps track of the 
//		      total number of records
//  data in:  data file containing information to be placed in
//            the array
//  data out: an array of records and the number of records
//
//**************************************************************

void readIt(ifstream & inData, gradeType &gradeRec, int &total)
// FILL IN THE CODE FOR THE FORMAL PARAMETERS AND THEIR
// DATA  TYPES. 
//  inData, gradeRec and total are the formal parameters
//  total is passed by reference)
{
	total = 0;

	inData.get(gradeRec[total].name, NAMESIZE);
	while (inData) {
		// FILL IN THE CODE TO READ test1
		inData >> gradeRec[total].test1;
		// FILL IN THE CODE TO READ test2
		inData >> gradeRec[total].test2;
		// FILL IN THE CODE TO READ final
		inData >> gradeRec[total].final;

		// Get's the letter grade
		gradeRec[total].letter = getLetter(
			gradeRec[total].test1,
			gradeRec[total].test2,
			gradeRec[total].final);


		total++;     // add one to total


		inData.ignore();// FILL IN THE CODE TO CONSUME THE END OF LINE
		inData.get(gradeRec[total].name, NAMESIZE);// FILL IN THE CODE TO READ name


	}

}

char getLetter(int a, int b, int f) {
	char letter = 'F';
	double average = 0;
	average += a * 3;
	average += b * 3;
	average += f * 4;
	average /= 10;

	if(average >= 90){
		letter = 'A';
	} else if (average >= 80){
		letter = 'B';
	} else if (average >= 70){
		letter = 'C';
	} else if (average >= 60){
		letter = 'D';
	}

	return letter;

}