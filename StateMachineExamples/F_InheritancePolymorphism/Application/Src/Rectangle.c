/*
 * Rectangle.c
 *
 *  Created on: Aug 18, 2022
 *      Author: furkan.altay
 */


#include "Rectangle.h"		/* Rectangle class interface */




/*********************************************************************
 * @fn      		  - Rectangle_ctor
 *
 * @brief             - Rectangle constructor function
 *
 * @param[me]         - Rectangle pointer structure
 * @param[x0]         - x-Coordinate of Shape Structure
 * @param[y0]         - y-Coordinate of Shape Structure
 * @param[w0]         - Width of Rectangle Structure
 * @param[h0]         - Height of Rectangle Structure
 *
 * @return			  - void
 *
 * @Note              - This function initialises rectangle structure member elements

 */
void Rectangle_ctor(Rectangle * const me,
					int16_t x0,int16_t y0,
					uint16_t w0,uint16_t h0)
{

	/* TODO: Information has to be written here */
	static const struct ShapeVtable vtable = {
			(void (*)(Shape const * const me))&Rectangle_draw,
			(uint32_t (*)(Shape const * const me))Rectangle_area
	};


	Shape_ctor(&me->super, x0, y0); /*Shape class constructor*/

	me->super.vptr = &vtable;

	/* init attributes added in this class */
	me->width  = w0;
	me->height = h0;

}



/*********************************************************************
 * @fn      		  - Rectangle_draw
 *
 * @brief             - Rectangle draw function
 *
 * @param[me]         - Rectangle pointer structure
 *
 * @return			  - void
 *
 * @Note              - This function draws a rectangle based on width and height members

 */
void Rectangle_draw(Rectangle const * const me){

}


/*********************************************************************
 * @fn      		  - Rectangle_area
 *
 * @brief             - Rectangle area calculator
 *
 * @param[me]         - Rectangle pointer structure
 *
 * @return			  - Rectangle area absolute value
 *
 * @Note              - This function calculates a rectangle area based on width and height members

 */
uint32_t Rectangle_area(Rectangle const * const me){

	uint32_t rect_area = 0;	/* rectangle area variable */

	rect_area = (uint32_t)me->width * (uint32_t)me->height; /*rectangle area calculated & assigned to value */

	return rect_area; /* rectangle area is returned */
}




