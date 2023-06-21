/*
 * FIG07_20_1.h
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_20_1_H_
#define CHAPTER7_FIG07_20_1_H_

#include "Answers.h"

#if (FIG07_20 )

class Implementation {

public:

	Implementation(int);

	void setValue(int);

	int getValue() const;

private:
	int value;
};

#endif

#endif /* CHAPTER7_FIG07_20_1_H_ */
