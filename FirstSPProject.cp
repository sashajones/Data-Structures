//============================================================================
// Name        : FirstSPProject.cpp
// Author      : Sasha Jones
// Date		   : February 15h, 2018
// Date Due    : Friday February 19th, 2018
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <time.h>
#include <cmath>
using namespace std;

// Function Declarations
bool Is_Prime (int x);
int Sum_Num (int x, int y);
int Collatz (int x);
int leapYears();
void RecursiveX(int x, int row);
int CollatzMod(int num1, int num2);


string gap = "****************************************";

int main() {
	cout << "Problem 1" << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//*******************
	cout << gap << endl;
	cout << "Problem 2" << endl;

	cout << Is_Prime(29) << endl; // Should result with 1 (yes)
	cout << Is_Prime(20) << endl; // Should result with 0 ( no)
	cout << Is_Prime(4) << endl; // Should result with 0 (no)

	cout << gap << endl;
	cout << "Problem 3" << endl;
	cout << Sum_Num(2,5) << endl; // Should get 7
	cout << Sum_Num(2,12) << endl; // Should get 63
	cout << Sum_Num(3,9) << endl; // Should get 30

	cout << gap << endl;
	cout << "Problem 4" << endl;
	cout << Collatz(20) << endl; // should get 7

	cout << gap << endl;
	cout << "Problem 5" << endl;
	cout << leapYears() << endl;

	cout << gap << endl;
	cout << "Problem 6" << endl;
	RecursiveX (3,0);
	RecursiveX (5,0);
	RecursiveX (9,0);

	cout << gap << endl;
	cout << "Problem 7" << endl;
	cout << CollatzMod(2, 7) << endl;
	cout << CollatzMod(3, 9) << endl;
	cout << CollatzMod(4, 12) << endl;


	return 0;
}


// Problem 2

bool Is_Prime (int x) {
	int count = 2;
	while ( count < x) {
		if (x % count == 0) {
			return false;}
		count++;
	}
	return true;
}


// Problem 3

int Sum_Num(int num1, int num2) {
	int start = num1 + 1;
	int total = 0;
	while(start < num2 ) {
		total = total + start;
		start++;
	}
	return total;
}

// Problem 4

int Collatz(int num) {
	int count = 0;
	while(num != 1) {
		if (num % 2 == 0) { // if number is even divide by 2
			num = num / 2;
			count++;
		} // end if

		if (num % 2 == 1 && num != 1) { // if number is odd, multiply by 3 and add 1
			num = (num * 3) + 1;
			count++;
		} // end if loop
	} // end while loop
	return count;
}


// Problem 5

int leapYears() {
	string list = "";
	for(int i=2017; i < 2417; i++) {
		if (i % 4 == 0) {
			cout << i << endl;
		}
	}
	return 0;
}

// Problem 6

/*
void HelperX(int x, int row) {
	string star = "*";
	string space = " ";

}

*/

void HelperX(int x, int row) { // Helper function that just prints out one line
	string star = "*";
	string space = " ";
	int breakoff;
	int branch;
	if (row <= x) {
		breakoff = row - 1;
		if (row != x) {
			branch = (2 * x) - (2 * row) - 1;
		}
	}
	else {
		breakoff = (2 * x) - (row--);
		branch = (2 * row) - (2 * x) - 1; }
	if (row == x) {
		for (int first = 0; first < breakoff; ++first) {
			cout << space;
		}
		cout << star << endl;
	}
	else {
		for (int second = 0; second < breakoff; ++second) {
			cout << space;
		}
		cout << star;
		for (int third = 0; third < branch; ++third) {
			cout << space;
		}
		cout << star << endl;
	}
}

// Main Problem 6 Function
void RecursiveX(int x, int row){ // row variable, always starts out at 0
	if (row == (2 * x)- 1) {
		// prints last 2 lines
		HelperX(x, row);
		HelperX(x, row + 1);
	}
	else {
		HelperX(x, row);
		RecursiveX(x, row + 1);
	}
}


// Problem 7

int CollatzMod(int num1, int num2) {
	int count = 0;
	int loops = num1;
	while( loops != num2) {
		cout << loops << endl;

	while(num1 != 1) {
		if (num1 % 2 == 0) { // if number is even divide by 2
			num1 = num1 / 2;
			count++;
		} // end if

		if (num1 % 2 == 1 && num1 != 1) { // if number is odd, multiply by 3 and add 1
			num1 = (num1 * 3) + 1;
			count++;
		} // end if loop
		}
		if (num1 == 1) {
					cout << "Collatz Conjecture is still working." << endl;

	} // end while loop
	loops++;
}
	return count;
}

