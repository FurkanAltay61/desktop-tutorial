/*
 * FIG07_20_1.cpp
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */

#include "FIG07_20_1.h"

#if (FIG07_20 )
Implementation::Implementation(int v):value(v){
	//empty body
}

void Implementation::setValue(int v){
	value = v;
}

int Implementation::getValue() const{
	return value;
}
#endif
