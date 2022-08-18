/*
 * Shape.c
 *
 *  Created on: Aug 18, 2022
 *      Author: furkan.altay
 */

#include "Shape.h"

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
void Shape_ctor(Shape * const me,int16_t x0,int16_t y0){
	me->x = x0;       /*Shape structure x element are initiliased to x0*/
	me->y = y0;		  /*Shape structure y element are initiliased to y0*/
}


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
void Shape_moveBy(Shape * const me,int16_t dx,int16_t dy){
	me->x += dx;		/*Shape structure x element is increased by dx*/
	me->y += dy;		/*Shape structure y element is increased by dy*/
}


/*********************************************************************
 * @fn      		  - Shape_distanceFrom
 *
 * @brief             -	Shape Distance Calculator
 *
 * @param[*me]        -	Shape pointer structure
 * @param[*other]     - Another shape pointer structure
 *
 * @return            - Absolute distance betweeen two shapes
 *
 * @Note              - This function calculates absolute distance between two shapes
 */
uint16_t Shape_distanceFrom(Shape const * const me,Shape const * const other){

	int16_t dx = me->x - other->x;	/* x coordinates of two elements are evaluated */
	int16_t dy = me->y - other->y;	/* y coordinates of two elements are evaluated */

	if(dx < 0){
		dx = -dx;					/* if x coordinates difference is smaller than zero assign negative value */
	}

	if(dy < 0){
		dy = -dy;					/* if y coordinates difference is smaller than zero assign negative value */
	}

	return dx + dy;					/* calculate & return sum of two coordinates */
}
