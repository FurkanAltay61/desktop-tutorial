/*
 * FIG07_06_Employee.h
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_06_EMPLOYEE_H_
#define CHAPTER7_FIG07_06_EMPLOYEE_H_

#include "Answers.h"

#if ( FIG07_06 )

#include "FIG07_06_Date.h"
#include <iostream>
#include <string>

using namespace std;

class Employee {

public:
	Employee(const char *,const char *,const Date &, const Date &);
	void print() const;
	~Employee();

private:
	char Name[25];
	char Surname[25];
	const Date birthDate;
	const Date hireDate;
};



#endif

#endif /* CHAPTER7_FIG07_06_EMPLOYEE_H_ */
