// Copyright 2025 UNN-CS
#include "circle.h"
#include <cmath>

static const double PI = 3.14159265358979323846;

void Circle::recalcFromRadius() {
  ference = 2.0 * PI * radius;
  area = PI * radius * radius;
}

void Circle::recalcFromFerence() {
  radius = ference / (2.0 * PI);
  area = PI * radius * radius;
}

void Circle::recalcFromArea() {
  radius = sqrt(area / PI);
  ference = 2.0 * PI * radius;
}

Circle::Circle(double r) : radius(r) {
  recalcFromRadius();
}

void Circle::setRadius(double r) {
  radius = r;
  recalcFromRadius();
}

void Circle::setFerence(double f) {
  ference = f;
  recalcFromFerence();
}

void Circle::setArea(double a) {
  area = a;
  recalcFromArea();
}

double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }
