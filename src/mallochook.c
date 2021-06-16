#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "mem_tracer.h"

#define DYLD_INTERPOSE(_replacement,_replacee) \
__attribute__((used)) static struct{ const void* replacement; const void* replacee; } _interpose_##_replacee \
__attribute__ ((section ("__DATA,__interpose"))) = { (const void*)(unsigned long)&_replacement, (const void*)(unsigned long)&_replacee };

extern bool setuped; // set by constructor

void *hacked_malloc(size_t size){
    void *ret = malloc(size);

    if (setuped) {
        if (!ret) {
            printf("Malloc failed\n");
            return NULL;
        }
        if (!add_ele(ret))
            printf("Add ele failed\n");
    }
    return ret;
}

void hacked_free(void *addr){
    if (setuped && addr != NULL) {
        if (!remove_ele(addr))
            printf("Rm ele failed\n");
    }
    free(addr);
}

DYLD_INTERPOSE(hacked_malloc, malloc)
DYLD_INTERPOSE(hacked_free, free);
