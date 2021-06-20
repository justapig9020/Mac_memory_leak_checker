#include "mem_tracer.h"
#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void *addr;
    size_t size;
    UT_hash_handle hh;
} ele_t;

ele_t *hash = NULL;

bool add_ele(void *addr, size_t size) {
    ele_t *e = malloc(sizeof(ele_t));
    if (!e)
        return false;
    e->addr = addr;
    e->size = size;
    HASH_ADD_PTR(hash, addr, e);
    return true;
}

bool remove_ele(void *addr) {
    ele_t *e;
    HASH_FIND_PTR(hash, &addr, e);
    if (!e) {
        return false;
    }
    HASH_DEL(hash, e);
    free(e);
    return true;
}

int list_ele() {
    unsigned int num = HASH_COUNT(hash);
    if (0 != num) {
        ele_t *iter;
        for (iter = hash; NULL != iter; iter = iter->hh.next)
            printf("Unfreed address %p: size %lu\n", iter->addr, iter->size);
    }
    return num;
}
