//***************************************
// HEADER
// Author: Catherine 
//***************************************

#ifndef _DYNARR_H_
#define _DYNARR_H_
#include <iostream>
using namespace std;

class dynArr {
	int** value; // array of row pointers
	int row;
	int col;
	int cursorRow; // current row position
	int cursorCol; // current column position
public:
	~dynArr(); // destructor
	dynArr(); // default constructor 
	dynArr(const dynArr& other); // copy constructor
	dynArr& operator=(const dynArr& other); // assignment operator
	dynArr(int r, int c); // parameterized constructor
	bool insert(int userVal, int r, int c); // insert
	bool remove(int r, int c); // remove 
	bool search(int const userVal); // search
	void printColMajor(); // print column major
	void printRowMajor(); // print row major

};
#endif
