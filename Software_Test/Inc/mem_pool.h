/*
 * mem_pool.h
 *
 *  Created on: 9 Eyl 2022
 *      Author: furkan.altay
 */

#ifndef MEM_POOL_H_
#define MEM_POOL_H_

#include <inttypes.h>

/**
 * \brief      Allocates a chunk from the memory pool
 * \param buf  Must be a double NULL pointer.
 * \param size Must be greater than zero.
*/
void mem_pool_alloc(void **buf, uint16_t size);

/**
 * \brief      Re-allocates a chunk from the memory pool.
 *             The new chunk is always bigger.
 * \param buf  Must be a double NULL pointer.
 * \param size Must be greater than zero.
*/
void mem_pool_realloc(void **buf, uint16_t new_size);

/**
 * \brief     Release a chunk from the memory pool.
 * \param buf Must be a double pointer.
*/
void mem_pool_free(void **buf);

#endif /* MEM_POOL_H_ */
