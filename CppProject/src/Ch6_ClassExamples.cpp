/*
 * Ch6_ClassExamples.cpp
 *
 *  Created on: 28 Eyl 2022
 *      Author: furkan.altay
 */



#include <iostream>

using namespace std;

#include <iomanip>


struct Time {
	int hour;
	int minute;
	int second;
};

void PrintUniversal(const Time &);
void PrintStandard(const Time &);

int main(){

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

	return 0;
}

void PrintUniversal(const Time &t){

	cout << setfill('0') << setw(2) << t.hour << ":" << setw(2) << t.minute << ":" << setw(2) << t.second;

}

void PrintStandard(const Time &t){

	cout << ((t.hour == 0 || t.hour == 12) ? 12 : t.hour % 12) <<
			":" << setfill('0') << setw(2) << t.minute << ":" << setw(2) << t.second
				<< (t.hour < 12 ? "AM" : "PM");
}
