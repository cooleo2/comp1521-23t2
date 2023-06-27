#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);

    // How do we print this number in different bases?
    printf("Decimal: %d, Hexadecimal: 0x%x, Octal: 0%o\n", n, n, n);

    return 0;
}
