#include "Map.h"	// Defines template Map<Key, Value>
#include "Employee.h"	// Defines class Employee
#include "BookInfo.h"
#include <iostream>

using namespace std;

int main() {

	typedef unsigned int ID;	// Identification number of Employee
	Map<ID, Employee> database;	// Database of employees

	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee: name: Anna Zaradna, position: secretary, age: 32

	cout << "ORIGINAL DB:" << endl << database << endl;	// Print database

	Map<ID, Employee> newDatabase = database;	// Make a copy of database (copy constructor called)

	Employee* pE;
	pE = newDatabase.find(510212881);	// Find employee using its ID
	pE->position = "salesman";	// Modify the position of employee
	pE = newDatabase.find(761028073);	// Find employee using its ID
	pE->age = 29;	// Modify the age of employee

	database = newDatabase;		// Update original database (assignment operator called)

	cout << "MODIFIED DB: " << endl << database << endl;	// Print original database*/

	typedef string BookTitle;
	Map<BookTitle, BookInfo> library;

	library.add("The Adventures of Tom Sawyer", BookInfo("Mark Twain", "Children's literature", 200, BookInfo::ONTHEBOOKSHELF));
	library.add("Romeo and Juliet", BookInfo("William Shakespeare ", "Tragedy", 120, BookInfo::BORROWED));
	library.add("Metro 2033", BookInfo("Dmitry Glukhovsky", "Post-apocalyptic", 350, BookInfo::ONTHEBOOKSHELF));

	cout << endl << "=== LIBRARY ===" << endl;
	cout << library;

}