/*
 * Ch6_ClassExamples.cpp
 *
 *  Created on: 28 Eyl 2022
 *      Author: furkan.altay
 */



#include "Answers.h"
#include <iostream>

using namespace std;

#include <iomanip>





#if	(FIG06_01 == true)
struct Time {
	int hour;
	int minute;
	int second;
};

void PrintUniversal(const Time &);
void PrintStandard(const Time &);

#endif


#if	(FIG06_04 == true)
class Count{

public:
	int x;

	void print(){
		cout << x << endl;
	}
};

#endif

int main(){

#if	(FIG06_01 == true)
	Time dinnertime;

	dinnertime.hour = 18;
	dinnertime.minute = 30;
	dinnertime.second = 0;

	cout << "Dinner will be held at ";
	PrintUniversal(dinnertime);
	cout << " universal time , \n which is ";
	PrintStandard(dinnertime);
	cout << "standard time.\n";

	dinnertime.hour = 29;
	dinnertime.minute = 72;

	cout << "\nTime with invalid values: ";
	PrintUniversal(dinnertime);
	cout << endl;
#endif


#if	(FIG06_04 == true)
	Count counter;						//create counter object
	Count *counterPtr = &counter;		//create pointer to counter
	Count &counterRef = counter;		//create reference to counter

	cout << "Assign 1 to x and print using the object's name : ";
	counter.x = 1;						//assign 1 to data member x
	counter.print();					//call member function print

	cout << "Assign 2 to x and print using a reference : ";
	counterRef.x = 2;					//assign 2 to data member x
	counterRef.print();					//call member function print

	cout << "Assign 3 to x and print using the pointer : ";
	counterPtr->x = 3;					//assign 3 to data member x
	counterPtr->print();				//call member function print

#endif

	return 0;
}


#if	(FIG06_01 == true)
void PrintUniversal(const Time &t){

	cout << setfill('0') << setw(2) << t.hour << ":" << setw(2) << t.minute << ":" << setw(2) << t.second;

}

void PrintStandard(const Time &t){

	cout << ((t.hour == 0 || t.hour == 12) ? 12 : t.hour % 12) <<
			":" << setfill('0') << setw(2) << t.minute << ":" << setw(2) << t.second
				<< (t.hour < 12 ? "AM" : "PM");
}

#endif

#if	(FIG06_04 == true)


#endif
