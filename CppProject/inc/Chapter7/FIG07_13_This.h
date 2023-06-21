/*
 * FIG07_13_This.h
 *
 *  Created on: 6 Eki 2022
 *      Author: ALTAYSAN
 */

#ifndef CHAPTER7_FIG07_13_THIS_H_
#define CHAPTER7_FIG07_13_THIS_H_

#include "Answers.h"

#if (FIG07_13)

#include <iostream>

using namespace std;

class Test {

public:
	Test( int = 0);
	void print() const;
private:
	int x;
};

#endif

#endif /* CHAPTER7_FIG07_13_THIS_H_ */
