/*
 * Create.cpp
 *
 *  Created on: 29 Eyl 2022
 *      Author: furkan.altay
 */



#include "Create.h"

#if(FIG06_15)

#include <iostream>
using namespace std;

CreateAndDestroy::CreateAndDestroy(
		int objectNumber , char *messagePtr)
{
	ObjectID = objectNumber;
	message = messagePtr;

	cout << "Object" << ObjectID << "  constructor runs  " << message << endl;
}

CreateAndDestroy::~CreateAndDestroy(){

	cout << (ObjectID == 1 || ObjectID == 6 ? "\n" : "" );
	cout << "Object" << ObjectID << " destructor runs  " << message << endl;
}

#endif



