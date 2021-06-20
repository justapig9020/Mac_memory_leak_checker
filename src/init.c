#include <stdio.h>
#include <stdlib.h>
#include <sys/cdefs.h>
#include <stdbool.h>
#include "mem_tracer.h"

extern void setup_hash(void) __attribute__ ((constructor));
extern void check_leak(void) __attribute__ ((destructor));

bool setuped = false;

void setup_hash(void) {
    printf(""); // pre-init the printf buffer to avoid tracing it
    setuped = true;
}

void check_leak(void) {
    unsigned int unfreed = list_ele();
    if (0 != unfreed) {
        printf("%u memory items unfreed\n", unfreed);
        exit(unfreed);
    } else {
        printf("No memory leak\n");
    }
    setuped = false;
}
