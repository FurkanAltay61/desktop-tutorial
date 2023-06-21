/*
 * Rational.h
 *
 *  Created on: 1 Eki 2022
 *      Author: ALTAYSAN
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "Answers.h"


#if ( QUE06_07 )

class Rational {

public:
	Rational(double,double);
	void AddRational(Rational &);
	void SubtractRational(Rational &);
	void MultiplyRational(Rational &);
	void DivideRational(Rational &);
	void PrintRational(void);
	void PrintRationalFloating(void);
	void SetRational(double , double);
private:
	double numerator;
	double denominator;
};

#endif



#endif /* RATIONAL_H_ */
