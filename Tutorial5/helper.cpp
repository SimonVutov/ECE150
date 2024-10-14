#include <iostream>

void print_bits(unsigned int a) {
    for (int i = 31; i >= 0; i--)
        std::cout << ((a >> i) & 1);
    std::cout << std::endl;
}

unsigned int flip_double(unsigned int a) {
    unsigned int mask(3);

    for (int i = 0; i < 16; i++) {
        if (((a >> (2 * i)) & mask) == 1) {
            a &= ~(mask << (2 * i));
            a |= (mask << (2 * i + 1));
        } else if (((a >> (2 * i)) & mask) == 2) {
            a &= ~(mask << (2 * i));
            a |= (mask << (2 * i - 1));
        }
    }

    return a;
}