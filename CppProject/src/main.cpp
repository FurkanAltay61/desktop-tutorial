//============================================================================
// Name        : CppProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "iostream"
#include "string.h"

using namespace std;


#define FIG3_3 false
#define FIG3_5 false
#define FIG3_7 false
#define FIG3_9 false
#define FIG3_11 true


#if (FIG3_3 == true)
class GradeBook {
    public:
    void displayMsg(string courseName){
        cout << "Welcome to the grade book for \n" << courseName << "!" << endl;
    }
};
#endif

#if (FIG3_5 == true)
class GradeBook {

public:
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
#endif

#if (FIG3_7 == true)
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
#endif

#if (FIG3_9 == true)
#include "GradeBook.h"
#endif

#if (FIG3_11 == true)
#include "GradeBook2.h"
#endif

int main(){

#if (FIG3_3 == true)
    string nameofcourse;
    GradeBook myGradeBook;

    cout << "Please enter the course name : ";
    getline(cin,nameofcourse);
    cout << endl;

    myGradeBook.displayMsg(nameofcourse);
#endif

#if (FIG3_5 == true)
    string nameofcourse;
    GradeBook myGradeBook;

    cout << "Initial course name is :" << myGradeBook.getCoursename() << endl;
    cout <<  "\nPlease enter the course name : " << endl;
    getline(cin,nameofcourse);
    myGradeBook.setCourseName(nameofcourse);
    cout << endl;
    myGradeBook.displayMsg();
#endif

#if (FIG3_7 == true)
    GradeBook gradebook1("CS101 Introduction to C++ Programming");
    GradeBook gradebook2("CS102 Data Strctures in C++");

    cout << "gradebook1 created for course :" << gradebook1.getCoursename()
    	 << "\ngradebook2 created for course :" << gradebook2.getCoursename()
		 << endl;
#endif

#if (FIG3_9 == true)
    GradeBook gradebook1("CS101 Introduction to C++ Programming");
    GradeBook gradebook2("CS102 Data Strctures in C++");

    cout << "gradebook1 created for course :" << gradebook1.getCoursename()
    	 << "\ngradebook2 created for course :" << gradebook2.getCoursename()
		 << endl;
#endif

#if (FIG3_11 == true)
    GradeBook2 gradebook1("CS101 Introduction to C++ Programming");
    GradeBook2 gradebook2("CS102 Data Strctures in C++");

    cout << "gradebook1 created for course :" << gradebook1.getCoursename()
    	 << "\ngradebook2 created for course :" << gradebook2.getCoursename()
		 << endl;
#endif

    system("pause");
    return 0;
}
