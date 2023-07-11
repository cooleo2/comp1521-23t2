#include <stdio.h>
#include <stdint.h>
 
 void print_word_binary(char *string, uint32_t value);

typedef struct six_bit_groups {
    uint8_t middle_bits;
    uint8_t lower_bits;
} six_bit_groups_t;

 
/* 
For example:
00000000 00000101 01000000 01110110 

 
middle six bits are 101010
 lower six bits are 11 0110  
*/
 
// TODO
six_bit_groups_t get_bit_groups(uint32_t value) {
    six_bit_groups_t result;

    // Mask with 6 bits
    uint32_t mask = 0x3F;
    print_word_binary("Mask Lower", mask);
    result.lower_bits = value & mask;
    print_word_binary("Lower", result.lower_bits);
    // Shift mask to middle 6 bits
    mask <<= 13;
    print_word_binary("Mask Middle", mask);
    result.middle_bits = (value & mask) >> 13;
    print_word_binary("Middle",  result.middle_bits);


    return result;
}
 
int main(void) {
    uint32_t num = 0b00000000000001010100000001110110;
    six_bit_groups_t result = get_bit_groups(num);
    printf("Middle: %x, Lower %x\n", result.middle_bits, result.lower_bits);

    return 0;
}

////////////// HELPER FUNCTIONS //////////////
void print_word_binary(char *string, uint32_t value) {
    printf("%s\n", string);
    for (int i = 31; i >= 0; i--) {
        putchar(((value & ((uint32_t)0x1 << i)) >> i) + 48);
    }
    putchar('\n');
}