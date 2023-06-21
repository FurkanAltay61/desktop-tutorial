/*
 * Rational.cpp
 *
 *  Created on: 5 Eki 2022
 *      Author: furkan.altay
 */



#include <QUE06_07.h>

#if ( QUE06_07 )

#include <iostream>

using namespace std;

Rational::Rational( double num , double denum){
	setRational(num,denum);
}

void Rational::setRational(double num, double denum){
	numerator = num;
	denominator = denum;
}

Rational Rational::addRational(Rational &f_num2){

	Rational temp_num;
	temp_num.numerator = numerator * f_num2.denominator + denominator * f_num2.numerator;
	temp_num.denominator = denominator * f_num2.denominator;
	temp_num.reduction();

	return temp_num;
}

Rational Rational::subRational(Rational &f_num2){

	Rational temp_num;
	temp_num.numerator = numerator * f_num2.denominator - denominator * f_num2.numerator;
	temp_num.denominator = denominator * f_num2.denominator;
	temp_num.reduction();
	return temp_num;
}

Rational Rational::multiplyRational(Rational &f_num2){

	Rational temp_num;
	temp_num.numerator = numerator *  f_num2.numerator;
	temp_num.denominator = denominator * f_num2.denominator;
	temp_num.reduction();
	return temp_num;
}

Rational Rational::divideRational(Rational &f_num2){

	Rational temp_num;
	temp_num.numerator = numerator /  f_num2.numerator;
	temp_num.denominator = denominator / f_num2.denominator;
	temp_num.reduction();
	return temp_num;
}

void Rational::printRational(){

	if(denominator == 0){
		cout << "Divide By Zero Error !!! " << endl;
	}
	else if(numerator == 0){
		cout << 0;
	}
	else{
		cout << numerator << '/' << denominator << endl;
	}
}

void Rational::printfloatRational(){
	cout << static_cast < double > (numerator) / denominator << endl;
}

void Rational::reduction(void){
	int largest;
	largest = numerator > denominator ? numerator : denominator;

	int gcd = 0; // gcd common divisor

	for(int loop = 2; loop <= largest ; ++loop){
		if ( numerator % loop == 0 && denominator % loop == 0)
			gcd = loop;
	}

	if ( gcd != 0){
		numerator /= gcd;
		denominator /= gcd;
	}

}

#endif


