#include <stdio.h>
#include <sys/cdefs.h>
#include <stdbool.h>

extern void setup_hash(void) __attribute__ ((constructor));
extern void check_leak(void) __attribute__ ((destructor));

bool setuped = false;

void setup_hash(void) {
    printf("Init\n");
    setuped = true;
}

void check_leak(void) {
    printf("Terminate\n");
    setuped = false;
}
