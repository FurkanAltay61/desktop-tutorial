//============================================================================
// Name        : Tekrar.cpp
// Author      : Furkan Altay
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
using namespace std;

#include "Answers.h"

#if(FIG06_05)
#include "time1.h"
#elif(FIG06_10)
#include "SalesPerson.h"
#elif(FIG06_12)
#include "time2.h"
#elif(FIG06_17)
#include "create.h"
CreateAndDestroy obj1(1,"defined Globally");
void funccreate(void);
#elif(FIG06_18)
#include "time3.h"
void IncrementMinutes(Time &, int value);
#endif



int main() {

#if (FIG06_05)
	Time time1;

	time1.setTime(11,59,34);
	time1.printStandard();
	time1.printUniversal();
#elif(FIG06_10)
	SalesPerson sp1;

	sp1.getSales();
	sp1.printSales();
#elif(FIG06_12)
	Time time2;

	time2.setTime(11,59,34);
	time2.printStandard();
	time2.printUniversal();
#elif(FIG06_17)
	CreateAndDestroy obj2(2,"defined in main");
	funccreate();
#elif(FIG06_18)
	Time time3;

	time3.setTime(11,43,56);
	time3.printStandard();
	time3.printUniversal();
	time3.setHour(22);
	time3.printStandard();
	time3.printUniversal();
	IncrementMinutes(time3,60);
#endif

	//system("pause");
	return 0;
}

#if (FIG06_17 )
void funccreate(void){
	CreateAndDestroy obj3(3,"defined in function");
	static CreateAndDestroy obj4(4,"defined in function statically");
}
#elif (FIG06_18)
void IncrementMinutes(Time &tt, int value){

	for(uint8_t i=0; i < value ; i++){
		tt.setMinute((tt.getMinute()+1) % 60);

		if(tt.getMinute() == 0)  tt.setHour((tt.getHour()+1) % 24);

		tt.printStandard();
	}


}
#endif

