#include <assert.h>
#include <stdio.h>

// most machines have 32 bit integers
// C standard states this can be anything >= 16 bits
typedef unsigned int Word;

Word reverse_bits(Word value) {
    Word result = 0;

    for (int i = 0; i < 32; i++) {
        // Iterating from the left of the value
        Word mask = (Word)0x1 << (31 - i);
        if (value & mask) {
            // Our digit is 1
            // Shift a 1 into the right place

            // Iterating from the right of the result
            result = result | ((Word)0x1 << i);
        } else {
            // Our digit is 0
        }


    }
    return result;
}

int main(void) {
    assert(reverse_bits(0xFFFFFFFF) == 0xFFFFFFFF);
    assert(reverse_bits(0x00000000) == 0x00000000);
    assert(reverse_bits(0x1) == 0x80000000);
    assert(reverse_bits(0x2) == 0x40000000);
    assert(reverse_bits(0x01234567) == 0xE6A2C480);
    printf("All tests passed!\n");
    return 0;
}
