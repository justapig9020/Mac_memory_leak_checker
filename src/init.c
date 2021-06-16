#include <stdio.h>
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
    printf("%u memory items unfreed\n", unfreed);
    setuped = false;
}
