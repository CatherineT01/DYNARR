//***************************************
// SOURCE FILE (DYNARR.cpp)
// Authors: Adi,AJ, Betsy, Catherine 
//***************************************

#include "DYNARR.h"
//***************************************
// Author: Catherine
// Name: ~dynArr()
// Description: delete/free up all dynamically allocated memory
// Incoming: None
// Outgoing: None
// Return: None
//***************************************
dynArr :: ~dynArr(){ //Destructor
	if (value != nullptr) {
		for (int i = 0; i < row; i++) {
			delete[] value[i]; // delete each row and columns
		}
		delete[] value; 
	}
	value = nullptr; // set value equal to null pointer. no hanging pointers
} 

//***************************************
// Author: Catherine 
// Name: dynArr()
// Description: Initialize empty array with no rows or columns
// Incoming: None
// Outgoing:None
// Return: None
//***************************************
dynArr::dynArr(): row(0), col(0),value(nullptr), cursorRow(-1), cursorCol(-1) {} //Default constructor

//***************************************
// Author: AJ 
// Name: dynArr(const dynArr& other)
// Description: Creates deep copy of another dynArr object
// Incoming: const dynArr& other
// Outgoing:None
// Return: None
//***************************************
dynArr::dynArr(const dynArr& other): row(other.row), col(other.col), cursorRow(other.cursorRow), cursorCol(other.cursorCol) { //Copy constructor
	if (row == 0 || col == 0) {
		value = nullptr;
		return;
	}
	value = new int* [row];
	for (int i = 0; i < row; i++) {
		value[i] = new int[col];
		for (int j = 0; j < col; j++) {
			value[i][j] = other.value[i][j];
		}
	}
}

//***************************************
// Author: AJ
// Name: operator=(const dynArr& other)
// Description: Assigns one dynArr to another using deep copy
// Incoming: const dynArr& other
// Outgoing: *this 
// Return: dynArr&
//***************************************
dynArr& dynArr::operator=(const dynArr& other) //Copy assignment operator
{
	if (this == &other) // Check for self-assignment //
		return *this;

	if (value != nullptr){ // Check if the pointer is not null before deleting //
		for (int i = 0; i < row; i++){ // Loop through each row and delete the memory allocated for each row //
			delete[] value[i];
		}
		delete[] value;
		value = nullptr;
	}

	// Copy the data members from the other object //
	row = other.row;
	col = other.col;
	cursorRow = other.cursorRow;
	cursorCol = other.cursorCol;

	if (row == 0 || col == 0) {
		value = nullptr;
		return *this;
	}

	value = new int* [row];
	for (int i = 0; i < row; i++){ // Loop through each row and allocate memory for each row //
		value[i] = new int[col];
			for (int j = 0; j < col; j++){ // Loop through each column in the current row and copy the element from the other array //
			value[i][j] = other.value[i][j];
		}
	}
	// Set the pointer to the newly created array //
	return *this;
}

//***************************************
// Author: Catherine 
// Name: dynArr(int r, int c)
// Description: This function creates a 2D array with r rows and c columns
// Incoming: int r (rows), int c(columns)
// Outgoing: None
//***************************************
dynArr::dynArr(int r, int c): row(r), col(c), cursorRow(-1), cursorCol(-1){ // parameterized constructor
	value = new int* [row];
	for (int i = 0; i < row; i++) {
		value[i] = new int[col];
			for (int j = 0; j < col; j++) {
				value[i][j] = 0;
		}
	}
} 

//***************************************
// Author: Catherine 
// Name: insert(int userVal, int r, int c)
// Description: This functions inserts the users value given the row, column, and value.
// Incoming: int userVal, int r, int c
// Outgoing: None
// Return: bool- true if item is inserted, false if not inserted
//***************************************
bool dynArr::insert(int userVal, int r, int c) { // Insert
	if (r < 0 || r >= row || c < 0 || c >= col) { // check if input is valid
		cout << "Not Done" << endl; // item is not inserted
		return false;
	}

	value[r][c] = userVal; // set matrix
	cout << "Done" << endl << endl; ///item inserted
	return true;
}

//***************************************
// Author: Adi
// Name: remove(int r, int c)
// Description: This function removes the value given by row and column from user.
// Incoming: int r, int c
// Outgoing: None
// Return: bool- true if item is removed, false if not removed
//***************************************
bool dynArr::remove(int r, int c) { // Remove
	if (r < 0 || r >= row || c < 0 || c >= col) { 
		cout << "Invalid location" << endl; 
		return false;
	}
	int removed = value[r][c];
	value[r][c] = 0;
	cout << "Removed value: " << removed << endl; // item removed at [location]
	return true;
}

//***************************************
// Author: Adi
// Name: search(int const userVal)
// Description: This functions searches the users value. If value is found, return where the value 
//		was found. If not, print "value was not found. 
// Incoming: int userVal- value to search for
// Outgoing: None
// Return: bool- true if value is found, false if not found
//***************************************
bool dynArr::search(int const userVal) {
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			if (value[i][j] == userVal) {
				cout << "Value found at [" << i << "," << j << "]" << endl;
				return true;
			}
		}
	}
	cout << "Value not found" << endl;
	return false;
}

//***************************************
// Author: Catherine 
// Name: PrintColMajor()
// Description: Print matrix in column major.
// Incoming: None
// Outgoing: Printed user matrix
// Return: None
//***************************************
void dynArr::printColMajor() {
	cout << "Printing column major" << endl;
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			cout << value[i][j] << " ";
		}
		cout << endl;
	}
}

//***************************************
// Author: Catherine 
// Name: PrintRowMajor()
// Description: Print matrix in row major.
// Incoming: None
// Outgoing: Printed user matrix
// Return: None
//***************************************
void dynArr:: printRowMajor(){
	cout << "Printing row major" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << value[i][j] << " ";
		}
		cout << endl;
	}
}
	
