#include <cassert>
#include <iostream>
#include <string>

int main() {
  int randArray[20] = {74, 20, 30, 50, 10, 60, 44, 55, 22, 33,
                       77, 88, 99, 11, 22, 55, 66, 77, 99, 11};
  int res = -1;
  for (int i = 0; i < 20; i++) {
    if (randArray[i] % 5 == 0) {
      res = i;
    }
  }
  std::cout << res << std::endl;
}