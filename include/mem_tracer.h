#ifndef _MEM_TRACER_H_
#define _MEM_TRACER_H_

#include <stdbool.h>
#include <stdlib.h>

/* Don't insert "NULL" to the following two functions
 */
bool add_ele(void *addr, size_t size);
bool remove_ele(void *addr);
int list_ele();

#endif
