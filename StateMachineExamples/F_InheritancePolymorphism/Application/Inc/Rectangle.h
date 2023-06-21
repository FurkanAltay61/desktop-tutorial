/*
 * Rectangle.h
 *
 *  Created on: Aug 18, 2022
 *      Author: furkan.altay
 */

#ifndef INC_RECTANGLE_H_
#define INC_RECTANGLE_H_

#include "Shape.h"

/*
 * Structure Definition
 */
/*********************************************************************
 * @fn      		  - Rectangle Class
 *
 * @brief             - Class that contains basic rectangle member elements
 *
 * @param[super]      - Shape super structure contains shape's elements
 * @param[width]      - Rectangle shape width elements
 * @param[height]      - Rectangle shape height elements
 *
 * @Note              -

 */

typedef struct{

	Shape super; 		/*Inherited Shape*/
	uint16_t width;		/*Width of the rectangle*/
	uint16_t height;	/*Height of the rectangle*/

}Rectangle;

/* Rectangle's operations.. */


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
					uint16_t w0,uint16_t h0);



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
void Rectangle_draw(Rectangle const * const me);


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
uint32_t Rectangle_area(Rectangle const * const me);


#endif /* INC_RECTANGLE_H_ */
