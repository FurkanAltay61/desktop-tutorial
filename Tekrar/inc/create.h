/*
 * create.h
 *
 *  Created on: 30 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef CREATE_H_
#define CREATE_H_

#include "Answers.h"

#if ( FIG06_17 )

class CreateAndDestroy {

public:
	CreateAndDestroy(int, char *);
	~CreateAndDestroy();

private:
	char *message;
	int dataID;
};

#endif

#endif /* CREATE_H_ */
