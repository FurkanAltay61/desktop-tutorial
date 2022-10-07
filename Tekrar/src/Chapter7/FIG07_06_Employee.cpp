/*
 * FIG07_06_Employee.cpp
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */

#include "FIG07_06_Employee.h"

#if ( FIG07_06 )

#include <cstring>

Employee::Employee(const char *fname,const char *lname,const Date &dateofBirth, const Date &dateofHire)
:birthDate(dateofBirth), //initialize birthDate
 hireDate(dateofHire){	 //initialize hireDate

	int length = strlen(fname);
	length = (length < 25 ? length : 24);
	for(uint8_t i=0; i < length ? (Name[i] = fname[i]) : '\0' ;i++);

	length = strlen(lname);
	length = (length < 25 ? length : 24);
	for(uint8_t i=0; i < length ? (Surname[i] = lname[i]) : '\0' ;i++);

	/*Method without length checking
	for(uint8_t i=0;(Name[i] = fname[i]) != '\0';i++);
	for(uint8_t i=0;(Surname[i] = lname[i]) != '\0';i++);
	*/
	cout << "Employee object constructor:" << Name << ' ' << Surname << endl;
}

void Employee::print() const {
   cout << Name << " " << Surname << " Hired \n" << endl;
   hireDate.print();
   cout << " Birth Date: ";
   birthDate.print();
   cout << endl;
}

Employee::~Employee(){
	cout << "Employee object destructor: " << Name << " " << Surname << endl;
}


#endif
