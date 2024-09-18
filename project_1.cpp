#include <iostream>
#include <cmath>

int main() {
  float a = -1, b = -1, c = -1, d = -1, e = -1, f = -1, g = -1;
  float ag = -1, bg = -1, cg = -1, dg = -1, eg = -1, fg = -1, gg = -1;

  while (a <= 0) {
    std::cout << "Enter your max grade on the final examination: ";
    std::cin >> a;
  }
  while (ag < 0 || ag > a) {
    std::cout << "Enter your grade on the final examination: ";
    std::cin >> ag;
  }

  while (b <= 0) {
    std::cout << "Enter your max grade on the midterm examination: ";
    std::cin >> b;
  }
  while (bg < 0 || bg > b) {
    std::cout << "Enter your grade on the midterm examination: ";
    std::cin >> bg;
  }

  while (c <= 0) {
    std::cout << "Enter your max grade on project 1: ";
    std::cin >> c;
  }
  while (cg < 0 || cg > c) {
    std::cout << "Enter your grade on project 1: ";
    std::cin >> cg;
  }

  while (d <= 0) {
    std::cout << "Enter your max grade on project 2: ";
    std::cin >> d;
  }
  while (dg < 0 || dg > d) {
    std::cout << "Enter your grade on project 2: ";
    std::cin >> dg;
  }

  while (e <= 0) {
    std::cout << "Enter your max grade on project 3: ";
    std::cin >> e;
  }
  while (eg < 0 || eg > e) {
    std::cout << "Enter your grade on project 3: ";
    std::cin >> eg;
  }

  while (f <= 0) {
    std::cout << "Enter your max grade on project 4: ";
    std::cin >> f;
  }
  while (fg < 0 || fg > f) {
    std::cout << "Enter your grade on project 4: ";
    std::cin >> fg;
  }

  while (g <= 0) {
    std::cout << "Enter your max grade on project 5: ";
    std::cin >> g;
  }
  while (gg < 0 || gg > g) {
    std::cout << "Enter your grade on project 5: ";
    std::cin >> gg;
  }

  float F100 = (ag / a) * 100;
  float M100 = (bg / b) * 100;
  float P1100 = (cg / c) * 100;
  float P2100 = (dg / d) * 100;
  float P3100 = (eg / e) * 100;
  float P4100 = (fg / f) * 100;
  float P5100 = (gg / g) * 100;
  if (M100 < F100) M100 = F100;
  if (P1100 < F100) P1100 = F100;
  if (P2100 < F100) P2100 = F100;
  if (P3100 < F100) P3100 = F100;
  if (P4100 < F100) P4100 = F100;
  if (P5100 < F100) P5100 = F100;

  float E100 = (F100 * 0.75 + M100 * 0.25);
  float P100 = (P1100 + P2100 + P3100 + P4100 + P5100) / 5;

  float final_grade = E100 * (2.0/3.0) + P100 * (1.0/3.0);
  if (F100 < 60) final_grade = F100;
  else if (F100 > 40 && F100 < 60) final_grade = P100 * (1.0 / 3.0) * ((E100 - 40.0) / 20.0) + E100 * (1 - ((E100 - 40.0) / 20.0));

  int final_grade_int = round(final_grade + 1e-12);
  std::cout << "Your final grade is: " << final_grade_int << std::endl;
  return 0;
}