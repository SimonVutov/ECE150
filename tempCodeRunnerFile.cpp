
  std::sort(stuff, stuff + 5, [&rank, &stuff](std::string a, std::string b) {
    int indexA = std::distance(stuff, std::find(stuff, stuff + 5, a));
    int indexB = std::distance(stuff, std::find(stuff, stuff + 5, b));
    return rank[indexA] < rank[indexB];
  });
  for (int i = 0; i < 5; i++) {
    std::cout << stuff[i] << " " << rank[i] << std::endl;
  }