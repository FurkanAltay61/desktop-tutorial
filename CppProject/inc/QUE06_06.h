/*
 * Complex.h
 *
 *  Created on: 30 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef QUE06_06_H_
#define QUE06_06_H_

#include "Answers.h"

#if (QUE06_06)

class Complex {

public:
	Complex(double , double);
	void setReal(double);
	void setImaginary(double);
	double getReal(void);
	double getImaginary(void);
	double SubtractReal(Complex & , Complex &);
	double SubtractImaginary(Complex & , Complex &);
	double AddReal(Complex & , Complex &);
	double AddImaginary(Complex & , Complex &);
	void printResult(void);
private:
	double realPart;
	double imaginaryPart;

};

#endif

#endif /* QUE06_06_H_ */
