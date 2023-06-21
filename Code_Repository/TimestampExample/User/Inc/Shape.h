/*
 * Shape.h
 *
 *  Created on: May 5, 2022
 *      Author: furkan.altay
 */

#ifndef INC_SHAPE_H_
#define INC_SHAPE_H_

#include "stdint.h"


typedef struct {
	int16_t x;   /* x-xoordinate Shapes Position*/
	int16_t y;	 /* y-xoordinate Shapes Position*/
}Shape;


/*Special functions to access shape class*/
/* Shape structure intiliazer function*/
/*Note: const variable means that me pointer cannot change but the shape instance pointed to by the pointer is allowed to change*/
void Shape_ctor(Shape * const me,int16_t x0,int16_t y0);
void Shape_moveBy(Shape * const me,int16_t dx,int16_t dy);
uint16_t Shape_distanceFrom(Shape const * me,
							Shape const * other);

#endif /* INC_SHAPE_H_ */
