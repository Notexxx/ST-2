// Copyright 2025 UNN-CS
#include <iostream>
#include "circle.h"
#include "tasks.h"

int main() {
  Circle c(5.0);
  std::cout << "Circle r=5:" << std::endl;
  std::cout << "  Radius:    " << c.getRadius() << std::endl;
  std::cout << "  Ference:   " << c.getFerence() << std::endl;
  std::cout << "  Area:      " << c.getArea() << std::endl;

  std::cout << "\nEarth and rope gap: " << ropeGap() << " m" << std::endl;

  double fence = poolFenceCost(3.0, 1.0, 1000.0, 2000.0);
  double concrete = poolConcreteCost(3.0, 1.0, 1000.0);
  std::cout << "\nPool:" << std::endl;
  std::cout << "  Fence cost:    " << fence << " rub" << std::endl;
  std::cout << "  Concrete cost: " << concrete << " rub" << std::endl;

  return 0;
}
