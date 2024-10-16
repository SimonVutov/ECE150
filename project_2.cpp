#include <cassert>
#include <iostream>

void pattern(unsigned int n) {
  unsigned int width = 2 * n + 1;
  int dif = -2;
  for (unsigned int i = 0; i < 2 * n + 1; i++) {
    for (unsigned int j = 0; j < (2 * n + 1 - width) / 2; j++)
      std::cout << " ";
    for (unsigned int j = 0; j < width; j++)
      std::cout << "*";
    std::cout << std::endl;
    if (width == 1)
      dif = 2;
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
    if (bit == b)
      res++;
  }
  return res;
}

unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1) {
  if (b0 == b1)
    return n;

  // Calculate the bit positions for the bytes
  unsigned int shift0 = b0 * 8;
  unsigned int shift1 = b1 * 8;

  // Extract the bytes at positions b0 and b1
  unsigned int byte0 = (n >> shift0) & 0xFF;
  unsigned int byte1 = (n >> shift1) & 0xFF;

  // Create a mask for the bytes to be swapped
  unsigned int mask = (0xFF << shift0) | (0xFF << shift1);

  // Remove the original bytes from n
  n &= ~mask;

  // Place the swapped bytes back into n
  n |= (byte0 << shift1) | (byte1 << shift0);

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
  std::cout << std::hex << "Original: 0x" << number << ", Swapped: 0x"
            << swapped << std::endl;

  return 0;
}