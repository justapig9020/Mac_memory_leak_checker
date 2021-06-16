#include <stdio.h>
#include <sys/cdefs.h>

extern void setup_hash(void) __attribute__ ((constructor));
extern void check_leak(void) __attribute__ ((destructor));

void setup_hash(void) {
    printf("Init\n");
}

void check_leak(void) {
    printf("Terminate\n");
}
