/*
 * Complex.cpp
 *
 *  Created on: 30 Eyl 2022
 *      Author: furkan.altay
 */



#include <QUE06_06.h>

#if ( QUE06_06 )
#include "iostream"
using namespace std;

Complex::Complex(double rval , double ival){
	Set(rval,ival);
}

void Complex::Add(const Complex &num){
	realPart += num.realPart;
	imaginaryPart += num.imaginaryPart;
}

void Complex::Subtract(const Complex &num){
	realPart -= num.realPart;
	imaginaryPart -= num.imaginaryPart;
}

void Complex::print(void){
	cout << '(' << realPart << "," << imaginaryPart << ')' ;
}

void Complex::Set(double rval , double ival){
	realPart = rval;
	imaginaryPart = ival;
}

#endif
