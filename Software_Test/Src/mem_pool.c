/*
 * mem_pool.c
 *
 *  Created on: 9 Eyl 2022
 *      Author: furkan.altay
 */


#include "mem_pool.h"
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>


#define MEMORY_POOL_SIZE    (16384) /** The size in bytes of the statically allocated memory */
#define MEMORY_POOLS_NUM    (64)    /** The number of elements of the memory allocator */

typedef struct
{
    bool     locked;  /** Shows whether the element of the memory allocator is reserved or not */
    uint8_t* start_p; /** The pointer to the first element in the statically allocated memory */
    uint16_t size;    /** The total size of the chunk that is allocated from the memory */

}MemPoolAllocator;

/**
 * The statically allocated array in memory.
*/
static uint8_t memory_pool[MEMORY_POOL_SIZE];

/**
 * Memory allocator struct. It is used to allocate memory in the pool.
*/
static MemPoolAllocator mem_allocator[MEMORY_POOLS_NUM];



void mem_pool_alloc(void **buf, uint16_t size)
{
    assert(buf != NULL);
    assert(*buf == NULL);
    assert(size > 0);

    //__disable_irq();

    for (uint8_t i = 0; i < MEMORY_POOLS_NUM; i++) {
        if (mem_allocator[i].locked == false) {
            mem_allocator[i].locked = true;
            // Find the first unlocked element.
            if (i > 0) {
                mem_allocator[i].start_p = mem_allocator[i - 1].start_p + mem_allocator[i - 1].size;
            }
            else {
                // If the element is the first one the pointer of the chunk points to the first byte of
                // the statically allocated memory.
                mem_allocator[i].start_p = memory_pool;
            }
            mem_allocator[i].size = size;
            // The double pointer points to the address of the pointer.
            // This allows the pointers that the program use to be updated in case
            // a re-allocation is needed.
            *buf = &mem_allocator[i].start_p;

            //__enable_irq();
            return;
        }
    }

    *buf = NULL;
   // __enable_irq();
}

void mem_pool_realloc(void **buf, uint16_t new_size)
{
	assert(buf != NULL);
	assert(new_size > 0);

    //__disable_irq();

    if (*buf == NULL) {
        mem_pool_alloc(buf, new_size);
    }
    else {
        for (uint8_t id = 0; id < MEMORY_POOLS_NUM; id++) {
            if (*buf == &mem_allocator[id].start_p) {
                // The current element must be locked.
                assert(mem_allocator[id].locked == true);
                // Starting from the end, all elements of the memory pool and
                // the memory allocator must move as many as the new_size variable.
                for (uint8_t x = MEMORY_POOLS_NUM - 1; x > id; x--) {
                    if (mem_allocator[x].locked == true) {

                        uint16_t temp_size = mem_allocator[x].size;
                        uint16_t offset_size = new_size - mem_allocator[x].size;

                        for (uint16_t a = mem_allocator[x].size; a > 0; a--) {
                            *(mem_allocator[x].start_p + a + offset_size - 1) = *(mem_allocator[x].start_p + a - 1);
                            *(mem_allocator[x].start_p + a - 1) = 0; // Initialize the new space to 0.
                        }
                        mem_allocator[x].start_p += offset_size;
                        mem_allocator[x].size = new_size;
                    }
                }

                break;
            }
        }
    }

   //__enable_irq();
}

void mem_pool_free(void **buf)
{
    if ((*buf == NULL) || (buf == NULL)) {
        return;
    }

   // __disable_irq();

    uint8_t id = 0;
    for (id = 0; id < MEMORY_POOLS_NUM; id++) {
        if (*buf == &mem_allocator[id].start_p) {
            assert(mem_allocator[id].locked == true);

            mem_allocator[id].locked = false;
            *buf = NULL;

            for (uint16_t i = 0; i < mem_allocator[id].size; i++) {
                mem_allocator[id].start_p[i] = 0;
            }
            mem_allocator[id].start_p = NULL;
            mem_allocator[id].size = 0;

            break;
        }
    }

   // __enable_irq();
}
