/*
 * Shape.h
 *
 *  Created on: Aug 18, 2022
 *      Author: furkan.altay
 */

#ifndef INC_SHAPE_H_
#define INC_SHAPE_H_

#include "stdint.h"


/*
 * Structure Definition
 */
/*********************************************************************
 * @fn      		  - Shape
 *
 * @brief             -
 *
 * @param[in]         - x - coordinate of Shape's position
 * @param[in]         - y - coordinate of Shape's position
 *
 * @Note              -

 */

typedef struct{
	uint16_t x; /* x - coordinate of Shape's position */
	uint16_t y; /* y - coordinate of Shape's position */
}Shape;



/*********************************************************************
 * @fn      		  - Shape_ctor
 *
 * @brief             -	Shape Constructor
 *
 * @param[*me]        -	Shape pointer structure
 * @param[x0]         - Shape initializer element
 * @param[y0]         - Shape initializer element
 *
 * @return            - void
 *
 * @Note              - This function initialises elements of Shape structure
 */
void Shape_ctor(Shape * const me,int16_t x0,int16_t y0);


/*********************************************************************
 * @fn      		  - Shape_movBy
 *
 * @brief             -	Shape Mover
 *
 * @param[*me]        -	Shape pointer structure
 * @param[dx]         - Shape distance offset of x coordinates
 * @param[dy]         - Shape distance offset of y coordinates
 *
 * @return            - void
 *
 * @Note              - This function moves a shape by given dx and dy values.
 */
void Shape_moveBy(Shape * const me,int16_t dx,int16_t dy);

#endif /* INC_SHAPE_H_ */
