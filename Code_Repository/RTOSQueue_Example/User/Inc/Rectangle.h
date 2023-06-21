/*
 * Rectangle.h
 *
 *  Created on: May 5, 2022
 *      Author: furkan.altay
 */

#ifndef INC_RECTANGLE_H_
#define INC_RECTANGLE_H_

#include "Shape.h"

/*Rectangle's attributes*/
typedef struct {
	Shape super; 	/*inherited Shape*/

	/*attributes specific to this class*/
	uint16_t width;
	uint16_t height;

}Rectangle;

void Rectangle_ctor(Rectangle * const me,int16_t x0,int16_t y0,int16_t w0,int16_t h0);
void Rectangle_draw(Rectangle const * const me);
uint32_t Rectangle_area(Rectangle const * const me);


#endif /* INC_RECTANGLE_H_ */
