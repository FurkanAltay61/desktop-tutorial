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
 * IMPORTANT LINK FOR UNDERSTANDING POLYMORPHISM : https://www.youtube.com/watch?v=2v_qM5SJDlY&list=PLPW8O6W-1chwyTzI3BHwBLbGQoPFxPAPM&index=13
 */


/*
 * Structure Definition
 */
/*********************************************************************
 * @fn      		  - Shape Class
 *
 * @brief             -
 *
 * @param[vptr]       - vptr - virtual pointer of structure
 * @param[x]          - x - coordinate of Shape's position
 * @param[y]          - y - coordinate of Shape's position
 *
 * @Note              -

 */

typedef struct{
	struct ShapeVtable	const * vptr; 	/*virtual pointer*/
	uint16_t x; 					  	/* x - coordinate of Shape's position */
	uint16_t y; 					  	/* y - coordinate of Shape's position */
}Shape;


/* TODO: Information has to be written here */
struct ShapeVtable {
	/* pointer to draw() method */
	void (*draw)(Shape const * const me);
	/* pointer to area() method */
	uint32_t (*area)(Shape const * const me);
};


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
uint16_t Shape_distanceFrom(Shape const * const me,Shape const * const other);



/* TODO: Information has to be written here */
void drawGraph(Shape const *graph[]);

/*virtual calls late binding*/

/* TODO: Information has to be written here */
static inline void Shape_draw_vcall(Shape const * const me){

	(*me->vptr->draw)(me);
}

/* TODO: Information has to be written here */
static inline uint32_t Shape_area_vcall(Shape const * const me){

	return (*me->vptr->area)(me);

}


#define SHAPE_DRAW_VCALL(me) (*(me)->vptr->draw)((me))
#define SHAPE_AREA_VCALL(me) (*(me)->vptr->area)((me))

#endif /* INC_SHAPE_H_ */
