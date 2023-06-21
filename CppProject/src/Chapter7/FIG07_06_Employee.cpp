/*
 * FIG07_06_Employee.cpp
 *
 *  Created on: 6 Eki 2022
 *      Author: furkan.altay
 */



#include "FIG07_06_Employee.h"
#if (FIG07_06 )
#include "string.h"

Employee::Employee(const char *first, const char *last ,
				   const Date &dateofBirth, const Date &dateofHire) : birthDate(dateofBirth) ,
				   	   	   	   	   	   	   	   	   	   	   	   	   	  hireDate( dateofHire)
{
	int length = strlen(first);
	length = (length < 25 ? length : 24);
	strncpy(firstName,first,length);
	firstName[ length ] = '\0';

	length = strlen(last );
	length = (length < 25 ? length : 24);
	strncpy(lastName,last,length);
	lastName[ length ] = '\0';


	cout << "Employee object constructor: " << firstName << ' ' << lastName << endl;
}

void Employee::print() const {
	cout << lastName << ", " << firstName << "\nHired: ";
	hireDate.print();
	cout << endl;
}

Employee::~Employee(){
	cout << "Employee object destructor : " << lastName << ", " << firstName << endl;
}

#endif
