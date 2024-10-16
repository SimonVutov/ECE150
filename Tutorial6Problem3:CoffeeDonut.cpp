#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

int main() {
  std::string sales[10] = {"pop", "pop",   "coffee", "coffee", "tea",
                           "pop", "donut", "tea",    "pop",    "coffee"};
  std::string items[5] = {"tea", "coffee", "decaf", "pop", "donut"};
  float prices[5] = {1.00, 1.20, 1.10, 1.85, 2.10};

  float total = 0.0f;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      if (sales[i] == items[j]) {
        total += prices[j];
      }
    }
  }
  std::cout << "Total: " << total << std::endl;
}