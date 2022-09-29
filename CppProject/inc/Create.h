/*
 * Create.h
 *
 *  Created on: 29 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef CREATE_H_
#define CREATE_H_

#include "Answers.h"

#if (FIG06_15)
class CreateAndDestroy {

public:
	CreateAndDestroy(int , char *);		//constructor
	~CreateAndDestroy();				//destructor

private:
	int ObjectID;
	char *message;
};
#endif


#endif /* CREATE_H_ */
