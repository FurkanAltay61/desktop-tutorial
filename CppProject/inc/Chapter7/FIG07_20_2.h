/*
 * FIG07_20_1.h
 *
 *  Created on: 7 Eki 2022
 *      Author: furkan.altay
 */

#ifndef CHAPTER7_FIG07_20_2_H_
#define CHAPTER7_FIG07_20_2_H_

#include "Answers.h"

#if (FIG07_20 )

class Implementation;		//forward class declaration

class Interface {

public:
	Interface(int);
	void setValue(int);
	int  getValue() const;
	~Interface();
private:
	Implementation *ptr;
};

#endif


#endif /* CHAPTER7_FIG07_20_2_H_ */
