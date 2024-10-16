#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

int main() {
  std::string stuff[5] = {"pencils", "pens", "books", "notebooks", "erasers"};
  int rank[5] = {-1, -1, -1, -1, -1};
  for (int i = 0; i < 5; i++) {
    int rankv = 0;
    while (rankv < 1 || rankv > 5) {
      std::cout << "Enter the rank of " << stuff[i] << ": ";

      std::cin >> rankv;
      for (int j = 0; j < 5; j++) {
        if (rank[j] == rankv) {
          std::cout << "Rank already taken, try again." << std::endl;
          rankv = -1;
          break;
        }
      }
    }
    rank[i] = rankv;
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (rank[i] > rank[j]) {
        std::string temp = stuff[i];
        stuff[i] = stuff[j];
        stuff[j] = temp;
        int tempv = rank[i];
        rank[i] = rank[j];
        rank[j] = tempv;
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    std::cout << stuff[i] << " " << rank[i] << std::endl;
  }
}