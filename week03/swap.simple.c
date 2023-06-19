#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};

f_i_init:
    i = 0;
f_i_cond:
    if (i >= 5) goto f_i_false;

    int x = numbers[i]; // offset = i * 4
        
    int y = numbers[9 - i]; // offset = (9-i) * 4

    numbers[i] = y; // Storing

    numbers[9 - i] = x; // Storing

f_i_step:
    i++;
    goto f_i_cond;
f_i_false:

}
