/*
 * GradeBook.h
 *
 *  Created on: 27 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef GRADEBOOK_H_
#define GRADEBOOK_H_

class GradeBook {

public:

	//constructor initializes coursename with string supplied as an argument
	GradeBook(string name){
		setCourseName(name); // call set function to initiliase courseName
	}

	void setCourseName( string name){
    	courseName = name;
    }

    string getCoursename(){
    	return courseName;
    }

	void displayMsg(){
        cout << "Welcome to the grade book for \n" << getCoursename() << "!" << endl;
    }

private:
	string courseName;

};

#endif /* GRADEBOOK_H_ */
