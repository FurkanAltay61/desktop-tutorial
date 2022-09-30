/*
 * Complex.cpp
 *
 *  Created on: 30 Eyl 2022
 *      Author: furkan.altay
 */



#include "Complex.h"

#if ( QUE06_06 )

Complex::Complex(double rval , double ival){
	setReal(rval);
	setImaginary(ival);
}

void Complex::setReal(double rval){
	realPart = rval;
}

void Complex::setImaginary(double ival){
	imaginaryPart = ival;
}

double Complex::getReal(void){
	return realPart;
}

double Complex::getImaginary(void){
	return imaginaryPart;
}

double Complex::SubtractReal(Complex &n1,Complex &n2){
	return n1.getReal() - n2.getReal();
}

double Complex::SubtractImaginary(Complex &n1,Complex &n2){
	return n1.getImaginary() - n2.getImaginary();
}

double Complex::AddReal(Complex &n1,Complex &n2){
	return n1.
}

double Complex::AddImaginary(Complex &n1,Complex &n2){

}

#endif
