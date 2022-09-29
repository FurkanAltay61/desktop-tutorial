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
#include "time1.h"
#elif(FIG06_10)
#include "Salesp.h"
#elif(FIG06_12)
#include "time2.h"
#elif(FIG06_15)
#include "Create.h"
void create(void);
CreateAndDestroy first(1 , "(global before main )");
#elif(FIG06_19)
#include "time3.h"
void incrementMinutes(Time & ,const int);
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

