/*
 * FIG07_17.cpp
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */


#include "FIG07_17.h"

#if (FIG07_17)

#include <iostream>

using namespace std;

#include <new>
#include <cstring>

int Employee::count = 0;

int Employee::getCount(){
	return count;
}

Employee::Employee(const char *first,const char *last){
	firstName = new char[strlen(first) + 1];
	strcpy(firstName, first);

	lastName = new char[strlen(last) + 1];
	strcpy(lastName, last);

	++count;

	cout << "Employee constructor for "
			<< firstName << ' ' << lastName << " called." << endl;
}

Employee::~Employee(){
	cout << "Employee destructor for " << firstName << ' ' << lastName
		 << " called." << endl;

	delete [] firstName; //free allocated memory
	delete [] lastName; //free allocated memory

	--count;	//decrement static count o employee
}

const char *Employee::getFirstName() const{

	/*
	 * const before return type prevents client from modifying
	 * private data; client should copy returned string before
	 * destructor deletes storage to prevent undefined pointer
	 */
	return firstName;
}

const char *Employee::getLastName() const{

	/*
	 * const before return type prevents client from modifying
	 * private data; client should copy returned string before
	 * destructor deletes storage to prevent undefined pointer
	 */
	return lastName;
}

#endif


