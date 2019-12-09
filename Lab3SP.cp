/*
 * Lab3SP.cpp
 *
 *  Created on: Mar 1, 2018
 *  Due Date: Sunday, March 4th, 2018
 *      Author: sashajones
 *  TA: Name: Ajith Kumar
 *  	Email address: kumar@udel.edu
 *  	Office Hours: Thursday 4:30-6:30
 */

//
//  TA: Name: Ajith Kumar
// 	Email address: kumar@udel.edu
// 	Office Hours: Thursday 4:30-6:30

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <time.h>

using namespace std;

// Function Declarations

// Problem 1
void prob1(int *arr, int size);
// Problem 1b
int *prob1b(int *num1, int *num2, int *num3);
// Problem 2
int *prob2(int num1);
//Problem 3
void prob3(int *arr, int size);
// Problem 4
void prob4(double *arr, int size);
// Problem 5
int hanning(int *arr, int win);
// Problem 6
int *filter(int *ogArr, int ogSize, int winSize);
int sum1(int num);

// Graphing function
void PrintGraph(int array[], int length, int highest, int lowest);

// Last Problem
int **twoD(int *rows, int *columns);




string gap = "\n**************************************** \n";



int main() {

	/* initialize random seed: */
	srand(time(NULL));


	int *x = new int[5]; // an array of integers
	int *xa = new int[8]; // an array of integers
	int *xb = new int[9]; // an array of integers


	double *x1 = new double[7]; // an array of doubles
	double *ya = new double[4]; // an array of doubles
	double *yb = new double[3]; // an array of doubles



	//Problem 1b
	cout << gap << endl;
	cout << "Problem 1b" << endl;
	int randlow = rand()%-10 + -5;
	//cout << randlow << endl;
	int a;
	int b;
	int c;
	int a1;
	int b1;
	int c1;
	int a2;
	int b2;
	int c2;
	prob1(prob1b(&a, &b, &c), a); // call by pointer // Prints out the array of random length
	prob1(prob1b(&a1, &b1, &c1), a1); // test 2  call by pointer // Prints out the array of random length
	prob1(prob1b(&a2, &b2, &c2), a2);// test 3   call by pointer // Prints out the array of random length

	// Problem 2
	cout << gap << endl;
	cout << "Problem 2" << endl;
	int d = rand()%25 + 25; //a random number between 25 and 50 which will be the length of the array
	prob1(prob2(d),d);
	// This doesn't work because the address of the array is on the stack which goes out of scope once the prob2 function is complete
	// Instead, prints out the first value and then seemingly random numbers

	// Test case 2
	int d1 = rand()%25 + 25; //a random number between 25 and 50 which will be the length of the array
	prob1(prob2(d1),d1);

	// Test case 3
	int d2 = rand()%25 + 25; //a random number between 25 and 50 which will be the length of the array
	prob1(prob2(d2),d2);


	// Problem 3
	cout << gap << endl;
	cout << "Problem 3" << endl;
	prob3(x, 5); // prints out the address of every value in the array of integers given an array and its length
	prob3(xa, 8); // Test case 2 :: prints out the address of every value in the array of integers
	prob3(xb, 9); // Test case 3 :: prints out the address of every value in the array of integers


	// Problem 4
	cout << gap << endl;
	cout << "Problem 4" << endl;
	prob4(x1, 7); // prints out the address of every value in the array of doubles given an array and its length
	prob4(ya, 4); // Test case 2 :: prints out the address of every value in the array of doubles
	prob4(yb, 3); // Test case 3 :: prints out the address of every value in the array of doubles

	// Problem 5
	cout << gap << endl;
	cout << "Problem 5 (Hanning window)" << endl;
	int arrh[9] = {3,8,2,5,1,4,6,0,2};
	int arrh1[7] = {1, 2, 3, 4, 5, 6, 7};
	int arrh2[11] = {11, 32, 7, 12, 19, 6, 14, 87, 76, 50, 73};
	// Given an array and a window size, this function weights and averages the values in the given window and returns the Weighted and averaged value

	cout << "The weighted average is: " << hanning(&arrh[0],5) << endl; // given array arrh and a window size of 5, the value returned should be 4
	cout << "The weighted average is: " << hanning(&arrh1[0],5) << endl; // Test Case 2 :: " " should return 3
	cout << "The weighted average is: " << hanning(&arrh2[0],5) << endl; // Test Case 2 :: " " should return 15


	// Filter hanning array problem
	cout << gap << endl;
	cout << "Problem 6 (Filter Hanning window)" << endl;
	// given an array, the array size, and the window size, this should return a new array that has been filtered
	// with the hanning window function of the original array
	// Prints the original array first and the new, filtered array second

	prob1(filter(&arrh[0], 9, 5), 9);  // Prints the original array first and the new, filtered array second
	cout <<endl;
	prob1(filter(&arrh1[0], 7, 5), 7); // Test case 2  Prints the original array first and the new, filtered array second
	cout <<endl;
	prob1(filter(&arrh2[0], 11, 5), 11); // Test case 3  Prints the original array first and the new, filtered array second

	// Printing Graph Function
	// Filter hanning array problem
	cout << gap << endl;
	cout << "Graphing function (Filter Hanning window graph)" << endl;
	int randomarray1[35] = {6, -2, -4, 5, -3, -4, -3, -1, 5, 2, -2, 0, -7, 2, -3, -4, -3, -1, -5,
			-3, 1, 7, 3, -7, -7, 3, -8, 1, -5, -4, -2, -5, -8, 0, -4,};
	// given an array, its length, the highest, and lowest values in the array, prints out a graph of the array
	// prints out a graph of the array
	PrintGraph(randomarray1, 35, 8, -8);
	cout <<endl;
	// prints out a graph of the filtered array
	PrintGraph(filter(randomarray1, 35, 5), 35, 8, -8);
	cout << endl;

	cout << "TEST CASE 2 " << endl;
	int hanningarray[35] = {0, 0, 0, 0, -1, -2, -1, 0, 1, 1, 0, -1, -2, -2, -2, -2, -3, -2, -2, -
			1, 1, 2, 0, -2, -3, -3, -3, -2, -3, -3, -4, -4, -4, 0, 0, };

	// given an array, its length, the highest, and lowest values in the array, prints out a graph of the array
	PrintGraph(hanningarray, 35, 2, -4);
	cout <<endl;
	// prints out a graph of the filtered array
	PrintGraph(filter(hanningarray, 35, 5), 35, 2, -4);
	cout << endl;


	cout << "TEST CASE 3 " << endl;
	// given an array, its length, the highest, and lowest values in the array, prints out a graph of the array
	PrintGraph(arrh, 9, 8, 0);
	cout <<endl;
	// prints out a graph of the filtered array with window size of 5
	PrintGraph(filter(arrh, 9, 5), 9, 8, 0);
	cout << endl;

	// Last Problem
	cout << gap << endl;
	cout << "Last Problem" << endl;
	// given two integer addresses (both called by pointer) returns and prints a 2-d array filled with 0's
	// The 2d array has 5 randomly generated number pairs and has a "1" in each of those random number locations
	// uses a for loop to print out the 2d array
	int lastV1;
	int lastV2;
	int **mat1 = twoD(&lastV1, &lastV2);
	for (int i = 0; i < lastV1; i++) {
		prob1(mat1[i], lastV2);
	}

	cout << "TEST CASE 2 " << endl;
	int lastV3;
	int lastV4;
	int **mat2 = twoD(&lastV3, &lastV4);
	for (int i = 0; i < lastV3; i++) {
		prob1(mat2[i], lastV4);
	}


	cout << "TEST CASE 3 " << endl;

	int lastV5;
	int lastV6;
	int **mat3 = twoD(&lastV5, &lastV6);
	for (int i = 0; i < lastV5; i++) {
		prob1(mat3[i], lastV6);
	}



	return 0;

} // END MAIN FUNCTION

// Problem 1
 // Prints out an array of integers as a single line.

void prob1(int *arr, int size) {

	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	} // prints out the array
	cout << "\n" << endl;

}

// Problem 1b

int *prob1b(int *num1, int *num2, int *num3) {
	int rannum = rand()%25 + 25; // random number between 25 and 50
	cout << "The length of the array is: " << rannum << endl;
	int *arr = NULL;
	arr = new int[rannum]; // creates an array of length (random size) on the heap
	int highval = rand()%5 + 5; // high value between 5 and 10
	int lowval = rand()%5 + -10; // low value between -5 and -10
	cout << "The low value is: " << lowval << endl;
	for( int i = 0; i < rannum; i++) {
		arr[i] = rand()% (highval - lowval) + lowval;
	} // end for loop
	*num1 = rannum;
	*num2 = highval;
	*num3 = lowval;

	return arr;

}

// Problem 2
int *prob2(int num1) { // num1 is the length of the array
	int stackArr[num1];
	int highval = rand()%5 + 5; // high value between 5 and 10
	int lowval = rand()%5 + -10; // low value between -5 and -10
	cout << " the low value is: " << lowval << endl;
	for( int i = 0; i < num1; i++) { // fills array with random numbers between low and high values
		stackArr[i] = rand()% (highval - lowval) + lowval;
	} // end for loop
	return stackArr; // returns the address of the first value of the array
}

// Problem 3
void prob3(int *arr, int size) { // takes in an array of integers
	for (int i = 0; i < size; i++) {
		cout << &arr[i] << ", ";
	} // prints the address of every value in the array
	cout << endl;
}

// Problem 4
void prob4(double *arr, int size) { // takes in an array of doubles
	for (int i = 0; i < size; i++) {
		cout << &arr[i] << ", ";
	} // prints the address of every value in the array
	cout << endl;
}

// Problem 5
int hanning(int *arr, int win) {
	int i, r, multi, sum = 0;
	int maxWeight = ceil(win/2) + 1; // This is the max weight of a given window
	//cout << "The maxWeight is: " << maxWeight << endl;
	int weightSum = (sum1(maxWeight) * 2) - maxWeight; // what you divide the sum by to get the weighted average
	//cout << "The weightSum is: " << weightSum << endl;
	// i is index, r is the reverse index, weight is the weight of value, sum is the running total
	r = win-1; // starts out at the last index of the array
	multi = 1; // The weight to multiply the value by
	for(i = 0; i<win/2; i++) {
		sum +=((arr[i]*multi)+ (arr[r]*multi)); // multiplies opposite end index values by the weight
		multi++;
		r--;
	}
	sum += (arr[i]*multi); // adds the middle number to the sum
	sum = sum/weightSum;

	return sum;
}

// Problem 5 helper function
int sum1(int num) {
	int total = 0;
	for( int i = 1; i <= num; i++) {
		total += i;
	}
	return total;
}


// Problem 6
int *filter(int *ogArr, int ogSize, int winSize) {
	int *filterArr =  new int[ogSize]; // creates a new array of the original array size on the heap
	for (int j = 0; j < ogSize; j++) { // fills the array with 0's
		filterArr[j] = 0;
	}
	for ( int i = 0; i <= ogSize - winSize; i++) {
		filterArr[i + (winSize/2)] = hanning(&ogArr[i], winSize);
	}
	cout << "The original Array is: \n";
	prob1(ogArr, ogSize);

	//cout << "The new Array is: \n";


	return filterArr;
}

// Printing graph function
void PrintGraph(int array[], int length, int highest, int lowest) {
	for (int i = highest; i >= lowest; --i) {
		cout << i << ":";
		for (int j = 0; j < length; ++j) {
			if (i == array[j]) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}


// Last Problem ( 5)
int **twoD(int *rows, int *columns) {
	// x is the size of the array of addresses
	int x = rand()%5 + 5; // a random number between 5 and 10
	// y is the size of each array of integers
	int y = rand()%4 + 4; // a random number between 4 and 8
	*rows = x;
	*columns = y;

	int **matrix1 = NULL;
	matrix1 = new int*[x];
	for(int i = 0; i < x; i++) {
		matrix1[i] = new int[y]; // creates a matrix of size [x][y]
	}
	// filling the matrix with 0's
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			matrix1[i][j] = 0;
		} // end for loop for filling one row with numbers
	} // end for loop for filling columns

	for (int count = 0; count < 5; count++) {
		int r = rand()%x; // r stands for row
		int c = rand()%y; // c stands for column
		if (matrix1[r][c] == 1) { // if the generated spot is already filled with a 1, pick another one
			r = rand()%x;
			c = rand()%y;
		}
		matrix1[r][c] = 1;
	} // end for loop

	return matrix1;

} // end twoD function


