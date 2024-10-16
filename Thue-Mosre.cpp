#include <iostream>

int main() {
  unsigned int n = 1;
  for (int i = 0; i < 5; i++) {
    unsigned int negate = ~n & ((1 << (1 << i)) - 1);
    n = (n << (1 << i)) | negate;
  }
  for (int i = 0; i < 32; i++) {
    int mask = 1 << (31 - i); // Change to print from MSB to LSB
    int bit = (n & mask) >> (31 - i);
    std::cout << bit;
  }
  std::cout << std::endl;
}
