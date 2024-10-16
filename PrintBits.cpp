#include <cassert>
#include <iostream>
#include <string>

void printBits(unsigned int n) {
  for (int i = 0; i < 32; i++) {
    int mask = 1 << i;
    int bit = (n & mask) >> i;
    std::cout << bit;
    if (i % 8 == 7)
      std::cout << " ";
  }
}

int main() {
  unsigned int n = 0;
  std::cin >> n;
  printBits(n);
}