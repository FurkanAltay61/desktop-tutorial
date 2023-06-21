/*
 * create.cpp
 *
 *  Created on: 30 Eyl 2022
 *      Author: furkan.altay
 */




#include "create.h"


#if ( FIG06_17 )

using namespace std;

CreateAndDestroy::CreateAndDestroy(int ID, char *msg){
	dataID = ID;
	message = msg;

	cout << "Object ID : " << dataID << " is created with a message : " << message << endl;
}

CreateAndDestroy::~CreateAndDestroy(){
	cout << "Object ID : " << dataID << " is destructed " << endl;
}

#endif
