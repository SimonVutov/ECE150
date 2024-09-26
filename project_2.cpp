#include <iostream>
#include <cassert>

void pattern(unsigned int n) {
    unsigned int width = 2 * n + 1;
    int dif = -2;
    for (unsigned int i = 0; i < 2 * n + 1; i++) {
        for (unsigned int j = 0; j < (2 * n + 1 - width) / 2; j++) std::cout << " ";
        for (unsigned int j = 0; j < width; j++) std::cout << "*";
        std::cout << std::endl;
        if (width == 1) dif = 2;
        width += dif;
    }
}

unsigned int log10(unsigned int n) {
    // Asserts that the argument n != 0.
    assert(n != 0);
    unsigned int res = 0;
    while (n >= 10) {
        n /= 10;
        res++;
    }
    return res;
}

unsigned int count(unsigned int n, unsigned int b) {
    // Assert that bit is either equal to 0 or 1
    assert(b == 0 || b == 1);
    unsigned int res = 0;
    // Iterate over all bits of unsigned int
    for (int i = 0; i < 32; ++i) {
        unsigned int bit = (n >> i) & 1;
        if (bit == b) res++;
    }
    return res;
}

unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1) {
    // Ensure that b0 and b1 are within the valid range [0, 3]
    assert(b0 <= 3);
    assert(b1 <= 3);

    // If the bytes are the same, return n unchanged
    if (b0 == b1) {
        return n;
    }

    // Calculate the byte masks for the two positions
    unsigned int shift_b0 = b0 * 8;  // b0 byte shift
    unsigned int shift_b1 = b1 * 8;  // b1 byte shift

    // Extract the bytes from the respective positions
    unsigned int byte_b0 = (n >> shift_b0) & 0xFF; // Extract byte at b0
    unsigned int byte_b1 = (n >> shift_b1) & 0xFF; // Extract byte at b1

    // Clear the b0 and b1 byte positions in n
    n &= ~(0xFF << shift_b0); // Clear b0 byte
    n &= ~(0xFF << shift_b1); // Clear b1 byte

    // Place the swapped bytes back into the cleared positions
    n |= (byte_b0 << shift_b1); // Place b0 byte in b1's position
    n |= (byte_b1 << shift_b0); // Place b1 byte in b0's position

    return n;
}

int main() {
    pattern(5);
    unsigned int input = 1001;
    std::cout << "log10(" << input << ") = " << log10(input) << std::endl;
    std::cout << "count(" << input << ", 1) = " << count(input, 1) << std::endl;
    std::cout << "count(" << input << ", 0) = " << count(input, 0) << std::endl;

    // Example usage of swap_bytes
    unsigned int number = 0x12345678;
    unsigned int swapped = swap_bytes(number, 0, 3);
    std::cout << std::hex << "Original: 0x" << number << ", Swapped: 0x" << swapped << std::endl;

    return 0;
}