#include <cassert>
#include <iostream>
#include <string>

void pairFlip(unsigned int &n) { // Pass n by reference
  for (int i = 0; i < 16; i++) {
    int bit1 = (n >> (2 * i)) & 1;     // Correct bit extraction
    int bit2 = (n >> (2 * i + 1)) & 1; // Correct bit extraction
    if (bit1 == bit2) {
      // Flip bit2
      n ^= (1 << (2 * i + 1)); // Use XOR to flip the bit
    }
  }
}

void printBits(unsigned int n) {
  for (int i = 0; i < 32; i++) {
    int mask = 1 << i;
    int bit = (n & mask) >> i;
    std::cout << bit;
    if (i % 8 == 7)
      std::cout << " ";
  }
  std::cout << std::endl;
}

int main() {
  unsigned int n = 0;
  std::cin >> n;
  printBits(n);
  pairFlip(n);
  printBits(n);
  std::cout << n << std::endl;
}
