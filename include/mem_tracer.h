#ifndef _MEM_TRACER_H_
#define _MEM_TRACER_H_

#include <stdbool.h>

/* Don't insert "NULL" to the following two functions
 */
bool add_ele(void *addr);
bool remove_ele(void *addr);
int list_ele();

#endif
