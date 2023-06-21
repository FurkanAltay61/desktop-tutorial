/*
 * FIG07_13_This.cpp
 *
 *  Created on: 6 Eki 2022
 *      Author: ALTAYSAN
 */


#include "FIG07_13_This.h"

#if (FIG07_13)

Test::Test(int value) : x(value){
	//Test constructor
}

void Test::print() const {

	cout << "         x  = " << x; 			//Implicitly use this pointer to access member x
	cout << "\n	this->x  = " << this->x;	//Explicitly use this pointer to access member x
	cout << "\n(*this).x = " << (*this).x << endl;	//Explicitly use dereferenced this pointer and dot
											//operator to access member x
}

#endif

