// Prompts the user for a size
// Asserts that the size is odd and at least 3
//  Prints out a capital ‘T’ made
//  out of dollar signs ($) that is
//  size wide and size - 1 tall

#include <cassert>
#include <iostream>
#include <string>
void printT(int size) {
  for (int i = 0; i < size; i++)
    std::cout << "$";
  std::cout << std::endl;
  std::string space = "";
  for (int i = 0; i < size / 2; i++)
    space += " ";
  space += "$";
  for (int i = 0; i < size - 2; i++)
    std::cout << space << std::endl;
}

int main() {
  int size = 0;
  std::cin >> size;
  assert(size % 2 == 1 && size >= 3);
  printT(size);
}