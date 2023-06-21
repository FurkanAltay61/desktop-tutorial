/*
 * Shape.h
 *
 *  Created on: May 5, 2022
 *      Author: furkan.altay
 */

#ifndef INC_SHAPE_H_
#define INC_SHAPE_H_

#include "stdint.h"


/*Shapes attributes..*/

typedef struct {

	struct ShapeVtable const *vptr; /*virtual pointer*/

	int16_t x;   /* x-coordinate Shapes Position*/
	int16_t y;	 /* y-coordinate Shapes Position*/

}Shape;

struct ShapeVtable {
	void (*draw)(Shape const * const me);
	uint32_t (*area)(Shape const * const me);
};

/*Special functions to access shape class*/
/* Shape structure intiliazer function*/
/*Note: const variable means that me pointer cannot change but the shape instance pointed to by the pointer is allowed to change*/
void Shape_ctor(Shape * const me,int16_t x0,int16_t y0);
void Shape_moveBy(Shape * const me,int16_t dx,int16_t dy);
uint16_t Shape_distanceFrom(Shape const * me,
							Shape const * other);


static inline void shape_draw_vcall(Shape const * const me){
	(*me->vptr->draw)(me);
}

static inline uint32_t shape_area_vcall(Shape const * const me){
	return (*me->vptr->area)(me);
}



/*virtual calls(late binding) */
#define SHAPE_DRAW_VCALL(me) (*me->vptr->draw)(me);
#define SHAPE_AREA_VCALL(me) return (*me->vptr->area)(me);

void drawGraph(Shape const *graph[]);

#endif /* INC_SHAPE_H_ */
