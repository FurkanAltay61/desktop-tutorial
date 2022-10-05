/*
 * Complex.h
 *
 *  Created on: 30 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include "Answers.h"

#if (QUE06_06)

class Complex {

public:
	Complex(double , double);
	void Add(const Complex &);
	void Subtract(const Complex &);
	void print(void);
	void Set(double,double);
private:
	double realPart;
	double imaginaryPart;

};

#endif

#endif /* COMPLEX_H_ */
