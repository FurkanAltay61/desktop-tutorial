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
 * @fn      		  - Shape Class
 *
 * @brief             -
 *
 * @param[in]         - x - coordinate of Shape's position
 * @param[in]         - y - coordinate of Shape's position
 *
 * @Note              -

 */

typedef struct{

	Shape super; 		/*Inherited Shape*/
	uint16_t width;		/*Width of the rectangle*/
	uint16_t height;	/*Height of the rectangle*/

}Rectangle;

/* Rectangle's operations.. */
void Rectangle_ctor(Rectangle * const me,
					int16_t x0,int16_t y0,
					uint16_t w0,uint16_t h0);

void Rectangle_draw(Rectangle const * const me);


#endif /* INC_RECTANGLE_H_ */
