#include <malloc/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define DYLD_INTERPOSE(_replacement,_replacee) \
__attribute__((used)) static struct{ const void* replacement; const void* replacee; } _interpose_##_replacee \
__attribute__ ((section ("__DATA,__interpose"))) = { (const void*)(unsigned long)&_replacement, (const void*)(unsigned long)&_replacee };

extern bool setuped; // set by constructor

void *hacked_malloc(size_t size){
    void *ret = malloc(size);

    if (setuped)
        malloc_printf("+ %p %d\n", ret, size);
    return ret;
}

void hacked_free(void *freed){
    if (setuped && freed != NULL)
        malloc_printf("- %p\n", freed);
    free(freed);
}

DYLD_INTERPOSE(hacked_malloc, malloc)
DYLD_INTERPOSE(hacked_free, free);
