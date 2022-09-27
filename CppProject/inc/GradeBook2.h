/*
 * GradeBook.h
 *
 *  Created on: 27 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef GRADEBOOK_H_
#define GRADEBOOK_H_

#include "string.h"
using namespace std;

class GradeBook2 {

public:

	//constructor initializes coursename with string supplied as an argument
	GradeBook2(string);
	void setCourseName( string );
    string getCoursename();
	void displayMsg();

private:
	string courseName;

};

#endif /* GRADEBOOK_H_ */
