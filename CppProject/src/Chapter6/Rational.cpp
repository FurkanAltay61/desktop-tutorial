/*
 * Rational.cpp
 *
 *  Created on: 1 Eki 2022
 *      Author: ALTAYSAN
 */



#include "Rational.h"

#if ( QUE06_07 )

#include <iostream>
using namespace std;

Rational::Rational(double num , double denum){
	SetRational(num,denum);
}

void Rational::SetRational(double num, double denum){
	numerator = num;
	denominator = denum;
}

void Rational::AddRational(Rational &num){

//	numerator += num.numerator;
//	denominator += num.denominator;

	numerator = (numerator * num.denominator) + (denominator * num.numerator);

	denominator = denominator * num.denominator;
}

void Rational::SubtractRational(Rational &num){

//	numerator -= num.numerator;
//	denominator -= num.denominator;

	numerator = (numerator * num.denominator) - (denominator * num.numerator);

	denominator = denominator * num.denominator;
}

void Rational::MultiplyRational(Rational &num){

	numerator *= num.numerator;
	denominator *= num.denominator;
}

void Rational::DivideRational(Rational &num){

	numerator /= num.numerator;
	denominator /= num.denominator;
}

void Rational::PrintRational(void){
	cout << numerator << "/" << denominator ;
}

void Rational::PrintRationalFloating(void){
	cout << numerator / denominator ;
}

#endif
