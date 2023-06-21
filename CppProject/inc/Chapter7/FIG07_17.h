/*
 * FIG07_17.h
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_17_H_
#define CHAPTER7_FIG07_17_H_

#include "Answers.h"

#if (FIG07_17)

#include <iostream>

class Employee {

public:
	Employee(const char *, const char *);
	~Employee();
	const char *getFirstName() const;
	const char *getLastName() const;

	/*-----------------------------------------*/
	//static member function
	static int getCount();
	/*-----------------------------------------*/

private:
	char *firstName;
	char *lastName;

	/*-----------------------------------------*/
	//static data member
	static int count;
	/*-----------------------------------------*/
};

#endif

#endif /* CHAPTER7_FIG07_17_H_ */
