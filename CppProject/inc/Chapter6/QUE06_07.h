/*
 * Rational.h
 *
 *  Created on: 5 Eki 2022
 *      Author: furkan.altay
 */

#ifndef QUE06_07_H_
#define QUE06_07_H_

#include "Answers.h"

#if ( QUE06_07 )

class Rational {

public:
	Rational(double = 0, double = 1);
	void setRational(double,double);
	Rational addRational (Rational &);
	Rational subRational (Rational &);
	Rational multiplyRational (Rational &);
	Rational divideRational(Rational &);
	void printRational();
	void printfloatRational();
private:
	int numerator;
	int denominator;
	void reduction(void);

};

#endif

#endif /* QUE06_07_H_ */
