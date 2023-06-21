/*
 * FIG07_06_Employee.h
 *
 *  Created on: 6 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_06_EMPLOYEE_H_
#define CHAPTER7_FIG07_06_EMPLOYEE_H_


#include "Answers.h"

#if (FIG07_06 )

#include <iostream>
#include "FIG07_06_Date.h"

using namespace std;

class Employee {

public:
	Employee(const char *, const char *,const Date &, const Date &);
	void print() const;
	~Employee();
private:
	char firstName[25];
	char lastName[25];
	const Date birthDate;		//composition: member object
	const Date hireDate;		//composition: member object

};

#endif

#endif /* CHAPTER7_FIG07_06_EMPLOYEE_H_ */
