#include <cassert>
#include <iostream>

void prime_factorization(int n) {
  int arr[1000000] = {0};
  while (n != 1) {
    for (int i = 2; i <= n; i++) {
      if (n % i == 0) {
        arr[i]++;
        n /= i;
        break;
      }
    }
  }
  for (int i = 0; i < 1000000; i++) {
    if (arr[i] != 0) {
      std::cout << i << "^" << arr[i] << " ";
    }
  }
}

int main() {
  int x = 0;
  std::cin >> x;
  prime_factorization(x);
}