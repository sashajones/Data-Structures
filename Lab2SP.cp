/*
 * Lab2SP.cpp
 *
 *  Created on: Feb 22, 2018
 *  Due Date: Sunday, February 25th, 2018
 *      Author: sashajones
 */


#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <time.h>

using namespace std;

// Function Declarations

// Problem 1
void prob1();
// Problem 2
void prob2(int x);
// Problem 3
int prob3();
// Problem 4
void prob4(int *x);
// Problem 5
void prob5(int &x);
// Problem 6
void prob6(int *x1, int *x2);
// Problem 7
void prob7(char p1, char &p2, char *p3);
// Problem 8
void prob8(int x, int *x2);
// Problem 9
void prob9(int len, int &x2, int &x3);
// Problem 10
void prob10(int x);
// Problem 11
void prob11(int len, int cap);




string gap = "****************************************";


int main() {

	/* initialize random seed: */
	srand(time(NULL));


	cout << "Problem 1" << endl;
	prob1();

	cout << gap << endl;
	cout << "Problem 2" << endl;
	int x0 = 21;
	cout << "The value of x0 is: " << x0 << endl;
	cout << "The address of x0 is: " << &x0 << endl;
	prob2(x0); // this is the default call by value

	cout << gap << endl;
	cout << "Problem 3" << endl;
	int x1 = prob3();
	cout << "The value of x1 is: " << x1 << endl;
	cout << "The address of x1 is: " << &x1 << endl;

	cout << gap << endl;
	cout << "Problem 4" << endl;
	int x2 = 3;
	cout << "The value of x2 is: " << x2 << endl;
	cout << "The address of x2 is: " << &x2 << endl;
	prob4(&x2); // passes in the address of variable x2 // This is call by pointer
	cout << "The value of x2 is: " << x2 << endl; // should be 27
	cout << "The address of x2 is: " << &x2 << endl;

	cout << gap << endl;
	cout << "Problem 5" << endl;
	int x3 = 4;
	cout << "The value of x3 is: " << x3 << endl;
	cout << "The address of x3 is: " << &x3 << endl;
	prob5(x3); // Call by reference
	cout << "The value of x3 after the function call is: " << x3 << endl;
	cout << "The address of x3 after the function call is: " << &x3 << endl;

	cout << gap << endl;
	cout << "Problem 6" << endl;
	int x4 = 10;
	int x5 = 20;
	//cout << "The address of variable x4 is: " << &x4 << endl;
	//cout << "The address of variable x5 is: " << &x5 << endl;
	prob6(&x4, &x5);
	cout << "The value of variable x4 after the function call is: " << x4 << endl;
	cout << "The value of variable x5 after the function call is: " << x5 << endl;

	cout << gap << endl;
	cout << "Problem 7" << endl;
	char r = 'm';
	char h = 'a';
	char u = 'b';
	char o = 'e';
	cout << u << o << h << r << endl;
	prob7(u, h, &r);
	cout << u << o << h << h << r << endl;

	cout << gap << endl;
	cout << "Problem 8" << endl;
	int x6 = -1;
	int x7 = 15;
	// Call the function with the second integer as the length, and the address f the first integer
	prob8(x7, &x6);
	cout << "The first variable is: " << x6 << endl;
	prob8(x7, &x6);
	cout << "The first variable is: " << x6 << endl;
	prob8(x7, &x6);
	cout << "The first variable is: " << x6 << endl;

	cout << gap << endl;
	cout << "Problem 9" << endl;
	int para2 = -1;
	int para3 = -1;
	prob9(14, para2, para3);
	cout << "The smallest value in the array is: " << para2 << endl;
	cout << "The index of the smallest value in the array is: " << para3 << endl;
	int para4 = -1;
	int para5 = -1;
	prob9(5, para4, para5);
	cout << "The smallest value in the array is: " << para4 << endl;
	cout << "The index of the smallest value in the array is: " << para5 << endl;
	int para6 = -1;
	int para7 = -1;
	prob9(7, para6, para7);
	cout << "The smallest value in the array is: " << para6 << endl;
	cout << "The index of the smallest value in the array is: " << para7 << endl;

	cout << gap << endl;
	cout << "Problem 10" << endl;
	prob10(5);
	prob10(7);
	prob10(11);

	cout << gap << endl;
	cout << "Problem 11" << endl;
	prob11(7,50);








	return 0;
} // END MAIN FUNCTION

// Problem 1

void prob1() {
	int var1 = 7;
	cout << "The value of var1 is " << var1 << endl;
	cout << "The address of var1 is " << &var1 << endl;
}

// Problem 2

void prob2(int x) {
	x = x + 4;
	cout << "The value of x is: " << x << endl;
	cout << "The address of x is: " << &x << endl;
}


// Problem 3

int prob3() {
	int var1 = rand()%51;
	cout << "The value of var1 is: " << var1 << endl;
	cout << "The address of var1 is: " << &var1 << endl;
	return var1; // CHANGE LATER WHAT VALUE AM I SUPPOSED TO RETURN
}

// Problem 4

void prob4(int *x) { // takes as input parameter an address of an int
	cout << "x is: " << x << endl;
	//takes the value at the address and cubes it
	*x = *x * *x * *x;
	// The value at the address
	cout << "The value at the address is: " << *x << endl; // Prints the value at the address that was passed in i.e. value of x
	// The address in the parameter
	cout << "The address in the parameter is: " << x << endl; // Prints the address in the parameter x
	// The address of the parameter
	cout << "The address of the parameter is: " << &x << endl;
}

// Problem 5

void prob5(int &x) { // takes as input parameter an alias for an integer
	int var2 = rand()&11;
	x = x + var2;
	cout << "The random number is: " << var2 << endl;
	cout << "The new value of the input variable is: " << x << endl;
	cout << "The address of the input parameter is: " << &x << endl;
}

// Problem 6

void prob6(int *x1, int *x2) {
	cout << "The address in the first parameter is: " << x1 << endl;
	int *var3 = x1; // sets var3 to the address in the first parameter
	cout << var3 << endl;
	*var3 = 32; // changes the value at the address of parameter 1 to 32 using local variable
	cout << "The address in the second parameter is: " << x2 << endl;
	var3 = x2; // changes the address in var3 to hold the address in the second parameter
	*var3 = 42; // changes the value at the address of parameter 2 to 42 using local variable
}

void prob7(char p1, char &p2, char *p3) {
	p1 = 'j';
	p2 = 'l';
	*p3 = 'y';
}

void prob8(int x, int *x2) {
	cout << "x2 is: " << x2 << endl; // prints the address in x2
	int arr1[x]; // Creates an array the length of the first integer
	for(int i = 0; i < x; i++) {
		arr1[i] = rand()%501;
	} // end for loop
	for(int i = 0; i < x; i++) {
		cout << arr1[i] << ", ";
	} // end for loop
	cout << endl;
	for(int i = 0; i < x; i++) {
		if(arr1[i] > *x2) {
			*x2 = arr1[i];
		} // end if statement
	} // end for loop

} // end prob8 function

void prob9(int len, int &x2, int &x3) {
	int arr1[len];
	for(int i = 0; i < len; i++) {
		arr1[i] = rand()% 201 + 100;
	}
	for(int i = 0; i < len; i++) {
		cout << arr1[i] << ", ";
	} // end for loop
	cout << endl;
	int min = 300;
	for(int i = 0; i < len; i++) {
		if (arr1[i] < min) {
			min = arr1[i];
			x3 = i; // index location of the smallest value
		} // end if statement
		x2 = min;
	} // end for loop

}

void prob10(int x) {
	int arr1[x];
	for(int i = 0; i < x; i++) {
		arr1[i] = rand()%51;
	}  // makes a list of len x filled with random numbers
	for(int i = 0; i < x; i++) {
		cout << arr1[i] << ", ";
	} // end for loop
	cout << endl;
	for(int i = x-1; i > -1; i--) {
		cout << arr1[i] << ", ";
	} // end for loop
	cout << endl;

}

// Problem 11
void prob11(int len, int cap) {
	int arr1[len];
	for(int i = 0; i < len; i++) {
		arr1[i] = rand()%cap;
	}
	// print list
	for(int i = 0; i < len; i++) {
		cout << arr1[i] << ", ";
	} // end for loop
	cout << endl;
	// finds smallest number in list and prints it out

	for(int i = 0; i < len; ++i) {
		int min = cap;
			if (arr1[i] < min) {
				min = arr1[i];
			}
				arr1[i] = cap + 1; // index location of the smallest value
				//cout << min << ", ";
			//} // end if statement
			cout << min << ", ";
		} // end for loop

}










