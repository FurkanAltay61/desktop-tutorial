/*
 * FIG07_20_1.cpp
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */



#include "FIG07_20_2.h"
#include "FIG07_20_1.h"


#if (FIG07_20 )

Interface::Interface(int v):ptr(new Implementation(v)){
	//empty body of Interface constructor
}

void Interface::setValue(int v){
	ptr->setValue(v);
}

int Interface::getValue() const {
	return ptr->getValue();
}

Interface::~Interface(){
	delete ptr;
}

#endif
