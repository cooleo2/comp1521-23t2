#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0};

    i = 0;
    while (i < 10) {
        int *curr = (numbers + (i * sizeof(int)));
        scanf("%d", curr);
        i++;
    }

    i = 0;
    while (i < 10) {
        int *curr = (numbers + (i * sizeof(int)));
        printf("%d ", *curr);
        i++;
    }
}
