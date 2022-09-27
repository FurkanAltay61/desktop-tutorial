/*
 * GradeBook.cpp
 *
 *  Created on: 27 Eyl 2022
 *      Author: furkan.altay
 */



#include "iostream"
#include "GradeBook2.h"

#define FIG3_16		true

using namespace std;

GradeBook2::GradeBook2(string name){
	setCourseName(name); //call set function to initialise courseName
}

#if (FIG3_16 == true)
void GradeBook2::setCourseName(string name){
	if(name.length() <= 25)
	courseName = name; // strore the course name in the object

	if(name.length() > 25){
		courseName = name.substr(0,25);

		cout << "Name \"" << name << "\" exceeds maximum length (25).\n" << endl;
	}
}
#else
void GradeBook2::setCourseName(string name){
	courseName = name; // strore the course name in the object
}
#endif
string GradeBook2::getCoursename(){
	return courseName;
}

void GradeBook2::displayMsg(){
	cout << "Welcome the grade book for \n" << getCoursename() << "!" << endl;
}

