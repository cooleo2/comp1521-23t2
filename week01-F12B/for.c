#include <stdio.h>

int main(void) {
    // print every number from 1 to 10 inclusive with a while loop.
    int i = 1;  // initial value
    while (i <= 10 /* condition */) {
        printf("%d\n", i);
        i++; /* increment */
    }

    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }

    printf("%d\n", i);

   return 0;
}
