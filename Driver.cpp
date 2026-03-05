//***************************************
// DRIVER
// Authors: Adi, AJ, Betsy, Catherine 
//***************************************


#include "DYNARR.h"
#include <iostream>
#include <cctype>
void displayMenu();
int validInt();
using namespace std;

string const SEP = "===========================================";

int main() {
	int userVal;
	int row, col;
	int userRow, userCol;

	cout << "Your Matrix Values:" << endl;

	cout << "Enter row size: ";
	cin >> row;

	cout << "Enter column size: ";
	cin >> col;
	
	cout << endl << endl;

	while (row <= 0 || col <= 0) {
		cout << "Invalid size. Enter positive values." << endl;
		cout << "Enter row size: ";
		cin >> row;

		cout << "Enter column size: ";
		cin >> col;
	}

	dynArr d(row, col);
	char userChoice, loopChoice;
	
	do {
		displayMenu();
		cout << "Enter your choice: ";
		cin >> userChoice;

		switch (toupper(userChoice)) {

			case '+': // INSERT
				cout << "Enter value: ";
				cin >> userVal;

				cout << "Enter row: ";
				cin >> userRow ;

				cout << "Enter column: ";
				cin >> userCol;

				d.insert(userVal, userRow, userCol);
				break;

			case '-': // REMOVE
				cout << "Enter row: ";
				cin >> userRow;

				cout << "Enter column: ";
				cin >> userCol;

				d.remove(userRow,userCol);
				break;

			case '?': // SEARCH
				cout << "Enter value to search: ";
				cin >> userVal;
				d.search(userVal);
				break;

			case 'R': // PRINT ROW MAJOR
				d.printRowMajor();
				break;

			case 'C': // PRINT COLUMN MAJOR
				d.printColMajor();
				break;

			case 'Q':// EXIT PROGRAM
				cout << endl << "Exiting program" << endl;
				return 0;

			default:
				cout << "Invalid selection" << endl;
			}

		//cin >> loopChoice; 
		cout << endl;

	} while (userChoice != 'Q');
	
	cout << "Exiting program" << endl;
	return 0;
}

//***************************************
// Author: Catherine
// Name: displayMenu()
// Description: Display users selection menu
// Incoming: None
// Outgoing: Display menu for user
// Return: None
//***************************************

void displayMenu() {
	cout << "========== Menu ==========" << endl;
	cout << "Enter '+' to insert value into table" << endl;
	cout << "Enter '-' to remove value from location" << endl;
	cout << "Enter '?' to search for value" << endl;
	cout << "Enter 'R' to display row major" << endl;
	cout << "Enter 'C' to display column major" << endl;
	cout << "Enter 'Q' to quit" << endl; cout << SEP << endl;
}

//***************************************
// Author: Catherine
// Name: validInt()
// Description: This function validates the users inputs
// Incoming: None
// Outgoing: None
// Return: val
//***************************************
//int validInt() {
//	int val;
//
//	while (!(cin >> val)) {
//		cin.clear();
//		cin.ignore(9999, '\n');
//		cout << "Invalid input. Enter an integer: ";
//	}
//	cin.ignore(9999, '\n');
//	return val;
//}
