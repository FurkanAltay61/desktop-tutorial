//============================================================================
// Name        : CppProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "iostream"
#include "string.h"
#include "Answers.h"

using namespace std;

#if(FIG06_05)
#include <FIG06_05.h>
#elif(FIG06_10)
#include <FIG06_10.h>
#elif(FIG06_12)
#include <FIG06_12.h>
#elif(FIG06_15)
#include <FIG06_15.h>
void create(void);
CreateAndDestroy first(1 , "(global before main )");
#elif(FIG06_19)
#include <FIG06_19.h>
void incrementMinutes(Time & ,const int);
#elif(QUE06_06)

#elif(QUE06_07)
#include <QUE06_07.h>
#elif(QUE06_08)
#include "QUE06_08.h"
#elif(QUE06_09)
#include "QUE06_09.h"
#elif(FIG07_06)
#include "FIG07_06_Date.h"
#include "FIG07_06_Employee.h"
#elif(FIG07_13)
#include "FIG07_13_This.h"
#elif(FIG07_14)
#include "FIG07_14.h"
#endif




int main(){

#if(FIG06_05)
	Time t;

	cout << " The ini t ial universal t ime i s " ;
	t . printUniversal ( ) ; // 0 0 : 0 0 : 0 0
	cout << " \n The initial standard t ime i s " ;
	t . printStandard ( ) ; // 1 2 : 0 0 : 0 0 AM

	t.SetTime ( 13 , 27 , 6 ) ;

	cout << "\n\n Universal time after setTime is ";
	t.printUniversal();		//13:27:6
	cout << "\n\n Standard time after setTime is ";
	t.printStandard();		//1:27:06 PM

	t.SetTime(99, 99, 99);

	cout << "\n\n After attempting invalid settings: "
		 << "\nUniversal time: ";
	t.printUniversal();
	cout << "\nStandard time: ";
	t.printStandard();
	cout << endl;


#elif(FIG06_10)
	SalesPerson s; //create salesperson object s

	s.getSalesFromUser();
	s.printAnnualSales();


#elif(FIG06_12)

	Time t1;			//all arguments defaulted
	Time t2(2);			//minute and second defaulted
	Time t3(21,34);		//second(time) defaulted
	Time t4(12,25,42);	//all values specified
	Time t5(27,74,99);	//all values specified



	t1. printUniversal ( ) ; // 0 0 : 0 0 : 0 0
	cout << "\t";
	t1. printStandard ( ) ; // 1 2 : 0 0 : 0 0 AM
	cout << "\n";
	t2. printUniversal ( ) ; // 0 0 : 0 0 : 0 0
	cout << "\t";
	t2. printStandard ( ) ; // 1 2 : 0 0 : 0 0 AM
	cout << "\n";
	t3. printUniversal ( ) ; // 0 0 : 0 0 : 0 0
	cout << "\t";
	t3. printStandard ( ) ; // 1 2 : 0 0 : 0 0 AM
	cout << "\n";
	t4. printUniversal ( ) ; // 0 0 : 0 0 : 0 0
	cout << "\t";
	t4. printStandard ( ) ; // 1 2 : 0 0 : 0 0 AM
	cout << "\n";
	t5. printUniversal ( ) ; // 0 0 : 0 0 : 0 0
	cout << "\t";
	t5. printStandard ( ) ; // 1 2 : 0 0 : 0 0 AM
	cout << "\n";
	cout << endl;

#elif(FIG06_15)

	cout << "\n MAIN FUNCTION : EXECUTION BEGINS " << endl;

	CreateAndDestroy second(2, "(local automatic in main)" );

	static CreateAndDestroy third ( 3, "(local static in main)" );

	create();

	cout << "\n MAIN FUNCTION : EXECUTION RESUMES " << endl;

	CreateAndDestroy fourth ( 4, "(local automatic in main)" );

	cout << "\n MAIN FUNCTION : EXECUTION ENDS " << endl;

	return 0;

#elif( FIG06_19 )

	Time t;			//Create Time Object

	//Set Time using individual set functions

	t.setHour(17);
	t.setMinute(34);
	t.setSecond(55);

	cout << "Result of setting all valid values:\n"
		 << " Hour: " << t.getHour()
		 << " Minute: " << t.getMinute()
		 << " Second: " << t.getSecond()
		 << "\n\n";

	t.setHour(234); 		//Set invalid val
	t.setMinute(43);
	t.setSecond(6373);		//Set invalid second

	cout << "Result of setting invalid value :\n"
		 << " Hour: " << t.getHour()
		 << " Minute: " << t.getMinute()
		 << " Second: " << t.getSecond()
		 << "\n\n";

	t.SetTime(11,58,0);			//set time

	incrementMinutes(t,55);		//increment t's minute by 3

#elif( QUE06_06 )

#elif( QUE06_07 )

Rational r1(1,2) , r2(3,4) , Result;


cout << "number1 is : " ;
r1.printRational();

cout << "number2 is : " ;
r2.printRational();

Result = r1.addRational(r2);

cout << "number1 + number 2 is ";

Result.printfloatRational();


Result = r1.multiplyRational(r2);

cout << "number1 * number 2 is ";

Result.printfloatRational();


Result = r1.divideRational(r2);

cout << "number1 / number 2 is ";

Result.printfloatRational();

#elif( QUE06_08 )
	Time d1(1,11,34,27);

	for(uint32_t i=0;i<100000;i++){
		d1.printTime();
		d1.tickEvent();
	}

#elif( QUE06_09 )
	Date d1(1,3,2012);

	for(uint32_t i=0;i<1000;i++){
		d1.printDate();
		d1.nextDay();
	}

#elif(FIG07_06)
	Date birth(7, 24, 1949);
	Date hire( 3, 12, 1988);
	Employee manager("Bob", "Jones", birth, hire);
	cout << '\n';

	manager.print();

	cout << "\nTest Date constructor with invalid values: \n";
	Date lastDayOff(14, 35, 1994);	//invalid month and day
	cout << endl;

#elif(FIG07_13)
Test testObject(12);
testObject.print();

#elif(FIG07_14)
	Time t;

	t.setHour(18).setMinute(30).setSecond(55);

	cout << "Universal time : ";
	t.printUniversal();

	cout << "\nStandard time : ";
	t.printStandard();

	cout << "\n\nNew Standard Universal time : ";
	t.setTime(20,20,20).printUniversal();

	cout << endl;
#endif

    system("pause");
    return 0;
}


#if(FIG06_15)

void create(void){
	cout << "\nCREATE FUNCTION : EXECUTE BEGINS " << endl;

	CreateAndDestroy fifth(5, "(local automatic in create)" );

	static CreateAndDestroy sixth(6, "(local static create)" );

	CreateAndDestroy seventh(7, "(local automatic in create) " );
}

#elif(FIG06_19)

void incrementMinutes(Time &tt ,const int count){

	cout << " Incrementing minute " << count
		 << "times: \n Start time: ";

	tt.printStandard();

	for(int i = 0; i < count ; i++) {
		tt.setMinute((tt.getMinute() + 1) % 60);

		if(tt.getMinute() == 0)
			tt.setHour((tt.getHour() + 1) % 24);

		cout << "\n minute + 1: ";
		tt.printStandard();
	}

	cout << endl;
}

#endif

